int cds = A0;
int led = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int cdsValue = analogRead(cds);

  Serial.print("cds = ");
  Serial.println(cdsValue);

  if (cdsValue>  200) {
    digitalWrite(led, LOW);

    Serial.println("LED OFF (CDS > 200)");
  }

  else {
    digitalWrite (led, HIGH);
    Serial.println("LED ON (CDS <= 200)");
  }

  delay(200);

}
