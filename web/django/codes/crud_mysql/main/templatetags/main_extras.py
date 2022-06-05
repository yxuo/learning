from unicodedata import name
from django import template
from main.models import ToDoList, Item

register = template.Library()

@register.simple_tag
def todo_list():
    # ret = range(1,3)
    # return ret
    return ToDoList.objects.filter().values_list('pk', flat=True)


@register.simple_tag
def todo_list_id_name(arg):
    try:
        return ToDoList.objects.get(name=arg)
    except:
        return None

@register.simple_tag
def todo_list_name_id(arg):
    try:
        return ToDoList.objects.get(id=arg)
    except:
        return None

@register.filter(name='inlist')
def inlist(value, given_list):
    return True if value in given_list else False

# source: https://stackoverflow.com/questions/14328525/django-template-with-if-x-in-list-not-working
