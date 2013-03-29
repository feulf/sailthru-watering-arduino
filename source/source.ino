const int MOISTURE_LEVEL = 500; // the value after the LED goes ON
const int VAL_PROBE = 0; // Analog pin 0
const int RELAY_PIN = 10;
const int BUTTON_PIN = 2;

void setup() {
    Serial.begin(9600);
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(VAL_PROBE, INPUT);
}

void LedState(int state) {
    digitalWrite(13, state);
}

void loop() {
    int moisture_level = analogRead(VAL_PROBE);
    Serial.println(moisture_level);
    int is_switched_off = digitalRead(2);
    if (moisture_level > MOISTURE_LEVEL) {
        LedState(HIGH);
    } else   {
        LedState(LOW);
    }

      if (is_switched_off && moisture_level < MOISTURE_LEVEL) {
        digitalWrite(RELAY_PIN, LOW);
      } else {
      digitalWrite(RELAY_PIN, HIGH);
    }
    
    delay(100);
}
