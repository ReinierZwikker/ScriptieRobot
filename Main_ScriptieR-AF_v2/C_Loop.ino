void loop() {

  switch (state) {
    case 0:
      //Do nothing
      break;
    case 1:

      startMillis = millis();

      while(currentMillis - startMillis <= millisToCount) {
          currentMillis = millis();
      }

      state = 2;

      break;

    case 2: {

      resetLightSens();

      turn(false);

      scan(true);

      drive();

      while(!LightFound()) {

        if(distance() < TurnDistance) {
          drive(0);
          turn(RandBool());
          drive();
        }
      }

      state = 0;

      DebugLED();

      break;

    }

    case 3: {

      drive();
      
      startMillis = millis();

      while(currentMillis - startMillis <= millisToCount) {

          currentMillis = millis();

          if (distance() < TurnDistance) {
            drive(0);
            turn(RandBool());
            drive();
          }

          if (RandBoolXS()) {
            turn(RandBool());
          }
      }

      DebugLED();

      state = 4;

      break;

    }

    case 4: {

      FlashLED();
      break;
    }

    case 5: {

        bool TestRondjeDirection = true;

          drive();
        delay(2000);
          turn(TestRondjeDirection);
          drive();
        delay(2000);
          turn(TestRondjeDirection);
          drive();
        delay(2000);
          turn(TestRondjeDirection);
          drive();
        delay(2000);
          turn(TestRondjeDirection);

        state = 0;

        break;
    }

    case 6:

      drive();
      delay(5000);
      drive(0);

      state = 0;

      break;

    case 7:


      Serial.println(distance());

      break;

    case 8:

      Serial.println(analogRead(A0));
      if(LightFound())
        Serial.println(0);



      break;
  }
}
