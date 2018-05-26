int RELAY_CONTROL = 7;

void setup() {
  pinMode(RELAY_CONTROL, OUTPUT);
  digitalWrite(RELAY_CONTROL, LOW);
}

void loop() {
  digitalWrite(RELAY_CONTROL, HIGH);
  delay(2000);
  digitalWrite(RELAY_CONTROL, LOW);
  delay(5000);
}
