#include"arquivo.h"
#include <stdio.h>
#include<stdlib.h>

Arquivo arquivo_analisar(const char *caminho)
{
    Arquivo file = {
        .linhas = 0, .palavras = 0,
        .tamanho = 0, .ptr_arquivo = NULL
    };

    file.ptr_arquivo = fopen(caminho, "r");

    if(file.ptr_arquivo == NULL)
    {
        perror("Erro ao abrir arquivo");
        return file;
    }

    fseek(file.ptr_arquivo, 0, SEEK_END);
    file.tamanho = ftell(file.ptr_arquivo);
    fseek(file.ptr_arquivo, 0, SEEK_SET);

    int c;

    if((c = getc(file.ptr_arquivo)) != EOF)
    {
        file.linhas++;
        ungetc(c, file.ptr_arquivo);
    }

    char* string_arquivo = malloc(sizeof(char) * file.tamanho);
    if(!string_arquivo) return file;

    while(fscanf(file.ptr_arquivo, "%s", string_arquivo) != EOF) {
        file.palavras++;
        while((c = fgetc(file.ptr_arquivo)) != EOF) {
            if(c == '\n') file.linhas++;
            else if(c != ' ' && c != '\t') {
                ungetc(c, file.ptr_arquivo);
                break;
            }
        }
    }
    free(string_arquivo);
    return file;
}

void Arquivo_imprimir_resultado(Arquivo* arq, const char *caminho)
{
    if(arq->tamanho > 0)
    {
        printf("Arquivo %s:\nTamanho: %ldB\nLinhas: %d\nPalavras: %d\n",
                caminho, arq->tamanho, arq->linhas, arq->palavras);
    }
}

void Arquivo_fechar(Arquivo* arq)
{
    if(arq->tamanho > 0)
    {
        if(arq->ptr_arquivo)
            fclose(arq->ptr_arquivo);
        arq->ptr_arquivo = NULL;
        arq->linhas = 0;
        arq->palavras = 0;
        arq->tamanho = 0;
    }
    else {
        if(arq->ptr_arquivo)
            fclose(arq->ptr_arquivo);
        arq->ptr_arquivo = NULL;
    }
}
