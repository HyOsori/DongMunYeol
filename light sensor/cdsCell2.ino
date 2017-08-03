/* 조도센서 실습 with 풀다운저항 */

  /*
   * 보통은 밝으면 저항값이 작아져서 전압이 높아짐
   * 하지만 풀업저항 사용시 반대로 밝으면 전압이 낮아짐 (VCC에 연결)
   * 반대로 풀다운저항 사용시 밝으면 전압이 높아짐 (GND에 연결)
  */

#include <stdlib.h>
#include <time.h>
#define LED_NUM 6
#define LED_START 3 // Digital Signal

int cds = A0; // Analog Signal
int led[LED_NUM];
int flag[LED_NUM]={false};

void setup() {
  Serial.begin(9600);
  
  for(int i=0,j=LED_START;i<LED_NUM;i++,j++)
  {
    led[i]=j;
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  int i;
  int cdsValue = analogRead(cds); // 입력된 전압값(0-5V를 1024등분하여 0-1023까지 나타냄)
  
  srand(time(NULL));
  
  Serial.print("cds = ");
  Serial.println(cdsValue);

  if (cdsValue >  500) { // 밝을 때 (밝으면 cdsValue가 낮아짐)
    for(i=0;i<LED_NUM;i++)
      led_off(i);
    Serial.println("LED OFF (CDS > 500)");
  }

  else { // 어두울 때
    while(1)
    {
      for(i=0;i<LED_NUM;i++)
      {
        if(!flag[i])
          break;
      }
      
      if(i==LED_NUM)
        break;
             
      int num=(rand()+2)%LED_NUM;
      led_on(num);
      
      delay(1000);
    }
    Serial.println("LED ON (CDS <= 500)");
  }

  delay(200);

}

void led_off(int num){
  digitalWrite(led[num],LOW);
  flag[num]=false;
}

void led_on(int num){
  digitalWrite(led[num],HIGH);
  flag[num]=true;
}
