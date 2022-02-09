#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quiteKnock = 30;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  Serial.begin(9600);

  digitalWrite(greenLed, HIGH);
  myServo.write(0);

  Serial.println("The box is unlocked");
}

void loop() {
  if (!locked) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked");
      delay(100);
    }
  }

  if (locked) {
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal)) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    if (numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked");
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnock(int value) {
  if (value > quiteKnock && value < loudKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(100);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value: ");
    Serial.println(value);
    return true;
  }

  Serial.print("Bad knock value: ");
  Serial.println(value);
  return false;
}
