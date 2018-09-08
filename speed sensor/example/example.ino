const int datapin = A2;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print(analogRead(datapin));
  Serial.println();
  delay(100);
}
