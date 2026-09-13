#include<stdlib.h>
#include<string.h>
#include"arquivo.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Uso: %s <arquivo(.txt)>\n", argv[0]);
        return 0;
    }

    Arquivo file = {
        .linhas = 0,
        .palavras = 0,
        .tamanho = 0,
        .ptr_arquivo = NULL
    };

    char nome_arquivo[256] = {0};
    strncpy(nome_arquivo, argv[1], 256);

    char *extensao = strrchr(nome_arquivo, '.');
    
    if(extensao != NULL && strcmp(extensao, ".txt") == 0)
    {
        printf("Arquivo válido.\nFazendo leitura...\n");
    }
    else {
        printf("Extensão diferente ou não encontrada\n");
        return 0;
    }

    file.ptr_arquivo = fopen(argv[1], "r");
    if(!file.ptr_arquivo)
    {
        perror("Erro ao abrir arquivo para leitura");
        return -1;
    }

    printf("Ok\n");

    FILE* pptr_arquivo = file.ptr_arquivo;

    fseek(pptr_arquivo, 0, SEEK_END);
    file.tamanho = ftell(pptr_arquivo);
    fseek(pptr_arquivo, 0, SEEK_SET);

    if(file.tamanho < 0)
    {
        printf("Falha ao calcular o tamanho do arquivo\n");
        fclose(pptr_arquivo);
        return -1;
    }
    int c;

    if((c = getc(pptr_arquivo)) != EOF)
    {
        file.linhas++;
        file.palavras++;
        ungetc(c, pptr_arquivo);
    }

    char *string_arquivo = malloc(sizeof(char) * file.tamanho);

    while(fscanf(pptr_arquivo, "%s", string_arquivo) != EOF)
    {
        if(file.palavras == 0)
            break;
        file.palavras++;

        while((c = fgetc(pptr_arquivo)) != EOF)
        {
            if(c == '\n')
            {
                file.linhas++;
            }
            else if(c != ' ' && c != '\t')
            {
                ungetc(c, pptr_arquivo);
                break;
            }
        }
    }

    printf("Arquivo %s:\nTamanho: %ldB\nLinhas: %d\nPalavras: %d\n", 
        argv[1], file.tamanho, file.linhas, file.palavras);
    
    free(string_arquivo);
    fclose(pptr_arquivo);
    file.ptr_arquivo = NULL;
    file.tamanho = 0;
    file.linhas = 0;
    file.palavras = 0;
    return 0;
}
