#include <stdio.h>  //printf, scanf
#include <stdlib.h> //alloc free
#include <string.h> //memset, memcpy

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

int main()
{
    array_basic();
    printf("\n");
    array_basic_fn();
}