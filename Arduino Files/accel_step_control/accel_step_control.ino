#include <ros.h>
#include <std_msgs/Float64.h>
#include <AccelStepper.h>

const int dirPin = 5; 
const int stepPin = 2;
const int motorType = 1;
const int motorSteps = 200;

AccelStepper stepper = AccelStepper(motorType, stepPin, dirPin);
ros::NodeHandle nh;

void stepMotor1(const std_msgs::Float64 &value){
  const double positionSteps = (value.data/(2.0*3.1415926)) * (double)motorSteps;
  stepper.moveTo(positionSteps);
  stepper.runToPosition();
  delay(1000);
}

ros::Subscriber<std_msgs::Float64> motor1("/assembly/Rev1_position_controller/command", &stepMotor1);

void setup(){
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(1000);

  nh.initNode();
  nh.subscribe(motor1);
  
}

void loop(){
  nh.spinOnce();
  delay(1);
}
