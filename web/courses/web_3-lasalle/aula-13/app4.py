import tkinter as tk
from tkinter import messagebox

def calc():
    grau = rs_grau.get()
    c = e_c.get()
    f = e_f.get()

    if (grau == "f" and not c) or (grau == "c" and not f):
        messagebox.showerror("Erro", "Preencha o campo")
        return
    
    c = float(c) if c else 0
    f = float(f) if f else 0

    if grau == "c":
        # (1 °F − 32) × 5/9 = -17,22 °C
        e_c.delete(0, tk.END)
        e_c.insert(0, (f-32) * 5/9)
    else:
        # (1 °C × 9/5) + 32 = 33,8 °F
        e_f.delete(0, tk.END)
        e_f.insert(0, (c * (9/5) + 32))

win = tk.Tk()
win.geometry('300x400')
win.title("Conversor de graus")
win.bind('<Escape>', lambda e: win.quit())

l_c = tk.Label(win, text="Celcius")
l_c.pack()

e_c = tk.Entry(win)
e_c.pack()

l_f = tk.Label(win, text="Farenheit")
l_f.pack()

e_f = tk.Entry(win)
e_f.pack()

rs_grau = tk.StringVar(value="c")

r1 = tk.Radiobutton(win, text="Celcius", value="c", variable=rs_grau)
r1.pack()

r2 = tk.Radiobutton(win, text="Farenheit", value="f", variable=rs_grau)
r2.pack()

b_calc = tk.Button(win, text="Calcular", command=calc).pack()

win.mainloop()

