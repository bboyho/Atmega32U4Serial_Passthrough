# Atmega32U4 Serial Passhthrough
This example code passes serial data between an Arduino's serial monitor
 and a device connected to an Atmega32U4's hardware UART (pin 0 and 1).
 Characters sent through the serial monitor will display it back on the
 serial monitor. This code was designed to send serial data from XBees 
 attached to FioV3's XBee sockets. The design of the FioV3's XBee sockets  
 use the hardware UART pins. The Atmega32U4 Serial Passthrough will work
 for other Arduinos with an Atmega32U4 such as the Pro Micro, Arduino 
 Leonardo, and LilyPad Arduino USB. 
 
 For assistance on configuring two XBees, check out Digi's Tutorials:
 
 - XBee Series 1: http://examples.digi.com/get-started/basic-xbee-802-15-4-chat/
 
 - XBee Series 2: http://examples.digi.com/get-started/basic-xbee-zb-zigbee-chat/
