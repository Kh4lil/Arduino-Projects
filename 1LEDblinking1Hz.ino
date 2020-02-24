int LEDOutputPin = 9; //Use Pin 9 for Output. 

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDOutputPin, OUTPUT); // Tells arduino that we will be using Pin 9 for Output. 
}

void blinkEveryHz() {
  digitalWrite(LEDOutputPin, HIGH); // First: Turns ON
  delay(1000); // Frequency of 1Hz
  digitalWrite(LEDOutputPin, LOW); // After delay: Turns OFF
  delay(1000); // Frequency of 1Hz
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkEveryHz();
}
