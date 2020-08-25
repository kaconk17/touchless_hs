#include <Arduino.h>
#include <Servo.h>

int echopin = 13;
int trigpin = 12;
int servopin = 11;
int ledpin = 4;
int duration;
float d_cm;

int awal = 0;
int press = 100;
Servo myServo;

void setup() {
 
  
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin,INPUT);
  myServo.attach(servopin);
  myServo.write(awal);
  digitalWrite(ledpin,LOW);
}

void loop() {
  
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin,LOW);

 duration = pulseIn(echopin, HIGH);
 d_cm = duration * 0.034/2.;
 if (d_cm >= 11 & d_cm<=14)
 {
   digitalWrite(ledpin,HIGH);
  for (int i = 0; i <= press; i+=10)
  {
    myServo.write(i);
    delay(15);
  }
  delay(400);
  myServo.write(awal);
  digitalWrite(ledpin,LOW);
  delay(1000);
  
 }
 Serial.print("Jarak: ");
 Serial.print(d_cm);
 Serial.print("cm");
 Serial.println();
}