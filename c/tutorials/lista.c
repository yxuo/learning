#include <stdio.h>  // print,scan
#include <stdlib.h> // malloc, free

struct Lista
{
    int valor;
    struct Lista *prox;
};
typedef struct Lista Lista;

Lista *lista_novo(int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = valor;
    return novo;
}

void print_lista_valor(int pos, Lista *lista)
{
    // pos começa do final, ela vai diminuindo

    // se tiver vazio, sai;
    if (lista == NULL)
        return;

    // imprime se pos = 0
    if (pos == 0)
    {
        printf("valor = %i\n", lista->valor);
        return;
    }

    // se pos > 0, chama o prox, pos -=1
    else if (pos > 0)
        print_lista_valor(pos - 1, lista->prox);
}

void lista_add_antes(Lista **lista, int valor)
{
    Lista *novo = lista_novo(valor);
}

int main()
{
    // vetor ordenado
    int arr[5] = {0};
    // printf("size = %zu",sizeof(arr)/sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr); i++)
    {
        //
    }

    // vetor não ordenado
    Lista *var_lista = NULL;

    // 1o elemento
    var_lista = lista_novo(10);
    printf("valor = %i\n", var_lista->valor);
    // 2o elemento
    var_lista->prox = (Lista *)malloc(sizeof(Lista));
    var_lista->prox->valor = 30;
    // printf("valor = %i\n", var_lista->prox->valor);
    print_lista_valor(1, var_lista);

    // ponteiro e refência
    // int num = 10;
    // int *ptr_num = &num;
    // ptr_num = &num;
    // printf("endereco %i tem valor %i\n",&num,num);
    // printf("endereco %i tem valor %i\n",ptr_num,*ptr_num);
}