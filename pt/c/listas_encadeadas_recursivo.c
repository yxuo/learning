/**
 * @file listas_encadeadas_recursivo.c
 * @author Raphael Rivas (raphaelrivas@hotmail.com)
 * @brief Qualquer dúvida, me chame e verei se posso ajudar
 * @version 0.1
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
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
    // 1. se a lista tá vazia, adicionar o 1o elemento
    if (*no == NULL)
    {
        *no = lista_novo_no(valor);
        return;
    }

    // 2. percorrer até o último elemento, daí este último pode apontar para o novo elemento

    // ao invés de usar while, chamamos a própria função em si mesma. Isto é recursividade.
    if ((*no)->Prox != NULL)
        lista_adicionar_fim(&(*no)->Prox, valor);

    // 3. último nó! apontar para o novo nó
    else
        (*no)->Prox = lista_novo_no(valor);
    // tome cuidado, todas as funções chamadas, uma dentro da outra, vão passar por aqui
}

// nada de recursivo para fazer aqui...
void lista_adicionar_inicio(No **no, int valor)
{
    No *novo = lista_novo_no(valor);
    novo->Prox = *no;
    *no = novo;
}

void lista_print(No *no)
{
    // troca while por recursividade
    if (no != NULL)
    {
        printf("%d ", no->valor);
        lista_print(no->Prox);
    }
}

int lista_remover_por_valor(No **no, int valor)
{
    // ele removerá o 1o elemento que contém este valor

    // 1. se não existe nó, cancela
    if (*no == NULL)
        return 0;

    // 2. remove índice 0       (se o nó tem o valor)
    if ((*no)->valor == valor)
    {
        // libera endereço de memória
        *no = (*no)->Prox;
        // o ponteiro não apontará mais para este endereço
        free(no);
        return 0;
    }
    // 3. remove índice 1-n    (se o nó tem o valor)

    int removido = 0;
    // substitui while por recursividade
    // o nó que vamos passar será o nó anterior, para isso vemos se o nó possui 'Prox'
    if ((*no)->Prox != NULL)
    {
        // remove nó Prox       (se tem o valor)
        if ((*no)->Prox->valor == valor)
        {
            // o nó anterior ignorará o elemento_removido, apontando para o elemento seguinte (ou NULO se for o último)
            No *elemento_removido = (*no)->Prox;
            (*no)->Prox = (*no)->Prox->Prox;
            free(elemento_removido);
            // como queremos remover apenas o 1o elemento, terminamos por aqui :)
            return 1;
        }
        if (removido == 0) // congele caso queira remover todos que tenham o valor
            removido += lista_remover_por_valor(&(*no)->Prox, valor);
    }
    return removido;
}

void lista_remover_ultimo(No **no)
{
    // 1. se lsita é nula, cancela
    if (*no == NULL)
        return;

    // 2. remove indice 0
    if ((*no)->Prox == NULL)
    {
        free(*no);
        *no = NULL;
        return;
    }

    // 3. remove indice 1-n

    // substituir while por recursividade, enviaremos o anterior como parâmetro
    //             ->    <- se este não existe, o nó atual é o penúltimo elemento,
    // podemos deletar o último e limpar o Prox do penúltimo.
    if ((*no)->Prox->Prox != NULL)
        lista_remover_ultimo(&(*no)->Prox);

    // remover

    // Lembre-se sempre, todas as funções chamadas vão passar por aqui!
    else
    {
        free((*no)->Prox);
        (*no)->Prox = NULL;
    }
}

void lista_remover_indice(No **no, int indice)
{
    // 1. se lista é nula, cancela
    if (*no == NULL || indice < 0)
        return;

    // há muitas maneiras de fazer esta função de forma recursiva;
    // escolhi o seguinte: se indice = 0 pode deletar, senão, indice subtrai 1 e chama denovo.

    // 2. remove se indice = 0
    if (indice == 0)
    {
        *no = (*no)->Prox;
        free(no);
        return;
    }

    // 3. indice subtrai 1 e chama denovo

    // troca while por recursividade
    if (*no != NULL)
        lista_remover_indice(&(*no)->Prox, indice - 1);
}

int main()
{
    No *lista = NULL;

    printf("lista: adicionar no fim\n");
    for (int i = 0; i < 5; i++)
        lista_adicionar_fim(&lista, i);
    lista_print(lista);
    printf("\n\n");

    printf("lista: adicionar no inicio\n");
    for (int i = 5; i < 10; i++)
        lista_adicionar_inicio(&lista, i);
    lista_print(lista);
    printf("\n\n");

    printf("lista: remover por indice [4] = 5\n");
    lista_remover_indice(&lista, 4);
    lista_print(lista);
    printf("\n\n");

    printf("lista: remover por valor (7)\n");
    lista_remover_por_valor(&lista, 7);
    lista_print(lista);
    printf("\n\n");

    printf("lista: remover o ultimo\n");
    lista_remover_ultimo(&lista);
    lista_print(lista);
    printf("\n\n");
}