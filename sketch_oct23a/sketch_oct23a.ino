const int SENSOR_PIN = 10;
int currentState;         

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  currentState = digitalRead(SENSOR_PIN);

  if(currentState == HIGH) {
    noTone(3);
  }
  else {
    tone(3, 1000);
  }
}
