;; Auto-generated. Do not edit!


(when (boundp 'yolov5_ros_msgs::arr_rank)
  (if (not (find-package "YOLOV5_ROS_MSGS"))
    (make-package "YOLOV5_ROS_MSGS"))
  (shadow 'arr_rank (find-package "YOLOV5_ROS_MSGS")))
(unless (find-package "YOLOV5_ROS_MSGS::ARR_RANK")
  (make-package "YOLOV5_ROS_MSGS::ARR_RANK"))

(in-package "ROS")
;;//! \htmlinclude arr_rank.msg.html


(defclass yolov5_ros_msgs::arr_rank
  :super ros::object
  :slots (_arrs _rank ))

(defmethod yolov5_ros_msgs::arr_rank
  (:init
   (&key
    ((:arrs __arrs) ())
    ((:rank __rank) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _arrs __arrs)
   (setq _rank __rank)
   self)
  (:arrs
   (&rest __arrs)
   (if (keywordp (car __arrs))
       (send* _arrs __arrs)
     (progn
       (if __arrs (setq _arrs (car __arrs)))
       _arrs)))
  (:rank
   (&optional __rank)
   (if __rank (setq _rank __rank)) _rank)
  (:serialization-length
   ()
   (+
    ;; yolov5_ros_msgs/arr[] _arrs
    (apply #'+ (send-all _arrs :serialization-length)) 4
    ;; int32[] _rank
    (* 4    (length _rank)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; yolov5_ros_msgs/arr[] _arrs
     (write-long (length _arrs) s)
     (dolist (elem _arrs)
       (send elem :serialize s)
       )
     ;; int32[] _rank
     (write-long (length _rank) s)
     (dotimes (i (length _rank))
       (write-long (elt _rank i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; yolov5_ros_msgs/arr[] _arrs
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _arrs (let (r) (dotimes (i n) (push (instance yolov5_ros_msgs::arr :init) r)) r))
     (dolist (elem- _arrs)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; int32[] _rank
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _rank (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _rank i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get yolov5_ros_msgs::arr_rank :md5sum-) "fda0ba7f4327a4a5573e422b6bef24b9")
(setf (get yolov5_ros_msgs::arr_rank :datatype-) "yolov5_ros_msgs/arr_rank")
(setf (get yolov5_ros_msgs::arr_rank :definition-)
      "arr[] arrs
int32[] rank
================================================================================
MSG: yolov5_ros_msgs/arr
int32[] arr
")



(provide :yolov5_ros_msgs/arr_rank "fda0ba7f4327a4a5573e422b6bef24b9")


