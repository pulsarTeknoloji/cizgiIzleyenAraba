// Pin tanımlamaları
const int solSensorPin = A0; // Sol sensör pin
const int sagSensorPin = A1; // Sağ sensör pin

// Eşik değerleri (sensörün gördüğü siyah çizgiyi beyaz zeminden ayırt etmek için)
const int esikDegeriSol = 3500;
const int esikDegeriSag = 3500;

void setup() {
  // Pin modları ayarlanıyor
  pinMode(solSensorPin, INPUT);
  pinMode(sagSensorPin, INPUT);
  Serial.begin(115200); // Seri haberleşme başlatılıyor (Sensör değerlerini izlemek için)
}

void loop() {
  // Sol ve sağ sensörlerin okuma değerleri alınıyor
  int solOkuma = analogRead(solSensorPin);
  int sagOkuma = analogRead(sagSensorPin);

  // Sol sensör değeri eşik değerinden küçükse, çizgiyi algıladı
  if (solOkuma > esikDegeriSol) {
    Serial.println("Sol sensör çizgiyi algıladı!");
  }
  else
    Serial.println("Sol sensör çizgiyi algılamadı!");
  
  // Sağ sensör değeri eşik değerinden küçükse, çizgiyi algıladı
  if (sagOkuma > esikDegeriSag) {
    Serial.println("Sağ sensör çizgiyi algıladı!");
  }
  else
    Serial.println("Sağ sensör çizgiyi algılamadı!");
  
  // Biraz gecikme ekleyebilirsiniz, örneğin:
  delay(100); // 100 milisaniye bekleyin
}
