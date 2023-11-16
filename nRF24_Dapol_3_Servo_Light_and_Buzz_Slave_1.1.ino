
#include <Servo.h>
#include  <SPI.h>
#include "RF24.h"
Servo myservoA;     
Servo myservoB; // Create  3 servo object to control a servo A,B,C:
Servo myservoC;
int cr = 1420; //ServoA Cab Right
int cl = 1534; //ServoA Cab Left
int hu = 1350; //ServoB Gib Hook Up 1350
int hd = 1620; //ServoB Gib Hook Down
int gu = 1350; //ServoB Gib Arm Up
int gd = 1660; //ServoB Gib Arm Down 
const int LEDpin = A3;
int LEDState =HIGH;
int Horn = 9;
const long onDuration = 300;// ON time for LED
const long offDuration = 100;// OFF time for LED
long rememberTime=0;
int msg[1];
RF24 radio(7,8);
const byte address[6] = "00009";


void setup() {
  Serial.begin(9600);//  setup serial
  radio.begin();
  radio.openReadingPipe(1,address);
  radio.startListening(); 
Serial.println();
Serial.println("Sunday 13/03/22:");
Serial.println("nRF24_Dapol 3 Servo Joystick Light and Buzz_Slave:");
Serial.println("Folder nRF24_Dapol_3_Servo_Light_and_Buzz_Slave:");
Serial.println("Saturday 26/03/22: Working on NANO using ATmega328P(Old Bootloades)");
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
  pinMode (LEDpin, OUTPUT);
  pinMode (Horn, OUTPUT);
  digitalWrite(LEDpin,LEDState);// set initial state
  myservoA.attach(6);  
  myservoB.attach(5);// attaches the servos A,B,C on pin's 6,5,3
  myservoC.attach(3);
  myservoA.writeMicroseconds(1500);  
  myservoB.writeMicroseconds(1500);  // set servos to stall-point
  myservoC.writeMicroseconds(1500); 
  Serial.println("Folder nRF24_Dapol_3_Servo_Light_and_Buzz_Slave:"); 
  Serial.println("Dapol Crane 3 Digital Servos Full Control...SLAVE...");
  Serial.println();
}

void loop() 
{
 radio.read(msg, sizeof(msg));
  
  if (msg[0] == 1)
 {
 Serial.print(" Button Alarm "); Serial.println(msg[0]);
 tone(Horn, 460, 100);
 }
  if (msg[0] == 2)
 {
 myservoA.writeMicroseconds(cl);
 Serial.print(" ServoA Cab Left "); Serial.println(msg[0]);
      delay(50);
      }else{
 myservoB.writeMicroseconds(1500);
 myservoC.writeMicroseconds(1500);
 msg[0] == 0;
 }
  if (msg[0] == 3)
 {
 myservoA.writeMicroseconds(cr);
 Serial.print(" ServoA Cab Right "); Serial.println(msg[0]);
      delay(50);
      }else{
 myservoB.writeMicroseconds(1500);
 myservoC.writeMicroseconds(1500);
 msg[0] == 0;
 }
  if (msg[0] == 4 )
 {
 myservoB.writeMicroseconds(hu);
 Serial.print(" ServoB Gib Hook Down "); Serial.println(msg[0]);
      delay(50);
      }else{
 myservoA.writeMicroseconds(1500);
 myservoC.writeMicroseconds(1500);
 msg[0] == 0;
 }
  if (msg[0] == 5)
 {
 myservoB.writeMicroseconds(hd);
 Serial.print(" ServoB Gib Hook Up "); Serial.println(msg[0]);
      delay(50);
      }else{
 myservoA.writeMicroseconds(1500);
 myservoC.writeMicroseconds(1500);
 msg[0] == 0;
 }
  if (msg[0] == 6)
 {
 myservoC.writeMicroseconds(gd);
 Serial.print(" ServoC Gib Arm Down "); Serial.println(msg[0]);
      delay(50);
      }else{
 myservoA.writeMicroseconds(1500);
 myservoB.writeMicroseconds(1500);
 msg[0] == 0;
 }
  if (msg[0] == 7)
 {
 myservoC.writeMicroseconds(gu);
 Serial.print(" ServoC Gib Arm Up "); Serial.println(msg[0]);
      delay(50);
      }else{
 myservoA.writeMicroseconds(1500);
 myservoB.writeMicroseconds(1500);
 msg[0] == 0;
 }
  if( LEDState ==HIGH )
 {
  if( (millis()- rememberTime) >= onDuration){   
 LEDState = LOW;// change the state of LED
 rememberTime=millis();// remember Current millis() time
 }
 }else{   
 if( (millis()- rememberTime) >= offDuration){     
 LEDState = HIGH;// change the state of LED
 rememberTime=millis();// remember Current millis() time
 }
 }
 digitalWrite(LEDpin,LEDState);// turn the LED ON or OFF
}
  






  
