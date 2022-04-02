/**
 * @file arvore_abb.c
 * @author Raphael Rivas (raphaelrivas@hotmail.com)
 * @brief Qualquer dúvida, me chame e verei se posso ajudar
 * @version 0.1
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
 * Dúvidas:
 * ABB - Árvore de Busca Binária, simples e sem frescura com otimização
 */

#include <stdio.h>  //print, scan
#include <stdlib.h> //alloc, free
#include <time.h>   // srand, rand

struct Arv
{
    int valor;
    struct Arv *Esq;
    struct Arv *Dir;
};
typedef struct Arv Arv; // apenas um macro, facilita a vida

// macro para novo nó
Arv *arv_novo(int valor)
{
    Arv *novo = (Arv *)malloc(sizeof(Arv));
    novo->valor = valor;
    novo->Esq = NULL;
    novo->Dir = NULL;
    return novo;
}

int _arv_altura(Arv *arv, int nivel)
{
    if (!arv)
        return 0;
    int altura_esq = _arv_altura(arv->Esq, nivel);
    int altura_dir = _arv_altura(arv->Dir, nivel);
    int altura = altura_esq ? altura_esq : (altura_dir ? altura_dir : 1);
    return altura;
}

Arv *arv_buscar_menor(Arv *arv)
{
    if (!arv)
        return NULL;
    Arv *menor_valor = arv;
    Arv *menor_esq = arv_buscar_menor(arv->Esq);
    Arv *menor_dir = arv_buscar_menor(arv->Dir);

    if (menor_esq && menor_esq->valor < menor_valor->valor)
        menor_valor = menor_esq;
    if (menor_dir && menor_dir->valor < menor_valor->valor)
        menor_valor = menor_dir;
    return menor_valor;
}

Arv *arv_buscar_maior(Arv *arv)
{
    if (!arv)
        return NULL;
    Arv *maior_valor = arv;
    Arv *maior_esq = arv_buscar_maior(arv->Esq);
    Arv *maior_dir = arv_buscar_maior(arv->Dir);
    if (maior_esq && maior_esq->valor > maior_valor->valor)
        maior_valor = maior_esq;
    if (maior_dir && maior_dir->valor > maior_valor->valor)
        maior_valor = maior_dir;
    return maior_valor;
}

Arv *arv_buscar_valor(Arv *arv, int valor)
{
    if (!arv)
        return NULL;
    if (arv->valor == valor)
        return arv;
    Arv *valor_valor = NULL;
    Arv *valor_esq = arv_buscar_valor(arv->Esq, valor);
    Arv *valor_dir = arv_buscar_valor(arv->Dir, valor);
    if (valor_esq && valor_esq->valor == valor)
        valor_valor = valor_esq;
    if (valor_dir && valor_dir->valor == valor)
        valor_valor = valor_dir;
    return valor_valor;
}

int arv_esta_vazia(Arv *arv)
{
    return (arv ? 0 : 1);
}

// como trata-se de ABB, só precisamos saber adicionar no final :D
// esta árvore não organiza os menores valores à esquerda, apenas adiciona e já era.
void arv_adicionar_fim(Arv **arv, int valor)
{
    // 1. se vazio, cria e sai
    if (*arv == NULL)
    {
        *arv = arv_novo(valor);
        return;
    }

    // 2. se tem 2 filhos
    if ((*arv)->Esq && (*arv)->Dir)
    {
        // entra no filho cujo valor é mais próximo do valor do novo nó

        // - como sei quem é o mais próximo?

        // calcula a diferença (distância) entre valor do novo nó e o valor dos nós Esq e Dir

        // - exemplo: Esq = 50          novo = 13           Dir = 20

        //   Esq: abs(50-13) = 33                           Dir: abs(13-20) = 7

        // A distância de novo para Dir é apenas 7. 13 é mais próximo de 20 do que de 50, certo?

        // 13+7 = 20.           13+33 = 50.

        int dif_dir = abs((*arv)->Dir->valor - valor); // 2.1. calcula a distância entre cada lado
        int dif_esq = abs((*arv)->Esq->valor - valor);
        if (dif_dir < dif_esq)
            arv_adicionar_fim(&(*arv)->Dir, valor); // 2.2. se direita é mais próximo, entra
        else
            arv_adicionar_fim(&(*arv)->Esq, valor); // 2.3. se esquerda é mais próximo, entra
    }

    // 3. se tem 1 ou 0 filhos, adiciona
    else
    {
        if ((*arv)->Dir)
            (*arv)->Esq = arv_novo(valor); // 3.2. se tiver direita, add esquerda
        else if ((*arv)->Esq)
            (*arv)->Dir = arv_novo(valor); // 3.3. se tiver esquerda, add direita
        else
            (*arv)->Esq = arv_novo(valor); // 3.4. se vazio, preferência criar esquerda
    }
}

