#include <stdio.h> //printf, scanf

int main()
{
    int num1, num2;
    scanf("%i %i", &num1,  &num2);
    if (num1 > num2)
        printf("num = %i",num1);
    else
        printf("num = %i",num2);
    return 0;
}