'''TKinter comes built-in with Python'''

import tkinter as tk
import mysql.connector

# mysql

conexao = mysql.connector.connect(host="localhost",user="root",password="")
cursor = conexao.cursor()

cursor.execute("create database if not exists login_tst")
cursor.fetchall()

cursor.execute("use login_tst")
cursor.fetchall()

cursor.execute(" \
CREATE TABLE IF NOT EXISTS login( \
id int PRIMARY KEY AUTO_INCREMENT, \
nome varchar(30), \
senha varchar(16) \
) \
")

def login():
    print("login")
# tkinter

windows = []
def window_add(window: tk.Tk()):
    if not window in windows:
        windows.append(window)
    window.mainloop()

def window_del(window: tk.Tk()):
    if window in windows:
        window.destroy

window1 = tk.Tk()
# win_login.protocol("WM_DELETE_WINDOW", tk_close)

window1.geometry("300x250")
window1.minsize(300,250)
window1.title("Login")
window1.iconbitmap("img/tomato.ico")

window1.grid_columnconfigure(0, weight=0)
window1.grid_columnconfigure(1, weight=0)
window1.grid_columnconfigure(2, weight=0)
window1.grid_columnconfigure(3, weight=1)

window1.grid_rowconfigure(0, weight=0)
window1.grid_rowconfigure(1, weight=0)
window1.grid_rowconfigure(2, weight=0)

# def tk_close():
#     print("tk close")
#     win_newuser.destroy()
#     win_login.destroy()

label_login = tk.Label(
    window1,
    text="Login",
)
label_login.grid(
    padx=10,
    pady=5,
    row=0,
    column=0,
)
# label_login.config(bg="yellow")

txt_login = tk.Entry(
    window1,
)
txt_login.grid(
    padx=10,
    pady=5,
    row=0,
    column=1,
    sticky="ew",
    columnspan=3,
)
# txt_login.insert(0, 'username')
# txt_login.config(bg="orange")

label_pass = tk.Label(
    window1,
    text="Password",
)
label_pass.grid(
    padx=10,
    pady=5,
    row=1,
    column=0,
)
# label_pass.config(bg="lightblue")

txt_pass = tk.Entry(
    window1,
)
txt_pass.grid(
    padx=10,
    pady=5,
    row=1,
    column=1,
    sticky="ew",
    columnspan=3,
)
# txt_pass.config(bg="cyan")

btn_new = tk.Button(
    window1,
    text="Login",
    command=login,
)
btn_new.grid(
    padx=10,
    pady=5,
    row=2,
    column=0,
)
q2 = tk.Button(
    window1,
    text="New account",
    command=window1.destroy,
)
q2.grid(
    padx=10,
    pady=5,
    row=2,
    column=1,
)

window1.mainloop()