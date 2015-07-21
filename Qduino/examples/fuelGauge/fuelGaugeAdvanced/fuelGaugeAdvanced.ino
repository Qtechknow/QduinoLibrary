/*
  Qduino Mini built-in LiPo Battery Fuel Gauge
  
  Reads the battery state of charge - make sure the
  battery is connected or you will get weird readings!
  
  Returns the value in percent - check Qduino.cpp for
  documentation on how to put the fuel gauge to sleep
  and wake it up.
 
  created by Quin Etnyre
  driver forked from Matt Newberry
*/

#include "Arduino.h"
#include "Wire.h"
#include "Qduino.h"

fuelGauge battery;  // initialize the library

qduino q;

void setup(){
  
 Wire.begin(); 
 Serial.begin(9600);  // start Serial port
 battery.setup();  // setup fuel gauge
 
 //while(!Serial);  // wait for Serial port to be opened
 
 attachInterrupt(4, function, CHANGE);
 
 Serial.println("Begin");
}

void loop(){
  int charge = battery.chargePercentage();  // get %
  battery.reset();  // reset for next data request
  Serial.print(charge); // print out the battery %
  Serial.println("%");
  
  battery.setThreshold(87);
  
  EICRB |= (1<<ISC60)|(1<<ISC61); // sets the interrupt type
  EIMSK |= (1<<INT6); // activates the interrupt
  
  
 // ISR(INT6_vect) {  // normal AVR way (interupt)
    
 // } 
  
  Serial.println(battery.currentThreshold());
  
  delay(1000);  // wait a second to read again
}

void function() {
  for(int i = 0; i<100; i++) {
      q.setRGB("white");
      delay(100);
      q.ledOff();
      delay(100);
    }
}
