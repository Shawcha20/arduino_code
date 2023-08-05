
//edison science corner

#include <QTRSensors.h>
QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
float Kp = 0.4; 
float Ki = 0;
float Kd =0;
int P;
int I;
int D;
int lastError = 0;
boolean onoff = false;

const uint8_t maxspeeda = 250;
const uint8_t maxspeedb = 250;
const uint8_t basespeeda = 100;
const uint8_t basespeedb = 100;


#define PWM1 9
#define PWM2 3
#define A11 7
#define A12 8
#define B11 5
#define B12 4

int buttoncalibrate = 17;//pin A3
int buttonstart = 2;

void setup() {
  Serial.begin(9600);
 
 qtr.setTypeRC();
qtr.setSensorPins((const uint8_t[]){11, 10,A0, A1, A2, A3, A4, A5}, SensorCount);

  qtr.setEmitterPin(-1);//LEDON PIN
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(A0,INPUT);
  pinMode(A1, INPUT);
  pinMode(A2,INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT); 
  pinMode(A5,INPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(A11, OUTPUT);
   pinMode(A12, OUTPUT);
  pinMode(B11, OUTPUT);
   pinMode(B12, OUTPUT);
 // delay(500);
 // pinMode(LED_BUILTIN, OUTPUT);

  boolean Ok = false;
  while (Ok == false) { 
    //if(digitalRead(buttoncalibrate) == HIGH) {
      calibration(); 
      Ok = true;
  // }
  }
  //forward_brake(0, 0);
}

void calibration() {
  digitalWrite(13, HIGH);
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(13, LOW);
}

void loop() {
  uint16_t position = qtr.readLineBlack(sensorValues);
  Serial.println(position);
  // if(digitalRead(buttonstart) == HIGH) {
  //   onoff =! onoff;
  //   if(onoff = true) {
  //     delay(1000);
  //   }
  //   else {
  //     delay(50);
  //   }
  // }
  // if (onoff == true) {
    if(digitalRead(10)&&digitalRead(11)&&digitalRead(A0)&& digitalRead(A1)&&digitalRead(A2)&&digitalRead(A3)&&digitalRead(A4)&&digitalRead(A5))
    {
      forward_brake(0, 0);
    }
    else if(position==3500)
{
  forward_brake(200, 200);
}
    else
   PID_control();
  // }
  // else {
  //   forward_brake(0,0);
  // }
}
void forward_brake(int posa, int posb) {
  analogWrite(PWM1, posa);
  analogWrite(PWM2, posb);
  digitalWrite(A11, HIGH);
  digitalWrite(B11, HIGH);
 
}
void PID_control() {
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = 3500 - position;

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorspeed = P*Kp + I*Ki + D*Kd;
  
  int motorspeeda = basespeeda + motorspeed;
  int motorspeedb = basespeedb - motorspeed;
  
  if (motorspeeda > maxspeeda) {
    motorspeeda = maxspeeda;
  }
  if (motorspeedb > maxspeedb) {
    motorspeedb = maxspeedb;
  }
  if (motorspeeda < 0) {
    motorspeeda = 0;
  }
  if (motorspeedb < 0) {
    motorspeedb = 0;
  } 
  forward_brake(motorspeeda, motorspeedb);
}
