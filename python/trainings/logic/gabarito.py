# gabarito das listas de web 3

'''
# como chamar as funções
lista_1.q1() 
lista_1.q2()
etc.
'''

class lista_1:

    def q1():
        lista = [2,3,4,5,10,12]
        resultado = sum(lista)/2
        print(resultado)

    def q2():
        a = 3
        b = 4
        print("Números:",a,b)
        print("Soma:", a+b)
        print("Subtração:", a-b)
        print("Multiplicação:",a*b)
        print("Divisão:",a/b)
        print("Divisão inteira:",int(a/b))
        maior = a if a>b else b
        menor = a if a<b else b
        print("Maior:",maior)
        print("menor:",menor)
        print("Divisão maior pelo menor:",maior/menor)

    def q3():
        notas = [int(input("Insira nota:")) for i in range(4)]
        print("Notas:",notas)
        print("Média:",sum(notas)/len(notas))

    def q4():
        dia = input("Insira dia:")
        mes = input("Insira mês:")
        ano = input("Insira ano:")
        meses = [
            "janeiro", "fevereiro", "março", "abril", "maio",
            "junho", "julho", "agosto", "setembro", "outubro",
            "nonvembro", "dezembro"
        ]
        nums = [
            "zero", "um", "dois", "três", "quatro", "cinco",
            "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze","catorze",
        "quinze","dezesseis","dezessete","dezoito","dezenove","vinte","trinta"]
        if len(ano)==2 and int(ano) <= 22:
            ano = int(ano) + 2000
        elif len(ano) == 2 and int(ano) > 22:
            ano = int(ano) + 1000
        cento = "cento" if int(ano[1:3])>100 else "cem"
        txt_dia = "zero";
        if int(dia)>0 and int(dia)<=20:
            txt_dia = nums[int(dia)]
        else:
            dezenas = ["dez","vinte","trinta"]
            txt_dia = dezenas[int(dia[0])]
            txt_dia += " e "
            txt_dia += nums[int(dia[1])]
        
        txt_ano = ""
        # milhar
        if ano[0] != "0":
            txt_ano += "mil " if ano[0] == "1" else nums[int(ano)] + " mil "
        # centena
        if ano[1] != "0":
            centena = [
                "cem","cento","duzentos","tezentos","quatrocentos","quinhentos",
                "seiscentos","setecentos","oitocentos","novecentos"
            ]
            if ano[2:] == "00":
                txt_ano += " e "
            else:
                txt_ano = centena[0] if ano[1] == "1" else centena[int(ano[1])]
        #dezena
        if ano[2] != "0":
            dezena = [
                0,"dez","vinte","trinta","quarenta","cinquenta","sessenta","setenta",
                "oitenta","noventa"]
            txt_ano += " e " + dezena[int(ano[2])]
        #unidade
        if ano[3] != "0":
            txt_ano += " e " + nums[int(ano[3])]
        print("Você nasceu em %s de %s de %s"%(txt_dia,meses[int(mes)-1],txt_ano))

########################################

class lista_2:

    def q1():
        import random
        num = str(random.randint(0,9999))
        print("unidade:",num[-1])
        if len(num)>1:
            print("dezena:",num[-2])
        if len(num)>2:
            print("centena:",num[-3])
        if len(num)>3:
            print("milhar:",num[-4])

    def q2():
        inteiros = [int(input("insira numero inteiro: ")) for i in range(2)]
        real = int(input("insira numero real: "))
        print((inteiros[0]*2)*(inteiros[1]/2))
        print((inteiros[0]*3)+(real))
        print(real**3)

    def q3():
        num = int(input("insira numero: "))
        print("O numero digitado foi:",num)

    def q4():
        metros = float(input("insira metros: "))
        print("%.2f metros é %.2f centímetros"%(metros,metros*100))

    def q5():
        far = float(input("insira fahrenheit: "))
        print("%.2f F é igual a %.2f oC"%(far,(5*((far-32)/9))))

#######################################

class lista_3:

    def q1():
        nome = input("insira nome completo: ")
        print("maiusc", nome.upper())
        print("minusc", nome.lower())
        nome_sp = [i for i in nome if i != ' ']
        print("comp nome sem sp", len(nome_sp))
        print("comp 1o nome", len(nome[:nome.index(' ')]))

    def q2():
        capacidade = int(input("insira capacidade elevador: "))
        peso_pessoas = [int(input("insira peso da pessoa %d/5"%i+1)) for i in range(5)]
        if sum(peso_pessoas) > capacidade:
            print("peso excedido")
        else:
            print("elevador liberado")

    def q3():
        nome = input("insira nome: ")
        meu_nome = "Raphael Rivas"
        if nome == meu_nome:
            print("O nome é igual ao meu")
        else:
            print("Nome Incorreto")

    def q4():
        ano = int(input("insira ano: "))
        if ano % 4 == 0:
            print("ano bissexto")
        else:
            print("ano comum")

