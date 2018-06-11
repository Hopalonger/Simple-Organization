print("Starting")
import serial
import time
import requests
import os
import RPi.GPIO as GPIO
import Tkinter as tk
import socket
from bs4 import BeautifulSoup
print("Setting Ip")
import socket
import fcntl
import struct
import os
import commands
end = 161;
def setIP_XXX(ip):

    os.system('sudo ifconfig eth0 down')

    os.system('sudo ifconfig eth0 ' + ip)

    os.system('sudo ifconfig eth0 up')
    

a = commands.getoutput('hostname -I')
print("Setting Ip:")
if a[-2;] = "."
    a.replace(a[-1:],161)
    setIP_XXX(a):
    print(a)
else:
    a.replace(a[-2:],161)
    setIP_XXX(a):
    print(a)
while True:

  Update()
  Status()
  time.sleep(1)
  




def Update():
UpURL = "http://10.42.252.186/Update.txt"
  Up = requests.get(UpURL)
  Ups = BeautifulSoup(Up.content, "html.parser")
  os.system(Ups)
  
  
def Status():
   print(subprocess.check_output(['hostname']))
