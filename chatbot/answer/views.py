from django.http import JsonResponse

def keyboard(request):

    return JsonResponse({
        'type' : 'buttons',
        'buttons' : ['1','2']
        })

# Create your views here.
