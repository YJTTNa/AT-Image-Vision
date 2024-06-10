; Auto-generated. Do not edit!


(cl:in-package yolov5_ros_msgs-msg)


;//! \htmlinclude arr_rank.msg.html

(cl:defclass <arr_rank> (roslisp-msg-protocol:ros-message)
  ((arrs
    :reader arrs
    :initarg :arrs
    :type (cl:vector yolov5_ros_msgs-msg:arr)
   :initform (cl:make-array 0 :element-type 'yolov5_ros_msgs-msg:arr :initial-element (cl:make-instance 'yolov5_ros_msgs-msg:arr)))
   (rank
    :reader rank
    :initarg :rank
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass arr_rank (<arr_rank>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <arr_rank>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'arr_rank)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolov5_ros_msgs-msg:<arr_rank> is deprecated: use yolov5_ros_msgs-msg:arr_rank instead.")))

(cl:ensure-generic-function 'arrs-val :lambda-list '(m))
(cl:defmethod arrs-val ((m <arr_rank>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_ros_msgs-msg:arrs-val is deprecated.  Use yolov5_ros_msgs-msg:arrs instead.")
  (arrs m))

(cl:ensure-generic-function 'rank-val :lambda-list '(m))
(cl:defmethod rank-val ((m <arr_rank>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolov5_ros_msgs-msg:rank-val is deprecated.  Use yolov5_ros_msgs-msg:rank instead.")
  (rank m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <arr_rank>) ostream)
  "Serializes a message object of type '<arr_rank>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'arrs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'arrs))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'rank))))
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
   (cl:slot-value msg 'rank))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <arr_rank>) istream)
  "Deserializes a message object of type '<arr_rank>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'arrs) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'arrs)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'yolov5_ros_msgs-msg:arr))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'rank) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'rank)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<arr_rank>)))
  "Returns string type for a message object of type '<arr_rank>"
  "yolov5_ros_msgs/arr_rank")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'arr_rank)))
  "Returns string type for a message object of type 'arr_rank"
  "yolov5_ros_msgs/arr_rank")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<arr_rank>)))
  "Returns md5sum for a message object of type '<arr_rank>"
  "fda0ba7f4327a4a5573e422b6bef24b9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'arr_rank)))
  "Returns md5sum for a message object of type 'arr_rank"
  "fda0ba7f4327a4a5573e422b6bef24b9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<arr_rank>)))
  "Returns full string definition for message of type '<arr_rank>"
  (cl:format cl:nil "arr[] arrs~%int32[] rank~%================================================================================~%MSG: yolov5_ros_msgs/arr~%int32[] arr~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'arr_rank)))
  "Returns full string definition for message of type 'arr_rank"
  (cl:format cl:nil "arr[] arrs~%int32[] rank~%================================================================================~%MSG: yolov5_ros_msgs/arr~%int32[] arr~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <arr_rank>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'arrs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'rank) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <arr_rank>))
  "Converts a ROS message object to a list"
  (cl:list 'arr_rank
    (cl:cons ':arrs (arrs msg))
    (cl:cons ':rank (rank msg))
))
