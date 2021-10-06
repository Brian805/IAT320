#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
   
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void setup(void) 
{
  Serial.begin(9600);
  pinMode(1, OUTPUT);
}

void loop(void) 
{   
  sensors_event_t event;
  tsl.getEvent(&event);
 
  if (event.light)
  {
    Serial.print(event.light); Serial.println(" lux");
  }
  else
  {
    Serial.println("Sensor overload");
  }
  delay(250);

  if (event.light > 20)
  tone(1, 100);
  else noTone(1);
}