// retorna: 2 - não removeu
//          1 - precisa limpar o ponteiro do nó pai
//          0 - removido!
int arv_remover_fim(Arv **arv)
{
    // 1. retorn
    if (*arv == NULL)
        return 2;

    // 2. entra nos filhos
    int ret = 2;

    // 2.1 se tem 0 filhos
    if ((*arv)->Esq == NULL && (*arv)->Dir == NULL)
    {
        free(*arv);
        *arv = NULL;
        return 1;
    }

    // 2.1 se tem Esq
    if ((*arv)->Esq != NULL)
    {
        ret = arv_remover_fim(&(*arv)->Esq);
        if (ret == 1)
        {
            (*arv)->Esq = NULL; // se Esq foi removido, limpa o ponteiro Esq
            ret = 0;
            return 0;
        }
    }

    // 2.1 se tem Dir
    if ((*arv)->Dir != NULL && ret == 2)
    {
        ret = arv_remover_fim(&(*arv)->Dir);
        if (ret == 1)
        {
            (*arv)->Dir = NULL; // se Dir foi removido, limpa o ponteiro Dir
            ret = 0;
            return 0;
        }
    }
    return ret;
}

// todo
// 1. vê se existe o valor
// 1. deleta o último elemento e guarda o valor
// 2. usa o valor pra pôr no lugar daquele a ser removido
int arv_remover_valor(Arv **arv, int valor)
{
    // return: 0 removido, 1 limpando ponteiro pai, 2 removido com sucesso
    int ret = 2;

    // 1. se nulo
    if (*arv == NULL)
        return ret;

    // 2 se tem o valor

    // 2.1 se é folha (sem filho)
    if ((!(*arv)->Esq && !(*arv)->Dir) && (*arv)->valor == valor)
    {
        free(*arv);
        *arv = NULL;
        return 1;
    }

    // 2.2 se tem 1 filho
    else if ((*arv)->Esq && (*arv)->Esq->valor == valor)
    {
        free((*arv)->Esq);
        (*arv)->Esq = NULL;
        return 0;
    }
    else if ((*arv)->Dir && (*arv)->Dir->valor == valor)
    {
        free((*arv)->Dir);
        (*arv)->Dir = NULL;
        return 0;
    }

    // 2.2 se tá no início da lista
    else if ((*arv)->valor == valor)
    {
        Arv *esq = (*arv)->Esq;
        Arv *dir = (*arv)->Dir;
        free(*arv);
        *arv = (*arv)->Esq ? (*arv)->Esq : (*arv)->Dir;
        return 0;
    }

    // 3. entra nos filhos

    // 3.1 se tem Esq
    if ((*arv)->Esq != NULL)
    {
        ret = arv_remover_valor(&(*arv)->Esq, valor);
        if (ret == 1)
        {
            (*arv)->Esq = NULL; // se Esq foi removido, limpa o ponteiro Esq
            ret = 0;
            return 0;
        }
    }

    // 3.2 se tem Dir
    if ((*arv)->Dir != NULL && ret == 2)
    {
        ret = arv_remover_valor(&(*arv)->Dir, valor);
        if (ret == 1)
        {
            (*arv)->Dir = NULL; // se Dir foi removido, limpa o ponteiro Dir
            ret = 0;
            return 0;
        }
    }
    return ret;
}

