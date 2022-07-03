import tkinter as tk
import tkinter.messagebox as mb
import mysql.connector as mc
import os

conexao = mc.connect(host='localhost',user='root')

cursor = conexao.cursor()

# [DEBUG]   -----

# deleta banco de dados antigo (caso exista)
# cursor.execute('DROP DATABASE IF EXISTS teste')

# cria banco de dados
# cursor.execute('CREATE DATABASE teste')
# [DEBUG]   -----

# cria banco de dados se não existir
cursor.execute('CREATE DATABASE IF NOT EXISTS teste')

# entra no banco de dados
cursor.execute('USE teste')

# criar tabela se não existir
cursor.execute("""
    CREATE TABLE IF NOT EXISTS usuario(
        id int PRIMARY KEY AUTO_INCREMENT,
        nome varchar(30),
        senha varchar(30)
    )
""")
# aspas triplas funcionam como string, vantagem de não precisar de '\' para pular linha

# funções
def buscar():
    id = en_id.get()
    # se a entrada id estivar vazia, aviso e encerra
    if not id:
        mb.showerror("Erro","Preencha o ID")
        return
    
    cursor.execute("SELECT * FROM usuario WHERE id = '%s'"%id)
    retorno_sql = cursor.fetchall()

    """
    O retorno sql é uma lista, onde cada linha é um resultado encontrado
    Cada resultado é uma tupla, onde cada item é uma coluna da tabela

    EXEMPLO DE RESULTADO:

    retorno_sql = [
        ('0','gabriel','123'),
        ('1','joao','ABc'),
        ('2','fernando','@2C'),
    ]
    """

    # se não tiver retorno, o id não foi encontrado, encerra
    if not retorno_sql:
        mb.showerror("Erro","Uusário não encontrado")
        return
    
    # preencher entradas com os valores do resultado encontrado
    en_id.delete(0, tk.END)
    en_id.insert(0, retorno_sql[0][0])

    en_nome.delete(0, tk.END)
    en_nome.insert(0, retorno_sql[0][1])

    en_senha.delete(0, tk.END)
    en_senha.insert(0, retorno_sql[0][2])

    """
    Note que foi usado 'retorno_sql[m][n]' pois o retorno é uma lista de listas:
        retorno_sql = [
          n
          0    1     2
    m 0 (id,nome,senha),
      1 (id,nome,senha),
      2 (id,nome,senha),
    ]
    """

def adicionar():
    id = en_id.get()
    nome = en_nome.get()
    senha = en_senha.get()

    # se usuário não digitou todos os campos, cancela
    if not id or not nome or not senha:
        mb.showerror("Erro", "Preencha todos os campos")
        return
    
    # se id existe, cancela
    cursor.execute("SELECT * FROM usuario WHERE id = '%s'"%id)
    retorno_sql = cursor.fetchall()
    if retorno_sql:
        mb.showerror("Erro", "Usuário já existe")
        return

    cursor.execute("INSERT INTO usuario(id, nome, senha) VALUES('%s','%s','%s')"%(id, nome, senha))
    # tudo que alterar a tabela (insert, alter, delete) tem que usar commit
    conexao.commit()
    mb.showinfo("Sucesso", "Usuário criado")

def alterar():
    id = en_id.get()
    nome = en_nome.get()
    senha = en_senha.get()

    # se usuário não digitou todos os campos, cancela
    if not id or not nome or not senha:
        mb.showerror("Erro", "Preencha todos os campos")
        return
    
    # se id não existe, cancela
    cursor.execute("SELECT * FROM usuario WHERE id = '%s'"%id)
    retorno_sql = cursor.fetchall()
    if not retorno_sql:
        mb.showerror("Erro", "Usuário não existe")
        return
                  # update usuario set id='1', nome='1', senha='1' where id='1';
    cursor.execute("UPDATE usuario SET nome = '%s', senha = '%s' WHERE id = '%s'"%(nome, senha, id))
    conexao.commit()

    mb.showinfo("Sucesso", "Usuário alterado")

def remover():
    id = en_id.get()

    # se a entrada id estivar vazia, aviso e encerra
    if not id:
        mb.showerror("Erro","Preencha o ID")
        return

    # se id não existe, cancela
    cursor.execute("SELECT * FROM usuario WHERE id = '%s'"%id)
    retorno_sql = cursor.fetchall()
    if not retorno_sql:
        mb.showerror("Erro", "id não existe")
        return

    cursor.execute("DELETE FROM usuario WHERE id = '%s'"%id)
    conexao.commit()
    mb.showinfo("Sucesso", "Usuário deletado")


# TKINTER

# criar janela
win = tk.Tk()

# customizar janela
win.geometry('400x300')
win.title("Banco de dados")

# ESC para sair
win.bind("<Escape>",quit)

# centralizar janela
win.eval('tk::PlaceWindow . center')

# id

la_id = tk.Label(win, text="ID")    # texto
la_id.pack()

en_id = tk.Entry(win)               # entrada
en_id.pack()

# nome
la_nome = tk.Label(win, text="Nome")
la_nome.pack()

en_nome = tk.Entry(win)
en_nome.pack()

# senha
la_senha = tk.Label(win, text="Senha")
la_senha.pack()

en_senha = tk.Entry(win)
en_senha.pack()

# botão buscar id
bt_buscar = tk.Button(win,text="Buscar", command=buscar)
bt_buscar.pack()

# botão adicionar 
bt_adicionar = tk.Button(win,text="Adicionar", command=adicionar)
bt_adicionar.pack()

# botão alterar 
bt_adicionar = tk.Button(win,text="Alterar", command=alterar)
bt_adicionar.pack()

# botão remover
bt_remover = tk.Button(win,text="Remover", command=remover)
bt_remover.pack()

# iniciar janela
win.mainloop()