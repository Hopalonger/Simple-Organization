# Install Instructions:
## Install Instructions For Server:
1. Clone the Repository to your computer with the `git clone https://github.com/Hopalonger/Simple-Organization.git` Command
2. Navigate to the Server Directory with the command `cd Simple-Organization/Server`
3. Run the install Script with `bash install.sh`. This could take a while Go Watch a Movie and Come back
4. In The Terminal Enter Command `sudo mysql -uroot -p` .
5. You will be promted With a Return that looks like this `mysql>` Enter `create database YOURDATABASENAME;`.
6. Then Enter ` GRANT ALL ON YOURDATABASENAME.* TO 'YOURUSER'@'localhost' IDENTIFIED BY 'YOURPASSWORD';`
7. Next run ` GRANT ALL PRIVILEGES ON *.* TO 'YOURUSER'@'localhost' IDENTIFIED BY 'YOURPASSWORD';`
7. Finally Enter '`quit`.
8. Navigate to the Web Site hosted on the Device.
9.Complete the installation through the web pages. Once the installation is complete remove the install directory.
10. Finally Type 'cd opencart/upload' Then ' rm -rf install'
11. Do a Final Reboot of the server. Everything Should be Working from then on. 
12. Create A Static IP Address for the PI.
12. You will be promted to move the storage you have to manualy do this with this command `sudo mv /var/www/html/system/storage/ /var/www/storage/`

## Install Instructions For ESP8266/Node MCU:
1. Clone the respository to an accessable place with either the `git clone` command or ZIP download. 
2. Open the Code in the Arduiono IDE.
3. Install the ESP8266 Board Manager.
4. Install the `Wifimanager`and `Adafruit_Neopixels`.
5. In the `Tools` Tab Select the correct Board and port for the the device.
6. Go to The lines that start with `#Define` then edit any of the values on the end.
7. Next you need to create a new unique device code for the `String Code` line.
8. Then Change the `IPString` String to be the IP address of the Raspberry PI.
9. Upload the Code to the Arduino with the upload button in the top left.
10. To start Wiring you can get Custom PCB's Ordered that connect to the Node MCU or Connnect it with basic soldering
11. Connect The Indicator Strips Data in to `D1` And the Main Strips Data in to `D8`, use Detachable connecters if possible.
12. Connect VCC of the LED Strip to a `3v3` Pin on the Node MCU
13. Connect The `NO` Side of a switch to Your Interupt Pin, and Connect Common or `C` to a `3v3` Pin on the Node MCU
14. Connect GND from both Strips to `GND` Pins on the Node MCU
15. Connect power source for the Node MCU such as  Batterys, Powersupply, ect.

## Install Instructions For Raspberry Pi:
1. Clone the Repository to your computer with the `git clone https://github.com/Hopalonger/Simple-Organization.git` Command.
2. Navigate to the Server Directory with the command `cd Simple-Organization/RaspberryPI`.
3. Run the install Script with `bash install.sh`.
4. Connect The Neopixels to the Raspberry Pi( They dont Need a logic converter. Run data and power at 3v3) .
5. Run the command `sudo reboot`.
6. All finished.
7. Change All of the settings on the top of the script for the Set that you are planning on using. 
8. To start Wiring you can get Custom PCB's Ordered that connect to the Raspberry PI or Connnect it with basic soldering
9. Connect The Indicator Strips Data in to Pin `18` And the Main Strips Data in to Pin `16`, use Detachable connecters if possable.
10. Connect VCC of the Strips to the Normaly Closes Side of a Push Switch So that they can be turned off
11. Connect the common terminal of the switch to a `3v3` Pin on the Raspberry PI
12. Connect GND from both Strips to `GND` Pins on the Raspberry Pi
13. Connect power source for the Raspberry Pi such as  Batterys, Powersupply, ect.

