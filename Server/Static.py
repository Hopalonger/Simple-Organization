def setIP_XXX(ip):

    os.system('sudo ifconfig eth0 down')

    os.system('sudo ifconfig eth0 ' + ip)

    os.system('sudo ifconfig eth0 up')
    
import socket
import fcntl
import struct

def get_ip_address(ifname):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(
        s.fileno(),
        0x8915,  # SIOCGIFADDR
        struct.pack('256s', ifname[:15])
    )[20:24])
    
first = get_ip_address('eth0')
if first[:3] > 100
    ip = First[:2] + ".50.50.80"
    setIP_XXX(ip)
    print(ip)
else:
    ip = First[:1] + ".50.50.80"
     setIP_XXX(ip)
     print(ip)
