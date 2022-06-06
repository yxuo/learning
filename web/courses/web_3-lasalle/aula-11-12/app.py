'''
REQUISITOS:
* XAMPP
* mysql-connector-python

source
* Center window - https://stackoverflow.com/questions/3352918/how-to-center-a-window-on-the-screen-in-tkinter
* info, warning window - https://www.geeksforgeeks.org/python-tkinter-messagebox-widget/
* tomato icon - https://icon-icons.com/icon/tomato-vegetables-vegetable-food-agriculture-fruit/220780
'''

import tkinter as tk
from tkinter import messagebox
import mysql.connector

# mysql

connection = mysql.connector.connect(
    host="localhost", user="root", password="")
cursor = connection.cursor()
db = "aula_10"
table_aluno = "aluno"

# fn


def db_app_update():
    # insert default login if not exists
    cursor.execute("SELECT * FROM %s"%table_aluno)
    ret = cursor.fetchall()
    print(str(ret))
    for row in ret:
        app_list.insert(len(ret)+1,str(row))
    #     for col in row:
    # messagebox.showinfo("Query result", ret)


def db_app_add(aluno_nome, aluno_email):
    # aluno_nome = app_txt_login.get()
    # aluno_email = app_txt_pass.get()

    if not aluno_nome or not aluno_email:
        messagebox.showerror(
            "Invalid login", "Login credentials can't be empty!")
        return

    # insert default login if not exists
    cursor.execute("INSERT IGNORE INTO %s (nome, email) VALUES ('%s','%s')" % (
        table_aluno, aluno_nome, aluno_email))
    connection.commit()
    print(cursor.fetchall())
    messagebox.showinfo(
        "Login", "New login created: user: %s, pass: %s" % (aluno_nome, aluno_email))


def db_app_check():
    cursor.execute("SELECT * from %s WHERE nome = '%s' AND email = '%s'" %
                   (table_aluno, app_txt_login.get(), app_txt_pass.get()))
    if cursor.fetchall():
        messagebox.showinfo("Login", "Login successfull")
    else:
        messagebox.showerror("Error", "Login \
incorrect!")


def db_show_table():
    cursor.execute("SELECT * from %s")
    print(cursor.fetchall())


# init
cursor.execute("create database if not exists %s" % db)
cursor.fetchall()

cursor.execute("USE %s" % db)
cursor.fetchall()

# create login table
cursor.execute(" \
CREATE TABLE IF NOT EXISTS %s( \
    id int PRIMARY KEY AUTO_INCREMENT, \
    nome varchar(40) UNIQUE KEY, \
    email varchar(30) \
) \
" % table_aluno)
print(cursor.fetchall())

ret = cursor.fetchall()
print(len(ret), bool(ret))

#ANCHOR tkinter

# window login

win_app = tk.Tk()
win_app.eval('tk::PlaceWindow . center')

win_app.geometry("300x250")
win_app.minsize(300, 250)
win_app.title("Teste de banco de dados")
# win_app.iconbitmap("tomato.ico")
win_app.bind("<Escape>", lambda e: win_app.quit())

win_app.grid_columnconfigure(0, weight=0)
win_app.grid_columnconfigure(1, weight=0)
win_app.grid_columnconfigure(2, weight=0)
win_app.grid_columnconfigure(3, weight=0)
win_app.grid_columnconfigure(4, weight=1)

win_app.grid_rowconfigure(0, weight=0)
win_app.grid_rowconfigure(1, weight=0)
win_app.grid_rowconfigure(2, weight=0)
win_app.grid_rowconfigure(3, weight=1)

app_label_login = tk.Label(win_app,text="Nome",)
app_label_login.grid(padx=10,pady=5,row=0,column=0,)

app_txt_login = tk.Entry(win_app,)
app_txt_login.grid(padx=10,pady=5,row=0,column=1,    sticky="ew",columnspan=5,)

app_label_pass = tk.Label(win_app,text="email",)
app_label_pass.grid(padx=10,pady=5,row=1,column=0,)

app_txt_pass = tk.Entry(win_app,)
app_txt_pass.grid(padx=10,pady=5,row=1,column=1,sticky="ew",columnspan=5,)

app_btn_login = tk.Button(win_app,text="Check",command=db_app_check,)
app_btn_login.grid(padx=10,pady=5,row=2,column=0,)

app_btn_new = tk.Button(win_app,text="Add",command=lambda: db_app_add(app_txt_login.get(), app_txt_pass.get()))
app_btn_new.grid(padx=10, pady=5, row=2, column=1,)

app_btn_new = tk.Button(win_app,text="remove",command=lambda: db_app_add(app_txt_login.get(), app_txt_pass.get()))
app_btn_new.grid(padx=10, pady=5, row=2, column=2,)

# app_btn_tst = tk.Button(win_app,text="Test",command=db_tst)
# app_btn_tst.grid(padx=10, pady=5, row=2, column=1,)

app_list = tk.Listbox(win_app)
app_list.grid(row=3, column=0,sticky="ew", columnspan=5,padx=10, pady=10)

db_app_update()

win_app.mainloop()
