void DebugLED() {
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}

void FlashLED(int pin, int timing, bool turnoff) {
  digitalWrite(pin, HIGH);
  delay(timing);
  if(turnoff) {
    digitalWrite(pin, LOW);
    delay(timing);
  }
}

bool RandBool() {

  if(round(random(0, 2)) == 0) {
    return(true);
  }
  else {
    return(false);
  }
}

bool RandBoolXS() {

  if(round(random(0, 10000)) == 0) {
    return(true);
  }
  else {
    return(false);
  }
}
