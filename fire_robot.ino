#include <AFMotor.h>
#include <Servo.h>
Servo myservo;
int pos = 65;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup()
{
  Serial.begin(9600);
  myservo.attach(10);
  myservo.write(90); //Set initial speed of the motor & stop
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);
}

void loop()
{
  // digitalWrite (2, LOW);
  // digitalWrite (2, HIGH);
  // delay(1000);
  // delay(1000);
  int sensorReading = analogRead (A0);
  int sensorReading2 = analogRead (A1);
  // Map sensor value between range 0-3
  int range = map (sensorReading, 0, 1024, 0, 3);

  if (range == 0) {
    Center();
    Serial.print("0");
  }
  if (range == 1 ) {
    Serial.print("1");
    Center();
  }
  if (range == 2 ) {
    Serial.print("2");
  }
  int range2 = map (sensorReading2, 0, 1024, 0, 3);
  if (range2 == 0) {
    Center();
    Serial.print("0");
  }
  if (range2 == 1 ) {
    Serial.print("1"); Center();
  }
  if (range2 == 2 ) {

    Serial.print("2");
  }
}
void Center() {
  // digitalWrite (2, LOW);
  motor1.run(FORWARD);
  motor1.setSpeed(200);
  motor3.run(FORWARD);
  motor3.setSpeed(200);
  delay(1000);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor2.setSpeed(200);
  for (pos = 50; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 130; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 50; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 130; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  delay(200);
   myservo.write(90); 
  motor2.run(RELEASE);
}

void Right() {

  motor2.run(FORWARD);
  motor2.setSpeed(200); // digitalWrite (2, LOW);
  motor3.run(FORWARD);
  motor3.setSpeed(120);
  motor4.run(FORWARD);
  motor4.setSpeed(120);
  delay(700);
  motor4.setSpeed(200);
  motor4.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  for (pos = 60; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 120; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    myservo.write(90);  
  motor4.setSpeed(200);
  motor4.run(RELEASE);
  delay(1500);
}

void Left() {

  motor2.run(FORWARD);
  motor2.setSpeed(200); // digitalWrite (2, LOW);
  motor3.run(FORWARD);
  motor3.setSpeed(120);
  motor4.run(FORWARD);
  motor4.setSpeed(120);
  delay(700);
  motor4.setSpeed(200);
  motor4.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  for (pos = 60; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'11:47 AM
delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 120; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  delay(2000);
}

void centerservo() {
  for (pos = 65; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 150; pos >= 65; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
  for (pos = 65; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 150; pos >= 65; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }

}
