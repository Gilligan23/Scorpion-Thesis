#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from std_msgs.msg import Empty
from std_msgs.msg import Int64
from sensor_msgs.msg import JointState
from math import degrees

def talker():
    motor = rospy.Publisher('toggle_led', Empty, queue_size=10)
    test = rospy.Publisher('steps', Int64, queue_size=10)
    
    
    rospy.init_node('motor_data', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        joints = rospy.Subscriber('joint_states', JointState, joint_states_move)
        #num = int(joint_array[0])
        #num = angle_to_steps()
        #motor.publish()
        #test.publish(num)
        rate.sleep()

def angle_to_steps():
    degrees = int(input("Please Input an Angle (degrees):"))
    step_interval = 200
    steps = int(degrees / 360 * step_interval)
    return steps

def joint_states_move(msg):
    #print(msg)
    position = msg.position
    print(position)
    #angle_joint_array = [] 
    #for joint_val in msg.data.position:
    #    val2degrees = degrees(joint_val)
    #    angle_joint_array.append(val2degrees)
    #
    return position



if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass