#include <Arduino.h>
#include <Wire.h>

#define lightAPRS_Adress 0x38
#define lightAPRS_Print 0x01

void printOnLightAPRS();

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if(Serial.available()){
    int a = Serial.parseInt();
    if(a==1){
      Serial.println("Poling lightAPRS");
      printOnLightAPRS();
    }
  }
  
  delay(1000);
}

void printOnLightAPRS(){
  Wire.beginTransmission(lightAPRS_Adress);
  Wire.write(lightAPRS_Print);
  Wire.endTransmission();
}


