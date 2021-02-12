#include <Arduino.h>
#include <EEPROM.h>

int address = 0;
int brightness = 255;
byte STEP = 0;
int once = 0;
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  STEP = EEPROM.read(address);
  switch (STEP)
  {
  case 0:
    analogWrite(address, brightness);
    break;
  case 1:
    analogWrite(address, brightness);
    delay(200);
    analogWrite(address, brightness / 1.5);
    break;
  case 2:
    analogWrite(address, brightness / 1.5);
    delay(200);
    analogWrite(address, brightness / 2);
    break;
  case 3:
    analogWrite(address, brightness / 2);
    delay(200);
    analogWrite(address, brightness / 4);
    break;
  }
  if (STEP == 3)
  {
    STEP = -1;
  }
  EEPROM.write(address, STEP + 1);
}
void loop()
{
  if (once < 1)
  {
    STEP = EEPROM.read(address);
    for (int i = 0; i < STEP + 1; i++)
    {
      digitalWrite(1, HIGH);
      delay(500);
      digitalWrite(1, LOW);
      delay(1000);
    }
    once++;
  }
}