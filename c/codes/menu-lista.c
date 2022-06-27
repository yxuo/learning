/**
 * @file menu-lista.c
 * @version 0.2
 * @date 2022-06-20
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

    if (pos > 0 || (pos < 0 && (*no)->Prox))
        lista_adicionar_indice(&(*no)->Prox, valor, pos - 1);

    // 3. adicionar nó no fim
    else
        (*no)->Prox = lista_novo_no(valor);
}

int lista_len(No *no)
{
    if(!no)
        return 0;
    return lista_len(no->Prox) + 1;
}

int lista_len(No *no)
{
    int comp = 0;
    for(No *no1 = no; no1; comp++, no1 = no1->Prox);
    return comp;
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

// mesma coisa, só muda o índice ao invés do valor
int lista_remover_indice(No **no, int indice)
{
    // 1. se lista é nula, cancela
    if (*no == NULL)
        return 0;

    // há muitas maneiras de fazer esta função de forma recursiva;
    // escolhi o seguinte: se indice = 0 pode deletar, senão, indice subtrai 1 e chama denovo.

    int novo_indice = indice;

    // 2. remove caso indice foi atingido

    // 2.1.a. caso seja o último nó
    if ((*no)->Prox == NULL)
    {
        // envita deletar o último elemento caso o índice esteja fora
        if(indice > 0)
            return 0;
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

int somar1(int num)
{
    // 
    if(num < 10)
        somar1(num+1);
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
               "5. Comprimento da lista\n"
               "6. Ajuda\n"
               "7. Sair\n"
               ">> ");
        scanf("%i", &entrada);

        switch (entrada)
        {
        case 7:
            return 0;
            break;
        case 6:
            printf(
                "Lista:\n"
                ".Esta e uma lista unicamente encadeada, apontando sempre para o elemento posterior\n"
                "Indices:\n"
                ".Se voce usar um indice fora da lista, nada acontece\n"
                ".Se voce usar um indice negativo, o indice sera o ultimo elemento\n"
                "Remover:\n"
                ".Se voce remover um item de uma lista vazia, um aviso sera dado\n\n"
                );
            break;
        case 5:
            printf("Comprimento: %i\n",lista_len(lista));
            break;
        case 4:
            print_listaln(lista);
            break;
        case 3:
            if(!lista_len(lista)){
                printf("Remover indice: Lista vazia!\n");
                break;
            }
            printf("Selecione o indice do item a remover ([-1] para remover no final): ");
            scanf("%i", &indice);
            lista_remover_indice(&lista, indice);
            print_listaln(lista);
            break;
        case 2:
            if(!lista_len(lista)){
                printf("Remover valor: Lista vazia!\n");
                break;
            }
            printf("Selecione o valor do item a remover: ");
            scanf("%i", &valor);
            lista_remover_valor(&lista, valor);
            print_listaln(lista);
            break;
        case 1:
            printf("Selecione o valor do novo item: ");
            scanf("%i", &valor);
            printf("Selecione o indice a adicionar ([-1] para adicionar no final): ");
            scanf("%i", &indice);
            lista_adicionar_indice(&lista, valor, indice);
            print_listaln(lista);
            break;

        default:
            printf("comando invalido!\n");
        }
    }
}