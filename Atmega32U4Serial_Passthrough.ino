/*Atmega32U4Serial_Passthrough.ino
 Modified by: Ho Yun "Bobby" Chan
 By: Jim Lindblom
 @ SparkFun Electronics Inc.
 on July 5th, 2016
 
 license: Public Domain - please use this code however you'd like.
 It's provided as a learning tool.
 
 This example code passes serial data between an Arduino's serial monitor
 and a device connected to an Atmega32U4's hardware UART (pin 0 and 1).
 Characters sent through the serial monitor will display it back on the
 serial monitor. This code was designed to send serial data from XBees 
 attached to FioV3's XBee sockets. The design of the FioV3's XBee sockets  
 use the hardware UART pins. The Atmega32U4 Serial Passthrough will work
 for other Arduinos with an Atmega32U4 such as the Pro Micro, Arduino 
 Leonardo, and LilyPad Arduino USB. 
 
 For assistance on configuring two XBees, check out Digi's Tutorials:
 XBee Series 1: http://examples.digi.com/get-started/basic-xbee-802-15-4-chat/
 XBee Series 2: http://examples.digi.com/get-started/basic-xbee-zb-zigbee-chat/
 */

char val; //init global var for serial characters being sent from XBee

void setup()
{

  Serial.begin(9600); //Set up serial monitor
  Serial1.begin(9600); //Set up hardware UART to pipe data from the XBee

}

void loop()
{

  if (Serial.available())
  {
    //If data comes in from serial monitor:
    //1.) echo the character back to the serial monitor
    //2.) send it to hardware UART.

    val  = Serial.read(); //save character from Arduino's buffer to a variable

    Serial.print(val); //display serial data back on the Arduino's serial monitor
    Serial1.write(val); //send serial data to Atmega32U4's hardware UART
  }

  if (Serial1.available())
  { // If data comes in from XBee connected to hardware UART,
    //display it on the serial monitor
    Serial.write(Serial1.read());//display serial data received from 
  }

}
