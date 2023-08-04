const int pinler[] = {D4, D5, D6, D7};
const int esikDegerOrta = 3500;
const int esikDegerSag = 3500;
const int esikDegerSol = 3500;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(pinler[i], OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  int ortaOkuma = analogRead(A0);
  int solOkuma = analogRead(A1);
  int sagOkuma = analogRead(A2);

  if (ortaOkuma > esikDegerOrta && sagOkuma > esikDegerSag && solOkuma > esikDegerSol) {
    ileri();
  } else if (ortaOkuma <= esikDegerOrta && sagOkuma > esikDegerSag && solOkuma <= esikDegerSol) {
    dur();
  } else if (ortaOkuma <= esikDegerOrta && sagOkuma <= esikDegerSag && solOkuma > esikDegerSol) {
    sag();
  } else if (ortaOkuma > esikDegerOrta && sagOkuma <= esikDegerSag && solOkuma <= esikDegerSol) {
    sol();
  } else {
    // Belirli bir şeridi izlemediğimiz durumlar için buraya eklemeler yapabilirsiniz.
    // Örneğin, geri gitmek gibi durumlar ekleyebilirsiniz.
    dur();
  }
}

void ileri() {
  digitalWrite(pinler[3], 1);
  digitalWrite(pinler[2], 0);
  digitalWrite(pinler[1], 1);
  digitalWrite(pinler[0], 0);
}

void geri() {
  digitalWrite(pinler[3], 0);
  digitalWrite(pinler[2], 1);
  digitalWrite(pinler[1], 0);
  digitalWrite(pinler[0], 1);
}

void sag() {
  digitalWrite(pinler[3], 0);
  digitalWrite(pinler[2], 1);
  digitalWrite(pinler[1], 0);
  digitalWrite(pinler[0], 0);
}

void sol() {
  digitalWrite(pinler[3], 0);
  digitalWrite(pinler[2], 0);
  digitalWrite(pinler[1], 0);
  digitalWrite(pinler[0], 1);
}

void dur() {
  digitalWrite(pinler[3], 0);
  digitalWrite(pinler[2], 0);
  digitalWrite(pinler[1], 0);
  digitalWrite(pinler[0], 0);
}
