#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int moistureSensorPin = A1;

int moistureSensorPinValue = 0;
int humidityPercentage = 0;

char moistureSensorPinValueMessage[20]; 
char humidityPercentageMessage[20]; 

const int dry = 614;
const int wet = 294;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  moistureSensorPinValue = analogRead(moistureSensorPin);
  sprintf(moistureSensorPinValueMessage, "Value: %d%", moistureSensorPinValue);

  humidityPercentage = map(moistureSensorPinValue, wet, dry, 100, 0);
  sprintf(humidityPercentageMessage, "Humidity: %d%%", humidityPercentage);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(moistureSensorPinValueMessage);

  lcd.setCursor(0, 1);
  lcd.print(humidityPercentageMessage);

  delay(500);
}
