print("ini")

import mysql.connector

# cria objeto de conexão SQL
conexao = mysql.connector.connect(
    host = 'localhost',
    user = 'root',
    password = ''
)

# cursor é a linha selecionada no BD
cursor = conexao.cursor()

# criar BD

cursor.execute('CREATE DATABASE IF NOT EXISTS aula8')

# percorrer (e descartar) todas as linhas do resultado

# print retorno SQL
'''
for x in cursor:
    print(x)
'''
retorno = cursor.fetchall()
print(retorno)

# ver todos os BDs

#cursor.execute('SHOW DATABASES;')

# entrar no BD

cursor.execute("USE aula8;")

# criar BD

cursor.execute(" \
CREATE TABLE IF NOT EXISTS aluno( \
    matricula int PRIMARY KEY AUTO_INCREMENT, \
    nome varchar(40), \
    idade int(3), \
    email varchar(30) \
); \
")
cursor.fetchall()

# mostrar tabelas do BD selecionado
cursor.execute("SHOW TABLES;")
cursor.fetchall()

# mostrar atributos da tabela

cursor.execute("DESC aluno;") #DESC ou DESCRIBE
cursor.fetchall()

#inserir dados

# string esqueleto para executar SQL
'''
sql = "insert into aluno(nome,idade,email) values(%s,%s,%s)"

val = [
    ["Anie","20","anie@gmail.com"],
    ["Adriana","25","adriana@gmail.com"],
    ["Paulo","32","paulo@gmail.com"]
    ]
cursor.executemany(sql,val)
conexao.commit()
print(cursor.rowcount, "registros inseridos") # 3 registros inseridos
'''
