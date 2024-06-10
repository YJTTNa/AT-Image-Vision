#! /bin/bash

###### 说明
#* 此shell为检测程序进程
#* 若没有此进程
#* 尝试重启
#* 如果多次重启失败 则reboot

###### 变量 
Project=""
sec=2
cnt=0

while [1]

do 
    line_count=`ps -ef | grep "" | grep -v "grep" | wc -l`
    if [ $line_count -ge 1]; then
        echo "My $Project is alive"
        sleep $sec
    else 
        echo "This is $cnt small reboot"
        ((cnt=cnt+1))
        gnome-terminal --tab "yolo_v5" -- ."/"

        echo "Tring restrat small reboot !!!"

        sleep $sec
        if [ $cnt -ge 10]; then
        echo "1s big_Reboot"
        # reboot
        fi
    fi
    
done
