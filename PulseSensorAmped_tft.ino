/*
 Pulse Sensor Amped + 2.2" TFT
 www.bajdi.com 
*/
#include "SPI.h"


#define _sclk 13
#define _miso 12
#define _mosi 11
#define _cs 10
#define _rst 9
#define _dc 8

//  VARIABLES
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

void setup(){
  //Start the TFT screen and paint it black
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS  
}

void loop(){
  
  if (QS == true){                       // Quantified Self flag is true when arduino finds a heartbeat
    Serial.print("BPM = ");
    Serial.println(BPM);   

    QS = false;  // reset the Quantified Self flag for next time    
  }
}











