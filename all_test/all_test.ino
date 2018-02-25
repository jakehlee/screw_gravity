#include <Servo.h>

#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs

int ha1 = 3;
int ha2 = 11;
int ha3 = 10;
int ha4 = 9;
Servo motA, motB;

int dty_to_analg(int dty) {
  int x = int((dty / 100.0) * 255.0);
  return x;
}

void set_all_nosnails(int x) {
  analogWrite(ha1, x);
  analogWrite(ha2, x);
}

void set_all_snails(int x) {
  //motA.writeMicroseconds(x);
  //motB.writeMicroseconds(x);
  analogWrite(ha3, x+15);
  analogWrite(ha4, x+15);
}

void set_all_hals(int x) {
  analogWrite(ha1, x);
  analogWrite(ha2, x);
  delay(800);
  analogWrite(ha3, x+15);
  analogWrite(ha4, x+15);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*
  motA.attach(10, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motB.attach(9, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  */
  int x = dty_to_analg(40);
  int y = dty_to_analg(90);
  /*
  int calib = dty_to_analg(100);
  Serial.print("calib port 10 (yellow)...\n");
  motA.writeMicroseconds(MAX_PULSE_LENGTH);
  delay(5000);
  Serial.print("going null...\n");
  motA.writeMicroseconds(MIN_PULSE_LENGTH);
  delay(3000);
  Serial.print("calib port 9 (green)...\n");
  motB.writeMicroseconds(MAX_PULSE_LENGTH);
  delay(5000);
  Serial.print("going null...\n");
  motB.writeMicroseconds(MIN_PULSE_LENGTH);
  Serial.print("8 more until we start...\n");
  */
  delay(5000);

  
  set_all_nosnails(x);
  /*
  for(int a = 1000; a <= 1600 ; a += 10){
    set_all_snails(a);
    delay(200);
  }
  */
  for(int a = x; a <= y; a += 6){
    set_all_snails(a);
    delay(300);
  }
  
  set_all_hals(y);
  delay(60000);
  set_all_hals(0);
  Serial.print("end\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
