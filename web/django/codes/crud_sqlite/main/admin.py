from django.contrib import admin

# from crud_sqlite.main.models import ToDoList
from .models import ToDoList, Item

# Register your models here.
admin.site.register(ToDoList)
admin.site.register(Item)