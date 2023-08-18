// Basit saksi sulayan su pompasi calistirma uygulamasi

#include <Arduino.h>
#include "deneyap.h"
#include <Deneyap_Servo.h>


Servo servo3; //Lower
Servo servo1; //Middle
Servo servo2; //Upper 



#define servopin1 D0
#define servopin2 D1
#define servopin3 D4


int buttondurum = 0;
bool atishazirlik = 1;
int lower , upper , middle;







void setup() {
servo1.attach(servopin1);
servo2.attach(servopin2);
servo3.attach(servopin3);
pinMode(GPKEY , INPUT);


hazir();
}

void loop() {
int buttondurum = digitalRead(GPKEY);

if(buttondurum == 1 ){
  atis();
  delay(4000);
  hazir();
}

}


void atis(){
  while (lower>120){
    lower -= 10;
    middle += 25;
    upper -= 8;

    servo3.write(lower);
    servo1.write(middle);
    servo2.write(upper);
  }

  servo1.write(130);
  delay(400);
  servo2.write(180);
  atishazirlik = 0;

}

void hazir(){
  lower = 180;
  middle = 15;
  upper = 150;

  atishazirlik = 1;

  servo3.write(lower);
  servo1.write(middle);
  servo2.write(upper);
}















  //Sensorden okunan degerleri kendi değişkenlerine depoladık:


