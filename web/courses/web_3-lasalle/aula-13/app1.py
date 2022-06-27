from tkinter import *
import tkinter.messagebox as Messagebox

def calc():
    peso = e_peso.get()
    altura = e_altura.get()

    if not peso or not altura:
        Messagebox.showerror("Erro", "Preencha todos os campos")
        return

    imc = float(peso)/((float(altura)/100)**2)

    tipo_peso = "Baixo"
    if imc >= 18.5:
        tipo_peso = "Normal"
    if imc >= 25:
        tipo_peso = "Sobrepeso"
    if imc >= 30:
        tipo_peso = "Obesidade"
    if imc >= 35:
        tipo_peso = "Obesidade extrema"
    Messagebox.showinfo("Resultado", "%.2f\n%s"%(imc, tipo_peso))

win=Tk()
win.geometry('400x300')
win.title('Calculadora de IMC')
win.bind("<Escape>", lambda e: win.quit())

l_peso=Label(win,text='Insira o peso (kg)')
l_peso.pack()

e_peso=Entry(win)
e_peso.pack()

l_altura=Label(win,text='Insira a altura cm')
l_altura.pack()

e_altura=Entry(win)
e_altura.pack()

b_imc=Button(win,text='Calcular', command=calc)
b_imc.pack()


win.mainloop()
