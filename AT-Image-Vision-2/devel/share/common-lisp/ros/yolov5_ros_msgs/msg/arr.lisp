; Auto-generated. Do not edit!


(cl:in-package yolov5_ros_msgs-msg)


;//! \htmlinclude arr.msg.html

(cl:defclass <arr> (roslisp-msg-protocol:ros-message)
  ((arr
    :reader arr
    :initarg :arr
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass arr (<arr>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <arr>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'arr)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolov5_ros_msgs-msg:<arr> is deprecated: use yolov5_ros_msgs-msg:arr instead.")))

(cl:ensure-generic-function 'arr-val :lambda-list '(m))
(cl:defmethod arr-val ((m <arr>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_ros_msgs-msg:arr-val is deprecated.  Use yolov5_ros_msgs-msg:arr instead.")
  (arr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <arr>) ostream)
  "Serializes a message object of type '<arr>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'arr))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'arr))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <arr>) istream)
  "Deserializes a message object of type '<arr>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'arr) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'arr)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<arr>)))
  "Returns string type for a message object of type '<arr>"
  "yolov5_ros_msgs/arr")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'arr)))
  "Returns string type for a message object of type 'arr"
  "yolov5_ros_msgs/arr")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<arr>)))
  "Returns md5sum for a message object of type '<arr>"
  "8b419786816700aebca77fec769e86a3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'arr)))
  "Returns md5sum for a message object of type 'arr"
  "8b419786816700aebca77fec769e86a3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<arr>)))
  "Returns full string definition for message of type '<arr>"
  (cl:format cl:nil "int32[] arr~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'arr)))
  "Returns full string definition for message of type 'arr"
  (cl:format cl:nil "int32[] arr~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <arr>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'arr) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <arr>))
  "Converts a ROS message object to a list"
  (cl:list 'arr
    (cl:cons ':arr (arr msg))
))
