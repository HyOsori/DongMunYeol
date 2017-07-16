//See attached jpeg
// plug button into digital pin 2
int btn = 2;
// plug Green LED into digital pin 3 
int led_G = 3; 
// plug Red LED into digital pin 4
int led_R = 4; 

//init the value
int nowState = 0;
int oldState = 0;
int btnState = 0;

void setup() {
    pinMode(btn, INPUT);
    pinMode(led_G, OUTPUT);
    pinMode(led_R, OUTPUT);
}

void loop() {
  //When you press the button, the value of 'nowState' will be 1
  nowState = digitalRead(btn);
  if(nowState != oldState) {
    if(nowState == 1) {
      if(btnState == 0) {
        //Red LED is on
        digitalWrite(led_R, HIGH);
        digitalWrite(led_G, LOW);
        btnState = 1;
      }
      else {
        //Green LED is on
        digitalWrite(led_R,LOW);
        digitalWrite(led_G,HIGH);
        btnState = 0;
      }
    }
    oldState = nowState;
  }
    delay(50);
}
