int notes[] = {262, 294, 330, 349};

void setup() { Serial.begin(9600); }

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  if (keyVal == 1023) {
    tone(8, notes[0]);
    return;
  }

  if (keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[1]);
    return;
  }

  if (keyVal >= 505 && keyVal <= 515) {
    tone(8, notes[2]);
    return;
  }

  if (keyVal >= 5 && keyVal <= 11) {
    tone(8, notes[3]);
    return;
  }

  noTone(8);
}