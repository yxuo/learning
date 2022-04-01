/**
 * @file listas_encadeadas.c
 * @author Raphael Rivas (raphaelrivas@hotmail.com)
 * @brief Qualquer dúvida, me chame e verei se posso ajudar
 * @version 0.1
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022 Licença GNU3
 *
 * Talvez te interesse:
 * - convenções de nomes em c   - https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c
 * - malloc precisa de cast     - https://www.reddit.com/r/C_Programming/comments/3wxgvb/malloc_type_casting_needed/
 */

#include <stdio.h>  //print, scan
#include <stdlib.h> // alloc, free

// o nosso nó
struct No
{
    int valor;
    struct No *Prox;
};
// um macro pra não ter que digitar "struct" toda hora (OPCIONAL)
typedef struct No No;

// um macro para (o ritual de) criar um ponteiro
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

    // último nó! apontar para o novo nó
    ultimo->Prox = lista_novo_no(valor);
}

void lista_adicionar_inicio(No **no, int valor)
{
    // novo nó vai destronar o atual 1o elemento, passando a ser o 2o elemento
    No *novo = lista_novo_no(valor);

    //. *no é um ponteiro raiz, que contém o endereço do 1o elemento
    //  O novo->prox agora também tem este endereço, ou seja, o próximo elemento de 'novo' é o antigo 1o elemento
    novo->Prox = *no;

    // lembra que *no é apenas um ponteiro raiz? Ele agora aponta para o novo 1o elemento, o novo.
    *no = novo;
}

void lista_print(No *no)
{
    // Como não quero mexer no 1o elemento, quero apenas imprimir, só preciso de um ponteiro uno

    // se nó existe, posso imprimir e ir para o próximo nó

    
    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->Prox;
    }
    printf("\n");
}

void lista_remover_por_valor(No **lista, int valor)
{
    // ele removerá o 1o elemento que contém este valor

    // se não existe nó, cancela
    if (*lista == NULL)
        return;

    No *no = *lista;
    No *ante = NULL;

    // remove índice 0      (se o nó tem o valor)
    if (no->valor == valor)
    {
        // libera endereço de memória
        *lista = no->Prox;
        free(no);
        // o ponteiro não apontará mais para este endereço
        return;
    }

    // remove índice 1-n    (se o nó tem o valor)

    // precisamos do nó anterior para ele deixar de apontar para o elemento removido
    while (no != NULL)
    {
        // remove nó        (se tem o valor)
        if (no->valor == valor)
        {
            // ante ignorará o elemento removido, aponta o elemento seguinte
            ante->Prox = no->Prox;
            free(no);
            // elemento removido, voltamos ao ante e continuamos a percorrer a lista
            no = ante;

            // como queremos remover apenas o 1o elemento, terminamos por aqui :)
            return; // congele este return caso queira continuar e remover todos os nós que contém o valor.
        }
        //
        ante = no;
        no = (no)->Prox;
    }
}

void lista_remover_ultimo(No **lista)
{
    // se lsita é nula, cancela
    if (*lista == NULL)
        return;

    No *no = *lista;
    No *ante = NULL;

    // remove indice 0
    if (no->Prox == NULL)
    {
        free(no);
        *lista = NULL;
        return;
    }

    // remove indice 1-n

    // percorre até o último elemento
    while (no->Prox != NULL)
    {
        ante = no;
        no = no->Prox;
    }

    // remove
    free(no);
    ante->Prox = NULL;
}

void lista_remover_indice(No **lista, int indice)
{
    // se lista nula, cancela
    if (*lista == NULL)
        return;

    int indice_atual = 0;

    No *no = *lista;
    No *ante = NULL;

    // remove indice 0
    if (indice_atual == indice)
    {
        *lista = no->Prox;
        free(no);
        return;
    }

    // remove indice 1-n
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
    printf("ini\n");
    No *lista = NULL;
    for (int i = 0; i < 2; i++)
        lista_adicionar_fim(&lista, i);
    lista_print(lista);

    // printf("lista: remover por valor\n");
    // lista_remover_por_valor(&lista, 7);
    // lista_print(lista);

    // printf("lista: remover por indice\n");
    // lista_remover_indice(&lista, 0);
    // lista_print(lista);

    printf("lista: remover o ultimo\n");
    lista_remover_ultimo(&lista);
    lista_remover_ultimo(&lista);
    lista_remover_ultimo(&lista);
    lista_print(lista);

    printf("fim\n");
}