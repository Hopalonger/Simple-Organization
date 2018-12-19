import requests
import time
url = "https:google.com" #url to post to
name = "xmlfiles.txt" #file with xml
file = open(name, 'r') #open file
lines = 200 #NUM of lines in xmlfiles.txt
print(”Sending Data to:"+ url + " Reading from file:"+ name)
print(”Starting Transfer”)
write = open('results.txt' , 'w')
while i < lines:
     data = file.readline()
     re = requests.post(url,data)
     i += 1
     print("Sent Xml Code" + data + "on number:"+ i)
     write.writeline(re)
     time.sleep(1)
     
file.close()
write.close()
