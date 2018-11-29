int distance() {
  long duration;
  int distance;
  
  digitalWrite(DisSensTrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(DisSensTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(DisSensTrigPin, LOW);
  
  duration = pulseIn(DisSensEchoPin, HIGH);
  distance = duration*0.034/2;

  TotalDistances = TotalDistances - Distances[DistanceIndex];
  Distances[DistanceIndex] = distance;
  TotalDistances = TotalDistances + Distances[DistanceIndex];
  DistanceIndex++;
  if (NumDistances <= MaxNumDistances) {
    NumDistances++;
  }

  if (DistanceIndex >= MaxNumDistances) {
    DistanceIndex = 0;
  }

  int AverageDistance = TotalDistances / NumDistances;

  return AverageDistance;
}

bool LightFound(int Sens) {
  CurrentInput = analogRead(A0);
  bool result = (CurrentInput - LastInput > Sens);
  LastInput = CurrentInput;
  return result;
}

void resetLightSens() {
  LastInput = 0;
  CurrentInput = 0;
}
