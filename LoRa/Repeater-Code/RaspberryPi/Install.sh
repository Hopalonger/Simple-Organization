echo "Installing"
sudo apt-get update
sudo apt-get -y install python3-pip
echo "installing Beautiful Soup"
pip3 install bs4
pip3 install beautifulsoup4
sudo apt-get -y install python3-bs4
echo "Instaling Requests" 
python -m pip install requests
sudo apt-get -y install libnss-mdns
sudo update-rc.d Simple-Organization/LoRa/Repeater-Code/RaspberryPi/Start.sh defaults
chmod +x Simple-Organization/LoRa/Repeater-Code/RaspberryPi/Start.sh
echo "All Done"
