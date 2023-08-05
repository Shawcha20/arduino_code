void setup() {
  // put your setup code here, to run once:
pinMode(10, INPUT);
pinMode(11, INPUT);
pinMode(A0,INPUT);
pinMode(A1, INPUT);
pinMode(A2,INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(A5,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(digitalRead(11));
Serial.print(" ");
Serial.print(digitalRead(10));
Serial.print(" ");
Serial.print(digitalRead(A0));
Serial.print(" ");
Serial.print(digitalRead(A1));
Serial.print(" ");
Serial.print(digitalRead(A2));
Serial.print(" ");
Serial.print(digitalRead(A3));
Serial.print(" ");
Serial.print(digitalRead(A4));
Serial.print(" ");
Serial.println(digitalRead(A5));
delay(500);
}
