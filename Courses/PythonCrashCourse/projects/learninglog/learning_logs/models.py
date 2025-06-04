from django.db import models
from django.contrib.auth.models import User

# Create your models here. A model is just a CLASS! 
default_user_id = 1
class Topic(models.Model):
    """A topic the user is learning about"""
    title = models.CharField(max_length=100)
    text = models.CharField(max_length=200)
    date_added = models.DateTimeField(auto_now_add=True)
    owner = models.ForeignKey(User, on_delete=models.CASCADE, default=default_user_id)
    def __str__(self):
         return self.title

class Entry(models.Model):
    """Something specific learned about a topic"""
    title = models.CharField(max_length=100, default='Default Title')
    topic = models.ForeignKey(Topic, on_delete=models.CASCADE)
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)
    
    class Meta:
        verbose_name_plural = 'entries'
    def __str__(self):
         return self.title

def __str__(self):
    """Return a string representation of the model."""
    return self.text[:50] + "..."

def __str__(self):
    """Return a string representation of the model."""
    return self.text
