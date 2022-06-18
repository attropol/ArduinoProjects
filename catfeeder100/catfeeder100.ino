#include <Servo.h>
int buzzerPin = 3;
unsigned long startMillis;
unsigned long currentMillis;
unsigned const long period = 7000;
#define servoPin 2
#define buttonPin 4

Servo myservo;

void setup() {
  myservo.attach(servoPin);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  myservo.write(180);
  delay(1000);
  myservo.detach();
  startMillis = millis();  //initial start time

}
void loop() {
  currentMillis = millis();
  int buttonVal = digitalRead(buttonPin);
  if (currentMillis - startMillis <= period) {
    if (buttonVal == LOW) {
      myservo.attach(servoPin);
      myservo.write(120);
      delay(1111);
      myservo.write(0);
      delay(575);
      myservo.detach();
      delay(5000);
    }
  }
  else if (currentMillis - startMillis >= period) {
    
  tone(buzzerPin, 500);
  delay(100);
  noTone(buzzerPin);
    delay(2000);
    myservo.attach(servoPin);
    myservo.write(0);
    delay(1000);
    myservo.write(180);
    delay(575);
    myservo.detach();
    delay(575);
    startMillis = currentMillis;
  }
}
