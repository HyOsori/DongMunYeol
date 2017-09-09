
import serial
from serial import SerialException


T = serial.Serial('COM5', 9600)
while T.isOpen():
    try:
        result=T.readline()
        print(result)
    except SerialException:
        print('ser cannot be open')
        T.close()