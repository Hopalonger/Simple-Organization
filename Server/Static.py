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

if a[-2;] = "."
    a.replace(a[-1:],161)
else:
    a.replace(a[-2:],161)
