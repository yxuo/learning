# Aula 5

## Termos utilizados:

* Checksum, hash - um código aleatório como este:
  
  ```git
  7f565c37e45effb008ef146b5661eb40e302e2d3
  ```
  
  ou este:
  
  ```git
  7f565c3
  ```

## Tag (etiqueta)

Servem como atalhos para algum commit que você considere importante, um marco do seu projeto.

Normalmente é usado para marcar as novas versões de programas (e.g. `v1.0`, `v1.1`)

> É possível adicionar várias tags para o mesmo commit.

Há dois tipos de tags:

* **Tag leve**  - um mero atalho que aponta para um commit específico;

* **Tag anotada** - além de ser um atalho para um commit, ele contém o nome , email, data, hash e uma mensagem de tag (opcional, mas recomendado). 

### Qual devo usar?

* **Tag leve**: Caso queira criar uma tag temporária ou simplesmente não quer guardar informações, apenas apontar.

* **Tag anotada**: Na dúvida, sempre crie tags anotadas, eles terão registros para você consultar depois.

### Listar tags:

```git
git tag
```

### Ver detalhes da tag:

:warning: Este comando abre o VIM, se usado fora do Git Bash.

```git
git show v1.0
```

Retorno:

```git
tag v1.0
Tagger: Raphael Rivas <raphaelrivas@hotmail.com>
Date:   Sun Apr 10 01:07:08 2022 -0300

primeira versao

commit 7f565c37e45effb008ef146b5661eb40e302e2d3 (tag: v1.0)
Author: Raphael Rivas <raphaelrivas@hotmail.com>
Date:   Sat Apr 9 02:26:27 2022 -0300

    teste del

diff --git a/teste.txt b/teste.txt
index 95d09f2..83063e3 100644
--- a/teste.txt
```

> Caso queira ver apenas os detalhes do commit, use `git show` + checksum do commit

### Criar tag leve:

Por padrão as tags são criadas apontando para o commit mais recente.

```git
git tag v1.0
```

> :warning: Não é encorajado usar tags leves, pois eles não contém informações

### Criar tag anotada:

```git
git tag -a v1.0 -m "versao 1.0"
```

### Criar tag em qualquer commit:

Como boa prática, criou-se uma tag anotada.

```git
git tag -a v0.0 -m "primeira versao" 7f565c37e45effb008ef146b5661eb40e302e2d3
```

> Em outras palavras: `git tag` + checksum do commit.
> 
> A ordem dos parâmetros não faz diferença, mas nesta ordem parece organizado.

VSCode:

![git tag no VSCode](../../img/git-tag-vscode.png)

gitk:

![git tag no gitk](../../img/git-tag-gitk.png)

> Não é possível criar tag no Git GUI, apenas no gitk.

### Remover tag:

```git
git tag --delete "primeira versao"
```

## Trocar de commit usando tag:

## Ver detalhes do commit:

```git
git show 576ac7be6b79d4e260ac9be5291134e88761854f
```

## Árvore Git

```mermaid
gitGraph:
options
{
    "nodeSpacing": 90,
    "nodeRadius": 10
}
end
commit
commit
branch test
checkout test
commit
commit
checkout master
commit
commit
merge test
```

A imagem acima é uma árvore Git.

Cada *bolinha* é um commit, cada um contendo cada alteração publicada no repositório.  
Como uma verdadeira máquina do tempo.

Nesta árvore temos dois ramos (branchs):

* Azul - o ramo principal chamado `master` (nome automático)

* Vermelho - o ramo extra, foi chamado chamado de `test`

### HEAD (você)

```mermaid
flowchart RL

H["HEAD<br><sub>Você está aqui"] -.-> c

subgraph S1[" "]
B1["master<br><sub>cabeça do ramo"]-.->a
a(("abe667b"))---b(("f3661c8"))---c(("9a48e92"))---d(("576ac7b"))
end

style H fill:#fef4ac, stroke:black
style S1 fill: transparent, stroke: transparent
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke:darkblue, stroke-width: 4px
style d stroke:darkblue, stroke-width: 4px
linkStyle 2,3,4 stroke:darkblue,stroke-width:8px;
```

HEAD é um ponteiro que aponta para o commit em que você está.

#### Mover HEAD para qualquer commit:

```git
git checkout 9a48e92
```

Resultado:

```mermaid
flowchart RL

H["HEAD<br><sub>Você está aqui"] -.-> b

subgraph S1[" "]
B1["master<br><sub>cabeça do ramo"]-.->d
d(("⠀<b>??⠀"))-.-c(("⠀<b>??⠀"))-.-b(("9a48e92"))---a(("576ac7b"))
end

style H fill:#fef4ac, stroke:black
style S1 fill: transparent, stroke: transparent
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke:darkblue, stroke-width: 4px, stroke-dasharray: 11 11
style d stroke:darkblue, stroke-width: 4px, stroke-dasharray: 11 11
linkStyle 4 stroke:darkblue,stroke-width:8px
linkStyle 2,3 stroke:darkblue,stroke-width:8px
```

