<?php
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: actComment.proto

namespace Protocol\QD\ActCommentPbServer;

use Google\Protobuf\Internal\GPBType;
use Google\Protobuf\Internal\RepeatedField;
use Google\Protobuf\Internal\GPBUtil;

/**
 * Generated from protobuf message <code>protocol.QD.ActCommentPbServer.SimpleComment</code>
 */
class SimpleComment extends \Google\Protobuf\Internal\Message
{
    /**
     * Generated from protobuf field <code>int32 id = 1;</code>
     */
    private $id = 0;
    /**
     * Generated from protobuf field <code>int64 activityId = 2;</code>
     */
    private $activityId = 0;
    /**
     * Generated from protobuf field <code>int64 userId = 3;</code>
     */
    private $userId = 0;
    /**
     * Generated from protobuf field <code>string content = 4;</code>
     */
    private $content = '';
    /**
     * Generated from protobuf field <code>string title = 5;</code>
     */
    private $title = '';
    /**
     * Generated from protobuf field <code>string ext1 = 6;</code>
     */
    private $ext1 = '';
    /**
     * Generated from protobuf field <code>int64 createTime = 7;</code>
     */
    private $createTime = 0;

    /**
     * Constructor.
     *
     * @param array $data {
     *     Optional. Data for populating the Message object.
     *
     *     @type int $id
     *     @type int|string $activityId
     *     @type int|string $userId
     *     @type string $content
     *     @type string $title
     *     @type string $ext1
     *     @type int|string $createTime
     * }
     */
    public function __construct($data = NULL) {
        \GPBMetadata\ActComment::initOnce();
        parent::__construct($data);
    }

    /**
     * Generated from protobuf field <code>int32 id = 1;</code>
     * @return int
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Generated from protobuf field <code>int32 id = 1;</code>
     * @param int $var
     * @return $this
     */
    public function setId($var)
    {
        GPBUtil::checkInt32($var);
        $this->id = $var;

        return $this;
    }

    /**
     * Generated from protobuf field <code>int64 activityId = 2;</code>
     * @return int|string
     */
    public function getActivityId()
    {
        return $this->activityId;
    }

    /**
     * Generated from protobuf field <code>int64 activityId = 2;</code>
     * @param int|string $var
     * @return $this
     */
    public function setActivityId($var)
    {
        GPBUtil::checkInt64($var);
        $this->activityId = $var;

        return $this;
    }

    /**
     * Generated from protobuf field <code>int64 userId = 3;</code>
     * @return int|string
     */
    public function getUserId()
    {
        return $this->userId;
    }

    /**
     * Generated from protobuf field <code>int64 userId = 3;</code>
     * @param int|string $var
     * @return $this
     */
    public function setUserId($var)
    {
        GPBUtil::checkInt64($var);
        $this->userId = $var;

        return $this;
    }

    /**
     * Generated from protobuf field <code>string content = 4;</code>
     * @return string
     */
    public function getContent()
    {
        return $this->content;
    }

    /**
     * Generated from protobuf field <code>string content = 4;</code>
     * @param string $var
     * @return $this
     */
    public function setContent($var)
    {
        GPBUtil::checkString($var, True);
        $this->content = $var;

        return $this;
    }

    /**
     * Generated from protobuf field <code>string title = 5;</code>
     * @return string
     */
    public function getTitle()
    {
        return $this->title;
    }

    /**
     * Generated from protobuf field <code>string title = 5;</code>
     * @param string $var
     * @return $this
     */
    public function setTitle($var)
    {
        GPBUtil::checkString($var, True);
        $this->title = $var;

        return $this;
    }

    /**
     * Generated from protobuf field <code>string ext1 = 6;</code>
     * @return string
     */
    public function getExt1()
    {
        return $this->ext1;
    }

    /**
     * Generated from protobuf field <code>string ext1 = 6;</code>
     * @param string $var
     * @return $this
     */
    public function setExt1($var)
    {
        GPBUtil::checkString($var, True);
        $this->ext1 = $var;

        return $this;
    }

    /**
     * Generated from protobuf field <code>int64 createTime = 7;</code>
     * @return int|string
     */
    public function getCreateTime()
    {
        return $this->createTime;
    }

    /**
     * Generated from protobuf field <code>int64 createTime = 7;</code>
     * @param int|string $var
     * @return $this
     */
    public function setCreateTime($var)
    {
        GPBUtil::checkInt64($var);
        $this->createTime = $var;

        return $this;
    }

}

