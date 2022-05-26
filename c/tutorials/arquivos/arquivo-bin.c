#include <stdio.h> // print, scan

struct pacote
{
    int valor;
    float decimal;
    char mensagem[50];
};

void salvar_pacote_bin(struct pacote pac)
{
    FILE *file = fopen("arquivo.bin", "wb");
    fread(file,&pac.valor,&pac.decimal,pac.mensagem);
    fclose(file);
}

void carregar_pacote_bin(struct pacote *pac)
{
    FILE *file = fopen("arquivo.bin", "rb");
    fscanf(file, "%d %f %s", pac->valor, pac->decimal, pac->mensagem);
    fclose(file);
}

int main()
{

    struct pacote pac = {5, 3.14, "hello world"};
    printf("Antes: %s\n",pac.mensagem);
    salvar_pacote_bin(pac);
    
    pac = (struct pacote) {0,0,0};
    printf("Zerado: %s\n",pac.mensagem);

    carregar_pacote_bin(&pac);
    printf("Depois: %s\n",pac.mensagem);
    return 0;
}