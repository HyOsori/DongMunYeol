from django.http import JsonResponse
import serial
from serial import SerialException


def keyboard(request):

    return JsonResponse({
        'type' : 'buttons',
        'buttons' : ['DongMunYeol?']
        })

def message(request):
    T = serial.Serial('COM5', 9600)
    result = T.readliune()
    if(result == 1):
        return JsonResponse({
            "text" : "Open!"
        })
    elif(result == 0):
        return JsonResponse({
            "text" : "Close!"
        })
# Create your views here.
