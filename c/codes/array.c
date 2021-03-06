#include <stdio.h>  //printf, scanf
#include <stdlib.h> //alloc free
#include <string.h> //memset, memcpy

typedef struct ArrDynDouble{
    int val;
    struct ArrDynDouble *ante;
    struct ArrDynDouble *prox;
} ArrDynDouble;

ArrDynDouble *array_dynamic_double_new(int val)
{
    ArrDynDouble *new = (ArrDynDouble*) malloc(sizeof(ArrDynDouble));
    new->ante = 0;
    new->prox = 0;
    new->val = val;
    return new;
}

void array_dynamic_double_add(ArrDynDouble **node, int val, int pos)
{
    if (!*node)
        return;
    if (pos)
        array_dynamic_double_add(&(*node)->prox, val, pos-1);

    ArrDynDouble *new = array_dynamic_double_new(val);
    new->ante = *node;
}

void array_dynamic_double_del_pos(ArrDynDouble **node, int pos)
{
    if (!*node)
        return;
    if (pos)
        array_dynamic_double_del_pos(&(*node)->prox, pos-1);

    ArrDynDouble *ante = (*node)->ante;
    ArrDynDouble *prox = (*node)->prox;
    free(*node);
    ante->prox = prox;
    prox->ante = ante;
}

// ARRAY BASIC

void print_array_basic(int *arr, int size, char *end)
{
    for (int i = 0; i < size; i++)
        printf(" %i ", arr[i]);
    if (end)
        printf("%s", end);
}

void array_basic_insert(int *arr, int arr_size, int *size, int pos, int value)
{
    // printf("SIZE %i",*size);
    // pos -1 = add last
    if (pos < 0)
    {
        pos = *size;
        if (*size == arr_size)
        {
            for (int i = 0; i < arr_size - 1; i++)
                arr[i] = arr[i + 1];
            pos = *size - 1;
        }
        arr[pos] = value;
        *size += 1;
    }
    else
    {
        for (int i = arr_size - 1; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        *size += 1;
    }
    arr[pos] = value;
}

void array_basic_remove(int *arr, int arr_size, int *size, int pos)
{
    if (pos >= 0)
        for (int i = pos; i < *size - 1; i++)
            arr[i] = arr[i + 1];
    else
        pos = *size - 1;
    if (*size)
        *size -= 1;
    arr[*size] = 0;
}

void array_basic_clear(int *arr, int arr_size, int *size)
{
    memset(arr, 0, arr_size);
    *size = 0;
}

void array_basic_fn()
{
    int arr[10] = {1, 2, 3};
    int pos = 0;
    int size = 3;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "\n");

    // insert first
    array_basic_insert(arr, sizeof(arr) / sizeof(int), &size, 0, 4);
    print_array_basic(arr, sizeof(arr) / sizeof(int), "+4\n");

    // insert position
    array_basic_insert(arr, sizeof(arr) / sizeof(int), &size, 1, 5);
    print_array_basic(arr, sizeof(arr) / sizeof(int), "+5\n");

    // insert last
    array_basic_insert(arr, sizeof(arr) / sizeof(int), &size, -1, 6);
    print_array_basic(arr, sizeof(arr) / sizeof(int), "+6\n");

    // remove first
    array_basic_remove(arr, sizeof(arr) / sizeof(int), &size, 0);
    print_array_basic(arr, sizeof(arr) / sizeof(int), "-4\n");

    // remove position
    array_basic_remove(arr, sizeof(arr) / sizeof(int), &size, 1);
    print_array_basic(arr, sizeof(arr) / sizeof(int), "-1\n");

    // remove last
    array_basic_remove(arr, sizeof(arr) / sizeof(int), &size, -1);
    print_array_basic(arr, sizeof(arr) / sizeof(int), "-6\n");
}

