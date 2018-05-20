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
  Status()
  time.sleep(1)
  




def Update():
UpURL = "http://10.42.252.186/Update.txt"
  Up = requests.get(UpURL)
  Ups = BeautifulSoup(Up.content, "html.parser")
  os.system(Ups)
  
  
def Status():
   result = subprocess.run(['hostname'], stdout=subprocess.PIPE)
