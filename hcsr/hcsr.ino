// Deklarasi pin sensor
const int trigPin = 9;
const int echoPin = 10;

// Variabel
long duration;
int distance;

void setup() {
  Serial.begin(9600);       // Mulai komunikasi serial
  pinMode(trigPin, OUTPUT); // Trig sebagai output
  pinMode(echoPin, INPUT);  // Echo sebagai input
}

void loop() {
  // Kirim sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca waktu pantulan (dengan timeout 20ms)
  duration = pulseIn(echoPin, HIGH, 20000); // 20.000 µs = jarak max sekitar 3.4 meter

  // Cek apakah tidak ada objek yang terdeteksi
  if (duration == 0) {
    Serial.println("Tidak terdeteksi.");
  } else {
    // Hitung jarak dalam cm
    distance = duration * 0.034 / 2;

    // Tampilkan hasil
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Peringatan bahaya jika terlalu dekat
    if (distance <= 5) {
      Serial.println("⚠️ ADA BAHAYA!");
    }
  }

  delay(50); // jeda antar pengukuran (real-time tapi tidak terlalu cepat)
}
