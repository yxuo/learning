# Aula 6

**Tema: Git em servidores.**

Para fins didáticos, será usado uma máquina virtual Windows ao invés de um servidor Linux configurado (recomendado).

Afinal a proposta do curso é focar no básico do Git.

## Criar repositório remoto:

```git
git init --bare
```

`--bare` = barebone (coluna), o servidor chefe.

## Clonar repositório remoto

```git
git clone file:////servidor/pasta/projeto1
```

### Clonar com outro nome para a pasta local:

```git
git clone file:////servidor/pasta/projeto1 nome
```

## Enviar alterações pro servidor remoto:

```git
git push origin master
```

Em outras palavras:

```git
git push remoto branch
```

## Receber alterações do servidor remoto

```git
git pull origin master
```

> Usado na maioria dos casos.

Git pull automaticamente dá merge das atualizações com teu ramo.

## Receber alterações sem mesclar:

```git
git fetch origin _branch_
```

## Ver apelido do servidor remoto:

```git
git remote
```

Retorno:

```git
origin
```

O nome padrão do remoto é sempre `origin`.

## Fonte:

* [Qual a diferença entre os comandos 'git pull' e 'git fetch'? - StackOverflow](https://pt.stackoverflow.com/questions/3231/qual-a-diferen%C3%A7a-entre-os-comandos-git-pull-e-git-fetch)