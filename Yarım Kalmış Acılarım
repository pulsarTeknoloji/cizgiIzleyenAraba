#include <Arduino.h>
#include <deneyap.h>
#include <Deneyap_CiftKanalliCizgiAlgilama.h>

LineFollower LineDetect;


const int rightForward = D4;
const int rightBackward = D5;
const int leftForward= D6;
const int leftBackward = D7;






void setup() {
 Serial.begin(115200);
pinMode(rightBackward , OUTPUT);
pinMode(rightForward , OUTPUT);
pinMode(leftForward , OUTPUT);
pinMode(leftBackward , OUTPUT);

if(LineDetect.begin(0x07)){
  delay(3000);
  Serial.println("I2C bağlanisi yapilamadi ");
  while(1);
}
 
}

void loop() {
  //Sensörleri Tanıtıyoruz:
bool Sensor2 = LineDetect.ReadlineFollowerDigital2();
bool Sensor1 = LineDetect.ReadLineFollowerDigital1();

if (Sensor1 == 1 && Sensor2 == 1){
  ileri();

}

else if (Sensor1 == 1 && Sensor2 == 0){
  Sol();
}

else if (Sensor1 == 0 && Sensor2 == 1){
  sag();
}

else if(Sensor1 == 0 && Sensor2 == 0){
  dur();
}

/*
-Yukarıda yazdığım kodun ayarlanabilir değerlisi, eğerki yine boolean değerler ihtiyacım olursa bool değişkenler atayıp onları 
bu değerlere göre 0 ve 1 değerlerine atayacağım-


uint16_t Sensor1Deger = LineDetect.ReadLineFollowerAnalog1();
uint16_t Sensor2Deger = LineDetect.ReadLineFollowerAnalog2();

if(Sensor1Deger > 3500 && Sensor2Deger < 3000){
  sol();
}

else if (Sensor1Deger > 3500 && Sensor2Deger > 3500){
  ileri();
}

else if(Sensor1Deger < 3500 && Sensor2Deger > 3500){
  sag();
}
else if(Sensor1Deger < 3500 && Sensor2Deger < 3500){
  dur();
}

*/