int arv_apagar(Arv **arv)
{
    // return: 0 ok, 1 vai limpar ponteiro, 2 nulo
    // 1. retorna se nulo
    if (!*arv)
        return 0;

    // 2. entra nos filhos
    int ret = 0;

    // 2.1 se tem 0 filhos
    if (!(*arv)->Esq && !(*arv)->Dir)
    {
        free(*arv);
        *arv = NULL;
        return 1;
    }

    // 2.1 se tem Esq
    if ((*arv)->Esq)
    {
        ret = arv_apagar(&(*arv)->Esq);
        if (ret == 1)
        {
            (*arv)->Esq = NULL; // se Esq foi removido, limpa o ponteiro Esq
            ret = 0;
        }
    }

    // 2.1 se tem Dir
    if ((*arv)->Dir)
    {
        ret = arv_apagar(&(*arv)->Dir);
        if (ret == 1)
        {
            (*arv)->Dir = NULL; // se Dir foi removido, limpa o ponteiro Dir
            ret = 0;
        }
    }

    // 3. após percorrer os filhos, deleta a casa.

    // este if é pra verificar que tudo foi apagado, realmente apaga tudo.
    if (!(*arv)->Esq && !(*arv)->Dir)
    {
        free(*arv);
        *arv = NULL;
        return 1;
    }

    return ret;
}

// imprime em forma de lista
// exemplo de saída:
// 1 5 34 6 87 4 65 2 3     (sim, zoado, mas fácil de fazer na prova)
void arv_print(Arv *temp)
{
    if (!temp)
        return;
    printf("%d ", temp->valor); // N
    arv_print(temp->Esq);       // L
    arv_print(temp->Dir);       // R
}

// como o nome sugere, ele imprime uma árvore em 2D (bom para estudos)

// NLR = prefixa
// LNR = infixa
// LRN = posfixa

// para mudar a sequência basta trocar de posição os LNR. Botei { } para não haver dúvida do que fazer.
void _arv_plot(Arv *a, int nivel, int lr)
{
    if (a == NULL)
        return;

    // L (esquerda)
    {
        _arv_plot(a->Esq, nivel + 1, -1);
    }

    // N (raiz)
    {
        char *lnr = "/|\\";             // lnr [0,1,2] = [esquerda, raiz, direita]
        for (int i = 0; i < nivel; i++) // para cada nível:
            if (i == nivel - 1)
                printf(" %c", lnr[lr + 1]); // imprime se o nó está à esquerda ou à direita
            else
                printf("   "); // imprime espaços vazios até chegar no nível do nó atual
        printf("%d", a->valor);
        // if(!a->Esq && !a->Dir)
        //     printf("*");
        printf("\n");
    }

    // R (direita)
    {
        _arv_plot(a->Dir, nivel + 1, 1);
    }
}

void arv_plot(Arv *a)
{
    // printf("arvore PLOT 2D\n");
    printf("\n/ esquerda\n\n"); // Esta barra '/' representa galho à esquerda
    _arv_plot(a, 0, 0);
    printf("\n\\ direita\n\n"); // Esta barra '\' representa galho à direita
}

int arv_comprimento(Arv *arv)
{
    int comp = 0;
    if (arv)
    {
        comp++; // soma 1
        if (arv->Esq)
            comp += arv_comprimento(arv->Esq); // L       soma os nós encontrados na esquerda
        if (arv->Dir)
            comp += arv_comprimento(arv->Dir); // R       soma os nós encontrados na direita
    }
    return comp;
}

int arv_nos(Arv *arv)
{
    int comp = 0;
    if (arv)
    {
        if (arv->Esq || arv->Dir)
            comp++; // soma 1
        if (arv->Esq)
            comp += arv_nos(arv->Esq); // L       soma os nós encontrados na esquerda
        if (arv->Dir)
            comp += arv_nos(arv->Dir); // R       soma os nós encontrados na direita
    }
    return comp;
}

int arv_folhas(Arv *arv)
{
    int comp = 0;
    if (arv)
    {
        if (!arv->Esq && !arv->Dir)
            comp++; // soma 1
        if (arv->Esq)
            comp += arv_folhas(arv->Esq); // L       soma os nós encontrados na esquerda
        if (arv->Dir)
            comp += arv_folhas(arv->Dir); // R       soma os nós encontrados na direita
    }
    return comp;
}

