from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse
import json
server_is_open = 0

def keyboard(request):
    return JsonResponse({
        'type' : 'buttons',
        'buttons' : ['동아리방 열렸나요?']
        })

@csrf_exempt
def message(request):
    global server_is_oepn
    isopen = server_is_open
    data = ''
    if(isopen == 1):
        data = {
            'message':{
                'text' : '열렸습니다!!'
            },
            'keyboard':{
                'type': 'buttons',
                'buttons': ['동아리방 열렸나요?']
            }
        }
    elif(isopen == 0):
        data = {
            'message':{
                'text' : '닫혔습니다!!'
            },
            'keyboard':{
                'type': 'buttons',
                'buttons': ['동아리방 열렸나요?']
            }
        }
    return JsonResponse(data)

@csrf_exempt
def receive(request):
    if(request.method == 'POST'):
        body = request.body
        body = json.loads(body.decode())
        global server_is_open
        server_is_open = body['status']
        print(server_is_open)
        return HttpResponse("Success")
    else:
        return HttpResponse("Fail")
# Create your views here.
