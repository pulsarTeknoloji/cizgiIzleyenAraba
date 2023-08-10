const int rightForward = D4;
const int rightBackward = D5;
const int leftForward= D6;
const int leftBackward = D7;

const int solsensorpin = A2;
const int sagsensorpin = A1;
const int ortasensorpin = A0;

const int esiksol = 3500;
const int esiksag = 3500;
const int esikorta = 3500;

bool solsensordeger;
bool sagsensordeger;
bool ortasensordeger;
  







void setup() {
  pinMode(rightForward , OUTPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(solsensorpin , INPUT);
  pinMode(sagsensorpin , INPUT);
  pinMode(ortasensorpin , INPUT);

Serial.begin(115200);

  

}

void loop() {
 int solsensor = analogRead(solsensorpin);
 int sagsensor = analogRead(sagsensorpin);
 int ortasensor = analogRead(ortasensorpin);

Serial.println("Sol: ");
Serial.println(solsensordeger);
Serial.println("Sağ: ");
Serial.println(sagsensordeger);
Serial.println("Orta ");
Serial.println(ortasensordeger); 

Serial.println("Sol: ");
Serial.println(solsensor);
Serial.println("Sağ: ");
Serial.println(sagsensor);
Serial.println("Orta ");
Serial.println(ortasensor);

 if(solsensor > 3500 && solsensordeger == 0){
  solsensordeger = 1;
  delay(100);
 }else if(sagsensor > 3500 && sagsensordeger == 0){
  sagsensordeger = 1;
  delay(100);
 }else if(ortasensor > 3500 && ortasensordeger == 0){
  ortasensordeger = 1;
  delay(100);
 }else if(solsensor < 3500 && solsensordeger ==  1){
  solsensordeger = 0;
  delay(100);
 }else if(sagsensor < 3500 && sagsensordeger == 1 ){
  sagsensordeger = 0;
  delay(100);
 }else if(ortasensor < 3500 && ortasensordeger == 1){
  ortasensordeger = 0;
  delay(100);
 }




  if (ortasensordeger == 1 ) {
    forward();
    delay(100);
  } else if (solsensordeger == 1 ) {
    left();
    delay(100);
  } else if (sagsensordeger == 1 ) {
    right();
    delay(100);
  } else if (solsensordeger == 0 && sagsensordeger == 0 && ortasensordeger == 0) {
    stopped();
    delay(100);
  }


}



void forward() {
  digitalWrite(rightForward, 1);
  digitalWrite(rightBackward, 0);
  digitalWrite(leftForward, 1);
  digitalWrite(leftBackward, 0);
}

void backward() {
  digitalWrite(rightForward, 0);
  digitalWrite(rightBackward, 1);
  digitalWrite(leftForward, 0);
  digitalWrite(leftBackward, 1);
}

void right() {
  digitalWrite(rightForward, 0);
  digitalWrite(rightBackward, 1);
  digitalWrite(leftForward, 1);
  digitalWrite(leftBackward, 0);
}

void left() {
  digitalWrite(rightForward, 1);
  digitalWrite(rightBackward, 0);
  digitalWrite(leftForward, 0);
  digitalWrite(leftBackward, 1);
}

void stopped() {
  digitalWrite(rightForward, 0);
  digitalWrite(rightForward, 0);
  digitalWrite(leftForward, 0);
  digitalWrite(leftBackward, 0);
}
