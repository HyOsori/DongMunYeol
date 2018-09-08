#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0x9F, 0x33, 0x79, 0x8B, 0x9D }; //physical mac address

EthernetClient client;
EthernetServer server(80);
String data;
int lastState=0;
const int datapin = A2;
float distance;

void setup() {

  Serial.begin(9600);
  if(Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
  }

  data = "";
}

void loop() {
  distance = analogRead(datapin);
  int currentState=0;
  
  if(distance<500){
    currentState=1;
  }
  else{
    currentState=0;
  }

  if(currentState!=lastState){
    if(currentState==1)
      postStatusData("1");
    else
      postStatusData("0");
  }
  
  lastState=currentState;
  
  delay(100);
}

void postStatusData(String value) {
  Serial.print(value);
  String data= "{\"status\":" + value + "}";

  Serial.println(Ethernet.localIP());
  if(client.connect("211.249.63.229", 1028)) {
    Serial.println(data);
    client.println("POST /receive HTTP/1.1");
    client.println("Host:  211.249.63.229:1028");
    client.println("User-Agent: Arduino/1.0");
    client.println("Connection: close");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.print(data);    
    Serial.println("We have connection");
  } else {
    Serial.println("adsfasfadfasfasdfdas");
  }

  if(client.connected()) {    
    Serial.println("We have abc");
    client.stop();
  }
}
