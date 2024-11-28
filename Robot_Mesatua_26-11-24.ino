#include <ESP32Servo.h> // Library untuk mengontrol servo menggunakan ESP32

// Pin dan objek servo untuk setiap bagian tubuh robot
int PINGANG_KANAN_PIN; Servo PINGGANG_KANAN; // Pinggang kanan
int PINGGANG_KIRI_PIN; Servo PINGGANG_KIRI; // Pinggang kiri

int PAHA_KANAN_PIN; // Pin untuk paha kanan (belum digunakan)
int PAHA_KIRI_PIN; // Pin untuk paha kiri (belum digunakan)

int LUTUT_KANAN_PIN; // Pin untuk lutut kanan (belum digunakan)
int LUTUT_KIRI_PIN; // Pin untuk lutut kiri (belum digunakan)

int PERGELANGAN_KAKI_KANAN_PIN; // Pin untuk pergelangan kaki kanan (belum digunakan)
int PERGELENGAN_KAKI_KIRI_PIN; // Pin untuk pergelangan kaki kiri (belum digunakan)

int TELAPAK_KAKI_KANAN_PIN; // Pin untuk telapak kaki kanan (belum digunakan)
int TELAPAK_KAKI_KIRI_PIN; // Pin untuk telapak kaki kiri (belum digunakan)

// Pin dan objek servo untuk tangan kanan dan kiri
int BAHU_KANAN_PIN = 33; Servo BAHU_KANAN; // Bahu kanan
int BAHU_KIRI_PIN = 27; Servo BAHU_KIRI;   // Bahu kiri

int SIKU_KANAN_PIN = 32; Servo SIKU_KANAN; // Siku kanan
int SIKU_KIRI_PIN = 26; Servo SIKU_KIRI;   // Siku kiri

int TANGAN_KANAN_PIN = 25; Servo TANGAN_KANAN; // Tangan kanan
int TANGAN_KIRI_PIN = 14; Servo TANGAN_KIRI;   // Tangan kiri

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan baud rate 9600

  // Menghubungkan servo ke pin yang sesuai
  BAHU_KANAN.attach(BAHU_KANAN_PIN);
  SIKU_KANAN.attach(SIKU_KANAN_PIN);
  TANGAN_KANAN.attach(TANGAN_KANAN_PIN);

  BAHU_KIRI.attach(BAHU_KIRI_PIN);
  SIKU_KIRI.attach(SIKU_KIRI_PIN);
  TANGAN_KIRI.attach(TANGAN_KIRI_PIN);
}

void ACTION_pushup() {
  // Mengatur posisi awal bahu (90 derajat - posisi netral)
  BAHU_KANAN.write(90);
  BAHU_KIRI.write(90);
  delay(1000);

  // Melakukan gerakan push-up sebanyak 4 kali
  for (int i = 0; i < 4; i++) {
    // Posisi push-up (naik)
    BAHU_KIRI.write(90);
    SIKU_KANAN.write(180);  // Siku kanan lurus
    TANGAN_KANAN.write(90); // Tangan kanan netral
    SIKU_KIRI.write(0);     // Siku kiri lurus
    TANGAN_KIRI.write(90);  // Tangan kiri netral
    delay(500);

    // Posisi push-up (turun)
    BAHU_KIRI.write(90);
    SIKU_KANAN.write(90);   // Siku kanan ditekuk
    TANGAN_KANAN.write(180); // Tangan kanan ke atas
    SIKU_KIRI.write(90);    // Siku kiri ditekuk
    TANGAN_KIRI.write(0);   // Tangan kiri ke bawah
    delay(500);
  }

  // Mengatur posisi akhir setelah selesai push-up
  BAHU_KIRI.write(180); // Bahu kiri tegak
  SIKU_KIRI.write(90);  // Siku kiri netral
  TANGAN_KIRI.write(0); // Tangan kiri ke bawah

  BAHU_KANAN.write(0);  // Bahu kanan tegak
  SIKU_KANAN.write(90); // Siku kanan netral
  TANGAN_KANAN.write(180); // Tangan kanan ke atas

  Serial.println("Push up selesai bos"); // Memberikan notifikasi melalui serial
  delay(10000); // Delay sebelum mengulang gerakan
}

void loop() {
  ACTION_pushup(); // Memanggil fungsi push-up secara terus-menerus
}
