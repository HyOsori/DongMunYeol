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
            "text" : "Open!"
        })
    elif(isopen == 0):
        return JsonResponse({
            "text" : "Close!"
        })


def receive(request):
    isopen = request.POST['status']
# Create your views here.
