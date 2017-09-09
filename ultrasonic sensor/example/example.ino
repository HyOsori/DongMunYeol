int lastState=0;
int trig_pin = 2;
int echo_pin = 3;
float duration, distance;

void setup() {
  // Setting for serial connection.
  Serial.begin(9600);

  // Setting for input,output
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}

void loop() {
  digitalWrite(trig_pin, HIGH);
  // Delay time : 1 sec
  delay(1000);
  digitalWrite(trig_pin, LOW);

  // Write duration of high state at echo pin.
  duration = pulseIn(echo_pin, HIGH);
  
  // Ultrasonic velocity : 340 m/s, Think about round trip
  distance = ((float)(340*duration)/10000)/2;

  int currentState=0;
  
  if(distance<10){
    currentState=1;
  }
  else{
    currentState=0;
  }

  if(currentState!=lastState){
    if(currentState==1)
      Serial.print("Open\n");
    else
      Serial.print("Close\n");
  }
  
  lastState=currentState;
  
  delay(100);
}
