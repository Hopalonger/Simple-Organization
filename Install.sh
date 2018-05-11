echo "[+]Main Installer"
read -r -p  "[+]What are you installing For Server [S], LoRa Repeater [R], Or Client [C] " response
if [[ $response =~ ^([sS])$ ]]
then
./Server/Install.sh
fi
[[ $response =~ ^([rR])$ ]]
then
./LoRa/Repeater-Code/RaspberryPi/Install.sh
fi
echo "[+] Installer Finsihed" 
echo "[+] Please install the proper Hardware before Exicuting Scripts"
