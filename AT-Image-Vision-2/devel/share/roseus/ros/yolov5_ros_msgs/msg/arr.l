;; Auto-generated. Do not edit!


(when (boundp 'yolov5_ros_msgs::arr)
  (if (not (find-package "YOLOV5_ROS_MSGS"))
    (make-package "YOLOV5_ROS_MSGS"))
  (shadow 'arr (find-package "YOLOV5_ROS_MSGS")))
(unless (find-package "YOLOV5_ROS_MSGS::ARR")
  (make-package "YOLOV5_ROS_MSGS::ARR"))

(in-package "ROS")
;;//! \htmlinclude arr.msg.html


(defclass yolov5_ros_msgs::arr
  :super ros::object
  :slots (_arr ))

(defmethod yolov5_ros_msgs::arr
  (:init
   (&key
    ((:arr __arr) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _arr __arr)
   self)
  (:arr
   (&optional __arr)
   (if __arr (setq _arr __arr)) _arr)
  (:serialization-length
   ()
   (+
    ;; int32[] _arr
    (* 4    (length _arr)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _arr
     (write-long (length _arr) s)
     (dotimes (i (length _arr))
       (write-long (elt _arr i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _arr
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _arr (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _arr i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get yolov5_ros_msgs::arr :md5sum-) "8b419786816700aebca77fec769e86a3")
(setf (get yolov5_ros_msgs::arr :datatype-) "yolov5_ros_msgs/arr")
(setf (get yolov5_ros_msgs::arr :definition-)
      "int32[] arr
")



(provide :yolov5_ros_msgs/arr "8b419786816700aebca77fec769e86a3")


