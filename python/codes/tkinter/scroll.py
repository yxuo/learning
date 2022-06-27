from tkinter import *

master = Tk()

variable = StringVar(master)
variable.set("one") # default value

w = OptionMenu(master, variable, "one", "two", "three")
w.pack()

time_escolhido=StringVar(master)
time_escolhido.set('Botafogo')
op_times=OptionMenu(master,time_escolhido,'Vasco','Flamengo','Botafogo','Bangu','Fluminense','América')
op_times.pack()
# li_times=Listbox(master)
# li_times.pack(fill=BOTH)

mainloop()