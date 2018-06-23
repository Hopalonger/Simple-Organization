echo "[+] Installing updates"
sudo apt update -y
echo "[+] Installing upgrades"
sudo apt upgrade -y 
echo "[+] Installing updates
sudo apt update -y 
echo "[+] Installing Webserver"
sudo apt-get install php7.0-curl
sudo apt-get install mysql-server --fix-missing
sudo apt-get install mysql-client php7.0-mysql
sudo apt-get install libapache2-mod-php5
sudo apt -y  install apache2
sudo apt -y  install php php-mbstring
sudo apt -y  install mysql-server php-mysql
sudo apt-get install php5-curl
sudo apt-get install curl
sudo apt-get -y install git 
sudo apt-get -y install avahi-utils
sudo apt-get -y install php-zip
sudo apt-get -y install php7.0-gd
sudo service apache2 restart
echo "[+] Installing Website"
sudo rm /var/www/html/index.html 
git clone https://github.com/Hopalonger/opencart.git 
sudo cp -r opencart/upload /var/www/
sudo rm -r /var/www/html
sudo mv /var/www/upload /var/www/html
sudo rm -r opencart
sudo ln -s /usr/share/phpmyadmin /var/www/html
sudo mv /var/www/html/admin/config-dist.php /var/www/html/admin/config.php
sudo mv /var/www/html/config-dist.php /var/www/html/config.php
sudo chmod 777 -R /var/www/html/
sudo /etc/init.d/apache2 restart
// Setting To Run At Startup 
echo "[+] Setting Auto Start Run"
sudo update-rc.d Simple-Organization/Server/Start.sh defaults
chmod +x Simple-Organization/Server/Start.sh
echo "Create Database and remove install. Once Completed Restart"
echo "Run sudo apt-get install phpmyadmin , Then Restart Apache"
