#include <ESP32Servo.h>


Servo PINGGANG_KANAN, 
PINGGANG_KIRI, 
BAHU_KANAN, 
BAHU_KIRI,
SIKU_KANAN, 
SIKU_KIRI, 
TANGAN_KANAN, 
TANGAN_KIRI;

int BAHU_KANAN_PIN = 33;
int BAHU_KIRI_PIN = 27;
int SIKU_KANAN_PIN = 32;
int SIKU_KIRI_PIN = 26;
int TANGAN_KANAN_PIN = 34;
int TANGAN_KIRI_PIN = 14;

void setup() {
  Serial.begin(9600);
  BAHU_KANAN.attach(BAHU_KANAN_PIN);
  BAHU_KIRI.attach(BAHU_KIRI_PIN);
  SIKU_KANAN.attach(SIKU_KANAN_PIN);
  SIKU_KIRI.attach(SIKU_KIRI_PIN);
  TANGAN_KANAN.attach(TANGAN_KANAN_PIN);
  TANGAN_KIRI.attach(TANGAN_KIRI_PIN);
}

void ACTION_pushup() {
  BAHU_KANAN.write(90);
  BAHU_KIRI.write(90);
  delay(1000);
  
 for (int i = 0; i < 4; i++) {
    SIKU_KANAN.write(180);
    SIKU_KIRI.write(0);
    TANGAN_KANAN.write(90);
    TANGAN_KIRI.write(90);
    delay(500);

    SIKU_KANAN.write(90);
    SIKU_KIRI.write(90);
    TANGAN_KANAN.write(180);
    TANGAN_KIRI.write(90);
    delay(500);
  }

void loop() {
  ACTION_pushup();
}
