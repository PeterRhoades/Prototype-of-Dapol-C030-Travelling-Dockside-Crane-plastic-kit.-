
#include  <SPI.h>
#include "RF24.h"
#include <Wire.h>
const byte address[6] = "00009"; //Writing Message Only Pipe:
RF24 radio(7,8);
int msg[1];

void setup() 
 {
  Serial.begin(9600);
  pinMode(A3, INPUT_PULLUP); //Alarm Horn "keeps all the Joystick wire on one side":
  pinMode(6, OUTPUT);
  digitalWrite (6, HIGH); //To Power nRF24 "keeps all the nRF24 wire on one side":
  Wire.begin();
  radio.begin();
  radio.openWritingPipe(address); //Writing Message Only:
 Serial.println();
 Serial.println("Sunday 13/03/22:");
 Serial.println("nRF24_Dapol 3 Servo Joystick Light and Buzz_Master:");
 Serial.println("Folder nRF24_Dapol_3_Servo_Light_and_Buzz_Master:");
 Serial.println();
 Serial.println("nRF Tranciver"); 
 Serial.println("  1 = GRN  Black");   
 Serial.println("  2 = 3.3v Red");
 Serial.println("  3 = CE   Pin 7  Blue");
 Serial.println("  4 = CSN  Pin 8  Green");
 Serial.println("  5 = SCK  Pin 13 Yellow");
 Serial.println("  6 = MOSI Pin 11 White");
 Serial.println("  7 = MISO Pin 12 Orange");
 Serial.println("  8 = UNUSED");
 Serial.println("  _______________________");
 Serial.println("  | 1 | 2 |              |");
 Serial.println("  | 3 | 4 |              |");
 Serial.println("  | 5 | 6 |              |");
 Serial.println("  |_7_|_8_|______________|");
 Serial.println(); 
  Serial.println("Folder nRF24_Dapol_3_Servo_Joystick_Light_and_Buzz_Master:");
  Serial.println("Dapol Crane 3 Digital Servos Full Control...MASTER...");
  Serial.println();
 }

void loop() 
 {
 if (digitalRead(A3) == 0) //Alarm Horn:
 {
  msg[0] = 1;
  Serial.print(digitalRead(4)); Serial.print(" Button Alarm "); Serial.println(msg[0]);
  radio.write(msg, sizeof(msg));
 }
  if (analogRead(A1) > 900)
 {
  Serial.print(analogRead(A1)); Serial.print(" ServoA Cab Left "); Serial.println(msg[0]);
  msg[0] = 2;
  radio.write(msg, sizeof(msg));
 }
 if (analogRead(A1) < 200)
 {
 Serial.print(analogRead(A1)); Serial.print(" ServoA Cab Right "); Serial.println(msg[0]);
 msg[0] = 3;
 radio.write(msg, sizeof(msg));
 }
  if (analogRead(A2) > 520 && analogRead(A2) < 800)
 {
 Serial.print(analogRead(A2)); Serial.print(" ServoB Gib Hook Down "); Serial.println(msg[0]);
 msg[0] = 4;
 radio.write(msg, sizeof(msg)); 
 }
  if (analogRead(A2) < 400 && analogRead(A2) > 150)
 {
 Serial.print(analogRead(A2)); Serial.print(" ServoB Gib Hook Up "); Serial.println(msg[0]);
 msg[0] = 5;
 radio.write(msg, sizeof(msg));  
 }
  if (analogRead(A2) > 800)
 {
 Serial.print(analogRead(A2)); Serial.print(" ServoC Gib Arm Down "); Serial.println(msg[0]);
 msg[0] = 6;
 radio.write(msg, sizeof(msg));
  }
  if (analogRead(A2) < 100)
 {
 Serial.print(analogRead(A2)); Serial.print(" ServoC Gib Arm Up "); Serial.println(msg[0]);
 msg[0] = 7;
 radio.write(msg, sizeof(msg));  
 }
}  
  






  
