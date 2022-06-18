#include <Servo.h>

unsigned long startMillis;
unsigned long currentMillis;
const long period = 14400000; 

#define servoPin 3
#define buttonPin 12

Servo myservo;

void setup() {
  myservo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  myservo.write(0);
  delay(1000);
  myservo.detach();
  startMillis = millis();  //initial start time

}

void loop() {
  int buttonVal = digitalRead(buttonPin);
  currentMillis = millis();
  if (currentMillis - startMillis <= period){
   if(buttonVal == LOW) {
    myservo.attach(servoPin);
    myservo.write(120);
    delay(575);
    myservo.write(0);
    delay(5000);
    myservo.detach();
   }
   else if (currentMillis - startMillis == period){
    currentMillis = millis();
    myservo.attach(servoPin);
    myservo.write(240);
    delay(575);
    myservo.write(0);
    delay(1500);
    myservo.detach();
    startMillis = currentMillis; 
   
   }
    }
  }
