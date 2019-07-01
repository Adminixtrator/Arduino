#include <Servo.h>
#include <SoftwareSerial.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 180; i += 20){
    myServo.write(i);
    delay(1000);
  }
  
}
