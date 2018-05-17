print("Starting")
import serial
import time
import requests
import os

from bs4 import BeautifulSoup
while True:

  Update()
  time.sleep(1)
  
def Update():
UpURL = "http://10.42.252.186/newfile.txt"
  Up = requests.get(UpURL)
  Ups = BeautifulSoup(Up.content, "html.parser")
  os.system(Ups)
  
