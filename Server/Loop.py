print("Starting")
import serial
import time
import requests
import os
import RPi.GPIO as GPIO
import Tkinter as tk
import socket
from bs4 import BeautifulSoup


while True:

  Update()
  Pair()
  time.sleep(1)
  




def Update():
UpURL = "http://10.42.252.186/Update.txt"
  Up = requests.get(UpURL)
  Ups = BeautifulSoup(Up.content, "html.parser")
  os.system(Ups)
  
def Pair():
    input_state = GPIO.input(18)
    if input_state == False:
       
    
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(("8.8.8.8", 80))
    print(s.getsockname()[0])
    s.close()
    
    Net = s[:-3]
    UDP_PORT = 520
    while i < 999
        UDP_IP = Net + i
        print("UDP target IP:", UDP_IP)
        print("UDP target port:", UDP_PORT)
        print("message:", MESSAGE)
        time.sleep(0.2)
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        sock.sendto(bytes(s "utf-8"), (UDP_IP, UDP_PORT))
        i += 1
    
        
