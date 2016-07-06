/*Atmega32U4Serial_Passthrough.ino
 by Ho Yun "Bobby" Chan
 @ SparkFun Electronics Inc.
 
 This example code passes serial data between an Arduino's serial monitor
 and a device connected to an Atmega32U4's hardware UART (pin 0 and 1).
 Characters sent through the serial monitor will display it back on the
 serial monitor.  This code was designed for an XBee connected to the
 FioV3's XBee sockets. The design of the FioV3's XBee sockets use the 
 hardware UART pins. The Atmega32U4 Serial Passthrough will work for other
 Arduinos with an Atmega32U4 such as the Pro Micro, Arduino Leonardo, and
 LilyPad Arduino USB.*/

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
