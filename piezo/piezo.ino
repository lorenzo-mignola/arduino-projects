int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    int value = analogRead(A0);
    if (value > sensorHigh) {
      sensorHigh = value;
    }
    if (value < sensorLow) {
      sensorLow = value;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  int sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  tone(8, pitch, 20);
  delay(100);
}