class lista_4:

    def q1():
        max = int(input("insira um número para calcular o Fibonacci"))
        a1 = 1
        a2 = 2
        num = 0
        while a1+a2 < max**2:
            num = a1+a2
            a1 = a2
            a2 = num
            if num >= max:
                print("%d"%num)

    def q2():
        num = int(input("insira numero"))
        _num = num
        for n in range(1,10):
            num*=n
        print(num)

    def q3():
        for n in range(1,10):
            print(n)
            if n == 9:
                break

    def q4():
        for n in range(1,20+1):
            print(n)
        for n in range(1,20+1):
            print(n,end=' ')
        print()

    def q5():
        while True:
            nota = input("Digite uma nota: ")
            if nota.isdigit() and int(nota) >= 0 and int(nota) <= 10:
                break
            print("VALOR INVALIDO. Insira um numero de 0-10")

    def q6():
        for i in range(1,50):
            if i % 2 != 0:
                print(i)

    def q7():
        lista = [18,43,2,489,90,666, -3]
        print("menor %d\t maior %d\tsoma %d"%(min(lista),max(lista),sum(lista)))

    def q8():
        lista = [18,43,2,489,90,666,-3]
        for i in reversed(lista):
            if i < 0 or i > 100:
                print(i)
                lista.remove(i)
        print("menor %d\tmaior %d\tsoma %d" % (min(lista),max(lista),sum(lista)))

    def q9():
        #a.
        soma = 0;
        for i in range(2,101):
            print(i)
            soma += i
        print("soma ",soma)

        #b.
        quad = 0
        for i in range(1,101):
            quad += i**2
        print("quadrado ",quad)

        #c.
        a = input("insira o numero a ")
        b = input("Insira o numero b ")
        print("soma entre %d - %d: " % (a,b), sum([i for i in range(a,b+1)]))

        #d.
        num = input("Insira um conjunto de digitos")
        soma = sum([int(i) for i in num if int(i)%2!=0])
        print(soma)

