from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse

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


@csrf_exempt
def receive(request):
    if(request.method == 'POST'):
        print(request.body)
        isopen = request.POST.get('status', False)

        return HttpResponse("Success")

    else:
        return HttpResponse("Fail")
# Create your views here.
