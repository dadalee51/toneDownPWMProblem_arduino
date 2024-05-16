#include <Arduino.h>
void show_RGB(long val);
void setup() {
  pinMode(PIN_PA3, OUTPUT);
  pinMode(PIN_PB4, OUTPUT);
  pinMode(PIN_PB5, OUTPUT);
  show_RGB(0xFFFFFF); 
}
int data=0;
void loop() {  
    if(data>0xFE)data=0;
    data+=20;
    show_RGB(data<<16 | 0xFFFF); 
    delay(10);
    show_RGB(data<<8 | 0xFF00FF); 
    delay(10);
    show_RGB(data | 0xFFFF00); 
    delay(10);
}
void show_RGB(long val){
    analogWrite(PIN_PA3,(val>>16) & 0xFF);
    analogWrite(PIN_PB4,(val>>8)  & 0xFF);
    analogWrite(PIN_PB5,val       & 0xFF);
}
