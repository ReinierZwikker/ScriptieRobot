void setup() {
  //Aangeven hoe de pins gebruikt moeten worden.
  pinMode(motorLSpeedPin, OUTPUT);
  pinMode(motorRSpeedPin, OUTPUT);
  pinMode(DisSensEchoPin, INPUT);
  pinMode(DisSensTrigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(3, OUTPUT);
  
  if(state == 2 || state == 8){
    Serial.begin(9600);
  }

  for (int thisDistance = 0; thisDistance < NumDistances; thisDistance++) {
    Distances[thisDistance] = 0;
  }
  
  delay(1000);
   digitalWrite(13, HIGH);
  delay(200);
    digitalWrite(13, LOW);
}
