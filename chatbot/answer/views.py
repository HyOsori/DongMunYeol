from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt

isopen = 0

def keyboard(request):
    return JsonResponse({
        'type' : 'buttons',
        'buttons' : ['DongMunYeol?']
        })

@csrf_exempt
def message(request):
    if(isopen == 1):
        return JsonResponse({
            'message':{
                'text' : 'Open!'
            },
            'keyboard':{
                'type': 'buttons',
                'buttons': ['DongMunYeol?']
            }
        })
    elif(isopen == 0):
        return JsonResponse({
            'message':{
                'text' : 'Close!'
            },
            'keyboard':{
                'type': 'buttons',
                'buttons': ['DongMunYeol?']
            }
        })


def receive(request):
    isopen = request.POST['status']
# Create your views here.
