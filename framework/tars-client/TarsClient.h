#ifndef TARS_CLIENT
#define TARS_CLIENT

#include <functional>
#include "framework/AdminReg.h"
#include "servant/Application.h"

class TarsClient {
 public:
  typedef std::function<void(TarsClient *, TC_Option &)> command_function;

  TarsClient(TC_Option &option);

  ~TarsClient();

  void add(const string &command, command_function func) {
    _commands[command] = func;
  }

  Communicator *getCommunicator() { return _comm; }

  void call(const string &command);

 protected:
  TC_Option _option;

  map<string, command_function> _commands;

  Communicator *_comm;
};

#endif