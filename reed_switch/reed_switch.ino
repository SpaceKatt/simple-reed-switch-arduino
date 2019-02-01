const int REED_PIN = 2; // Pin connected to reed switch
const int LED_PIN = 3; // LED pin - active-high

bool SWITCH_OPEN;

void setup() 
{
//  Serial.begin(9600);
  // Since the other end of the reed switch is connected to ground, we need
  // to pull-up the reed switch pin internally.
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  SWITCH_OPEN = false;
  digitalWrite(LED_PIN, LOW);
}

void loop() 
{
  int proximity = digitalRead(REED_PIN); // Read the state of the switch
  
  // If the pin reads low, the switch is closed.
  if (proximity == LOW) {
    if (SWITCH_OPEN) {
      digitalWrite(LED_PIN, LOW);
      SWITCH_OPEN = false;
    }
  } else {
    if (!SWITCH_OPEN) {
      digitalWrite(LED_PIN, HIGH);
      SWITCH_OPEN = true; 
    }
  }
}
