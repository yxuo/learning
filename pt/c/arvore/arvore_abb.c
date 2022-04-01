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

// imprime em forma de lista
// exemplo de saída:
// 1 5 34 6 87 4 65 2 3     (sim, zoado, mas fácil de fazer na prova)
void arv_print(Arv *temp)
{
    if (!temp)
        return;
    arv_print(temp->Esq);
    printf("%d ", temp->valor);
    arv_print(temp->Dir);
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
        printf("%d\n", a->valor);
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

int arv_comprimento(Arv *a)
{
    int comp = 0;
    if (a)
    {
        comp++; // soma 1
        if (a->Esq)
            comp += arv_comprimento(a->Esq); // L       soma os nós encontrados na esquerda
        if (a->Dir)
            comp += arv_comprimento(a->Dir); // R       soma os nós encontrados na direita
    }
    return comp;
}

int main()
{
    srand(time(0));
    Arv *arv = NULL;

    printf("1. aficionar 8 nós aleatórios na árvore\n");
    for (int i = 0; i < 8; i++)
    {
        int info = rand() % 90;         // entre 1-90
        arv_adicionar_fim(&arv, info);
    }
    
    printf("comp = %d\n",arv_comprimento(arv));
    arv_print(arv), printf("\n");
    arv_plot(arv);

    printf(" 2. remover o último item\n");
    arv_remover_fim(&arv);

    printf("comp = %d\n",arv_comprimento(arv));
    arv_print(arv), printf("\n");
    arv_plot(arv);
    return 0;
}