void array_basic()
{
    int arr[10] = {1, 2, 3};
    int pos = 0;
    int size = 3;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "\n");

    // insert first
    for (int i = sizeof(arr) / sizeof(int) - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 4;
    size++;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "+4\n");

    // insert position
    pos = 1;
    for (int i = sizeof(arr) / sizeof(int) - 1; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 5;
    size++;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "+5\n");

    // insert last
    pos = size;
    if (size == sizeof(arr) / sizeof(int))
        for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++)
            arr[i] = arr[i + 1];
    else
        size++;
    arr[pos] = 6;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "+6\n");

    // remove first
    pos = 0;
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = 0; // optional
    size--;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "-4\n");

    // remove position
    pos = 1;
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = 0;
    size--;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "-1\n");

    // remove last
    pos = size - 1;
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = 0;
    size--;
    print_array_basic(arr, sizeof(arr) / sizeof(int), "-6\n");
}

// ARRAY POINTER

void print_array_ptr(int *arr, int size, char *end)
{
    if (end)
        printf("%s", end);
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

int *array_ptr_ini(int size)
{
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    return arr;
}

void array_ptr_add(int **arr, int *size, int pos, int value)
{
    *size += 1;
    if (pos < 0)
        pos = *size - 1;
    (*arr) = (int *)realloc((*arr), sizeof(int) * *size);
    for (int i = *size - 1; i > pos; i--)
        (*arr)[i] = (*arr)[i - 1];
    (*arr)[pos] = value;
}

void array_ptr_del(int **arr, int *size, int pos)
{
    if (pos < 0)
        pos = *size - 1;
    for (int i = pos; i < *size - 1; i++)
        (*arr)[i] = (*arr)[i + 1];
    *size -= 1;
    (*arr) = (int *)realloc((*arr), sizeof(int) * *size);
        // printf("%i = %i\n",(*arr)[i], (*arr)[i + 1]),
}

void array_ptr_fn()
{
    int size = 3;
    int *arr = array_ptr_ini(size);

    // memset
    for (int i = 0; i < size; i++)
        arr[i] = i+1;
    print_array_ptr(arr, size, "   ");

    // add first
    array_ptr_add(&arr, &size, 0, 4);
    print_array_ptr(arr, size, "+4\t");

    // add pos
    array_ptr_add(&arr, &size, 1, 5);
    print_array_ptr(arr, size, "+5\t");

    // add end
    array_ptr_add(&arr, &size, -1, 6);
    print_array_ptr(arr, size, "+6\t");

    // del first
    array_ptr_del(&arr, &size, 0);
    print_array_ptr(arr, size, "-4\t");

    // del pos
    array_ptr_del(&arr, &size, 1);
    print_array_ptr(arr, size, "-1\t");

    // del end
    array_ptr_del(&arr, &size, -1);
    print_array_ptr(arr, size, "-6\t");
}

void array_ptr()
{
    int size = 3;
    int *arr = 0;

    // create array
    arr = (int *)malloc(sizeof(int) * size);

    // memset
    for (int i = 0; i < size; i++)
        arr[i] = 0;

    // set values
    for (int i = 0; i < 3; i++)
        arr[i] = i + 1;

    // print list
    printf("  \t");
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");

    // insert first
    size++;
    arr = (int *)realloc(arr, sizeof(int) * size);
    int pos = 0;
    for (int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 4;
    print_array_ptr(arr, size, "+4\t");

    // insert pos
    size++;
    arr = (int *)realloc(arr, sizeof(int) * size);
    pos = 1;
    for (int i = size - 1; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 5;
    print_array_ptr(arr, size, "+5\t");

    // insert last
    size++;
    arr = (int *)realloc(arr, sizeof(int) * size);
    pos = size - 1;
    arr[pos] = 6;
    print_array_ptr(arr, size, "+6\t");

    // delete first
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    arr = (int *)realloc(arr, sizeof(int) * size);
    print_array_ptr(arr, size, "-4\t");

    // delete pos
    pos = 1;
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    arr = (int *)realloc(arr, sizeof(int) * size);
    print_array_ptr(arr, size, "-1\t");

    // delete last
    size--;
    arr = (int *)realloc(arr, sizeof(int) * size);
    print_array_ptr(arr, size, "-6\t");
}

// TODO: ARRAY DYNAMIC

int main()
{
    // array_basic();
    // printf("\n");
    // array_basic_fn();
    // array_ptr();
    array_ptr_fn();
}