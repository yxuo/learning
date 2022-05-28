#include <stdio.h>  //printf, scanf
#include <stdlib.h> //alloc free

void array_ptr()
{
    int size = 5;
    int *arr = 0;

    // create array
    arr = (int *)malloc(sizeof(int) * size);

    // read/write
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 10;
        // printf("%i = %i\n", i, arr[i]);
    }

    // delete first
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 10;
        printf("%i = %i\n", i, arr[i]);
    }
}


void print_array_basic(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        printf(" %i ",arr[i]);
    printf("\n");
}

void array_basic_insert(int *arr, int size, int size_index, int value, int pos)
{
    // pos -1 = add last
    for (int i = 0; i < size; i++)
        arr[i] = arr[i - 1];
}

void array_basic()
{
    int arr[10] = {1, 2, 3};
    int pos = 0;
    int size = 3;
    print_array_basic(arr, sizeof(arr)/sizeof(int));

    // insert first
    for (int i = sizeof(arr)/sizeof(int) - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 4;
    size++;
    print_array_basic(arr, sizeof(arr)/sizeof(int));

    // insert position
    pos = 1;
    for (int i = sizeof(arr)/sizeof(int) - 1; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 5;
    size++;
    print_array_basic(arr, sizeof(arr)/sizeof(int));

    pos = size;
    // insert last
    if (size == sizeof(arr)/sizeof(int))
        for (int i = 0; i < sizeof(arr)/sizeof(int) - 1; i++)
            arr[i] = arr[i + 1];
    else
        size++;
    arr[pos] = 6;

    // remove first
    // for (int i = sizeof(arr)/sizeof(int); i - 1 > 0; i--)
    //     arr[i] = arr[i - 1];
    // arr[0] = 10;
    print_array_basic(arr, sizeof(arr)/sizeof(int));
}

int main()
{
    array_basic();
}