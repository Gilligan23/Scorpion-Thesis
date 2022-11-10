#!/usr/bin/env python
from cgi import test
import rospy as rp 
from std_msgs.msg import Int8
import tkinter as tk

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title('Button')

        self.button_frame = tk.Frame(self)
        self.button_frame.pack(side=tk.TOP)

        self.button = tk.Button(self.button_frame, text="tester", command=talker)
        self.button.pack(side=tk.TOP)

        self.led_state = 0

def talker():
    pub = rp.Publisher('chatter', Int8, queue_size=10)
    rp.init_node('talker', anonymous=True)
    rate = rp.Rate(1) # 10hz
    while not rp.is_shutdown():
        
        hello_str = 4
        rp.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
  
if __name__ == '__main__':
    
    try:
        app = App()
        app.mainloop()
    except rp.ROSInterruptException:
        pass            