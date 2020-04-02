#include <Wire.h> // Using I2C bus

#define SLAVE_ADDR 9

int LED = 13;

int receivedData;

int br;
int randNumber; //define random number


void setup() {
  // put your setup code here, to run once:

   pinMode(LED, OUTPUT);
   
   Wire.begin(SLAVE_ADDR);
   
   //Wire.onRequest(requestEvent);
   Wire.onReceive(receiveEvent);

   Serial.begin(9600);
   Serial.println("SLAVE");

   
}

void receiveEvent(){
  receivedData = Wire.read();
  Serial.println(receivedData);

  
  if (isPrime(receivedData)){
    delay(5000);
        digitalWrite(LED, HIGH);
        delay(1000);
        digitalWrite(LED, LOW);
      }
  
      if (!isPrime(receivedData)){
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
      }
}


void loop() {
  // put your main code here, to run repeatedly:
  
}

// METHOD TO CHECK IF NUMBER IS PRIME 
boolean isPrime(int x){
  boolean prime = true;
  for (int i = 2; i <= x/2; i++){
    if (x%i==0){
      prime = false;
      break;
    }
  }
  return prime;
}
