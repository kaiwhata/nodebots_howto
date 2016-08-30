/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
 to Arduino pin 11
 to Arduino pin 10
*/

#include <Servo.h> 

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

const int threshold = 10; //cm - sets how far robot responds

Servo leftwheel;  // create servo object to control a servo on a wheel
Servo rightwheel; // create another servo object to control the other wheel


void setup() {
  //setup serial communicstoin for debugging and testing threshold
  Serial.begin (9600);
  //setup ultrasouns sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //assuming these are continuous rotation servos
  leftwheel.attach(9);  // attaches the servo on pin 9 to the servo object 
  rightwheel.attach(10);  // attaches the servo on pin 10 to the servo object 
  //setup random number generator - yes this could easily be improved!
  randomSeed(analogRead(A0));
  //randomSeed(2023);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // 
  delayMicroseconds(2); // 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration/2) / 29.1; //converts from 10 bit binary to cm
  
  //controller logic
  if (distance < threshold) { 
        int randomNumber = random(1,10);
        Serial.print("Object detected: Turning ");
        Serial.println(randomNumber*100);
        turn_left(randomNumber*100);  //turns left for a random length of time
        //turn randomly left or right?
  }else{
    Serial.println("Nothing Detected: Driving Forward");
    //drive forward for one second
    drive_forward(1000, 15); //(time, speed)
  }
  /* this code is not necessary for robot exploring
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  */
  Serial.print(distance);
  Serial.println(" cm");
  delay(500); // time between sensor checks
}

//method for controlling robot movement
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
    leftwheel.write(80);              // stops left wheel
    rightwheel.write(115);             // drives right wheel (this should make the robot drive roughly turn left)
    delay(turntime);
}

void turn_right(int turntime)
{
    leftwheel.write(115);              // drives left wheel
    rightwheel.write(80);             // stops right wheel (this should make the robot drive roughly turn right)
    delay(turntime);
}
