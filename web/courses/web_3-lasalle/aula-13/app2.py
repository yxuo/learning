import tkinter as tk
from tkinter import messagebox

def calc():
    nota1 = e_nota1.get()
    nota2 = e_nota2.get()
    nota3 = e_nota3.get()
    if not (nota1 and nota2 and nota3):
        messagebox.showerror("Erro", "Preencha todos os campos")
        return

    media = (int(nota1) + int(nota2) + int(nota3)) / 3
    messagebox.showinfo("Média", media)

win = tk.Tk()
win.geometry('400x300')
win.title('Média das notas')
win.bind('<Escape>', lambda e: win.quit())

l_nota1 = tk.Label(win, text="Nota 1")
l_nota1.pack()

e_nota1 = tk.Entry(win)
e_nota1.pack()

l_nota2 = tk.Label(win, text="Nota 2")
l_nota2.pack()

e_nota2 = tk.Entry(win)
e_nota2.pack()

l_nota3 = tk.Label(win, text="Nota 3")
l_nota3.pack()

e_nota3 = tk.Entry(win)
e_nota3.pack()

b_action = tk.Button(win, text="calcular", command=calc)
b_action.pack()

win.mainloop()