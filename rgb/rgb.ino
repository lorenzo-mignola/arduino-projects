const int redLED = 9;
const int greenLED = 10;
const int blueLED = 11;

const int redSensor = A0;
const int greenSensor = A1;
const int blueSensor = A2;

int red = 0;
int green = 0;
int blue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensor);
  delay(5);
  greenSensorValue = analogRead(greenSensor);
  delay(5);
  blueSensorValue = analogRead(blueSensor);
  delay(5);

  red = redSensorValue / 4;
  green = greenSensorValue / 4;
  blue = blueSensorValue / 4;

  Serial.println("LED");
  Serial.println("-------");
  Serial.print("red: ");
  Serial.print(red);
  Serial.print("\tgreen: ");
  Serial.print(green);
  Serial.print("\tblue: ");
  Serial.print(blue);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();

  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
}