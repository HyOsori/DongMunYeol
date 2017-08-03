int cds = A0;
int led = 3;

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  
  int cdsValue = analogRead(cds);

  Serial.print("cds = ");
  Serial.println(cdsValue);

  if (cdsValue>  400) { // when the light is off (door opened)
    digitalWrite(led, LOW);
    Serial.println("Opened!");
  }

  else { // when the light is turned on (door closed)
    digitalWrite (led, HIGH);
    Serial.println("Closed!");
  }

  delay(1000);

}
