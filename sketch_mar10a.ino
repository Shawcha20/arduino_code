void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(analogRead(A0));
Serial.print(" " );
Serial.print(analogRead(A1));
Serial.print(" ");
Serial.print(analogRead(A2));
Serial.print(" ");
Serial.println(analogRead(A3));
delay(500);

}