class lista_5:

    def q1():
        extenso = (
            "zero", "um", "dois", "três", "quatro",
            "cinco", "seis", "sete", "oito", "nove",
            "dez", "onze", "doze", "treze", "quatorze",
            "quinze", "dezesseis", "dezessete", "dezoito", "dezenove",
            "vinte"
        )
        entrada = int(input("Insira um número 0-20: ") or 0)
        entrada = 20 if entrada > 20 else 0 if entrada < 0 else entrada
        print("Seu número é", extenso[entrada])

    def q2():
        campeonato = (
            "Atlético-MG", "Flamengo", "Palmeiras", "Fortaleza", "Corinthians",
            "Bragantino", "Fluminense", "América-MG", "Atlético-GO", "Santos",
            "Ceará", "Internacional", "Sâo Paulo", "Athletico-PR", "Cuiabá",
            "Juventude", "Grêmio", "Bahia", "Sport", "Chapecoense"
        )
        print("a) Os 5 primeiros colocados:", campeonato[5])
        print("b) Os 4 últimos colocados:", campeonato[-4])
        print("c) Jogadores em ordem alfabética:",', '.join(sorted(campeonato)))
        vasco = [i for i in campeonato if i == "Vasco"]
        print("d) Vasco está na colocação %d"%int(campeonato.index(vasco[0])+1) if vasco else "Vasco está fora dos 20 colocados")

    def q3():
        inteiros = [int(input("insira um número inteiro") or i) for i in range(4)]
        print("inteiros:",inteiros)
        print("O número 9 apareceu %d vezes"%inteiros.count(9))
        print("O número 3 apareceu primeiro na posição",inteiros.index(3))
        print("pares:",[i for i in inteiros if i%2==0])

    def q4():
        reais = [float(input("insira um número real: ") or i) for i in range(10)]
        print("números",reais)
        reais.reverse()
        print("reverso",reais)

    def q5():
        inteiros = [int(input("insira um número inteiro") or i) for i in range(20)]
        par = [i for i in inteiros if i%2==0]
        impar = [i for i in inteiros if i%2!=0]
        print("inteiros",inteiros)
        print("pares",par)
        print("ímpar",impar)

    def q6():
        import math
        inteiros = [int(input("insira um número inteiro:") or i+1)for i in range(5)]
        print("soma", sum(inteiros))
        print("multiplicação", math.prod(inteiros))
        print("números",inteiros)

    def q7():
        import random
        idades = []
        alturas = []
        for i in range(5):
            idades.insert(len(idades),int(input("insira a idades: ") or random.randint(15,40)))
            alturas.insert(len(alturas),float(input("insira a alturas: ") or round(float(random.random()),2)+1))
            # print("idades:", idades)
            # print("idades:", alturas)
        idades.reverse()
        alturas.reverse()
        print("As idades são:", idades)
        print("As alturas são:", alturas)

    def q8():
        perguntas = [
            (input("telefonou par a vítima? ") or "não"),
            input("Esteve no local do crime? ") or "não",
            input("Mora perto da vítima? ") or "não",
            input("Devia para a vítima? ") or "não",
            input("Já trabalhou com a vítima? ") or "não"
        ]
        positivas = [i for i in perguntas if i.lower() == "sim"]
        negativas = [i for i in perguntas if i.lower() != "sim"]
        if len(positivas) == 2:
            print("Suspeito")
        elif len(positivas) in [3,4]:
            print("Cúmplice")
        elif len(positivas) == 5:
            print("Assassino")
        else:
            print("Inocente")

    def q9():
        import random
        sorteio = [random.randint(1,10) for i in range(10)]
        print(sorteio)
        [print("%d foi sorteado"%i,sorteio.count(i),"vezes") for i in range(6)]

    def q10():
        import random
        vetor = [round(random.uniform(0,10),2) for i in range(4)]
        media = 6.0
        print("Vetor =",vetor)
        print("(média = %.2f)"%media)

        # 1. cria vetor_abs, contendo a diferença entre os números do vetor e a média
        # 2. obtém o menor valor
        # 3. obtém o índice desse menor valor
        # 4. usa esse índice para apontar o valor do vetor original, que é o menor número
        vetor_abs = [round(abs(i-media),2) for i in vetor]
        print("Valor mais próximo da média =",
            vetor[vetor_abs.index(min(vetor_abs))]
            )

class lista_6:

    def q1():
        semana = {}
        semana["segunda"] = ["WEB3"]
        semana["quarta"] = ["ARQUIT.INFO"]
        semana["quinta"] = ["ANALISE.SIST","EST.DADOS"]
        for k, v in semana.items():
            print(k, v)

    def q2():
        alunos = {}
        for i in range(3):
            nome = input("Nome: ")
            media = int(input("Media: "))
            alunos [nome] = "APROVADO" if i >= 6 else "REPROVADO"
        [print(k,v) for k, v in alunos.items()]

    def q3():
        import random
        jogadores = {}
        for i in range(3):
            jogadores [input("Jogador: ")] = [random.randint(1,6)]
        print("Resultado")
        print(sorted(jogadores, key=jogadores.get, reverse=True))
        print(sorted(jogadores.values(), reverse=True))

    def q4():
        pessoas = {}
        for i in range(3):
            nome = input("Nome: ")
            cpts = int(input("Carteira de trabalho? [0=NAO, 1=SIM]: "))
            if cpts != 0:
                ano = int(input("Ano de contratacao: "))
                salario = float(input("Salario: "))
                pessoas[nome] = [cpts, ano, salario]
            else:
                pessoas[nome] = [cpts]
        print(pessoas)

    def q5():
        pessoas = {}
        for i in range(3):
            nome = input("Nome: ")
            peso = float(input("Peso: "))
            pessoas [nome] = peso
        print("Cadastrados: ",len(pessoas))
        print("Mais pesados: ",
        sorted(pessoas, key=pessoas.get, reverse=True),
        sorted(pessoas.values(), reverse=True))
        print("Mais leves: ",
        sorted(pessoas, key=pessoas.get),
        sorted(pessoas.values()))

    def q6():
        nums = [int(input("Insira um numero: ")) for i in range(4)]
        print("Pares:",[i for i in nums if i%2==0])
        print("Imares:",[i for i in nums if i%2!=0])

    def q7():
        nums = [int(input("Insira um numero: ")) for i in range(5)]
        print(nums)
        for i in nums:
            while nums.count(i)>1:
                nums.remove(i)
        print(nums)

    def q8():
        tamanho = int(input("insira tamanho da agenda: "))
        agenda = {}
        for i in range(tamanho):
            nome = input("insira nome: ")
            telefone = int(input("insira telefone: "))
            agenda[nome] = telefone
        [print(i) for i in agenda.items()]

    def q9():
        def aprovados(d):
            print("Aprovados: ",[(i[0],sum(i[1])/3) for i in d.items() if sum(i[1])>7*3])
            print("Reprovados: ",[(i[0],sum(i[1])/3) for i in d.items() if sum(i[1])<=7*3])
        alunos = {'Alano':(7.5,8.0,6.5),'Denise':(9.0,8.5,9.5),'Ana Paula':(3.5,1.0,6.5)}
        aprovados(alunos)

