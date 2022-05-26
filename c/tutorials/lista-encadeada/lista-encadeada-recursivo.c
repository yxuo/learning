/**
 * @file listas_encadeadas_recursivo.c
 * @author Raphael Rivas (raphaelrivas@hotmail.com)
 * @brief Qualquer dúvida, me chame e verei se posso ajudar
 * @version 0.1
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
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

    if ((*no)->Prox != NULL) //                         chama função até o fim da lista
        lista_adicionar_fim(&(*no)->Prox, valor);

    // 3. adicionar nó no fim
    else
        (*no)->Prox = lista_novo_no(valor);
        
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
    // 1. se lista é nula, cancela
    if (*no == NULL)
        return 0;

    // há muitas maneiras de fazer esta função de forma recursiva;
    // escolhi o seguinte: se indice = 0 pode deletar, senão, indice subtrai 1 e chama denovo.

    // 2. remove se valor foi encontrado

    // 2.1.a. caso seja o último nó
    if ((*no)->Prox == NULL && (*no)->valor == valor)
    {
        free(*no);
        *no = NULL;

        // com este return a função chamada antes desta fará o papel do nó anterior.
        return 1;
    }

    // 2.2. caso seja no meio da lista
    else if ((*no)->Prox != NULL && (*no)->Prox->valor == valor)
    {
        // como o nó filho existe, considere este nó como o nó anterior
        No *remover = (*no)->Prox;
        (*no)->Prox = (*no)->Prox->Prox;
        free(remover);

        return 0;
    }

    // 2.3. caso seja o primeiro nó
    else if((*no)->valor == valor)
    {
        // guarda o próximo nó
        No *prox = (*no)->Prox;
        // deleta este nó
        free(*no);
        // O primeiro nó da lista será o próximo nó
        *no = prox;

        return 0;
    }

    // 3. chama denovo enquanto não deletar
    int removido = 0;
    removido += lista_remover_por_valor(&(*no)->Prox, valor);

    // 2.1.b. (continuação) você deletou o último nó, este aqui é o nó anterior ao deletado
    if (removido == 1)
        (*no)->Prox = NULL;

    // Apenas o nó anterior ao removido recebe o 'removido = 1'
    return 0;
}


void lista_remover_ultimo(No **no)
{
    // 1. se lsita é nula, cancela
    if (*no == NULL)
        return;

    // 2. remove o último item
    if ((*no)->Prox == NULL)
    {
        free(*no);
        *no = NULL;
        return;
    }

    // 3. enquanto não está no fim da lista
    if ((*no)->Prox->Prox != NULL)
        lista_remover_ultimo(&(*no)->Prox);

    // 4. remover último nó e limpar Prox
    else
    {
        free((*no)->Prox);
        (*no)->Prox = NULL;
    }
}


// mesma coisa, só muda o índice ao invés do valor
int lista_remover_indice(No **no, int indice)
{
    // 1. se lista é nula, cancela
    if (*no == NULL || indice < 0)
        return 0;

    // há muitas maneiras de fazer esta função de forma recursiva;
    // escolhi o seguinte: se indice = 0 pode deletar, senão, indice subtrai 1 e chama denovo.

    int novo_indice = indice;

    // 2. remove caso indice foi atingido

    // 2.1.a. caso seja o último nó
    if ((*no)->Prox == NULL && indice == 0)
    {
        free(*no);
        *no = NULL;

        // com este return a função chamada antes desta fará o papel do nó anterior.
        return 1;
    }

    // 2.2. caso seja do meio
    else if ((*no)->Prox != NULL && indice == 1)
    {
        // como o nó filho existe, considere este nó como 'no_anterior'
        No *remover = (*no)->Prox;
        (*no)->Prox = (*no)->Prox->Prox;
        free(remover);

        return 0;
    }

    // 2.3. caso seja o primeiro nó
    else if(indice == 0)
    {
        // guarda o próximo nó
        No *prox = (*no)->Prox;
        // deleta este nó
        free(*no);
        // O primeiro nó da lista será o próximo nó
        *no = prox;

        return 0;
    }

    // 3. chama denovo enquanto não deletar
    int removido = 0;
    removido += lista_remover_indice(&(*no)->Prox, indice - 1);

    // 2.1.b. (continuação) você deletou o último nó, este aqui é o nó anterior ao deletado
    if (removido == 1)
        (*no)->Prox = NULL;

    // Apenas o nó anterior ao removido recebe o 'removido = 1'
    return 0;
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