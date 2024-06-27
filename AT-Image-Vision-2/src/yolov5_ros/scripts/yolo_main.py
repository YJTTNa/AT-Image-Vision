#!/usr/bin/env python
# -*- coding: utf-8 -*-


'''
    代码用来记录比赛时的图像
'''
import cv2
import torch
import rospy
import numpy as np

from std_msgs.msg import Header
from sensor_msgs.msg import Image
from yolov5_ros_msgs.msg import BoundingBox, BoundingBoxes

Num1 = 0
class Yolo_Dect:
    def __init__(self):

        yolov5_path = rospy.get_param('/yolov5_path', '')
        weight_path = rospy.get_param('~weight_path', '')
        conf = rospy.get_param('~conf', '0.5')
        iou = rospy.get_param('~iou', '0.35')
        self.model = torch.hub.load(yolov5_path, 'custom', path=weight_path, source='local')
        if (rospy.get_param('/use_cpu', 'false')):
            self.model.cpu()
        else:
            self.model.cuda()
        self.model.conf = conf
        self.model.iou = iou
        image_topic = rospy.get_param('~image_topic', '/usb_cam/image_raw')
        pub_topic = rospy.get_param('~pub_topic', 'BoundingBoxes')
        self.color_image = Image()
        self.getImageStatus = False
        self.classes_colors = {}
        self.color_sub = rospy.Subscriber(image_topic, Image, self.image_callback, queue_size=1, buff_size=52428800)  
        self.position_pub = rospy.Publisher(pub_topic,  BoundingBoxes, queue_size=2)
        while (not self.getImageStatus):
            rospy.loginfo("waiting for image.")
            rospy.sleep(2)
    def image_callback(self, image):
        self.boundingBoxes = BoundingBoxes()
        self.boundingBoxes.header = image.header
        self.boundingBoxes.image_header = image.header
        self.getImageStatus = True
        self.color_image = np.frombuffer(image.data, dtype=np.uint8).reshape(image.height, image.width, -1) 
        self.color_image = cv2.cvtColor(self.color_image, cv2.COLOR_BGR2RGB)
        results = self.model(self.color_image)
        boxs = results.pandas().xyxy[0].values
        '''
            这里增加保存图像的代码
        '''
        global Num1
        Num1+=1
        if Num1 % 5 == 0:
            Num1 = 0
            # cv2.imread("", )
        self.dectshow(self.color_image, boxs)
        cv2.waitKey(3)
    def dectshow(self, img, boxs):
        count = 0
        basket = 0
        for box in boxs: 
            boundingBox = BoundingBox()
            boundingBox.probability =np.float64(box[4])
            boundingBox.xmin = np.int64(box[0])
            boundingBox.ymin = np.int64(box[1])
            boundingBox.xmax = np.int64(box[2])
            boundingBox.ymax = np.int64(box[3])
            boundingBox.Class = box[-1]
            if box[-1] in self.classes_colors.keys():
                color = self.classes_colors[box[-1]]
            else:
                color = np.random.randint(0, 183, 3)
                self.classes_colors[box[-1]] = color

            cv2.rectangle(img, (int(box[0]), int(box[1])),
                        (int(box[2]), int(box[3])), (int(color[0]),int(color[1]), int(color[2])), 2)
            if box[1] < 20:
                text_pos_y = box[1] + 30
            else:
                text_pos_y = box[1] - 10

            if box[-1] == 'basket' or ( box[-1] != 'basket' and 1.2 * (np.int64(box[2]) - np.int64(box[0])) > (np.int64(box[3]) - np.int64(box[1])) ):
                count += 1
                if box[-1] == 'basket':
                    basket += 1
                cv2.putText(img, box[-1],
                            (int(box[0]), int(text_pos_y)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2, cv2.LINE_AA)
                boundingBox.num = np.int16(count)
                self.boundingBoxes.bounding_boxes.append(boundingBox)
        self.position_pub.publish(self.boundingBoxes)
        cv2.line(img, (320, 1), (320, 450), (0, 0, 0), 2)
        cv2.imshow('YOLOv5', img)

def main():
    rospy.init_node('yolov5_ros_py', anonymous=True)
    yolo_dect = Yolo_Dect()
    rospy.spin()


if __name__ == "__main__":

    main()
