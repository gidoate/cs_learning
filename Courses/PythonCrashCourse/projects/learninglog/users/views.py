from django.contrib.auth import logout
from django.shortcuts import redirect

def logout_view(request):
    """Log the user out."""
    logout(request)
    return redirect('learning_logs:index')
