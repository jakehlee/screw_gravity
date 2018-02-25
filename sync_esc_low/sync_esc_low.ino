#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
Servo motA;
int data;
int ha1 = 3;
int ha2 = 9;

int dty_to_analg(int dty) {
  int x = int((dty / 100.0) * 255.0);
  return x;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int x = dty_to_analg(40);
  int y = x+10;
  analogWrite(ha1, x);
  analogWrite(ha2, y);
  delay(3000);
  x = dty_to_analg(50);
  y = x+25;
  analogWrite(ha1, x);
  delay(10000);
  analogWrite(ha1, 0);
  analogWrite(ha2, y);
  delay(10000);
  analogWrite(ha2, 0);
  analogWrite(ha1, 0);
  analogWrite(ha2, 0);
}

void loop() {

}
