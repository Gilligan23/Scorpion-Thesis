#!/usr/bin/env python
# license removed for brevity

from os import wait
import rospy
from sensor_msgs.msg import JointState
from std_msgs.msg import Int64
import threading
import math 


class JointStateListener:
    
    def __init__(self): 
        rospy.init_node('motor_controller')
        self.name = []
        self.position = []
        self.last_position = self.position
        self.velocity = []
        self.effort = []
        self.motor_steps = 200
        self.thread = threading.Thread(target=self.joint_states_listener)
        self.thread.start()
        self.thread2 = threading.Thread(target=self.joint_states_talker)
        self.thread2.start()

    def joint_states_listener(self):
        rospy.Subscriber('joint_states', JointState, self.joint_states_callback)
        rospy.spin()

    def joint_states_talker(self):
        self.motor = rospy.Publisher('steps', Int64, queue_size=10)
        rate = rospy.Rate(10) # 10hz    

        while not rospy.is_shutdown():
            #num = int(joint_array[0])
            #num = angle_to_steps()
            #motor.publish()
            #test.publish(num)
            rate.sleep()

    def joint_states_callback(self, msg):
        self.position = msg.position
        steps = self.rad2steps(float(self.position[0]))
        if (self.position != self.last_position):
            self.motor.publish(steps)
            self.last_position = self.position
        
    def rad2steps(self, jointrad):
        jointsteps = int(jointrad / 2*math.pi * self.motor_steps)
        return jointsteps

#run the server
if __name__ == "__main__":
    latestjointstates = JointStateListener()

    try:
        latestjointstates.joint_states_talker()
    except rospy.ROSInterruptException:
        pass



    

    
    
