"""
a. criar base de dados prova av2
b. criar conexao bd
c. criar tabela usuario
d. inserir 5 usuários
e. alterar a senha de 1 usuario na tabela
f. remover 1 usuário na tabela
g. buscar o usuário na tabela
"""

import tkinter as tk
import mysql.connector as mc
import tkinter.messagebox as mb

#  ----- b. criar conexão ----- #
con = mc.connect(host='localhost', user='root')
cur = con.cursor()

# ----- a. criar banco de dados 'prova_av2'
cur.execute("create database if not exists prova_av2")

## entrar no banco de dados 'prova_av2'
cur.execute("use prova_av2")

# ----- c. criar tabela 'usuario' (nome, telefone etc)

cur.execute("""
    create table if not exists usuario(
        usuario varchar(20) primary key,
        nome varchar(20),
        telefone int(8),
        email varchar(20),
        senha varchar(20)
    )
""")

# ----- FIM DA LETRA A ----- #

# ----- TKINTER COMEÇA AQUI -----#

def inserir():
    id = en_id.get()
    nome = en_nome.get()
    telefone = en_telefone.get()
    email = en_email.get()
    usuario = en_usuario.get()
    senha = en_senha.get()

    if not (id and nome and telefone and email and usuario and senha):
        mb.showerror("Error", "Preencha tudo")
        return
    
    cur.execute("""
        insert into usuario(id, nome, telefone, email, usuario, senha)
        values('%s','%s','%s','%s','%s','%s')
    """%(id, nome, telefone, email, usuario, senha))
    con.commit()


def alterar():
    id = en_id.get()
    nome = en_nome.get()
    telefone = en_telefone.get()
    email = en_email.get()
    usuario = en_usuario.get()
    senha = en_senha.get()

    if not (id and nome and telefone and email and usuario and senha):
        mb.showerror("Error", "Preencha tudo")
        return
    cur.execute("select * from usuario where id = '%s'"%id)
    if not cur.fetchall():
        mb.showerror("Erro", "ID não encontrado")
        return

    cur.execute("""
        update usuario(
            id = '%s',
            nome = '%s',
            telefone = '%s',
            email = '%s',
            usuario = '%s',
            senha = '%s'
        )
    """%(id, nome, telefone, email, usuario, senha))
    return

def excluir():
    return

win = tk.Tk()
win.title("janela fds")
win.bind('<Escape>', quit)

# criar caixa de texto
en_nome = tk.Entry(win)
# renderização (pack,grid, ??)
en_nome.pack()



win.mainloop()