// Based on Sweep Example
// This example code is in the public domain.

#include <Servo.h> 
 
Servo leftwheel;  // create servo object to control a servo on a wheel
Servo rightwheel; // create another servo object to control the other wheel

int threshold 400;

void setup() 
{ 
  //assuming these are continuous rotation servos
  leftwheel.attach(9);  // attaches the servo on pin 9 to the servo object 
  rightwheel.attach(10);  // attaches the servo on pin 10 to the servo object 
  //setup serial communicstoin for debugging and testing threshold
  Serial.begin(9600);
  
  //setup random number generator - yes this could easily be improved!
  randomSeed(analogRead(A0));
} 
 
 
void loop() 
{        
    //read data from sensor connected to A0 and print to serial monitor
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // print out the value you read:
    Serial.println(sensorValue);
    delay(1);        // delay in between reads for stability
    
    //if sensor detects something 
    if (sensorValue > threshold) {
        Serial.println('Object detected: Turning');
        //pick two random numbers
        int randomNumber1 = random(0,3);
        int randomNumber2 = random(1,10);
        
        if (randomNumber1 > 1) {
          //turn slowly left for a random length of time 
          turn_left(randomNumber2*100);   
          }
        else {
          //turn slowly right for a random length of time
          turn_right(randomNumber2*100); 
        }
      } 
    else { //otherwise drive forward
      drive_forward(500, 5);
    }
    //
    stop();
} 

void drive_forward(int drivetime, int speed)
{
    //the speed parameter should be between 1 and 10
    leftwheel.write(90-speed);              // tell servo to turn slowly in opposite directions
    rightwheel.write(90+speed);             // this should make the robot drive roughly straight ahead
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
