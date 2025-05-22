from django.contrib import admin
from learning_logs.models import Topic, Entry

class EntryAdmin(admin.ModelAdmin):
    list_display = ('topic', 'title', 'date_added')

admin.site.register(Topic)
admin.site.register(Entry, EntryAdmin)
# Register your models here.
