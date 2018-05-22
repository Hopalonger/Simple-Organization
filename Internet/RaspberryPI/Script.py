# **********************************Defintions: ****************************************
#Device Code
Device = "aaaa"

# URLS: 
# Address of Sever, Local or domain
Address = 'http://SimpleStorage.local/
# Set Color R=Red G=Green B=Blue Recommend using bright Colors 

R ="255"
G = "100"
B = "255"

Color = ","+R +","+G+","+B
# If the large Tray is enabled
Largetray = True

Large1 = True
Large2 = True
Large3 = True
Large4 = True
Large5 = True
Large6 = True
Large7 = True
Large8 = True
Large9 = True
# Large Trays Put Specified values Make Sure They are unique
Largetr1 = 101
Largetr2 = 102
Largetr3 = 103
Largetr4 = 104
Largetr5 = 105
Largetr6 = 106
Largetr7 = 107
Largetr8 = 108
Largetr9 = 109
#Large Trays LED value Code Custom Code ( Color value + Pixel number starts at Zero + Can have infinet pixels
LargetrLED1 = "23" + Color
LargetrLED2= "23" + Color
LargetrLED3= "23" + Color
LargetrLED4= "23" + Color
LargetrLED5= "23" + Color
LargetrLED6= "23" + Color
LargetrLED7="23" + Color
LargetrLED8= "23" + Color
LargetrLED9 "23" + Color
#**************************************************************************************
url = Address + 'newfile.txt'
power = Address + "power.txt"





import serial
import time
import requests
from bs4 import BeautifulSoup
import time
 
from neopixel import *
print
print




Word = "ON"


#Creates Loop
print "Starting"
while True:
	print("Connecting")
        powerresponse = requests.get(power)
	powerparsed = BeautifulSoup(powerresponse.content, "html.parser")
        print powerparsed
        pow = powerparsed
        word = pow
        value = str(pow)
	print("Connected Sucessfuly")
        if int(value) >= 1000:
		# Gets Web Data
        	response = requests.get(url)
		print("Requested Item:")
		soup = BeautifulSoup(response.content, "html.parser")
		soup_string = str(soup)
		ID = soup_string[:4]
		print(soup)
		if ID == Device:
				
			if Largetray == True:
			 	print("Large Trays Enabled")
				if Number == Largetr1:
					if Large1 == True:
						senddata(LargetrLED2)
						Number = " "
				elif Number == Largetr2:
					if Large2 == True:
						senddata(LargetrLED2)
						Number = " "
							
				elif Number == Largetr3:
					if Large3 == True:
						senddata(LargetrLED3)
						Number = " "
							
				elif Number == Largetr4:
					if Large4 == True:
						senddata(LargetrLED4)
						Number = " "
							
				elif Number == Largetr5:
					if Large5 == True:
						senddata(LargetrLED5)
						Number = " "
									
				elif Number == Largetr6:
					if Large6 == True:
						senddata(LargetrLED6)
						Number = " "
									
				elif Number == Largetr7:
					if Large6 == True:
						senddata(LargetrLED7)
						Number = " "
									
				elif Number == Largetr8:
					if Large6 == True:
						senddata(LargetrLED8)
						Number = " "
								
				elif Number == Largetr9:
					if Large6 == True:
						senddata(LargetrLED9)
						Number = " " 
				else:
					Number2 == Number -1 
					print("Sending Data")
					senddata(Number2 + Color)		




				
			
			
			
			
			
			
			
				time.sleep(2)
			else:	
				print("Large Tree Not Enabled Treating Normally")
				LED = int(soup_string)
                  		LED2 = LED -1
                    		senddata(Color + "P" + LED2)

		else:
			print("Not This Device")
			time.sleep(2)
  
	else:
		print("Device is still OFF")
		time.sleep(2)
def senddata(data):
	print("Sending Data:")
	print(data)
	setPixelColor(data)
	
