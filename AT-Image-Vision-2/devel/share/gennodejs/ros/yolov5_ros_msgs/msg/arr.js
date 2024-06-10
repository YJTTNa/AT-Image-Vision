// Auto-generated. Do not edit!

// (in-package yolov5_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class arr {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.arr = null;
    }
    else {
      if (initObj.hasOwnProperty('arr')) {
        this.arr = initObj.arr
      }
      else {
        this.arr = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type arr
    // Serialize message field [arr]
    bufferOffset = _arraySerializer.int32(obj.arr, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type arr
    let len;
    let data = new arr(null);
    // Deserialize message field [arr]
    data.arr = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.arr.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'yolov5_ros_msgs/arr';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8b419786816700aebca77fec769e86a3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[] arr
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new arr(null);
    if (msg.arr !== undefined) {
      resolved.arr = msg.arr;
    }
    else {
      resolved.arr = []
    }

    return resolved;
    }
};

module.exports = arr;