int arv_altura(Arv *arv)
{
    if (!arv)
        return 0;

    int altura = 1;
    int altura_esq = arv_altura(arv->Esq);
    int altura_dir = arv_altura(arv->Dir);

    // acumula a altura de baixo pra cima, apenas pega a altura que for mais longa
    if (altura_esq >= altura_dir)
        altura += altura_esq;
    else if (altura_dir > altura_esq)
        altura += altura_dir;
    return altura;
}

int arv_soma(Arv *arv)
{
    if (!arv)
        return 0;

    int soma = arv->valor;
    soma += arv_soma(arv->Esq);
    soma += arv_soma(arv->Dir);
    return soma;
}

float arv_media(Arv *arv)
{
    if (!arv)
        return 0;

    // soma metade
    float soma = (arv->valor) / 2;
    soma += arv_media(arv->Esq);
    soma += arv_media(arv->Dir);

    return soma;
}

Arv *arv_copiar(Arv *origem)
{
    if (!origem)
        return NULL;

    Arv *novo = (Arv *)malloc(sizeof(Arv));
    novo->valor = origem->valor;
    novo->Esq = arv_copiar(origem->Esq);
    novo->Dir = arv_copiar(origem->Dir);
    return novo;
}

int arv_iguais(Arv *a, Arv *b)
{
    if (!a && !b)
        return 1;
    if ((!a && b) || (a && !b))
        return 0;

    if (a->valor != b->valor)
        return 0;

    if ((!a->Esq && b->Esq) || (a->Esq && !b->Esq))
        return 0;
    if ((!a->Dir && b->Dir) || (a->Dir && !b->Dir))
        return 0;

    if (!arv_iguais(a->Esq, b->Esq))
        return 0;
    if (!arv_iguais(a->Dir, b->Dir))
        return 0;

    return 1;
}

void _arv_salvar_txt(Arv *arv, FILE *arquivo)
{
    // salva em forma de lista;
    // Transversal NLR (a ordem tanto faz, porém assim é conveniente)

    if (!arv)
        return;

    // 1. cmd = número 
    fprintf(arquivo, "*%d", arv->valor);

    // 2. cmd = esquerda
    if (arv->Esq)
        fprintf(arquivo, "%c", '/');
    _arv_salvar_txt(arv->Esq, arquivo);

    // 3. cmd = direita
    if (arv->Dir)
        fprintf(arquivo, "%c", '\\');
    _arv_salvar_txt(arv->Dir, arquivo);

    // 4. cmd = subir
    fprintf(arquivo, "%c", '|');
}

void arv_salvar_txt(Arv *arv, char *endereco)
{
    // limpar arquivo
    FILE *arquivo = fopen("arv.txt", "w");
    fclose(arquivo);

    // concatenar
    arquivo = fopen("arv.txt", "a");
    _arv_salvar_txt(arv, arquivo);
    fclose(arquivo);
}

int _arv_carregar_txt(Arv **arv, FILE *arquivo)
{
    // carrega em forma de lista;
    // transversal NLR (a ordem tanto faz, porém assim é conveniente)

    int valor = 0;
    char cmd = 0;

    // 1. ler
    if (fscanf(arquivo, "%c", &cmd) == EOF)
        return 2;
    if (cmd == '|') // cmd = subir
        return 0;
    
    // 2. cmd = valor
    if (cmd == '*')
    {
        if(fscanf(arquivo, "%d", &valor) == EOF)
            return 2;

        // primeiro no
        if (!*arv)
            *arv = arv_novo(valor);

        // demais nos
        else
            (*arv)->valor = valor;
    }

    // 3. ler
    if (fscanf(arquivo, "%c", &cmd) == EOF)
        return 2;
    if (cmd == '|') // cmd = subir
        return 0;


    // 4. cmd = esquerda
    if (cmd == '/')
    {
        if(!(*arv)->Esq)
            (*arv)->Esq = arv_novo(0);

        if(_arv_carregar_txt(&(*arv)->Esq, arquivo) == 2)
            return 2;
    }

    // 5. ler
    if (fscanf(arquivo, "%c", &cmd) == EOF)
        return 2;
    if (cmd == '|') // cmd = subir
        return 0;

    // 6. direita
    if (cmd == '\\')
    {
        if(!(*arv)->Dir)
            (*arv)->Dir = arv_novo(0);

        if(_arv_carregar_txt(&(*arv)->Dir, arquivo) == 2)
            return 2;
    }

     // cmd = subir     (em todos os casos)
    if (fscanf(arquivo, "%c", &cmd) == EOF)
        return 2;

    return 0;
}

