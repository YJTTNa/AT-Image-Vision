
(cl:in-package :asdf)

(defsystem "yolov5_ros_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "BoundingBox" :depends-on ("_package_BoundingBox"))
    (:file "_package_BoundingBox" :depends-on ("_package"))
    (:file "BoundingBoxes" :depends-on ("_package_BoundingBoxes"))
    (:file "_package_BoundingBoxes" :depends-on ("_package"))
    (:file "X_Y_ARG" :depends-on ("_package_X_Y_ARG"))
    (:file "_package_X_Y_ARG" :depends-on ("_package"))
    (:file "arr" :depends-on ("_package_arr"))
    (:file "_package_arr" :depends-on ("_package"))
    (:file "arr_rank" :depends-on ("_package_arr_rank"))
    (:file "_package_arr_rank" :depends-on ("_package"))
    (:file "port_serial" :depends-on ("_package_port_serial"))
    (:file "_package_port_serial" :depends-on ("_package"))
  ))