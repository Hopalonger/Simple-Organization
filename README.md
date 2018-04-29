# Simple-Organization
A IOT and LoRa based Organization and search Engine for all of your things

**Simple Organization** is a Local Internet/Radio Based Network of interfaces that
helps organize and keep track of all of your household items. People in the 
future have jobs based off creativity but if they are not allowd to be creative
due to them not being able to find things it makes them very unprotuctive.

## How it Works
Simple Organization is a Program Based off of Opencart but so much more at the same time.
The Program works by when a person checksout throuh opencart the devices check if they are
the Client that is being reqested for. If they are the client then they turn the light on.
The way that a client can check on the server is A thorugh the Internet (Wifi, Ethernet, ETC).
The Client can also connect over LoRa and a Repeater based system. This LoRa System Can me run
with less power and is better for things that might get moved around or be used in a portable
application.
### Internet Based
1. Server With Serch engine and device database
2. Device Querys server very 2 seconds 
3. Device turns of Coressponding Light

### Hybrid
1. Server With Serch engine and device database
2. Relay Querys server every 2 Seconds
3. Relay Sends all data over LoRa
4. Devices Recive and proccess turning on coresponding light


## Hardware
### LoRa Client:
Any Arduino With Support for *Arduino-LoRa Libary, Audafruit Neopixel libray*  and accompanying hardware.

### Internet Based
Raspberry Pi With a Arduino Nano to control the Addressable LEDs. 

### Internet Based Server
Raspberry Pi 3 b+ Recommened but any linux Computer will work.
