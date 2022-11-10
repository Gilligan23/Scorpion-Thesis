#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def node1():
    pub = rospy.Publisher('topic1', String, queue_size=10)
    rospy.init_node('node1')
    rate = rospy.Rate(10) #10 Hz
    while not rospy.is_shutdown():
        hello_str = "hello world"
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__=='__main__':
    try: 
        node1()
    except rospy.ROSInterruptException:
        pass