#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 10000.0; // resistance of R1 (100K) -see text!
float R2 = 2200.0; // resistance of R2 (2.2K) - see text!
int value = 0;
int mode = 0;
int interval = 300;
// Tracks the time since last event fired
unsigned long previousMillis = 0;
int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R11 = 1000;
float R22 = 0;
float buffer = 0;
void setup() {
  Serial.begin(9600);
  pinMode(analogInput, INPUT);
  pinMode(9, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  digitalWrite(9, HIGH);
  delay(40);
  digitalWrite(9, LOW);
  pinMode(13, OUTPUT);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}
void update_display(String val)
{
}
void loop()
{
  unsigned long currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    if (mode == 0)
    {
      value = analogRead(A0);
      vout = (value * 5.0) / 1024.0; // see text
      vin = vout / (R2 / (R1 + R2));
      if (vin < 0.09) {
        vin = 0.0; //statement to quash undesired reading !
      }
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Voltmeter Mode");
      display.setTextSize(2);
      display.setCursor(10, 12);
      display.print((vin));
      display.print("V");
      display.display();
    }
    if (mode == 1)
    {
      value = analogRead(A2);
      vout = (value * 5.0) / 1024.0; // see text
      vout = 5 - vout;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Diode/LED Test");
      display.setTextSize(2);
      display.setCursor(10, 12);
      display.print((vout));
      display.print(" V");
      display.display();
    }
    if (mode == 2)
    {
      raw = analogRead(A2);
      buffer = raw * Vin;
      Vout = (buffer) / 1024.0;
      buffer = (Vin / Vout) - 1;
      R22 = R11 * buffer;
      Serial.print(Vout);
      Serial.print("R2: ");
      Serial.println(R22);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("OHM Meter Mode");
      display.setTextSize(2);
      display.setCursor(2, 12);
      if (R22 < 1000)
      {
        display.setCursor(2, 12);
        display.print((R22));
        display.print(" OHM");
      }
      else
      {
        display.setCursor(10, 12);
        display.print((R22 / 1000));
        display.print(" K");
      }
      display.display();
      //delay(300);
    }
    if (mode == 3)
    {
      raw = analogRead(A2);
      buffer = raw * Vin;
      Vout = (buffer) / 1024.0;
      buffer = (Vin / Vout) - 1;
      R22 = R11 * buffer;
      Serial.print(Vout);
      Serial.print("R2: ");
      Serial.println(R22);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("continuity Test Mode");
      display.setTextSize(2);
      display.setCursor(2, 12);
      display.print((R22));
      display.print(" OHM");
      display.display();
      if(R22 < 100)
      {
        digitalWrite(9, HIGH);
      }
      else
      {
        digitalWrite(9, LOW);
      }
    }
    previousMillis = currentMillis;
  }
  // Use the snapshot to set track time until next event
  //previousMillis = currentMillis;
  if (digitalRead(7) == LOW)
  {
    delay(150);
    mode++;
    if (mode >= 4)
      mode = 0;
    Serial.println(mode);
  }
}
