int ha1 = 9;

int dty_to_analg(int dty) {
  int x = int((dty / 100.0) * 255.0);
  return x;
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  int x = dty_to_analg(40);
  Serial.print("40% duty cycle\n");
  analogWrite(ha1, x);
  delay(5000);
  for (int dty = 40; dty <= 90; dty += 1) {
    x = dty_to_analg(dty);
    analogWrite(ha1, x);
    delay(200);
    Serial.print("duty cycle = " + String(dty) + "\n");
  }
  analogWrite(ha1, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
