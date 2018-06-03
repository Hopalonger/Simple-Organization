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




