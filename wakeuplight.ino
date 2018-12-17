
// Output Pin Variables
int yellow1 = D5;       // Yellow LED - Turn on when it's ok to wake up
int yellow2 = D3;       // Yellow LED - Turn on when it's ok to wake up
int blue1 = D6;          // Blue LED - Turn on when it's bedtime
int blue2 = D4;          // Blue LED - Turn on when it's bedtime
int onboard = D7;       // Onboard Blue LED - We'll turn off during the day and turn on at bedtime

// State variables
bool isNight = true;
int checkDelay = 5 * 1000; // 1 minute

void setup() {
    // Initialize Outputs
    pinMode(blue1, OUTPUT);
    pinMode(blue2, OUTPUT);
    pinMode(onboard, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(yellow2, OUTPUT);
    
    // Initialize particle cloud functions
    Particle.function("wakeUp", wakeUp);
    Particle.function("bedtime", bedtime);
}

int wakeUp(String command) {
  isNight = false;
  return 1;
}

int bedtime(String command) {
  isNight = true;
  return 1;
}

void loop() {
    
    if (isNight) {
        digitalWrite(blue1, HIGH);
        digitalWrite(blue2, HIGH);
        digitalWrite(onboard, HIGH);
        digitalWrite(yellow1, LOW);
        digitalWrite(yellow2, LOW);
    } else {
        digitalWrite(blue1, LOW);
        digitalWrite(blue2, LOW);
        digitalWrite(onboard, LOW);
        digitalWrite(yellow1, HIGH);
        digitalWrite(yellow2, HIGH);
    }
    
    // Wait 1 min...
    delay(checkDelay);
}