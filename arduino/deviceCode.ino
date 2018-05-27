int RELAY_CONTROL = 7;
char toggle_signal;
boolean new_signal_available = false;
const char ON_SIGNAL = 'o';

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_CONTROL, OUTPUT);
  digitalWrite(RELAY_CONTROL, HIGH);
  Serial.println("<Arduino Board is Ready>");
}

void loop() {
  //READING SIGNAL FROM SERIAL PORT INCASE IT IS AVAILABLE
  read_single_char_from_serial();

  //CEARING THE SERIAL BUFFER, IN CASE ANY TRAILING BYTES ARE PASSED.
  clear_serial_buffer();
  
  //TOGGLE THE RELAY ONLY WHEN A SIGNAL IS RECEIVED
  if(new_signal_available == true) {
    //PRINGTING WHAT WE GOT. THIS IS JUST FOR DEBUGGING PURPOSE
    print_received_signal();

    //RE-SETTING THE FLAG, SO NEW SIGNALS MAY BE 
    new_signal_available = false;

    if(toggle_signal == ON_SIGNAL){
      digitalWrite(RELAY_CONTROL, LOW);
    } else {
      digitalWrite(RELAY_CONTROL, HIGH);
    }
  }
  delay(3000);
}

void print_received_signal() {
  Serial.print("Received Toggle Signal as : ");
  Serial.println(toggle_signal);
}

char read_single_char_from_serial() {
  if(Serial.available() > 0) {
    toggle_signal = Serial.read();
    new_signal_available = true;
  }
}

void clear_serial_buffer() {
  while(Serial.available() > 0) {
    Serial.read();
  }  
}
