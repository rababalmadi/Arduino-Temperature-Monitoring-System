#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// Create LCD object using I2C
Adafruit_LiquidCrystal lcd(0);

// ===== Pin Definitions =====
int TempPin = A0;   // Temperature sensor connected to analog pin A0

// ===== Variables =====
int RawValue;       // Raw analog reading from the sensor
float Voltage;      // Converted voltage value
float Temp;         // Calculated temperature in Celsius

void setup()
{
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  // Set cursor to the first row
  lcd.setCursor(0,0);
}

void loop()
{
  // Read analog value from the temperature sensor
  RawValue = analogRead(TempPin);

  // Convert analog reading to voltage
  Voltage = RawValue * (5.0 / 1023.0);

  // Convert voltage to temperature (TMP36 formula)
  Temp = (Voltage - 0.5) * 100;

  // Display temperature on LCD
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(Temp);
  lcd.print(" C");
}
