from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.urls import reverse

from django.contrib.auth import login, logout, authenticate
from django.contrib.auth.forms import UserCreationForm
from django.shortcuts import redirect


def logout_view(request):
    """Log the user out."""
    logout(request)
    return redirect('learning_logs:index')

def register(request):
    """Register a new user."""
    if request.method != 'POST':
        # Display blank registration form.
        form = UserCreationForm()
    else:
        # Process completed form.
        form = UserCreationForm(data=request.POST)
        if form.is_valid():
            new_user = form.save()
            # Authenticate and log in the new user.
            authenticated_user = authenticate(
                username=new_user.username,
                password=request.POST['password1']
            )
            if authenticated_user:
                login(request, authenticated_user)
                return redirect(reverse('learning_logs:index'))

    # Render the registration page with the form.
    context = {'form': form}
    return render(request, 'users/register.html', context)

