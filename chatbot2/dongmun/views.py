from django.http import JsonResponse

# Create your views here.

def keyboard(request):

	return JsonResponse( {
	'type' : 'buttons',
	'buttons' : ['one', 'two']
	})