void arv_carregar_txt(Arv **arv, char *endereco)
{
    FILE *arquivo = fopen("arv.txt", "r");
    _arv_carregar_txt(arv, arquivo);
    fclose(arquivo);
}

int main()
{
    srand(time(0));
    Arv *arv = NULL;

    printf("1. aficionar 8 nos aleatórios na árvore\n");
    for (int i = 0; i < 20; i++)
    {
        int info = rand() % 90; // entre 1-90
        arv_adicionar_fim(&arv, info);
    }

    arv_print(arv), printf("\n");
    arv_plot(arv);

    printf(" 2. remover o ultimo item\n");
    arv_remover_fim(&arv);
    arv_print(arv), printf("\n");
    arv_plot(arv);

    printf("3. altura = %d\n", arv_altura(arv));

    printf("4. menor valor da arvore =  %d\n", arv_buscar_menor(arv)->valor);

    printf("5. maior valor da arvore =  %d\n\n", arv_buscar_maior(arv)->valor);

    printf("6. buscar valor da arvore:\nComparacao: ");
    arv_print(arv), printf("\n");
    for (int i = 0; i < 20; i++)
    {
        int valor = rand() % 90;
        printf("%d %s, ", valor, arv_buscar_valor(arv, valor) ? "O" : "X");
    }
    printf("\n\n");

    printf("7. Arvore nula? %s:\n\n", arv_esta_vazia(arv) ? "SIM" : "NAO");

    printf("8. Apagar arvore:\n");
    printf("arvore: "), arv_print(arv), printf("\n");
    arv_apagar(&arv);
    printf("arvore apagada: "), arv_print(arv), printf("\n");
    for (int i = 0; i < 20; i++)
    {
        int info = rand() % 90; // entre 1-90
        arv_adicionar_fim(&arv, info);
    }
    printf("arvore: "), arv_print(arv), printf("\n\n");

    printf("8. Media dos valores: %.2f\n", arv_media(arv));
    printf("9. Soma dos valores: %d\n", arv_soma(arv));

    printf("10. Copiar dos valores: %d\n", arv_soma(arv));
    Arv *arv2 = arv_copiar(arv);
    int info = rand() % 90; // entre 1-90
    printf("arvore [%p]: ", &arv), arv_print(arv), printf("\n");
    printf("copia  [%p]: ", &arv2), arv_print(arv2), printf("\n\n");

    printf("10. Comparar arvores\n");
    printf("arvore 1: "), arv_print(arv), printf("\n");
    printf("arvore 2: "), arv_print(arv2), printf("\n");
    printf("Arvores iguais?: %s\n", arv_iguais(arv, arv2) ? "SIM" : "NAO");
    arv_adicionar_fim(&arv2, 100);
    printf("arvore 1: "), arv_print(arv), printf("\n");
    printf("arvore 2: "), arv_print(arv2), printf("\n");
    printf("Arvores iguais?: %s\n\n", arv_iguais(arv, arv2) ? "SIM" : "NAO");

    printf("11. Comparar folhas e nos\n");
    printf("comprimento:%d, folhas:%d, nos:%d\n\n", arv_comprimento(arv), arv_folhas(arv), arv_nos(arv));

    printf("12. Salvar e carregar em txt\n");
    arv_salvar_txt(arv, "arvore.txt");
    printf("arvore ao salvar:   "), arv_print(arv), printf("\n");
    arv_apagar(&arv);
    printf("arvore vazia:       "), arv_print(arv), printf("\n");
    arv_carregar_txt(&arv, "arvore.txt");
    printf("arvore ao carregar: "), arv_print(arv), printf("\n");

    // todo
    // printf("9. Remover valor:\n");
    // printf("arvore:    "), arv_print(arv), printf("\n");
    // printf("removendo: ");
    // for (int i = 0; i < 30; i++)
    // {
    //     int info = i; //rand() % 90; // entre 1-90
    //     printf("%d ",info);
    //     arv_remover_valor(&arv, info);
    // }
    // printf("\narvore:    "), arv_print(arv), printf("\n");

    return 0;
}