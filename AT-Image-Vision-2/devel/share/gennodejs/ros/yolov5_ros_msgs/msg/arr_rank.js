// Auto-generated. Do not edit!

// (in-package yolov5_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let arr = require('./arr.js');

//-----------------------------------------------------------

class arr_rank {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.arrs = null;
      this.rank = null;
    }
    else {
      if (initObj.hasOwnProperty('arrs')) {
        this.arrs = initObj.arrs
      }
      else {
        this.arrs = [];
      }
      if (initObj.hasOwnProperty('rank')) {
        this.rank = initObj.rank
      }
      else {
        this.rank = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type arr_rank
    // Serialize message field [arrs]
    // Serialize the length for message field [arrs]
    bufferOffset = _serializer.uint32(obj.arrs.length, buffer, bufferOffset);
    obj.arrs.forEach((val) => {
      bufferOffset = arr.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [rank]
    bufferOffset = _arraySerializer.int32(obj.rank, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type arr_rank
    let len;
    let data = new arr_rank(null);
    // Deserialize message field [arrs]
    // Deserialize array length for message field [arrs]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.arrs = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.arrs[i] = arr.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [rank]
    data.rank = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.arrs.forEach((val) => {
      length += arr.getMessageSize(val);
    });
    length += 4 * object.rank.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'yolov5_ros_msgs/arr_rank';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fda0ba7f4327a4a5573e422b6bef24b9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    arr[] arrs
    int32[] rank
    ================================================================================
    MSG: yolov5_ros_msgs/arr
    int32[] arr
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new arr_rank(null);
    if (msg.arrs !== undefined) {
      resolved.arrs = new Array(msg.arrs.length);
      for (let i = 0; i < resolved.arrs.length; ++i) {
        resolved.arrs[i] = arr.Resolve(msg.arrs[i]);
      }
    }
    else {
      resolved.arrs = []
    }

    if (msg.rank !== undefined) {
      resolved.rank = msg.rank;
    }
    else {
      resolved.rank = []
    }

    return resolved;
    }
};

module.exports = arr_rank;
