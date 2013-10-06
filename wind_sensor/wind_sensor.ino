// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.
#include <Servo.h> 
// named constants for the switch and motor pins
const int servoPin =  9; // the number of the motor pin
const int motorPin = 10;
const int led = 13;
const int windSensor = 1;
int val;


Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  pinMode(led, OUTPUT);
  pinMode(motorPin,   OUTPUT);
  pinMode(windSensor, INPUT);
  Serial.begin(9600);
} 
 
 
void loop()
{ 
  
  val = analogRead(windSensor);
  val = map(val, 0, 1023, 0, 179);
  Serial.println(val);
  if(val < 60) {
    digitalWrite(motorPin, HIGH); 
  }
  myservo.write(val);
  delay(500);
//  for(pos = 0; pos < 180; pos +=1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(30);
//
//  } 
//  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'  
//    delay(30);
//  } 

  //digitalWrite(led, HIGH);
  //digitalWrite(motorPin, HIGH); 
  //delay(1000);
  //digitalWrite(motorPin, LOW);
} 
