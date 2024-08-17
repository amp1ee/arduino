# Joystick controlled mouse

import mouse, sys
import time 
import serial

mouse.FAILSAFE = False
ArduinoSerial = serial.Serial('com9', 9600)   #Specify the correct COM port
time.sleep(1)                                 #delay   of 1 second

while 1:

   try:
      data=str(ArduinoSerial.readline().decode('ascii'))    #read the data
      (y,x,z) = data.split(",")           # assigns to x,y and   z
      (X,Y) = mouse.get_position()        #read the cursor's current position
      (x,y) = (int(x), int(y))            #convert to int
      mouse.move(X + x, Y - y)            #move cursor to desired position
      if '1' in z:                        #   read the Status of SW
         mouse.click(button = "left")    # clicks left button

   except KeyboardInterrupt:
        print("Exiting...")
        ser.close()
        break
