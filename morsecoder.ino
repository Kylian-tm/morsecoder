#include "morse.h"

void setup(){
  //serial
  Serial.begin(9600);
  Serial.println("starting...");

  //piezo
  pinMode(piezo, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    //reading and printing
    morse::incoming = Serial.read();
    Serial.println(morse::incoming);

    //decoding text to morse
    morse::decodeMorse();
  }
}