class lista_7:
    def q1():
        def voto(ano_nasc):
            if ano_nasc in range(16,19) and ano_nasc > 60:
                return "OPCIONAL"
            if ano_nasc in range(18,61):
                return "OBRIGATORIO"
            if ano_nasc < 16:
                return "NEGADO"
        voto(int(input("insira ano nascimento: ")))

    def q2():
        def fatorial(num, log = False):
            ret = 1;
            for i in reversed(range(1,num+1)):
                ret *= i
                print(i,end='X')
            return ret
        print(fatorial(5, show=False))

    def q3():
        def fichat(nome="Sem Nome",gols = 0):
            print("Nome:",nome)
            print("Gols:",gols)
        fichat(input("insira nome do jogador: "),int(input("insira numero de gols: ")))

    def q4():
        def leia_int(texto=""):
            inp = 0
            while True:
                inp = input(texto)
                if inp.isnumeric():
                    return(int(inp))
        print("número:",leia_int("insira número"))

    def q5():
        def notas():
            notas = {}
            for i in range(3):
                notas[input("insira aluno: ")] = [int(input("insira nota: ")) for i in range(3)]
            for k,v in notas.items():
                print("aluno:",k)
                print("maior nota:",max(v))
                print("menor nota:",min(v))
                v.remove(min(v))
            print("media da turma:",sum([sum(i) for i in notas.values()])/(3*len(notas)),end="\n\n")
            print("maior nota da turma:",max([max(i) for i in notas.values()]))
            print("menor nota da turma:",min([min(i) for i in notas.values()]))
        notas()

    def q6():
        def hello_world():
            '''
            Imprime um hello world :)
            '''
            print("hello world")

        help(hello_world)
        hello_world()

class lista_7_1:
    '''revisão / teste'''
    def q1():
        aluno = input("Insira nome do aluno: " )
        dias = input("insira dias da semana: ")
        tipo = input("Insira o tipo de curso [B]asico [I]ntermediario [A]vancado: " )
        dias = int(dias)
        total = dias*7*15
        if tipo == "I":
            total = dias*8.5*20
        if tipo == "A":
            total = dias*10*25
        print("aluno:",aluno)
        print("valor a ser pago:",total)

    def q2():
        num = int(input("insira num inteiro > 0: "))
        if not(num>0):
            print("Número inválido")
        else:
            num = str(num)
            num = sum([int(i) for i in num])
            print("soma dos algarismos:",num)

    def q3():
        nums = [int(input("insira numero %d/7: "%(i+1))) for i in range(7)]
        print("pares:",[i for i in nums if i%2==0])
        print("impares:",[i for i in nums if i%2!=0])

    def q4():
        pessoas = {}
        for i in range(3):
            nome = input("insira nome: ")
            idade = int(input("insira idade: "))
            cpf = input("Insira CPF: ")
            pessoas[cpf] = [nome,idade]
        pessoas2 = {}
        for k,v in list(pessoas.items()):
            if v[1] < 18:
                del(pessoas[k])
                pessoas2[k] = v
        print("Maiores de idade:",pessoas)
        print("Menores de idade:",pessoas2)

#######################################

class lista_7_2:
    '''AV1'''
    def q1():
        print("a) = 25")
        print("b) = Verdadeiro")

    def q2():
        ano = int(input("insira ano"))
        if (ano%40==0 or ano%400) and ano%100!=0:
            print("ano comum")
        elif True:
            print("ano bissexto")

    def q3():
        # TODO: esperar gabarito oficial
        return

    def q4():
        total = float(input("insira total pago "))
        tipo = int(input("insira tipo comprador: comum(1), func(2), vip(3) "))
        comp = ""
        if tipo == 1:
            comp = "comum"
        elif tipo == 2:
            total -= total*10/100
            comp = "funcionario"
        elif tipo == 3:
            total -= total*5/100
            comp = "vip"
        else:
            comp = "INVALIDO"
        
        print("total",total)
        print("compardor",comp)
lista_7_2.q4()