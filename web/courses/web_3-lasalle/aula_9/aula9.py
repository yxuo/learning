import mysql.connector

# criar obj conexão mysql
conexao = mysql.connector.connect(host="localhost",user="root",password="")
cursor = conexao.cursor()

# criar bd
cursor.execute("create database if not exists aula9")
print(cursor.fetchall())

# entrar bd
cursor.execute("use aula9")
print(cursor.fetchall())

# mostrar tabelas BD
cursor.execute("SHOW TABLES")
ret = cursor.fetchall()
print(ret)

# criar tabela
cursor.execute(" \
CREATE TABLE IF NOT EXISTS pessoa( \
    cod_pessoa int PRIMARY KEY AUTO_INCREMENT, \
    nome varchar(40), \
    idade int(3), \
    email varchar(30) \
) \
")
print(cursor.fetchall())

# inserir linha (usando listas)
sql = "insert into pessoa(nome,idade,email) values(%s,%s,%s)"
val = [
    ["Anie","20","anie@gmail.com"],
    ["Adriana","25","adriana@gmail.com"],
    ["Paulo","32","paulo@gmail.com"]
    ]
cursor.executemany(sql,val)
conexao.commit()
print(cursor.rowcount, "registros inseridos") # 3 registros inseridos
print(cursor.fetchall())

# ! sempre que alterar tabela usa .commit()

# mostrar tabela
def table_show(table, oneline=False):
    exec = "A " + "b"
    print(exec)
    cursor.execute("select * from " + table)
    if oneline:
        for x in cursor:
            print(x)
    else:
        print(cursor.fetchall())
table_show("pessoa", True)

# remover vários registros (linhas)
sql = "delete from pessoa where cod_pessoa in (%s,%s)"
cursor.execute(sql,(1,2))
val = [
    ["Anie","20","anie@gmail.com"],
    ["Adriana","25","adriana@gmail.com"],
    ["Paulo","32","paulo@gmail.com"]
    ]
conexao.commit()
print(cursor.rowcount, "registro(s) restantes") # 2 registros inseridos
print(cursor.fetchall())
table_show("pessoa",True)

# remover reg no intervalo
sql = "delete from pessoa where cod_pessoa in (%s,%s)"
cursor.execute(sql,(1,2))
val = [
    ["Anie","20","anie@gmail.com"],
    ["Adriana","25","adriana@gmail.com"],
    ["Paulo","32","paulo@gmail.com"]
    ]
conexao.commit()
print(cursor.rowcount, "registro(s) restantes") # 2 registros inseridos
print(cursor.fetchall())


# FIM
# apagar tabela
cursor.execute("drop table pessoa")