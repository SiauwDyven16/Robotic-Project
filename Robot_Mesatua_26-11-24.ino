#include <ESP32Servo.h>

// #include "BluetoothSerial.h"
// BluetoothSerial ESP_BT;

int PINGANG_KANAN_PIN; Servo PINGGANG_KANAN;
int PINGGANG_KIRI_PIN; Servo PINGGANG_KIRI;

int PAHA_KANAN_PIN;
int PAHA_KIRI_PIN;

int LUTUT_KANAN_PIN;
int LUTUT_KIRI_PIN;

int PERGELANGAN_KAKI_KANAN_PIN;
int PERGELENGAN_KAKI_KIRI_PIN;

int TELAPAK_KAKI_KANAN_PIN;
int TELAPAK_KAKI_KIRI_PIN;

int BAHU_KANAN_PIN = 33; Servo BAHU_KANAN;
int BAHU_KIRI_PIN = 27; Servo BAHU_KIRI;

int SIKU_KANAN_PIN = 32; Servo SIKU_KANAN;
int SIKU_KIRI_PIN = 26; Servo SIKU_KIRI;

int TANGAN_KANAN_PIN = 34; Servo TANGAN_KANAN;
int TANGAN_KIRI_PIN = 14; Servo TANGAN_KIRI;

void setup() {
  Serial.begin(9600);
  
  BAHU_KANAN.attach(BAHU_KANAN_PIN);
  SIKU_KANAN.attach(SIKU_KANAN_PIN);
  TANGAN_KANAN.attach(TANGAN_KANAN_PIN);

  BAHU_KIRI.attach(BAHU_KIRI_PIN);
  SIKU_KIRI.attach(SIKU_KIRI_PIN);
  TANGAN_KIRI.attach(TANGAN_KIRI_PIN);
}

void ACTION_pushup() {
  BAHU_KANAN.write(90);
  BAHU_KIRI.write(90);
  delay(1000);
  
  for (int i = 0; i < 4; i++) {
    SIKU_KANAN.write(180);
    TANGAN_KANAN.write(90);
    SIKU_KIRI.write(0);
    TANGAN_KIRI.write(90);
    delay(500);

    SIKU_KANAN.write(90);
    TANGAN_KANAN.write(180);
    SIKU_KIRI.write(90);
    TANGAN_KIRI.write(90);
    delay(500);
  }

  
}
void loop() {
  ACTION_pushup();
}