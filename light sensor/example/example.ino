int cds_value = 0;

void setup() {
  // Setting for serial connection.
  Serial.begin(9600);
}

void loop() {
  //Plug CdS cell into Analog pin 0
  cds_value = analogRead(A0);
  //You can see the brightness value
  //Serial.print("CdS : ");
  //Serial.print(cds_value);
  
  // Demo brightness : 300
  if(cds_value < 300){
    Serial.print("Open!\n");
  }
  else{
    Serial.print("Close!\n");
  }
  delay(100);
}
