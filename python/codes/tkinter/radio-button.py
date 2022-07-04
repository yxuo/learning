import tkinter

# aviso genérico
import tkinter.messagebox

def aviso():
    # a mensagem da janela de aviso é a variável que pega o valor dos radiobuttons selecionados
    valor = selecionado.get()   #o get() vai pegar o valor de uma var. tkinter

    # se o valor selecionado for nulo
    # if not valor:
    print(valor)

    if valor == 0:
        tkinter.messagebox.showerror("ERRO", "Escolha uma as opções acima!")
        return

    tkinter.messagebox.showinfo("Título", selecionado.get())

# criar uma janela
win = tkinter.Tk()

# tamanho da janela
win.geometry("400x300")

# configurações opcionais
win.bind("<Escape>", quit)


# valor do item selecionado
# selecionado = tkinter.StringVar(value="c")   #texto
selecionado = tkinter.IntVar()                 #número

# botão de opção (radio button)
op1 = tkinter.Radiobutton(win, text="a", value=1, variable=selecionado)
op1.pack()

op2 = tkinter.Radiobutton(win, text="b", value=2, variable=selecionado)
op2.pack()

op3 = tkinter.Radiobutton(win, text="c", value=3, variable=selecionado)
op3.pack()

op4 = tkinter.Radiobutton(win, text="d", value=4, variable=selecionado)
op4.pack()

# botão normal
bt_aviso = tkinter.Button(win, text="Mostrar aviso", command=aviso)
bt_aviso.pack()

# abrir janela
win.mainloop()