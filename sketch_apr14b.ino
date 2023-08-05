#include <U8g2lib.h>

// Define the OLED display object.
U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C display(U8G2_R0, /* clock=*/ 2, /* data=*/ 12, /* reset=*/ U8X8_PIN_NONE);
#define push 6
void setup() {
  // Initialize the OLED display.
  display.begin();
  pinMode(push,INPUT);
  // Clear the display buffer.
 
  pinMode(13,OUTPUT);
}

void loop() {

  if(digitalRead(push)==LOW){
  // Draw some text.
   display.clearBuffer();
  display.setFont(u8g2_font_ncenB14_tr);
  display.drawStr(10, 20, "WELCOME TO PID LFR");
   display.sendBuffer();
   digitalWrite(13,HIGH);
  }
  else {
     display.clearBuffer();
    display.setFont(u8g2_font_ncenB14_tr);
    display.drawStr(5, 15 ,"1.Calibrate");
    display.drawStr(5,30,"2.Change pid value");
     display.sendBuffer();
     digitalWrite(13,LOW);}
  // Send the buffer to the display.
 
}
