#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchState, INPUT);
  lcd.print("Chiedi");
  lcd.setCursor(0, 1);
  lcd.print("COSE");
}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(3);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("La cosa è");
      lcd.setCursor(0, 1);
      switch (reply) {
        case 0:
          lcd.print("OK");
          break;
        case 1:
          lcd.print("Bella");
          break;
        case 2:
          lcd.print("bho");
          break;
      }
    }
  }
  prevSwitchState = switchState;
}