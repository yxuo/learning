* Verifique como vai ficar a fila e memória após executar as instruções:

```
insert(q,20)
insert(q,10)
insert(q,50)
x = remove(S)
y = remove(S)
x = x+y
insert(q,20)
y=y*2
insert(q,y)
insert(q,45)
x=remove(q)
```

Rsposta:

```
q [20]
q [20,10]
q [20,10,50]
q [10,50]       x = 20
q [50]          y = 10
x = 30
q [50,30]
y = 20
q [50,30,20]
q [50,30,20,45]
q [30,20,45]    x = 50
```

* Verifique como a fila ficará:

```
push(s,20)
push(s,10)
push(s,50)
x=pop(s)
y=pop(s)
x=x+y
push(s,y)
push(s,30)
push(s,45)
x=pop(s)
```

Resposta:

```
20
10,20
50,10,20
10,20           x=50
20              y=10
x=60
60,20
y=30
30,60,20
30,30,60,20
45,30,30,60,20
30,30,60,20     x=45
```