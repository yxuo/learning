/**
 * @file listas_encadeadas.c
 * @author Raphael Rivas (raphaelrivas@hotmail.com)
 * @brief Qualquer dúvida, me chame e verei se posso ajudar
 * @version 0.1
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 * Talvez te interesse:
 * - convenções de nomes em c   - https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c
 * - malloc precisa de cast     - https://www.reddit.com/r/C_Programming/comments/3wxgvb/malloc_type_casting_needed/
 */

#include <stdio.h>  //print, scan
#include <stdlib.h> // alloc, free

struct No
{
    int valor;
    struct No *Prox;
};
typedef struct No No;           // macro para facilitar

// macro para criar novo nó
No *lista_novo_no(int valor)
{
    // novo ponteiro apontando para memória alocada
    No *novo = (No *)malloc(sizeof(No));

    // você precisa inicializar ponteiros, caso contrário ele não funciona.
    novo->valor = valor;
    novo->Prox = NULL;
    return novo;
}

void lista_adicionar_fim(No **no, int valor)
{
    // Por que **a e não *a?
    // - ponteiro duplo (**a) permite alterar o 1o elemento (por isso tem um ponteiro apontando pra outro ponteiro)
    // - ponteiro uno (*a) é tipo um token, se você tentar alterar o 1o elemento, estará na verdade alterando o valor do ponteiro, não do 1o elemento.

    // 1. se a lista tá vazia, adicionar o 1o elemento
    if (*no == NULL)
    {
        *no = lista_novo_no(valor);
        return;
    }

    // 2. percorrer até o último elemento, daí este último pode apontar para o novo elemento
    No *ultimo = *no;
    while (ultimo->Prox != NULL)
        ultimo = ultimo->Prox;

    // 3. último nó! apontar para o novo nó
    ultimo->Prox = lista_novo_no(valor);
}

void lista_adicionar_inicio(No **no, int valor)
{
    // 1. novo no
    No *novo = lista_novo_no(valor);
    // 2. Prox aponta para o endereço do (antigo) 1o elemento. (não confundir com o endereço do ponteiro *no)
    novo->Prox = *no;
    // 3. no aponta para o endereço do novo elemento.
    *no = novo;
}

void lista_print(No *no)
{
    // Como não quero mexer no 1o elemento, quero apenas imprimir, só preciso de um ponteiro uno

    // se o nó existe, imprimir e ir ao próximo nó
    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->Prox;
    }
    printf("\n");
}

// a função mais simples
void lista_remover_ultimo(No **lista)
{
    // 1. se lsita é nula, cancela
    if (*lista == NULL)
        return;

    No *no = *lista;
    No *ante = NULL;

    // 2. remove indice 0
    if (no->Prox == NULL)
    {
        free(no);
        *lista = NULL;
        return;
    }

    // 3. remove indice 1-n

    // percorre até o último elemento
    while (no->Prox != NULL)
    {
        ante = no;
        no = no->Prox;
    }

    // 3.1. removendo indice 1-n
    free(no);
    ante->Prox = NULL;
}

void lista_remover_por_valor(No **lista, int valor)
{
    // ele removerá o 1o elemento que contém este valor

    // 1. se não existe nó, cancela
    if (*lista == NULL)
        return;

    No *no = *lista;
    No *ante = NULL;

    // 2. remove índice 0      (se o nó tem o valor)
    if (no->valor == valor)
    {
        // libera endereço de memória
        *lista = no->Prox;
        free(no);
        // o ponteiro não apontará mais para este endereço
        return;
    }

    // 3. remove índice 1-n    (se o nó tem o valor)

    // precisamos do nó anterior para ele deixar de apontar para o elemento removido
    while (no != NULL)
    {
        // 3.1. remove nó            (se o nó tem o valor)
        if (no->valor == valor)
        {
            ante->Prox = no->Prox;  // ante ignora o elemento removido, aponta o nó seguinte
            free(no);               // apaga nó
            return;
        }
        //
        ante = no;                  // atualiza ante
        no = (no)->Prox;            // atualiza no
    }
}

void lista_remover_indice(No **lista, int indice)
{
    // 1. se lista nula, cancela
    if (*lista == NULL)
        return;

    int indice_atual = 0;

    No *no = *lista;
    No *ante = NULL;

    // 2. remove indice 0
    if (indice_atual == indice)
    {
        *lista = no->Prox;
        free(no);
        return;
    }

    // 3. remove indice 1-n
    while (no != NULL)
    {
        if (indice_atual == indice)
        {
            ante->Prox = no->Prox;
            free(no);
            return;
        }
        ante = no;
        no = no->Prox;
        indice_atual++;
    }
}

int main()
{
    No *lista = NULL;
    No *lista_invertida = NULL;

    printf("1. adicionar itens no inicio da lista\n");
    for (int i = 0; i < 5; i++)
        lista_adicionar_inicio(&lista_invertida, i);
    lista_print(lista_invertida);
    printf("\n\n");

    printf("2. adicionar itens no fim da lista\n");
    for (int i = 0; i < 5; i++)
        lista_adicionar_fim(&lista, i);
    lista_print(lista);
    printf("\n\n");

    printf("3. remover ultimo item\n");
    lista_remover_ultimo(&lista);
    lista_print(lista);
    printf("\n\n");

    printf("4. remover item no indice [2] = 2\n");
    lista_remover_indice(&lista, 2);
    lista_print(lista);
    printf("\n\n");

    printf("5. remover item com valor (1)\n");
    lista_remover_por_valor(&lista, 1);
    lista_print(lista);
    printf("\n\n");
}