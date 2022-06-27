import tkinter as tk
from tkinter import messagebox
import math

def calc():
    a = e_a.get()
    b = e_b.get()
    c = e_c.get()

    if not (a and b and c):
        messagebox.showerror("Erro", "Preencha todos os campos")
        return
    
    a = int(a)
    b = int(b)
    c = int(c)

    ret1 = -b + math.sqrt(b-4*a*c)
    ret2 = -b - math.sqrt(b-4*a*c)

    messagebox.showinfo("Resultado","%.2f\n%2.f"%(ret1, ret2))

win = tk.Tk()
win.geometry('400x300')
win.title("Calculadora de coeficiente")

l_a = tk.Label(win, text="a")
l_a.pack()

e_a = tk.Entry(win)
e_a.pack()

l_b = tk.Label(win, text="b")
l_b.pack()

e_b = tk.Entry(win)
e_b.pack()

l_c = tk.Label(win, text="c")
l_c.pack()

e_c = tk.Entry(win)
e_c.pack()

b_calc = tk.Button(win, text="Calcular", command=calc)
b_calc.pack()

win.mainloop()