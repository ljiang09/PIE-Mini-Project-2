
//      ******************************************************************
//      *                                                                *
//      *                                                                *
//      *     Example Arduino program that transmits data to a laptop    *
//      *                                                                *
//      *                                                                *
//      ******************************************************************


//
// setup function to initialize hardware and software
//

#include <Servo.h>
Servo servo1;
int pos = 0;


void setup()
{ 
  //
  // start the serial port
  //
  long baudRate = 115200;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication

  servo1.attach(3);
}

//
// main loop
//
void loop() 
{  
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15 ms for the servo to reach the position
    }
    //
    // delay after sending data so the serial connection is not over run
    //
    delay(400);
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15 ms for the servo to reach the position
    }
   
}



