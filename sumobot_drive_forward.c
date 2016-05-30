// Based on Sweep Example
// This example code is in the public domain.


#include <Servo.h> 
 
Servo leftwheel;  // create servo object to control a servo on a wheel
Servo rightwheel; // create another servo object to control the other wheel


void setup() 
{ 
  //assuming these are continuous rotation servos
  leftwheel.attach(9);  // attaches the servo on pin 9 to the servo object 
  rightwheel.attach(10);  // attaches the servo on pin 10 to the servo object 
} 
 
 
void loop() 
{        
    //for continuous rotation servos a number above 90 means turn in one direction 
    // and a number below 90 measn turn in the opposite direction.
    // the further away from 90 the number is the faster the servo rotation
    
    leftwheel.write(85);              // tell servo to turn slowly in opposite directions
    rightwheel.write(95);             // this should make the robot drive roughly straight ahead
    delay(500);
    
    //drive_forward(500, 5);          //this uses the method below to achieve the same effect as the 3 lines of code above
    
    leftwheel.write(90);              // tell both servos to stop 
    rightwheel.write(90);  
    delay(500);
    leftwheel.write(95);              // tell servo to turn slowly in opposite directions 
    rightwheel.write(85);             // this should make the robot drive roughly straight in reverse
    delay(500);
    leftwheel.write(90);              // tell both servos to stop 
    rightwheel.write(90);  
    delay(500);
    
    
} 

void drive_forward(int drivetime, int speed)
{
    //the speed parameter should be between 1 and 10
    leftwheel.write(90-speed);              // tell servo to turn slowly in opposite directions
    rightwheel.write(90+speed);             // this should make the robot drive roughly straight ahead
    delay(drivetime);
}
