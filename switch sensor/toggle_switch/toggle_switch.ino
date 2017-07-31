int togglepin = 7;
int prevstate = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(togglepin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(togglepin, HIGH);
  int curstate = digitalRead(togglepin);
  if (curstate != prevstate) {
    if (curstate == 1) Serial.print("toggle On\n");
    else Serial.print("toggle Off\n");
  }
  prevstate = curstate;
  delay(10);
}
