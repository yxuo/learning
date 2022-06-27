import tkinter as tk
from tkinter import messagebox
import mysql.connector as mysql

# init
con=mysql.connect(host='localhost',user='root',password='')
cursor = con.cursor()

cursor.execute("CREATE DATABASE IF NOT EXISTS precos")

cursor.execute("USE precos")

cursor.execute("CREATE TABLE IF NOT EXISTS precos (id INT PRIMARY KEY AUTO_INCREMENT, nome VARCHAR(20), preco FLOAT)")
con.commit()

cursor.execute("SELECT * FROM precos")
if not cursor.fetchall():
    for i in range(10):
        cursor.execute("INSERT INTO precos(nome, preco) VALUES('prod%i', %.2f)"%(i, i+0.99))
        con.commit()

def listar():
    cursor.execute("SELECT * FROM precos")
    ret = cursor.fetchall()
    l_precos.delete(0, tk.END)
    for i in range(len(ret)):
        l_precos.insert(i,str(ret[i]))

def consulta():
    nome = e_nome.get()
    if not nome:
        listar()
        return
    
    cursor.execute("SELECT * FROM precos WHERE nome = '%s'" % nome)
    ret = cursor.fetchall()
    l_precos.delete(0, tk.END)
    for i in range(len(ret)):
        l_precos.insert(i, str(ret[i]))


win = tk.Tk()
win.geometry('300x400')
win.title("Lista de preços")
win.bind('<Escape>', lambda e: win.quit())

l_nome = tk.Label(win, text="Nome do produto")
l_nome.pack()

e_nome = tk.Entry(win)
e_nome.pack()

l_precos = tk.Listbox(win)
l_precos.pack()
listar()

b_ver = tk.Button(win, text="Buscar",command=consulta)
b_ver.pack()

win.mainloop()
