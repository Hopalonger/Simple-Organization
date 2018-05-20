# Server Hostname
Name = "SimpleStorage"


import serial
import time
import requests
from bs4 import BeautifulSoup
print
print

url =  "http://" + Name + "/newfile.txt"
power = "http://" + Name + "/newfile.txt"


# NOTE the user must ensure that the serial port and baudrate are
# correct
serPort = "/dev/ttyACM0"
baudRate = 9600
ser = serial.Serial(serPort, baudRate)
print "Serial port " + serPort + " opened  Baudrate " + str(baudRate)


time.sleep(5)
# Lets Respond
Word = "ON"

while True:
	print("Connecting")
        powerresponse = requests.get(power)
	powerparsed = BeautifulSoup(powerresponse.content, "html.parser")
        print powerparsed
        pow = powerparsed
        word = pow
        value = str(pow)
		if int(value) >= 1000:
		# Gets Web Data
		response = requests.get(url)
		print("Requested Item:")
		soup = BeautifulSoup(response.content, "html.parser")
		soup_string = str(soup)
		print(soup)
		senddata(soup)
		
def senddata(data):
	print("Sending Data:")
	print(data)
	ser.write(data.encode("uft-8"))
