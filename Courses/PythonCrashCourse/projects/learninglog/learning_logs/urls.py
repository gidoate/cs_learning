"""
URL configuration for learning_log project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.urls import path
from . import views

app_name = 'learning_logs'

urlpatterns = [
    # Home page
    path('', views.index, name='index'),
    # Page that shows all topics
    path('topics/', views.topics, name='topics'),
    # Detail page for a single topic
    path('topics/<int:topic_id>/', views.topic, name='topic'),
    # Page for a new topic
    path('new_topic/', views.new_topic, name='new_topic'),
    # Page to confirm delete topic
    path('confirm_delete_topic/<int:topic_id>/', views.confirm_delete_topic, name='confirm_delete_topic'),
    # Page for delete topic
    path('delete_topic/<int:topic_id>/', views.delete_topic, name='delete_topic'),
    # Page for adding a new Entry
    path('new_entry/<int:topic_id>/', views.new_entry, name='new_entry'),
    # Page for editing an entry
    path('edit_entry/<int:entry_id>/', views.edit_entry, name='edit_entry'),
]