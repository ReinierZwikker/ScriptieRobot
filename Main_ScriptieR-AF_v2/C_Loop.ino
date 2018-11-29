void loop() {

  switch (state) {
    case 0:
      //Do nothing
      break;
    case 1:
    
      for(int i = 0; i < SecondsToCount; i++) {
        delay(800);
          digitalWrite(13, HIGH);
        delay(200);
          digitalWrite(13, LOW);
      }

      state = 2;
      
      break;
    
    case 2: {

      resetLightSens();

      turn(false);

      scan(true);

      while(!Found) {

        drive();

        

        while(distance() > TurnDistance && !Found) {
          Found = LightFound(150);
        }

        drive(0);
        
        if(!Found) {
          turn(RandBool());
        }
      }

      Found = false;
      
      while(!Found) {

        drive(40);
  
        while(distance() > TurnDistance && !Found) {
          Found = LightFound();
        }
      }

      state = 0;

      DebugLED();
      
      break;

    }
    
    case 3: {      

      for(int Count = 0; Count < MaxCount;  Count++){
        
        drive();
  
        while(distance() > TurnDistance && Count < MaxCount) {
          if(RandBoolXS()) {
            turn(RandBool());
          }
          Count++;
        }
      
        drive(0);
      
        if(Count < MaxCount) {
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
