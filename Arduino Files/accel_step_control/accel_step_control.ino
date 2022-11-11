#include <ros.h>
#include <std_msgs/Float64.h>
#include <AccelStepper.h>

const int dirPin = 5; 
const int stepPin = 2;
const int dirPin2 = 6;
const int stepPin2 = 3;
const int motorType = 1;
const int motorSteps = 200;

AccelStepper stepper = AccelStepper(motorType, stepPin, dirPin);
AccelStepper stepper2 = AccelStepper(motorType, stepPin2, dirPin2);
ros::NodeHandle nh;

void cycJointMotor1(const std_msgs::Float64 &value){
  const double positionSteps = (value.data/(2.0*3.1415926)) * (double)motorSteps;
  stepper.moveTo((double)25*positionSteps);
  stepper.runToPosition();
  delay(1000);
}

void cycJointMotor2(const std_msgs::Float64 &value){
  const double positionSteps = (value.data/(2.0*3.1415926)) * (double)motorSteps;
  stepper2.moveTo(-(double)25*positionSteps);
  stepper2.runToPosition();
  delay(1000);
}

ros::Subscriber<std_msgs::Float64> motor1("/assembly/Rev3_position_controller/command", &cycJointMotor1);
ros::Subscriber<std_msgs::Float64> motor2("/assembly/Rev4_position_controller/command", &cycJointMotor2);

void setup(){
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(1000);
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(1000);

  nh.initNode();
  nh.subscribe(motor1);
  nh.subscribe(motor2);
  
}

void loop(){
  nh.spinOnce();
  delay(1);
}
