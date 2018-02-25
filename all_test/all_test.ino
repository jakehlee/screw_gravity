int ha1 = 3;
int ha2 = 10;
int ha3 = 11;

int dty_to_analg(int dty) {
  int x = int((dty / 100.0) * 255.0);
  return x;
}

void set_all_has(int x) {
  analogWrite(ha1, x);
  analogWrite(ha2, x);
  analogWrite(ha3, x);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // put your setup code here, to run once:
  int x = dty_to_analg(40);
  Serial.print("40% duty cycle\n");
  set_all_has(x);
  delay(2000);
  for (int dty = 40; dty <= 70; dty += 1) {
    x = dty_to_analg(dty);
    set_all_has(x);
    delay(1000);
    Serial.print("duty cycle = " + String(dty) + "\n");
  }
  set_all_has(0);
  Serial.print("end\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
