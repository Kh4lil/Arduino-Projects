int LEDOutPin1 = 9; //Pin 1
int LEDOutPin2 = 7; //Pin 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDOutPin1, OUTPUT);
  pinMode(LEDOutPin2, OUTPUT);
}
void blinkRed() {
   
  digitalWrite(LEDOutPin1, HIGH); // First: Turns ON
  delay(1000); // Frequency of 1Hz
  digitalWrite(LEDOutPin1, LOW); // After delay: Turns OFF
  delay(1000); // Frequency of 1Hz
}

void blinkGreen(){
  digitalWrite(LEDOutPin2, HIGH); // First: Turns ON
  delay(1000); // Frequency of 1Hz
  digitalWrite(LEDOutPin2, LOW); // After delay: Turns OFF
  delay(1000); // Frequency of 1Hz
}
void loop() {
  // put your main code here, to run repeatedly:
  blinkRed();
  blinkGreen();

}
