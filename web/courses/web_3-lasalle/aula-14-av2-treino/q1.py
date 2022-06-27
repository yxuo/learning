import tkinter as tk
import tkinter.messagebox as mb
import mysql.connector as mc
import os

# DB table
con = mc.connect(host="localhost", user="root")
cur = con.cursor()
cur.execute("CREATE DATABASE IF NOT EXISTS banco")
cur.execute("USE banco")
# cur.execute("CREATE TABLE IF NOT EXISTS produtos(id int PRIMARY KEY AUTO_INCREMENT, nome varchar(50), preco float)")

def atualizar():
    cur.execute("select * from produtos")
    ret = cur.fetchall()

    li_lista.delete(0,tk.END)
    # [li_lista.insert(li_lista.size(), "%i     %s     %.2f"%(i[0],i[1],i[2])) for i in ret]
    [li_lista.insert(li_lista.size(), i) for i in ret]

def adicionar():
    nome = en_nome.get()
    preco = en_preco.get()

    if not nome or not preco:
        mb.showerror("Erro", "Preencha todos os campos")
        return

    cur.execute("insert into produtos(nome, preco) where('%s', '%i')"%(nome, preco))
    con.commit()
    mb.showinfo("Info", "Adicionado com sucesso")
    atualizar()

def remover():
    sel_index = li_lista.curselection()
    if not sel_index:
        mb.showerror("Erro", "Selecione um item")
        return
    sel = li_lista.get(sel_index[0])
    cur.execute("delete from produtos where(id = %i)"%sel[0])
    con.commit()
    atualizar()

    return

def tst():
    sel = li_lista.curselection()
    sel = li_lista.get(sel)
    print(sel)

win = tk.Tk()
win.title("Janela")
win.geometry("400x300")
win.bind('<Escape>', lambda e: quit())
"""
"abc abc abc"
["abc", "abc", "abc"]
"""

en_nome = tk.Entry(win)
en_nome.insert(0, "nome")
en_nome.pack()

en_preco = tk.Entry(win)
en_preco.pack()

# listbox
li_lista = tk.Listbox(win)
li_lista.pack()

# btn
bt_adc = tk.Button(win, text="Adicionar produto", command=adicionar)
bt_adc.pack()

bt_del = tk.Button(win, text="Remover produto", command=remover)
bt_del.pack()

bt_tst = tk.Button(win, text="Adicionar produto", command=tst)
bt_tst.pack()

atualizar()


win.mainloop()