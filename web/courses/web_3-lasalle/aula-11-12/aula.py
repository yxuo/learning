from tkinter import *
import tkinter.messagebox as Messagebox
import mysql.connector as mysql

# init
def ini():
    con=mysql.connect(host='localhost',user='root',password='',database='aula_10')
    cursor = con.cursor()
    cursor.execute('select * from aluno')
    rows = cursor.fetchall()


def insert():
    id = e_id.get()
    nome = e_nome.get()
    email = e_email.get()

    if(id=="" or nome =="" or email==""):
        Messagebox.showinfo('Status inserido','Todos os campos são obrigatórios')
    else:
        con=mysql.connect(host='localhost',user='root',password='',database='aula_10')
        cursor = con.cursor()
        cursor.execute("insert into aluno values(' "+ id +" ',' "+ nome +" ', ' "+ email +" ')")
        cursor.execute('commit')
        show()
        Messagebox.showinfo('Status inserido','Inserido com sucesso!')
        con.close()

def show():
    con=mysql.connect(host='localhost',user='root',password='',database='aula_10')
    cursor = con.cursor()
    cursor.execute('select * from aluno')
    rows = cursor.fetchall()

    for r in rows:
        insertData=str(r[0]) + '              ' +r[1]
        list.insert(list.size()+1,insertData)
    con.close()



    
r=Tk()
r.geometry('600x300')
r.title('Interface com Banco de Dados')

id=Label(r,text='Entre com id')
id.place(x=20,y=30)

nome=Label(r,text='Entre com nome')
nome.place(x=20,y=60)

email=Label(r,text='Entre com email')
email.place(x=20,y=90)

e_id=Entry()
e_id.place(x=130,y=30)

e_nome=Entry()
e_nome.place(x=130,y=60)

e_email=Entry()
e_email.place(x=130,y=90)

insert=Button(r,text='Insert', command=insert)
insert.place(x=20,y=140)

delete=Button(r,text='Delete')
delete.place(x=65,y=140)

update=Button(r,text='Update')
update.place(x=115,y=140)

get=Button(r,text='Select')
get.place(x=170,y=140)

#para mostrar o resultado dentro de um listbox

list = Listbox(r)
list.place(x=290,y=30)
show()


r.mainloop()
