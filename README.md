# Simple-Organization

╔══╦╗░░░░░░░░░╔═╗░░░░░░░░░╔╦═╗░░╔╗╔╗░░░░░
║══╬╬══╦═╦╗╔═╗║║╠╦╦═╦═╗╔═╦╬╬═╠═╗║╚╬╬═╦═╦╗
╠══║║║║║╬║╚╣╩╣║║║╔╣╬║╬╚╣║║║║═╣╬╚╣╔╣║╬║║║║
╚══╩╩╩╩╣╔╩═╩═╝╚═╩╝╠╗╠══╩╩═╩╩═╩══╩═╩╩═╩╩═╝
░░░░░░░╚╝░░░░░░░░░╚═╝░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░


An IOT Physical Orgaization and Search Engine for all of your things. 

**Simple Organization** is a Local Internet/Radio Based Network of interfaces that
help organize and keep track of all of your household items. People in the future have jobs based on creativity but if they are not allowed to be creative due to them not being able to find things it makes them very unproductive

## How it Works:
Simple Organization is a Program Based off of Opencart but so much more at the same time.
When A product is seached for and found, Coresponding Adressable LED lights/Neopixels turn
on in the tray/organizer of your chosing around the place where it is supposed to be. This 
system could be implemented into Cabinets, Part Orgaizers and much more.  


### Internet Based:
1. Server With Serch engine and device database
2. Device Query server every 2 seconds 
3. Device turns of Corresponding Light


## Hardware:

### Raspberry Pi Based Client:
Raspberry Pi (Recommend Zero W)
2 Seperate Strips of WS2812, WS2811, or WS2812B LEDS (One Strip is indicator and one is For each Item)
Any Organizer that you want to make smart

### ESP8266 Based Client:
Any ESP8266 With Support, Recommend Node MCU and a battery Backup of Some sort


### Server:
Any System that Supports OpenCart, Wamp/Lamp 
We Reccomend Raspberry Pi 3 - Model B+ 

## Installation:
Please Refer to [Install-Instructions.md](https://github.com/Hopalonger/Simple-Organization/blob/master/Install-Instructions.md) for detailed Instructions.

## Contributing:
Please read the [Wiki Article](https://github.com/Hopalonger/Simple-Organization/wiki/Contributing-Standards:) on Contributing.

## Licence:
### Server Code 
All Code in the `Server ` Folder  is Released under the GNU General Public License version 3 (GPLv3) Due to Opencarts Licencing. 
### Attribution-NonCommercial CC BY-NC
What this means that you are able to remix, tweak, and build upon your work non-commercially, Although new works must acknowledge
that I created the base code and that you are non-commercial, you don't have to use the same license in your works.  
