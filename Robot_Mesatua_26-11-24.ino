#include <ESP32Servo.h>

//Deklarasi Servo, dan pin-pin
Servo PINGGANG_KANAN, 
PINGGANG_KIRI, 
BAHU_KANAN, 
BAHU_KIRI,
SIKU_KANAN, 
SIKU_KIRI, 
TANGAN_KANAN, 
TANGAN_KIRI;


//inisialisasi pin servo sesuai part-part robot
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
//Posisi Awal
  //Tangan 90 derajat > Tegak Lurus Dengan Tubuh Robot
  BAHU_KANAN.write(90);
  BAHU_KIRI.write(90);
  delay(1000);

//Loop Untuk Gerakan Push-up
 for (int i = 0; i < 4; i++) {
   //Posisi Awal Push Up Bagian Siku/Lengan Bawah 
    SIKU_KANAN.write(180);
    SIKU_KIRI.write(0);
   
   //Posisi Awal Push Up Bagian Tangan/Lengan Atas 
    TANGAN_KANAN.write(90);
    TANGAN_KIRI.write(90);
    delay(500);
   
    //Posisi Turun Push Up Bagian Siku/Lengan Bawah
    SIKU_KANAN.write(90);//Ke kiri 90 derajat
    SIKU_KIRI.write(90);//Ke kanan 90 derajat
   
    //Posisi Turun Push Up Bagian Tangan/Lengan Atas
    TANGAN_KANAN.write(180);//Ke Kanan 90 derajat (posisi awal 90 derajat jg)
    TANGAN_KIRI.write(0);//Ke Kiri -90 derajat (posisi awal 90 derajat jg)
    delay(500);
  }

void loop() {
  ACTION_pushup();
}
