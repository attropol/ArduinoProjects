#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup()
{
  Serial.begin(9600);//set up Serial library at 9600 bps
  Serial.println("Motor test!");
  MotorSpeed(255);
}

void loop() {
   /* digitalWrite(trigPin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration / 29.1 / 2;

    if (distance < 15){
    AllBackward();
    delay(500);
    TurnRight();
    delay(500);
    }
    else 
    {
      AllForward();
    }*/
    AllForward();
    delay(5000);
}

void MotorSpeed(int Speed)
{
  motor3.setSpeed(Speed);     // set the speed to 200 (255 max)
  motor4.setSpeed(Speed);
}

void AllForward()
{
  Serial.print("forward");
  motor3.run(FORWARD);      // SOL ÖN
  motor4.run(BACKWARD);  // SOL ARKA
}

void AllBackward()
{
  Serial.print("backward");
  motor1.run(BACKWARD);      // turn it on going forward
  motor2.run(FORWARD);
}

void AllStop()
{
  Serial.print("stop");
  motor1.run(RELEASE);      // turn it on going forward
  motor2.run(RELEASE);
}
void TurnLeft() {
  Serial.print("LEFT");
  motor1.run(BACKWARD);      // SOL ÖN
  motor2.run(FORWARD);  // SOL ARKA

}
void TurnRight() {
  motor1.run(FORWARD);      // SOL ÖN
  motor2.run(BACKWARD);  // SOL ARKA
}
