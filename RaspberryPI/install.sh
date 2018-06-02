echo "Installing Prerequisite"
sudo apt-get install build-essential python-dev git scons swig
sudo apt-get update
sudo apt-get -y install python3-pip
echo "[+] Installing Beautiful Soup"
pip3 install bs4
pip3 install beautifulsoup4
sudo apt-get -y install python3-bs4
echo "[+] Instaling Requests" 
python -m pip install requests
echo "[+] Installing NeoPixels"
git clone https://github.com/jgarff/rpi_ws281x.git
cd rpi_ws281x
scons
echo "[+] Installing Python Update"
cd python
sudo python setup.py install
echo "All Done"