Como regra geral, você nunca consegue visualizar commits a sua frente, apenas atrás de você.  
Por isso a imagem mostra duas icógnitas, estão a frente de você.

#### Mover para a cabeça do branch:

```git
git checkout HEAD
```

#### V

### Ramo (branch)

> O branch é um ponteiro móvel para um commit.
> 
> A cada novo commit ele avança automaticamente.
 
*Documentação no site do Git*.

Você verá o branch através de seu nome (`master`, `test`, `meu ramo`, etc).

```mermaid
flowchart LR

H["HEAD<br><sub>Você está aqui"] -.-> c
T2>"v0.2<br><sub>Etiqueta"] -.-> d
B1["master<br><sub>cabceça do ramo"] -.-> d

subgraph S1[" "]
a(("576ac7b"))---b(("9a48e92"))---c(("f3661c8"))---d(("abe667b"))
end

%%subgraph S2[" "]
b---2a(("79af9f5"))---2b(("c82f976"))
%%end

B2["test<br><sub>cabceça do ramo"] -.-> 2b
T1>"v0.1<br><sub>Etiqueta"] -.-> a

style H fill:#fef4ac, stroke:black
style S1 fill: transparent, stroke: transparent
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke:darkblue, stroke-width: 4px
style d stroke:darkblue, stroke-width: 4px
style 2a stroke:darkred, stroke-width: 4px
style 2b stroke:darkred, stroke-width: 4px
linkStyle 3,4,5 stroke:darkblue,stroke-width:8px;
linkStyle 6,7 stroke:darkred,stroke-width:8px;
```

* O repositório foi criado, sem commits, sem nada.

* Então criamos o readme.md, e confirmamos.

* Como resultado, nossa árvore Git é uma única bolinha, um único commit

* HEAD representa duas coisas:
  
  1. O commit em que você (usuário) está;
  
  2. A cabeça do seu ramo.

Editamos o readme e confirmamos as alterações:

```mermaid
flowchart LR
subgraph S[" "]
a(("576ac7b"))---b(("<u>master</u><br>9a48e92"))---c(("f3661c8"))---d(("abe667b"))
end
N("HEAD<br><sub>Você está aqui") -..-> a

style S fill: transparent, stroke: transparent
style N fill:#fef4ac, stroke:#d3d398
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke-width: 0, fill: transparent,color: transparent
style d stroke-width: 0, fill: transparent,color: transparent

linkStyle 1,2 stroke: transparent
linkStyle 0 stroke:darkblue,stroke-width:8px;
```

* Perceba que você estava

## Branch (ramo)

```mermaid
flowchart LR
subgraph S[" "]
a(("<u>v1.0</u><br>576ac7b"))---b(("9a48e92"))---c(("f3661c8"))---d(("master<br>abe667b"))
end
b---b1(("test<br>79af9f5"))---b2(("c82f976"))

style S fill: transparent, stroke: transparent
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke:darkblue, stroke-width: 4px
style d stroke:darkblue, stroke-width: 4px
style b1 stroke:darkred, stroke-width: 4px
style b2 stroke:darkred, stroke-width: 4px
linkStyle 0,1,2 stroke:darkblue,stroke-width:8px;
linkStyle 3,4 stroke:darkred,stroke-width:8px;
```

## Navegando na árvore

# 

```mermaid
flowchart LR
subgraph S[" "]
a(("<u>v1.0</u><br>576ac7b"))---b(("7098351"))---c(("0009400"))---d(("master<br>abe667b"))
e("Você está<br>aqui") -..-> d
end
b---b1(("test<br>79af9f5"))---b2(("c82f976"))

style S fill: transparent, stroke: transparent
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke:darkblue, stroke-width: 4px
style d stroke:darkblue, stroke-width: 4px
style b1 stroke:darkred, stroke-width: 4px
style b2 stroke:darkred, stroke-width: 4px
linkStyle 0,1,2 stroke:darkblue,stroke-width:8px;
linkStyle 4,5 stroke:darkred,stroke-width:8px;
style e fill:#fef4ac, stroke:#d3d398
```

### Mudar de commit:

```git
git checkout insira_hash_do_commit
git checkout 
```

### Mudar de commit via tag:

```git
git checkout  nome_da_tag
```

## Recuperar commits que "sumiram":

Visualizar últimos *hashes*:

```git
git reflog
```

Retornar ao commit anterior:

```git
git reset --hard <sha1>
```

