#include <stdio.h> // print, scan

struct pacote
{
    int valor;
    float decimal;
    char mensagem[50];
};

void salvar_pacote_txt(struct pacote pac)
{
    FILE *file = fopen("arquivo.txt", "w");
    fprintf(file, "%d %f %s\n", pac.valor, pac.decimal, pac.mensagem);
    fclose(file);
}

void carregar_pacote_txt(struct pacote *pac)
{
    FILE *file = fopen("arquivo.txt", "r");
    fscanf(file, "%d %f %50[^\n]", &pac->valor, &pac->decimal, pac->mensagem);
    fclose(file);
}

int main()
{

    struct pacote pac = {5, 3.14, "hello world"};
    printf("Antes: %s\n",pac.mensagem);
    salvar_pacote_txt(pac);
 
    pac = (struct pacote){0, 0, 0};
    printf("Zerado: %s\n",pac.mensagem);

    carregar_pacote_txt(&pac);
    printf("Depois: %s\n",pac.mensagem);
}