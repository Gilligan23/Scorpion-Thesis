/* 
 * rosserial Subscriber 
 * Actuates stepper motor
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Float64.h>

const int stepPin = 2; // X.STEP
const int dirPin = 5; // X.DIR
const int stepPinY = 3; // Y.STEP
const int dirPinY = 6; // Y.DIR
const int stepPinJ2 = 4; // Joint 2 step pin
const int dirPinJ2 = 7; // Joint 2 direction pin

const int motorSteps = 200; // Amount of motor steps

ros::NodeHandle  nh;

void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(500); 
  }
  delay(1000); // One second delay
}

void motorCb( const std_msgs::Int64& toggle_msg){
  
  if (toggle_msg.data < 0) {
    digitalWrite(dirPin, LOW);
    for(int x = 0; x < abs(toggle_msg.data); x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  
  } else {
    digitalWrite(dirPin, HIGH);
    for(int x = 0; x < abs(toggle_msg.data); x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
    // digitalWrite(stepPinY, HIGH);
    // delayMicroseconds(500);
    // digitalWrite(stepPinY,LOW); 
    // delayMicroseconds(500);
  }
  
  }
}

void motorCb2(  const std_msgs:: Int64& toggle_msg){
if (toggle_msg.data < 0) {
    digitalWrite(dirPinY, LOW);
    for(int x = 0; x < abs(toggle_msg.data); x++) {
    digitalWrite(stepPinY,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinY,LOW); 
    delayMicroseconds(500); 
  }
  
  } else {
    digitalWrite(dirPinY, HIGH);
    for(int x = 0; x < abs(toggle_msg.data); x++) {
    digitalWrite(stepPinY,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinY,LOW); 
    delayMicroseconds(500); 
  }
}
}

void motorCb3(  const std_msgs:: Int64& toggle_msg){
if (toggle_msg.data < 0) {
    digitalWrite(dirPinJ2, LOW);
    for(int x = 0; x < abs(toggle_msg.data); x++) {
    digitalWrite(stepPinJ2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinJ2,LOW); 
    delayMicroseconds(500); 
  }
  
  } else {
    digitalWrite(dirPinJ2, HIGH);
    for(int x = 0; x < abs(toggle_msg.data); x++) {
    digitalWrite(stepPinJ2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinJ2,LOW); 
    delayMicroseconds(500); 
  }
}
}

// ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );
ros::Subscriber<std_msgs::Int64> motor1("steps", &motorCb);
ros::Subscriber<std_msgs::Int64> motor2("steps2", &motorCb2);
ros::Subscriber<std_msgs::Int64> motor3("steps3", &motorCb3);

void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(stepPinY,OUTPUT);
  pinMode(dirPinY, OUTPUT);
  nh.initNode();
  nh.subscribe(motor1);
  nh.subscribe(motor2);
  nh.subscribe(motor3);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