### Curiosidades sobre árvore Git

O sistema de metrô do Rio de Janeiro parece uma árvore Git.  
Uma bem reta.

![linhas de metrô do Rio de Janeiro](https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/Diagrama_metro_rio.png/1280px-Diagrama_metro_rio.png)

Veja como o metrô do Rio em forma de Git:

![mapa de metrô do Rio de Janeiro](../../img/git-metro-rio-map.svg)

```mermaid
flowchart
subgraph legenda
tag>tag]
branch[branch]
end
subgraph L1[" "]
a(("⠀"))---|"branch Linha-2<br>checkout Linha-2<br>commit"|b(("⠀"))---|commit|c(("⠀"))---|commit|d(("⠀"))---|commit|e(("⠀"))---|commit|f(("⠀"))---|commit<br>merge master|g(("⠀"))---|checkout maste<br>commit|h(("⠀"))---|commit|i(("⠀"))
end
subgraph L2[" "]
g---|branch Linha-2<br>checkout Linha-2<br>commit|2g(("⠀"))---|commit|2h(("⠀"))---|commit|2i(("⠀"))---|commit|2j(("⠀"))---|commit|2k(("⠀"))
end
subgraph L4[" "]
4a(("⠀"))---|commit|4b(("⠀"))---|commit|4c(("⠀"))-.->|rebase Linha-4 master|a
end

style L1 fill: transparent, stroke: transparent
style L2 fill: transparent, stroke: transparent
style L4 fill: transparent, stroke: transparent
style a fill: white, stroke: #f26820, stroke-width: 4px
style b fill: white, stroke: #f26820, stroke-width: 4px
style c fill: white, stroke: #f26820, stroke-width: 4px
style d fill: white, stroke: #f26820, stroke-width: 4px
style e fill: white, stroke: #f26820, stroke-width: 4px
style f fill: white, stroke: #f26820, stroke-width: 4px
style g fill: white, stroke: #f26820, stroke-width: 4px
style h fill: white, stroke: #f26820, stroke-width: 4px
style i fill: white, stroke: #f26820, stroke-width: 4px
style 2g fill: white, stroke: darkgreen, stroke-width: 4px
style 2h fill: white, stroke: darkgreen, stroke-width: 4px
style 2i fill: white, stroke: darkgreen, stroke-width: 4px
style 2j fill: white, stroke: darkgreen, stroke-width: 4px
style 2k fill: white, stroke: darkgreen, stroke-width: 4px
style 4a fill: white, stroke: orange, stroke-width: 4px
style 4b fill: white, stroke: orange, stroke-width: 4px
style 4c fill: white, stroke: orange, stroke-width: 4px

linkStyle 6,7 stroke: #f26820, stroke-width:8px;
linkStyle 0,1,2,3,4,5,8,9,10,11,12 stroke:darkgreen,stroke-width:8px;
linkStyle 13,14,15 stroke: orange,stroke-width:8px;

%%C1(first commit) -.-> a
%%C4(first commit) -.-> 4a
B1[Master] -.-> i
B2[Linha-2] -.-> 2k
B4[Linha-4] -.-> 4a
tag1c>VLT-1] -.-> c
tag1d>VLT-2] -.-> d
tag1d1>Barcas-1] -.-> d
tag1g>SuperVia-1] -.-> g
tag2g>SuperVia-2] -.-> 2g
tag2h>BRT-1] -.-> 2h
tag2k>SuperVia-3] -.-> 2k
tag4c>BRT-2] -.-> 4c

%%style tag4c fill:#fef4ac, stroke:#d3d398
style B1 fill: white, stroke: #f26820, stroke-width: 2
style B2 fill: white, stroke: darkgreen, stroke-width: 2
style B4 fill: white, stroke: orange, stroke-width: 2
style branch fill: white, stroke: gray, stroke-width: 2
%%style C1 fill: transparent, stroke: black ,stroke-dasharray: 5 5
```

*Mapa resumido. Algumas estações e a linha 3 (cancelada) foram ocultados para fins didáticos.*

## Fontes:

* [Criando Tags - Git](https://git-scm.com/book/pt-br/v2/Fundamentos-de-Git-Criando-Tags)
* [What is HEAD in Git? - Stack Overflow](https://stackoverflow.com/questions/2304087/what-is-head-in-git)

### Imagens:

Usado como base para o mapa metroviário de Rio e Niterói:

* [**Sobre o Metrô, Rio** - Rio Cidade Maravilhosa](http://www.riocidademaravilhosa.com.br/riodejaneiro/mobilidade/metro/)

* [**Metrô desfigurado - As recentes intervenções no modal estrangulam a capacidade do metrô** - Diário do Rio de Janeiro](https://diariodorio.com/metro-desfigurado/)
