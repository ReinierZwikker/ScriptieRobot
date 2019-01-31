void drive(int Speed) {
  
  // Maximale snelheid
  Speed = max(min(Speed, 100), 0);
  

  // Snelheid van percentage naar 0-255 omzetten en offset toevoegen (correctie voor ongelijke motoren)
  int MappedSpeedL = map(Speed, 0, 100, 0, 255) + motorLOffset;
  int MappedSpeedR = map(Speed, 0, 100, 0, 255) + motorROffset;

  // PWM-Signaal naar motoren sturen
  analogWrite(motorRSpeedPin, MappedSpeedR);
  analogWrite(motorLSpeedPin, MappedSpeedL);
}

void turn(bool side, int Speed, int angle) {  //true = right, false = left; angle = 45, 90, 180
  
  // Maximale snelheid
  Speed = max(min(Speed, 100), 0);


    // Snelheid van percentage naar 0-255 omzetten en offset toevoegen (correctie voor ongelijke motoren)
  int MappedSpeedL = map(Speed, 0, 100, 0, 255) + motorLOffset + 10;
  int MappedSpeedR = map(Speed, 0, 100, 0, 255) + motorROffset - 20;
  
  switch (side) {
    case true:
    
      // PWM-Signaal naar motoren sturen
      analogWrite(motorRSpeedPin, 0);
      analogWrite(motorLSpeedPin, MappedSpeedL);
    
      break;
    case false:

      // PWM-Signaal naar motoren sturen
      analogWrite(motorRSpeedPin, MappedSpeedR);
      analogWrite(motorLSpeedPin, 0);
      
      break;
  }

  switch (angle) {
    case 90:
      delay(TurnTime90/(Speed/50));
      break;
    case 180:
      delay(TurnTime180/(Speed/50));
      break;
    case 45:
      delay(TurnTime45/(Speed/50));
      break;
    default:
      delay(TurnTime90/(Speed/50));
      break;
  }
  
  analogWrite(motorRSpeedPin, 0);
  analogWrite(motorLSpeedPin, 0);
}

void scan(bool side) {  //true = right, false = left
  
  int Speed = 50;

    // Snelheid van percentage naar 0-255 omzetten en offset toevoegen (correctie voor ongelijke motoren)
  int MappedSpeedL = map(Speed, 0, 100, 0, 255) + motorLOffset + 10;
  int MappedSpeedR = map(Speed, 0, 100, 0, 255) + motorROffset - 20;
  
  switch (side) {
    case true:
    
      // PWM-Signaal naar motoren sturen
      analogWrite(motorRSpeedPin, 0);
      analogWrite(motorLSpeedPin, MappedSpeedL);
    
      break;
    case false:

      // PWM-Signaal naar motoren sturen
      analogWrite(motorRSpeedPin, MappedSpeedR);
      analogWrite(motorLSpeedPin, 0);
      
      break;
  }

  while(distance() > 50) {
    //do nothing
  }

//delay(TurnTime180/(Speed/50));
  
  analogWrite(motorRSpeedPin, 0);
  analogWrite(motorLSpeedPin, 0);
}
