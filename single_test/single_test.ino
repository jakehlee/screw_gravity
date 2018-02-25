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
  for (int dty = 40; duty <= 80; dty += 5) {
    x = dty_to_analg(40);
  }

  
  x = dty_to_analg(70);
  analogWrite(ha1, x);
  Serial.print("70% duty cycle\n");
  delay(10000);
  analogWrite(ha1, 0);
  Serial.print("0% duty cycle\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
