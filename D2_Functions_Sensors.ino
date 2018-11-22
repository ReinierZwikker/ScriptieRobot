int distance() {
  long duration;
  int distance;
  
  digitalWrite(DisSensTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(DisSensTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(DisSensTrigPin, LOW);
  
  duration = pulseIn(DisSensEchoPin, HIGH);
  distance = duration*0.034/2;

  return distance;
}

bool LightFound() { //veranderen naar gemiddelde van n rondes
  CurrentInput = analogRead(A0);
  bool result = (CurrentInput - LastInput > LightSens);
  LastInput = CurrentInput;
  return result;
}

void resetLightSens() {
  LastInput = 0;
  CurrentInput = 0;
}
