
sudo apt update -y
sudo apt upgrade -y 
sudo apt update -y 
sudo apt -y  install apache2
sudo apt -y  install php php-mbstring
sudo apt -y  install mysql-server php-mysql
sudo apt-get install php5-curl
wget https://github.com/opencart/opencart/archive/master.zip
sudo cp master.zip /var/www/html/
sudo cd /var/www/html
sudo unzip master.zip
sudo cd opencart-master
sudo mv -v upload/* ../opencart-master/\
sudo cp /var/www/html/opencart-master/admin/config-dist.php /var/www/html/opencart-master/admin/config.php
sudo cp /var/www/html/opencart-master/config-dist.php /var/www/html/opencart-master/config.php
sudo chmod 777 -R /var/www/html/opencart-master 
print "Create Database and remove install"
