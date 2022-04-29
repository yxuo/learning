# Aula 6

**Tema: Git em servidores.**

Para fins didáticos, será usado uma máquina virtual Windows ao invés de um servidor Linux configurado (recomendado).

Afinal a proposta do curso é focar no básico do Git.

## GitHub

É um site feito para hospedar repositórios de forma prática.

Para poder usar, cadastre-se: https://github.com

### Página inicial

Ao entrar no GitHub, por padrão, sua tela inicial é uma "lsita de notícias" (news feed):

> Tela inicial do GitHub em 26/04/2022.

![Tela inicial do GitHub após entrar](../../img/github-main-page-feed.png)

### Acessar seu perfil GitHub

O endereço do seu perfil é github.com/`nome-de-usuario`

Para acessar seu perfil dentro do site, clique no seu `ícone de usuário (🧑)` > `Seu perfil` (*Your profile*):

![Menu para entrar no seu perfil GitHub](../../img/github-menu-profile.png)

### Seu perfil github

![Tela do seu perfil do GitHub](../../img/github-profile.png)

> Este é o meu perfil :3

Seu perfil GitHub contém:

* Seus repositórios;

* Seu mapa de atividade: quantidade de commits você subiu para o GitHub a cada;

* Quais atividades e contribuições você fez no GitHub, que inclui:
  * Commits feitos no repositório.;
  * Repositórios criados;
  * Organizações (tipo perfis de empresa) que você entrou;
  * Pull requests, comentários, etc...
  * E no final da lista: quando você criou sua conta GitHub.

### Liberar acesso do seu PC ao seu GitHub

Para seu PC poder clonar, baixar e alterar repositórios no GitHub, é preciso:

1. Criar uma chave de acesso SSH no PC:

Git Bash:

```git
ssh-keygen
```

Confirme o nome do arquivo:

> Prefira não editar o nome de arquivo sugerido.

* Aperte `Enter` para confirmar

```git
Generating public/private rsa key pair.
Enter file in which to save the key (/c/users/Rapha/.ssh/id_rsa)
```

Defina a senha para acessar a chave SSH:

> Prefira não usar senha!
> 
> Toda vez que sincronizar terá que digitar esta senha.
>
> Senhas em chaves SSH apenas valem a pena em ambientes que precisam de muita segurança.

* Aperte `Enter` para não criar senha.

:warning: Execute este comando sempre dentro do Git Bash, nunca no Powershell ou Prompt. Caso contrário a chave estará mal configurada e não será reconhecida corretamente.

1. Adicionar a chave na lista de chaves SSH do seu GitHub:

1. Criar uma chave de acesso no PC;
2. 