# Install Instructions:
## Install Instructions For Server:
1. Clone the Repository to your computer with the `git clone https://github.com/Hopalonger/Simple-Organization.git` Command
2. Navigate to the Server Directory with the command `cd Simple-Organization/Server`
3. Run the install Script with `bash install.sh`
4. In The Terminal Enter Command `mysql -uroot -p` .
5. You will be promted With a Return that looks like this `mysql>` Enter `create database YOURDATABASENAME;`.
6. Then Enter ` GRANT ALL ON YOURDATABASENAME.* TO 'YOURUSER'@'localhost' IDENTIFIED BY 'YOURPASSWORD';`.
7. Finally Enter '`quit`.
8. Navigate to the Web Site hosted on the Device.
9.Complete the installation through the web pages. Once the installation is complete remove the install directory.
10. Finally Type 'cd opencart/upload' Then ' rm -rf install'
11. Do a Final Reboot of the server. Everything Should be Working from then on. 

## Install Instructions for LoRa Client
1. Donwload and Install the Arduino IDE for you Computer Platform and Down Load the Repository. 
2. Plug Arduino Of Choice into Computer (Arduino Pro Mini Recommened)
3. Open The Code That is in the in the CLient Code folder of LoRa. 
4. Install the used Libarys Which include `Arduino-LoRa` and `Adafruit_NeoPixel`.
5 Change Any of The Varibles that Are in the top Or Middle of the Code.
6 Select The COM port that the Arduino Corresponds to in the Tools Tab.
7 Hit the Upload Button in the top left. (The Arrow to the Left).
8 Attach the LoRa Module to the Arduino Based off Diagram Below.

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

9.Connect Your Choice of Addressable LEDS to the Arduino on the Pins Selected in the Code.
10. Power Up the Device on a 3.3v Power Source. Do Not use 5v, LoRa Boards Do Not Use 5v.

## Install Instructions for the LoRa Repeater

1. Donwload and Install the Arduino IDE for you Computer Platform and Download the Repository. 
2. Plug Arduino Of Choice into Computer (Arduino Pro Mini Recommened)
3. Open The Code That is in the in the `Repeater-Code` folder of LoRa. 
4. Install the used Libarys Which include `Arduino-LoRa` and `Adafruit_NeoPixel`.
5 Change Any of The Varibles that Are in the top Or Middle of the Code.
6 Select The COM port that the Arduino Corresponds to in the Tools Tab.
7 Hit the Upload Button in the top left. (The Arrow to the Left).
8 Attach the LoRa Module to the Arduino Based off Diagram Below.

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

9. Connect A FTDI USB to Serial Connverter to the Corresponding Pins of the Arduino pro mini
10. Connect the FTDI USB to Serial Converter to the Raspberry Pi with a USB cable
11. Clone the Repository to your computer with the `git clone https://github.com/Hopalonger/Simple-Organization.git` Command
12. Navigate to the LoRa Repeater Folder With `cd Simple-Organization/LoRa/Repeater-Code/RaspberryPi`
13. Run the Install.sh Script with `sudo bash install.sh`
14. Reboot Device 
15. The Device Should be Working
