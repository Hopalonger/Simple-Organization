
sudo apt update -y
sudo apt upgrade -y 
sudo apt update -y 
sudo apt -y  install apache2
sudo apt -y  install php php-mbstring
sudo apt -y  install mysql-server php-mysql
sudo apt-get install php5-curl
sudo apt-get -y install git 
sudo apt-get -y install avahi-utils
git clone https://github.com/Hopalonger/opencart.git 
sudo cp master.zip /var/www/html/
sudo cd /var/www/html
sudo unzip master.zip
sudo cd opencart-master
sudo mv -v upload/* ../opencart-master/\
sudo cp /var/www/html/opencart-master/admin/config-dist.php /var/www/html/opencart-master/admin/config.php
sudo cp /var/www/html/opencart-master/config-dist.php /var/www/html/opencart-master/config.php
sudo chmod 777 -R /var/www/html/opencart-master 
// Update This When ISO Done
sudo sed -i '/SearchPattern/aNew python /home/pi/myscript.py &' /etc/rc.local
print "Create Database and remove install"
echo  "Run Start.sh When done. It has A Gui or Reboot "
