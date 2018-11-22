//Toewijzen van pins
#define motorLSpeedPin 5
#define motorRSpeedPin 6
#define DisSensEchoPin 8
#define DisSensTrigPin 7

#define ledPin 2

int state = 8;

// state:
// 0 = Idle
// 1 = Tellen
// 2 = Zoeken
// 3 = Verstoppen
// 4 = Wachten op zoeker
// 5 = Testrondje
// 6 = Testlijn
// 7 = Print Distancesensor naar Serial
// 8 = Print LichtSensor naar Serial

const float motorLOffset = 0;
const float motorROffset = 0;

const int SecondsToCount = 15; //s
const int LightSens = 250; // van de 1024
const int TurnDistance = 18; //cm

//voor states
bool Found = false;
bool Counting = false;

int LastInput = 1000;
int CurrentInput;

int MaxCount = 200;

int TurnTime90 = 525; //Tijd om 90 graden te draaien bij snelheid = 50 in ms
int TurnTime180 = TurnTime90*2 + 0; 
int TurnTime45 = TurnTime90/2 + 0; 

//default values voor functies
void drive(int Speed = 50);
void turn(bool side, int Speed = 50, int angle = 90);
void FlashLED(int pin = ledPin, int timing = 500, bool turnoff = true);
