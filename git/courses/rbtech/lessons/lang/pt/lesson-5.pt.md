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

Há dois tipos de tags:

* **Tag leve**  - um mero atalho que aponta para um commit específico;

* **Tag anotada** - além de ser um atalho para um commit, ele contém o nome , email, data, hash e uma mensagem de tag (opcional, mas recomendado). 

Qual devo usar?

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

Cada bolinha é um commit.

Cada commit tem um hash único.

### Evolução de uma árvore Git

Imagine que criamos um repositório novo, adicionamos um arquivo `readme.md` e confirmamos no Git:

```git
git init
git add readme.md
git commit -m "primeiro commit"
```

```mermaid
flowchart LR
subgraph L1[" "]
a(("<u>master</u><br>576ac7b"))---b(("9a48e92"))---c(("f3661c8"))---d(("abe667b"))
end
N("Você está<br>aqui") -..-> a

style L1 fill: transparent, stroke: transparent
style N fill:#fef4ac, stroke:#d3d398
style a stroke:darkblue, stroke-width: 4px
style b stroke-width: 0, fill: transparent,color: transparent
style c stroke-width: 0, fill: transparent,color: transparent
style d stroke-width: 0, fill: transparent,color: transparent

linkStyle 0,1,2 stroke: transparent
```

Editamos o readme e confirmamos as alterações:

```mermaid
flowchart LR
subgraph S[" "]
a(("576ac7b"))---b(("<u>master</u><br>9a48e92"))---c(("f3661c8"))---d(("abe667b"))
end
N("Você está<br>aqui") -.-> b

style S fill: transparent, stroke: transparent
style N fill:#fef4ac, stroke:#d3d398
style a stroke:darkblue, stroke-width: 4px
style b stroke:darkblue, stroke-width: 4px
style c stroke-width: 0, fill: transparent,color: transparent
style d stroke-width: 0, fill: transparent,color: transparent

linkStyle 1,2 stroke: transparent
linkStyle 0 stroke:darkblue,stroke-width:8px;
```

* Note que o 

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

Isto é uma árvore Git.

Cada bolinha é um commit, neles você pode ver seus checksums.

O primeiro commit da árvore foi marcado com a tag `v1.0`.

Nesta árvre temos dois ramos:

* Azul - o ramo principal `master`.

* Vermelho - o ramo extra (`test`) que foi criado para testes.

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

### Imagens:

Usado como base para o mapa metroviário de Rio e Niterói:

* [**Sobre o Metrô, Rio** - Rio Cidade Maravilhosa](http://www.riocidademaravilhosa.com.br/riodejaneiro/mobilidade/metro/)

* [**Metrô desfigurado - As recentes intervenções no modal estrangulam a capacidade do metrô** - Diário do Rio de Janeiro](https://diariodorio.com/metro-desfigurado/)
