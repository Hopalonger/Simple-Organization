print "[+] Installing updates"
sudo apt update -y
print "[+] Installing upgrades"
sudo apt upgrade -y 
print "[+] Installing updates
sudo apt update -y 
print "[+] Installing Webserver"
sudo apt -y  install apache2
sudo apt -y  install php php-mbstring
sudo apt -y  install mysql-server php-mysql
sudo apt-get install php5-curl
sudo apt-get -y install git 
sudo apt-get -y install avahi-utils
print "[+] Installing Website"
sudo rm /var/www/html/index.html 
git clone https://github.com/Hopalonger/opencart.git 
sudo cp -r opencart/upload /var/www/
sudo rm /var/www/html
mv /var/www/upload /var/www/html


sudo cp /var/www/html/admin/config-dist.php /var/www/html/admin/config.php
sudo cp /var/www/html/config-dist.php /var/www/html/config.php
sudo chmod 777 -R /var/www/html/opencart
rm /var/www/html/admin/config-dist.php
rm /var/www/html/config-dist.php
sudo rm -r opencart
// Setting To Run At Startup 
print "[+] Setting Auto Start Run"
sudo update-rc.d Simple-Organization/Server/Start.sh defaults
chmod +x Simple-Organization/Server/Start.sh
print "Create Database and remove install. Once Completed Restart"

