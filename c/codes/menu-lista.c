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

/**
 * @brief Adicionar item na posição desejada
 *
 * @param no O endereço da lista
 * @param valor O valor do novo item
 * @param pos A posição desejada (-1 = última posição)
 */
void lista_adicionar_indice(No **no, int valor, int pos)
{
    // 1. se a lista tá vazia, adicionar o 1o elemento
    if (*no == NULL || pos == 0)
    {
        No *novo = lista_novo_no(valor);
        novo->Prox = *no;
        *no = novo;
        return;
    }

    // 2. percorrer até a posição, daí este elemento  pode apontar para o novo elemento

    if (pos > 1 || (pos < 0 && (*no)->Prox))
        lista_adicionar_indice(&(*no)->Prox, valor, pos - 1);

    // 3. adicionar nó no fim
    else
    {
        // No *novo = lista_novo_no(valor);
        // novo->Prox = *no;
        // *no = novo;
        (*no)->Prox = lista_novo_no(valor);
    }
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

void print_lista(No *no)
{
    // troca while por recursividade
    if (no != NULL)
    {
        printf("%d ", no->valor);
        print_lista(no->Prox);
    }
}

void print_listaln(No *no)
{
    printf("Inicio -> ");
    print_lista(no);
    printf(" <- Fim\n");
}

int lista_remover_valor(No **no, int valor)
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
    else if ((*no)->valor == valor)
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
    removido += lista_remover_valor(&(*no)->Prox, valor);

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
    else if (indice == 0)
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
    char *op[2] = {"adicionar", "remover"};
    int indice = 0;
    int valor = 0;
    No *lista = NULL;
    int entrada = 0;

    for(;;)
    {
        printf("MENU - Lista\n"
               "1. Adicionar valor\n"
               "2. Remover valor\n"
               "3. Remover indice\n"
               "4. Imprimir lista\n"
               "5. Ajuda\n"
               "6. Sair\n"
               ">> ");
        scanf("%i", &entrada);

        switch (entrada)
        {
        case 6:
            return 0;
            break;
        case 5:
            printf(
                "Lista:\n"
                ".Esta e uma lista unicamente encadeada, apontando sempre para o elemento posterior\n"
                "Indices:\n"
                ".Se voce usar um indice fora da lista, o indice sera o ultimo elemento\n"
                "Remover:\n"
                ".Se voce remover um item de uma lista vazia, nada acontecera\n\n"
                );
            break;
        case 4:
            print_listaln(lista);
            break;
        case 3:
            printf("Selecione o indice do item a remover: ");
            scanf("%i", &indice);
            lista_remover_indice(&lista, indice);
            print_listaln(lista);
            break;
        case 2:
            printf("Selecione o valor do item a remover: ");
            scanf("%i", &valor);
            lista_remover_valor(&lista, valor);
            print_listaln(lista);
            break;
        case 1:
            printf("Selecione o valor do novo item: ");
            scanf("%i", &valor);
            printf("Selecione o 5ndice a adicionar ([-1] para adicionar no final): ");
            scanf("%i", &indice);
            lista_adicionar_indice(&lista, valor, indice);
            print_listaln(lista);
            break;

        default:
            printf("comando invalido!\n");
        }
    }
    No *lista_invertida = NULL;

    printf("1. adicionar itens no inicio da lista\n");
    for (int i = 0; i < 5; i++)
        lista_adicionar_indice(&lista_invertida, i, 0);
    print_listaln(lista_invertida);

    printf("2. adicionar itens no fim da lista\n");
    for (int i = 0; i < 5; i++)
        lista_adicionar_indice(&lista, i, -1);
    print_listaln(lista);

    printf("2. adicionar item no indice [3]\n");
    lista_adicionar_indice(&lista, 10, 3);
    print_listaln(lista);

    printf("3. remover ultimo item\n");
    lista_remover_ultimo(&lista);
    print_listaln(lista);

    printf("4. remover item no indice [2] = 2\n");
    lista_remover_indice(&lista, 2);
    print_listaln(lista);

    printf("5. remover item com valor (1)\n");
    lista_remover_valor(&lista, 1);
    print_listaln(lista);
}