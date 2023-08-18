#include <Deneyap_Servo.h>


Servo servo1;
Servo servo2;
Servo servo3;

#define servopin1 D0
#define servopin2 D1
#define servopin3 D4



int servoderece1= 0;
int servoderece2= 0;
int servodereve3 = 0;
void setup() {
  // put your setup code here, to run once:


servo1.attach(servopin1);
servo2.attach(servopin2);
servo3.attach(servopin3);
Serial.begin(115200);



}

void loop() {
  // put your main code here, to run repeatedly:
while(a>180){
    a -= 10;
    b += 25;
    c -= 8;


     servo1.write(a);
     servo2.write(b);
     servo3.write(c);

     
     Serial.println(a);
     Serial.println(b);
     Serial.println(c);
}
servo2.write(130);
delay(400);
servo3.write(180);




}
