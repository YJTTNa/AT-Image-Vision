'''
    用来解决代码重启问题
    利用时间间隔
    解决时间问题
'''
from datetime import datetime  
current_datetime = datetime.now()    
current_time = current_datetime.time()  
print("当前时间:", current_time)

