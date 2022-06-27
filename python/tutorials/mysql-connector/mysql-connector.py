'''
REQUISITOS:

* XAMPP - para usar localhost, PHP, APache e MySQL

    * 🖥️ Terminal: winget install xampp

    * ⬇️ Baixar: https://www.apachefriends.org/pt_br/index.html

    Pós instalação:

    1. Após instalar, inicie o XAMPP

    2. Na janela principal, clique em Start em Apache e MySQL
    
        * Caso a coluna Service mostre um ❌ em Apache ou MySQL, clique neste botão ❌ para instalar o módulo.
        
        * Caso Apache e MySQL estejam mostrando um ✔️, então tudo está funcionando!
        
    * 💽 Para ver o banco de dados, clique em Admin na linha MySQL!

    * 🌎 O seu site local normalmente é [localhost]

    * 📁 Para ver a pasta onde o site fica há 2 maneiras:

        1. Na janela do XAMP, clique no botão [📁 Explorer]

        2. Pesquise no Windows por [htdocs], você verá uma sugestão chamada [XAMPP htdocs folder].


* Python nativo no PC

    * 🖥️ Terminal: winget install "python 3.10* 

    * ⬇️ Baixar: https://www.python.org/downloads/
'''

import mysql.connector
import os

conexao = mysql.connector.connect(
    host='localhost',
    user='root',
    password=''
)

cursor = conexao.cursor()

cursor.execute('CREATE DATABASE IF NOT EXISTS aula8')
cursor.fetchall()


# TEMP
cursor.execute("show columns from cadastro like 'time';")
if not cursor.fetchall():
    cursor.execute("ALTER TABLE 'cadastro' ADD 'time_id' INT NOT NULL AFTER 'senha';")
    conexao.commit()
    cursor.execute("ALTER TABLE 'cadastro' ADD CONSTRAINT 'time_fk' FOREIGN KEY ('time_id') REFERENCES 'times'('id') ON DELETE NO ACTION ON UPDATE NO ACTION;")
    conexao.commit()
    # ALTER TABLE `cadastro` ADD CONSTRAINT `time_fk` FOREIGN KEY (`time_id`) REFERENCES `times`(`id`) ON DELETE NO ACTION ON UPDATE NO ACTION; 

    # alter table  'cadastro' add constraint 'time_fk' foreign key ('time_id') references 'times'('id') on delect no action;
    
    
# IF EXISTS( SELECT time FROM cadastro)THEN select * from cadastro END IF;

# if not exists(select * from information_schema.tables where table_schema = 'TheSchema') then 
cursor.execute("\
                IF NOT EXISTS( \
                    SELECT * \
                    FROM INFORMATION_SCHEMA.TABLES \
                    WHERE TABLE_SCHEMA = 'TheSchema' \
                    AND  TABLE_NAME = 'TheTable')) \
                ) THEN \
                    ALTER TABLE `TableName` ADD `ColumnName` int(1) NOT NULL default '0';\
                END IF;\
")
# select * from information_schema.table_constraints where constraint_schema = 'cadastro'
# ALTER TABLE `cadastro` ADD `ColumnName` int(1) NOT NULL default '0';

os._exit(0)
# TEMP

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

cursor.execute("USE aula8")

# criar tabela

# cursor.execute(" \
# CREATE TABLE IF NOT EXISTS aluno( \
#     matricula int PRIMARY KEY AUTO_INCREMENT, \
#     nome varchar(40), \
#     idade int(3), \
#     email varchar(30) \
# ) \
# ")
cursor.execute(
    "create table if not exists cadastro(usuario varchar(20) primary key, senha varchar(20))")
# cursor.fetchall()
# os._exit(0)

# mostrar tabelas do BD selecionado
cursor.execute("SHOW TABLES;")
cursor.fetchall()

# mostrar atributos da tabela

cursor.execute("DESC aluno;")  # DESC ou DESCRIBE
cursor.fetchall()

# inserir dados

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
