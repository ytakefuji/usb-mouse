import serial
from time import time_ns as ns,sleep
s=serial.Serial('com3',115200)
f=open('log.txt','a')
sleep(1)
start=ns()
while 1:
 t=ns()
 if t-start>5000000000:
  break
 f.write(str(s.read())+str(t)+'\r\n')
f.close() 
 
 
 
