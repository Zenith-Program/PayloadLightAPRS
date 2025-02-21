#include <Arduino.h>
#include <Wire.h>

#define lightAPRS_Address 0x38
#define lightAPRS_Print 0x01

void transmitAPRS(const char *message);

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if(Serial.available()){

    

    String art = Serial.readString();
    
    Serial.println("Poling lightAPRS");
      
      transmitAPRS((const char*)art.c_str());
    
  }

  //Serial.println("Waiting for input...");

  delay(1000);
}

void printOnLightAPRS(){
  Wire.beginTransmission(lightAPRS_Address);
  Wire.write(lightAPRS_Print);
  Wire.endTransmission();
}
void transmitAPRS(const char *message) {
  Wire.beginTransmission(lightAPRS_Address);
  Wire.write(lightAPRS_Print);  // Send command byte if required
  
  // Send the string character by character
  while (*message) {
    Wire.write(*message++);
  }

  Wire.endTransmission();
}


