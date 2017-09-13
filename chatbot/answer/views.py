from django.http import JsonResponse

isopen = 0

def keyboard(request):
    return JsonResponse({
        'type' : 'buttons',
        'buttons' : ['DongMunYeol?']
        })

def message(request):
    if(isopen == 1):
        return JsonResponse({
            "message":{
                "text" : "Open!"
            },
            "keyboard":{
                'type': 'buttons',
                'buttons': ['DongMunYeol?']
            }
        })
    elif(isopen == 0):
        return JsonResponse({
            "message":{
                "text" : "Close!"
            },
            "keyboard":{
                'type': 'buttons',
                'buttons': ['DongMunYeol?']
            }
        })


def receive(request):
    isopen = request.POST['status']
# Create your views here.
