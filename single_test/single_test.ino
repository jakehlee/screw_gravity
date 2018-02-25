int ha1 = 11;

int dty_to_analg(int dty) {
  int x = int((dty / 100.0) * 255.0);
  return x;
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  int x = dty_to_analg(0);
  Serial.print("0% duty cycle\n");
  analogWrite(ha1, x);
  delay(5000);
  /*
  x = dty_to_analg(80);
  Serial.print("100% duty cycle\n");
  analogWrite(ha1, x);
  delay(10000);
  x = dty_to_analg(20);
  Serial.print("10% duty cycle\n");
  analogWrite(ha1, x);
  delay(5000);
  x = dty_to_analg(80);
  Serial.print("100% duty cycle\n");
  analogWrite(ha1, x);
  delay(5000);
  */
  
  for (int dty = 0; dty <= 100; dty += 1) {
    int x = dty_to_analg(dty);
    analogWrite(ha1, x);
    delay(20);
    Serial.print("duty cycle = " + String(dty) + "\n");
  }
  delay(10000);
  


  
  for (int dty = 100; dty >= 0; dty -= 1) {
    int x = dty_to_analg(dty);
    analogWrite(ha1, x);
    delay(20);
    Serial.print("duty cycle = " + String(dty) + "\n");
  }
  for (int dty = 0; dty <= 100; dty += 1) {
    int x = dty_to_analg(dty);
    analogWrite(ha1, x);
    delay(20);
    Serial.print("duty cycle = " + String(dty) + "\n");
  }
  for (int dty = 100; dty >= 0; dty -= 1) {
    int x = dty_to_analg(dty);
    analogWrite(ha1, x);
    delay(20);
    Serial.print("duty cycle = " + String(dty) + "\n");
  }
  x = dty_to_analg(50);
  analogWrite(ha1, x);
  delay(10000);
  
  analogWrite(ha1, 0);
  Serial.print("end\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
