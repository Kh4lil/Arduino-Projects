#include <Wire.h>
#define ACTIVATED LOW //Stateofthe button is activated when LOW (connected to ground)

long randNumber; //define random number

#define RED 13 //RED is our pin 13.

const int buttonPin = 2; //Pin 2 connected to the button
int buttonState = 0;//Stateof the button pushed or not

int x =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(RED, OUTPUT); //define LED port as output
  pinMode(buttonPin,INPUT); // define button as input
  digitalWrite(buttonPin,HIGH);

  Wire.begin(13); //communication on address #13
  Wire.onReceive(receiveEvent);
  randomSeed(analogRead(0));
}
void receiveEvent(int bytes){
  x = Wire.read();
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

void loop() {
  // put your main code here, to run repeatedly:
  buttonState =digitalRead(buttonPin);
  //CHECK IF BUTTON IS ACTIVATED
  while(buttonState==ACTIVATED){
      randNumber = random(255);
      Serial.println(randNumber);
  
      if (isPrime(randNumber)){
        digitalWrite(RED, HIGH);
        delay(1000);
        digitalWrite(RED, LOW);
      }
  
      if (!isPrime(randNumber)){
        digitalWrite(RED, HIGH);
        delay(200);
        digitalWrite(RED, LOW);
      }
      break;
  }
}
