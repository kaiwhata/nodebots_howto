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
  
  //setup serial communication for debugging and testing threshold
  Serial.begin(9600);

} 
 
 
void loop() 
{        
    //read data from serial connection
    if (Serial.available() > 0) {
      char inChar = Serial.read();

      // print out the value you read:
      Serial.println(inChar);
      delay(1);        // delay in between reads for stability
    
      //if serial input is something
      switch (inChar) {   
            case 'u':
              // move robot forward
              drive_forward(500, 5);
              break; 
            case 'd':
              // move robot backward
              drive_backward(500, 5);
              break;
            case 'l':
              // move mouse left
              turn_left(500);
              break;
            case 'r':
              // move mouse right
              turn_right(500);
              break;
            }
    stop();
} 

void drive_forward(int drivetime, int speed)
{
    //the speed parameter should be between 1 and 10
    leftwheel.write(90-speed);              // tell servo to turn slowly in opposite directions
    rightwheel.write(90+speed);             // this should make the robot drive roughly straight ahead
    delay(drivetime);
}

void drive_backward(int drivetime, int speed)
{
    //the speed parameter should be between 1 and 10
    leftwheel.write(90+speed);              // tell servo to turn slowly in opposite directions
    rightwheel.write(90-speed);             // this should make the robot drive roughly straight backward
    delay(drivetime);
}

void stop()
{
    leftwheel.write(90);              // stop left motor
    rightwheel.write(90);             // stop right motor
    delay(100);
}

void turn_left(int turntime)
{
    leftwheel.write(90);              // stops left wheel
    rightwheel.write(95);             // drives right wheel (this should make the robot drive roughly turn left)
    delay(turntime);
}

void turn_right(int turntime)
{
    leftwheel.write(95);              // drives left wheel
    rightwheel.write(90);             // stops right wheel (this should make the robot drive roughly turn right)
    delay(turntime);
}
