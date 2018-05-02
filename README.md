# Simple-Organization
╔══╦╗░░░░░░░░░╔═╗░░░░░░░░░╔╦═╗░░╔╗╔╗░░░░░
║══╬╬══╦═╦╗╔═╗║║╠╦╦═╦═╗╔═╦╬╬═╠═╗║╚╬╬═╦═╦╗
╠══║║║║║╬║╚╣╩╣║║║╔╣╬║╬╚╣║║║║═╣╬╚╣╔╣║╬║║║║
╚══╩╩╩╩╣╔╩═╩═╝╚═╩╝╠╗╠══╩╩═╩╩═╩══╩═╩╩═╩╩═╝
░░░░░░░╚╝░░░░░░░░░╚═╝░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

An IOT and LoRa based Organization and Search Engine for all of your things

**Simple Organization** is a Local Internet/Radio Based Network of interfaces that
help organize and keep track of all of your household items. People in the future have jobs based on creativity but if they are not allowed to be creative due to them not being able to find things it makes them very unproductive.

## How it Works
Simple Organization is a Program Based off of Opencart but so much more at the same time.
The Program works by when a person checks out through Opencart the devices check if they are
the Client that is being requested for. If they are the client then they turn the light on.
The way that a client can check on the server is A through the Internet (Wifi, Ethernet, ETC).
The Client can also connect over LoRa and a Repeater based system. This LoRa System Can me run
with less power and is better for things that might get moved around or be used in a portable
application.
### Internet Based
1. Server With Serch engine and device database
2. Device Query server every 2 seconds 
3. Device turns of Corresponding Light

### Hybrid
1. Server With Serch engine and device database
2. Relay Query server every 2 Seconds
3. Relay Sends all data over LoRa
4. Devices Receive and process turning on corresponding light


## Hardware
### LoRa Client:
Any Arduino With Support for *Arduino-LoRa Libary, Audafruit Neopixel libray*  and accompanying hardware.

### Internet Based
Raspberry Pi With an Arduino Nano to control the Addressable LEDs. 

### Internet Based Server
Raspberry Pi 3 b+ Recommended but any Linux Computer will work.

## Installation
### Server
Run The Install.sh Script in The Server Folder

### LoRa Client: 
Upload the Client.ino from LoRa to The Arduino Of Choice. 
Connect to LoRa Module According to this diagram

| Semtech SX1276/77/78/79 | Arduino |
| :---------------------: | :------:|
| VCC | 3.3V |
| GND | GND |
| SCK | SCK |
| MISO | MISO |
| MOSI | MOSI |
| NSS | 10 |
| NRESET | 9 |
| DIO0 | 2 |

### Internet Client
Upload Slave.ino to the Arduino. Then Run The Install.sh Script Under Internet

### LoRa Relay
Upload The Repeater.ino to the Arduino. Then Run The Install.sh Script Under Internet

## Licence
### Attribution-NonCommercial CC BY-NC
What this means that you are able to remix, tweak, and build upon your work non-commercially, Although new works must acknowledge
that I created the base code and that you are non-commercial, you don't have to use the same license in your works.  
