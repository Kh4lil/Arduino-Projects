
#include <Wire.h> // Using I2C bus

int var; //define random number

int ledTest = 13;

#define SLAVE_ADDR 9
int buttonPin = 2;

void setup() {
     //Serial.begin(9600);
  pinMode(ledTest, OUTPUT);
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT); // define button as input
  //digitalWrite(buttonPin, HIGH);
  Wire.begin(); // Initilization of I2C

}


void loop() {
  // put your main code here, to run repeatedly:

  // put your main code here, to run repeatedly:
    int buttonState =digitalRead(buttonPin);
    //CHECK IF BUTTON IS ACTIVATED
    if (buttonState == HIGH){
      var = random(255);
    }

        
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(var);
  Wire.endTransmission();

}
