#include <Adafruit_NeoPixel.h>  

// Code Found Here: https://www.hackster.io/FunguyPro/the-complete-neopixel-guide-18374f

#define PIN 3 // the pin your strip is connected to 
#define COUNT 36 // how many led's are on that strip  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(COUNT, PIN, NEO_GRB + NEO_KHZ800); //defines the strips properties  
int R; 
int G; 
int B;  
void setColor(int Pixel, int R2, int G2, int B2) {
uint32_t color = strip.Color(R2, G2, B2); // make a color   
strip.setPixelColor(Pixel, color); //set a single pixel color   
strip.show(); //update the colors
}   
void doShow() {
for (int i = 0; i < COUNT; i++) {
setColor(i, 0, 0, 0);   
}   
for (int i = 0; i < COUNT; i++) {
setColor(i, 255, 0, 0); //turn all to red
delay(50);   
}   
for (int i = 0; i < COUNT; i++) {
setColor(i, 0, 255, 0); //turn all to blue
delay(50);   
}   
for (int i = 0; i < COUNT; i++) {
setColor(i, 0, 0, 255); //turn all to green
delay(50);   
}   
for (int i = 0; i < COUNT; i++) {
setColor(i, 255, 247, 0); //turn all to yellow
delay(50);   
}
for (int i = 0; i < COUNT; i++) {
setColor(i, 255, 100, 0); //turn all to orange
delay(50);   
}   
for (int i = 0; i < COUNT; i++) {
setColor(i, 255, 0, 205); //turn all to purple
delay(50);   
}
for (int i = 0; i < COUNT; i++) {
setColor(i, 0, 213, 255); //turn all to turquoise
delay(50);   
}   
if (Serial.available() < 0) {
doShow();   
} 
}  
void Indicator() {
  count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 0, 0, 0);
    count++;
  }

}
void setup() {
strip.begin(); // start the strip
strip.show(); // set the strip to black (because we havent told it to do anything yet)
Serial.begin(9600);
Serial.println("ready to change color"); 
}
void loop() {
if (Serial.available() > 0) { // if bytes are available through the serial port     
char c = Serial.read(); //read the first byte
if (c == 'R') {
R = Serial.parseInt(); //get the INT     
}
if (c == 'G') {
G = Serial.parseInt(); //get the INT     
}
if (c == 'B') {
B = Serial.parseInt(); //get the INT     
}
if (c == 'P') {
setColor(Serial.parseInt(), R, G, B);
Indicator();
}
if (c == 'S') {
doShow();
}
}
}
