# Simple-Organization

╔══╦╗░░░░░░░░░╔═╗░░░░░░░░░╔╦═╗░░╔╗╔╗░░░░░
║══╬╬══╦═╦╗╔═╗║║╠╦╦═╦═╗╔═╦╬╬═╠═╗║╚╬╬═╦═╦╗
╠══║║║║║╬║╚╣╩╣║║║╔╣╬║╬╚╣║║║║═╣╬╚╣╔╣║╬║║║║
╚══╩╩╩╩╣╔╩═╩═╝╚═╩╝╠╗╠══╩╩═╩╩═╩══╩═╩╩═╩╩═╝
░░░░░░░╚╝░░░░░░░░░╚═╝░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░


An Physical Orgaization and Search Engine for all of your things based off of LoRa, IOT, and Addressable LED's 

**Simple Organization** is a Local Internet/Radio Based Network of interfaces that
help organize and keep track of all of your household items. People in the future have jobs based on creativity but if they are not allowed to be creative due to them not being able to find things it makes them very unproductive

## How it Works:
Simple Organization is a Program Based off of Opencart but so much more at the same time.
When A product is seached for and found, Coresponding Adressable LED lights/Neopixels turn on around the place where it
is supposed to be. There are 2 Basic Ways of trasmiting data, Intnernet and LoRa. The LoRa Method Requires internet 
for the Relay module. This system could be implemented into Cabinets, Part Orgaizers and much more.  


### Internet Based:
1. Server With Serch engine and device database
2. Device Query server every 2 seconds 
3. Device turns of Corresponding Light

### LoRa Based:
1. Server With Serch engine and device database
2. Relay Query server every 2 Seconds
3. Relay Sends all data over LoRa
4. Devices Receive and process turning on corresponding light


## Hardware:
### LoRa Client:
Any Arduino (Recommnend Pro Mini Run at 3v3)
2 Seperate Strips of WS2812, WS2811, or WS2812B LEDS (One Strip is indicator and one is For each Item)
And Any Semtech SX1276/77/78/79

### Relay (LoRa):
Raspberry Pi (Recommend Zero W)
Any Arduino With built in USB (Reccomend A Nano)
Any Semtech SX1276/77/78/79 Soldered to the Arduino

### Internet Based:
Raspberry Pi (Recommend Zero W)
Any Arduino With built in USB (Reccomend A Nano)
2 Seperate Strips of WS2812, WS2811, or WS2812B LEDS (One Strip is indicator and one is For each Item)

### Server:
Any System that Supports OpenCart, Wamp/Lamp 
We Reccomend Raspberry Pi 3 - Model B+ 

## Installation:
Please Refer to [Install-Instructions.md](https://github.com/Hopalonger/Simple-Organization/blob/master/Install-Instructions.md) for detailed Instructions.

## Contributing:
Please read the [Wiki Article](https://github.com/Hopalonger/Simple-Organization/wiki/Contributing-Standards:) on Contributing.

## Licence:
### Attribution-NonCommercial CC BY-NC
What this means that you are able to remix, tweak, and build upon your work non-commercially, Although new works must acknowledge
that I created the base code and that you are non-commercial, you don't have to use the same license in your works.  
