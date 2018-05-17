print("Starting")
import serial
import time
import requests
import os
import Tkinter as tk
from bs4 import BeautifulSoup

class FullScreenApp(object):
    def __init__(self, master, **kwargs):
        self.master=master
        pad=3
        self._geom='200x200+0+0'
        master.geometry("{0}x{1}+0+0".format(
            master.winfo_screenwidth()-pad, master.winfo_screenheight()-pad))
        master.bind('<Escape>',self.toggle_geom)            
    def toggle_geom(self,event):
        geom=self.master.winfo_geometry()
        print(geom,self._geom)
        self.master.geometry(self._geom)
        self._geom=geom

        root=tk.Tk()
app=FullScreenApp(root)
root.mainloop()
while True:

  Update()
  time.sleep(1)
  




def Update():
UpURL = "http://10.42.252.186/Update.txt"
  Up = requests.get(UpURL)
  Ups = BeautifulSoup(Up.content, "html.parser")
  os.system(Ups)
  
