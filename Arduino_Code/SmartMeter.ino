#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
int potPin = A0;
int button1 = 2;
int button2 = 3;
int button3 = 4;

int greenLED = 5;
int redLED = 6;
int buzzer = 8;
int pir = 9;
int relay = 11;

// Variables
int value = 0;
int prevValue = 0;
int threshold = 50;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(relay, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("SMART METER");
  delay(2000);
  lcd.clear();
}

void loop() {

  value = analogRead(potPin);

  // Simulate usage
  if (digitalRead(button1) == LOW) value += 20;
  if (digitalRead(button2) == LOW) value += 30;
  if (digitalRead(button3) == LOW) value += 40;

  int change = abs(value - prevValue);

  lcd.setCursor(0,0);
  lcd.print("Units:");
  lcd.print(value);
  lcd.print("   ");

  // -------- NORMAL --------
  if (change < threshold && digitalRead(pir) == LOW) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, HIGH);

    lcd.setCursor(0,1);
    lcd.print("Status: NORMAL   ");

    Serial.println("NORMAL");
  }

  // -------- INTRUSION (PIR) --------
  else if (digitalRead(pir) == HIGH) {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, LOW);

    lcd.setCursor(0,1);
    lcd.print("INTRUSION ALERT ");

    Serial.println("INTRUSION DETECTED");
  }

  // -------- ANOMALY --------
  else {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, LOW);

    lcd.setCursor(0,1);
    lcd.print("ANOMALY DETECTED");

    Serial.println("ANOMALY DETECTED");
  }

  prevValue = value;

  delay(500);
}
