//  Dummy class to disable Arnduino Serial.println
//  Add other Serial. members if needed


#include <Arduino.h>

void dummySerial::println(const char * c) {}

dummySerial dSerial;
