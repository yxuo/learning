#include <stdlib.h> // alloc, free
#include <stdio.h>  // print, scan

#define TAMANHO 5

void bubblesort_facil()
{
    int lista[TAMANHO] = {5, 4, 3, 2, 1};

    // 5 4 3 2 1
    // a-b
    // Compara o 1o com o 2o, até o penúltimo

    // print lista
    for (int i = 0; i < TAMANHO; i++)
        printf("%d ", lista[i]);
    printf("\n");

    // Dá N voltas,     N é o no. de itens da lista
    for (int i = 0; i < TAMANHO; i++)
    {
        // Vai de 0 a N-1
        for (int j = 0; j < TAMANHO - 1; j++)
        {
            // atual = j, prox = j+1
            // se atual > prox, troca.
            if (lista[j] > lista[j + 1])
            {
                int atual = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = atual;
            }
        }
    }

    // print lista
    for (int i = 0; i < TAMANHO; i++)
        printf("%d ", lista[i]);
    printf("\n");
}

int main()
{
    /**
     * Bubble sort
     *
     * Queremos transformar:
     * 5 4 3 2 1
     *
     * em:
     * 1 2 3 4 5
     */
    bubblesort_facil();
    // bubblesort_recomendado();
}