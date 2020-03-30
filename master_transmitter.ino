#include <Wire.h>
char incomingByte;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("Hello World.");
  Wire.beginTransmission(13);

  if (Serial.available()){
    while(Serial.available() > 0){
       incomingByte = Serial.read();
       Wire.write(incomingByte);
       Serial.println(incomingByte);
       Wire.endTransmission();   
    }

  }
  delay(500);
}
