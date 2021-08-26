﻿/**
 * Tencent is pleased to support the open source community by making Tars
 * available.
 *
 * Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
#include "util/tc_timer.h"

namespace tars {

TC_Timer::~TC_Timer() { stopTimer(); }

void TC_Timer::startTimer(int numThread) {
  if (numThread <= 0) {
    numThread = 1;
  }

  _terminate = false;

  _tpool.init(numThread + 1);
  _tpool.start();
  _tpool.exec(std::bind(&TC_Timer::run, this));
}

void TC_Timer::stopTimer() {
  if (_terminate) {
    return;
  }

  {
    std::unique_lock<std::mutex> lck(_mutex);
    _terminate = true;
    _cond.notify_all();
  }

  _tpool.stop();
}

bool TC_Timer::exist(int64_t uniqId, bool repeat) {
  std::lock_guard<std::mutex> lock(_mutex);
  if (repeat) {
    return _repeatIds.find(uniqId) != _repeatIds.end();
  } else {
    return _mapEvent.find(uniqId) != _mapEvent.end();
  }
}

void TC_Timer::clear() {
  std::lock_guard<std::mutex> lock(_mutex);

  _mapEvent.clear();
  _mapTimer.clear();
  _repeatIds.clear();
}

void TC_Timer::erase(int64_t uniqId) {
  std::lock_guard<std::mutex> lock(_mutex);
  auto it = _mapEvent.find(uniqId);

  // LOG_CONSOLE_DEBUG << "before erase event!" << ",uniqId=" << uniqId <<
  // "|event size :" << _mapEvent.size() << "|timer size:" << _mapTimer.size() <<
  // endl;
  if (it != _mapEvent.end()) {
    auto itEvent = _mapTimer.find(it->second->_fireMillseconds);
    if (itEvent != _mapTimer.end()) {
      itEvent->second.erase(uniqId);
      if (itEvent->second.empty()) {
        _mapTimer.erase(itEvent);
      }
    }
    it->second->_func = nullptr;
    _mapEvent.erase(it);
  }
  _repeatIds.erase(uniqId);
  //    LOG_CONSOLE_DEBUG << "after erase event!" << ",uniqId=" << uniqId <<
  //    "|event size :" << _mapEvent.size() << "|timer size:" <<
  //    _mapTimer.size() << endl;
}

int64_t TC_Timer::post(const shared_ptr<TC_Timer::Func> &event, bool repeat) {
  std::unique_lock<std::mutex> lock(_mutex);

  int64_t uniqId = event->_uniqueId;

  if (repeat) {
    _repeatIds.insert(uniqId);
  }

  if (_mapEvent.find(uniqId) == _mapEvent.end()) {
    _mapEvent[uniqId] = event;
  }
  _mapTimer[event->_fireMillseconds].insert(uniqId);
  //    LOG_CONSOLE_DEBUG << "post event! fire time:" <<
  //    TC_Common::msToTimeString(event->_fireMillseconds ) << ",uniqId=" <<
  //    uniqId << "|event size :"
  //                      << _mapEvent.size() << "|timer size:" <<
  //                      _mapTimer.size() <<",_func=" << &(event->_func)<<
  //                      endl;
  _cond.notify_one();
  return uniqId;
}

void TC_Timer::fireEvent(const EVENT_SET &el) {
  auto itList = el.begin();

  while (itList != el.end()) {
    shared_ptr<Func> func;

    {
      std::lock_guard<std::mutex> lock(_mutex);

      auto it = _mapEvent.find(*itList);
      if (it != _mapEvent.end()) {
        func = it->second;
        _tmpEvent[it->first] = it->second;
        _mapEvent.erase(it);
      }
    }
    if (func) {
      //执行具体事件对象
      _tpool.exec(func->_func);
    }

    ++itList;
  }
}

void TC_Timer::run() {
  while (!_terminate) {
    try {
      EVENT_SET el;

      {
        std::unique_lock<std::mutex> lock(_mutex);

        auto it = _mapTimer.begin();

        if (it != _mapTimer.end()) {
          uint64_t ms = TC_TimeProvider::getInstance()->getNowMs();

          //                    LOG_CONSOLE_DEBUG << "now ms:" <<
          //                    TC_Common::msToTimeString(ms ) << "|timer:" <<
          //                    TC_Common::msToTimeString(it->first) << endl;
          if (it->first <= ms) {
            //时间过了, 有事件需要触发了
            el.swap(it->second);
            _mapTimer.erase(it);
          } else {
            //时间还没到
            ms = it->first - ms;
            _cond.wait_for(lock, std::chrono::milliseconds(ms));
          }
        } else {
          //没有任何事件, 等待一下
          _cond.wait_for(lock, std::chrono::milliseconds(1000));
        }
      }

      if (!el.empty()) {
        //触发相关所有事件
        fireEvent(el);
      }

    } catch (exception &ex) {
      cerr << ex.what() << endl;
    }
  }
}

uint32_t TC_Timer::genUniqueId() {
  uint32_t i = ++_increaseId;
  if (i == 0) {
    i = ++_increaseId;
  }

  return i;
}

tuple<int64_t, int64_t, int64_t> TC_Timer::status() {
  std::unique_lock<std::mutex> lock(_mutex);
  return make_tuple(_tpool.getJobNum(), _mapEvent.size(), _repeatIds.size());
}
}  // namespace tars
