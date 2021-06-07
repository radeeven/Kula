#include <Servo.h>

Servo myServo;

int led2 = 7;
int led3 = 0;
int led4 = 1;
int led5 = 2;
int led6 = 3;
int led7 = 4;
int led8 = 5;
int led9 = 6;
int led10 = 11;
int led11 = 12;

// definer pins og setter lysene av
void setup() {
  myServo.attach(13);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
}

// loop setter lysene av og på med 100ms mellomrom
void loop() {
  myServo.write(180); // motor heiser flagget opp
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(100);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  delay(100);
  digitalWrite(led6, LOW);
  digitalWrite(led7, HIGH);
  delay(100);
  digitalWrite(led7, LOW);
  digitalWrite(led8, HIGH);
  delay(100);
  digitalWrite(led8, LOW);
  digitalWrite(led9, HIGH);
  delay(100);
  digitalWrite(led9, LOW);
  digitalWrite(led10, HIGH);
  delay(100);
  digitalWrite(led10, LOW);
  digitalWrite(led11, HIGH);
  delay(100);
  digitalWrite(led11, LOW);
  
} 
