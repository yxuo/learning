#include <stdio.h> // print, scan

int main()
{
    printf("hello world\n");

    int num = 42;
    int *ptr_num = &num;

    printf("&num = %p\n", &num);
    printf("num = %d\n", num);
    printf("\n");
    
    printf("&ptr_num = %p\n", &ptr_num);
    printf("ptr_num = %p\n", ptr_num);
    printf("*ptr_num = %d\n", *ptr_num);

    return 0;
}