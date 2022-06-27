#include <stdio.h>  // scanf, printf
#include <string.h> //strcpy, memcpy

int main()
{
    // Copas, Espadas, U (ouros), Paus
    char naipes[4] = {'C', 'E', 'U', 'P'};

    char *cartas[13] = {
        "01", // 0 - As
        "02",
        "03",
        "04",
        "05",
        "06",
        "07",
        "08",
        "09",
        "10",
        "11",
        "12",
        "13", // 12
    };

    // recebe cartas
    char entrada[156] = {0};
    scanf("%156s[^\n]", entrada);
    // char *entrada = "11P01C02C01U02U03U04U";
    int total[4] = {0};
    int repetido[4] = {0};

    // conta duplicadas
    int ret[4][13] = {{0}, {0}, {0}, {0}};
    char carta_n[] = {0, 0, 0};
    for (int i = 0; strlen(entrada) - i >= 3; i++)
    {
        for (int j = 0; j < 4; j++)
            if (naipes[j] == entrada[i + 2])
            {
                memcpy(carta_n, entrada + i, 2);

                for (int k = 0; k < 13; k++)
                {
                    // printf("entrada: '%s' vs lista '%s'\n", carta_n, cartas[k]);
                    if (strcmp(carta_n, cartas[k]) == 0)
                    {
                        ret[j][k]++;
                        total[j]++;
                        if (ret[j][k] > 1)
                            repetido[j]++;
                    }
                }
            }
    }

    for (int i = 0; i < 4; i++)
    {
        // for (int j = 0; j < 13; j++)
            // printf("[%i][%i] = %i\n", i, j, ret[i][j]);
            // printf("%i ", ret[i][j]);
        // printf("Total %i, Repetido %i\n",total[i],repetido[i]);
        if(repetido[i])
            printf("erro\n");
        else
            printf("%i\n", 13 - total[i]);
    }
    return 0;
}