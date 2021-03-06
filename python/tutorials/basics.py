'''
Fontes:

* https://stackoverflow.com/questions/5844672/delete-an-element-from-a-dictionary
'''


# comentários

# comentário de 1 linha

'''
Comentário de
várias
linhas
'''

"""
Aspas simples
ou duplas
"""

# imprimir comentário

def ler_comentario():
    '''
    Imprimir comentário multi linha,
    usando help()!
    '''
help(ler_comentario)

# print

print("hello world")

print("hello",end=' ')
print("world")

## realiza operações matemáticas

print(1+1) # 2      (soma)

print(1-1) # 0      (subtração)

print(2*3) # 6      (multiplicação)

print(2**3) # 8     (potência)
print(pow(2,3))

print(2/3) # 0.6_   (divisão)

print(2//3) # 0     (divisão arredondado pra baixo)

print(10%2) # 0      (resto)

## juntar texto com número

print("texto", 10) # texto 10                       (vírgula, espaço automático)

print("texto %d"%10) # texto 10                     (estilo C)
print("texto %d"%(10 + 1)) # texto 11               (operações matemáticas)
print("texto %d e %d"%(10, 34)) # texto 10 e 34     (mais de uma variável)

print("texto {}".format(10)) # texto 10             (format)

## aspas simples é o mesmo que aspas duplas

print('hello world')
print("hello world")

## declarar várias variáveis na mesma linha

a, b, c, d, e = 1, 2, 3, 4, 5
# a=1, b=2, c=3, d=4, e=5

## operadores lógicos

print(1 == 2) # False

print(1 > 2) # False

print(1 >= 1) # True
print(1 >= 2) # False

print(1 <= 1) # True
print(1 <= 2) # True

print(not 1 < 2) # False

## oepradores relacionais

num = 10
print(not num == 10) # False
# mesmo que num != 10

for i in range(10):
    print(i) # 0 1 2 3 4 5 6 7 8 9

## dicionário

# criar

dicionario = dict()
dicionario = {}
dicionario = {"chave1":123, 2:"valor2"}

# adicionar

dicionario ["chave1"] = "valor1"
dicionario ["chave2"] = "valor2"

# remover

valor = dicionario.pop("chave1")
del dicionario["chave2"]

# encontrar chave

if "chave1" in dicionario:
    print("chave1 existe")

# iterar chave

for k in dicionario:
    print(k)

# iterar chave e valor

for tuple_kv in dicionario.items():
    print("key",   tuple_kv[0],
          "value", tuple_kv[1])

for k, v in dicionario.items():
    print(k, v)


## lista

# criar

lista = list()
lista = []
lista = [1,2,3]

# adicionar

lista.append(4)             # valor
lista.insert(len(lista), 5) # índice, valor

lista2 = [6,7,8]
lista.extend(lista2)        # lista = [1,2,3,4,5,6,7,8]

# remover

print(lista.index(2))
valor_item_removido = lista.pop()
lista.remove(7)

# aleatório

import random

print(random.random()) # 0.0-1.0

print(random.randrange(0,10)) # 0-10

print(random.uniform(0,10)) # 0.0-10.0

# índice

n = ['a','b','c','d','e','f']
#     0,  1,  2,  3,  4,  5
#    -6, -5,- 4,- 3, -2, -1

print(n[1]) # b

print(n[-1]) # f

print(n[1:3]) # b,c     (igual o range())

