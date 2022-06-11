import tkinter as tk
from tkinter import messagebox
import mysql.connector

# mysql

connection = mysql.connector.connect(
    host=' localhost', user="root", password="")
cursor = connection.cursor()
db = "aula11"
table = "usuario"

# banco de dados
cursor.execute("CREATE DATABASE IF NOT EXISTS %s" % db)
cursor.fetchall()

cursor.execute("USE %s" % db)
cursor.fetchall()

# tabela
cursor.execute("\
    CREATE TABLE %s IF NOT EXISTS(\
        id int PRIMARY KEY AUTO_INCREMENT,\
        nome varchar(40),\
        telefone varchar(11),\
        email varchar(30),\
        usuario varchar(30),\
        senha varchar(30),\
    )\
"%table)

def user_update():
    v0 = en_id.get()
    v1 = en_nome.get()
    v2 = en_telefone.get()
    v3 = en_email.get()
    v4 = en_usuario.get()
    v5 = en_senha.get()
    cursor.execute("\
        UPDATE %s SET \
            nome = %s, \
            telefone = %s, \
            email = %s, \
            usuario = %s, \
            senha = %s, \
            WHERE id = %s\
        "%(table,v1,v2,v3,v4,v5,v0))
        connection.commit()
        cursor.fetchalll()

def user_add():
    v0 = en_id.get()
    v1 = en_nome.get()
    v2 = en_telefone.get()
    v3 = en_email.get()
    v4 = en_usuario.get()
    v5 = en_senha.get()
    cursor.execute("\
        INSERT INTO %s(nome,telefone,email,usuario,senha) \
            VALUES('%s','%s','%s','%s','%s')\
        "%(table,v1,v2,v3,v4,v5))
        connection.commit()
        cursor.fetchalll()

