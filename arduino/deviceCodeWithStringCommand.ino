int RELAY_CONTROL = 7;
String ON_COMMAND = "ON";
String OFF_COMMAND = "OFF";
String command;

void setup() {
  pinMode(RELAY_CONTROL, OUTPUT);
  digitalWrite(RELAY_CONTROL, HIGH); //OFF
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
}

void loop() {
  
   while(Serial.available()) {
    command = Serial.readStringUntil("\n");// read the incoming data as string
    if(command.equals(ON_COMMAND)){
      digitalWrite(RELAY_CONTROL, LOW); //ON
    }else if(command.equals(OFF_COMMAND)){
      digitalWrite(RELAY_CONTROL, HIGH); // OFF
    }
  }
}
