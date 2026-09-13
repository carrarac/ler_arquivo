#include"arquivo.h"
#include<string.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Uso: %s <arquivo(.txt)>\n", argv[0]);
        return 0;
    }

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
    
    Arquivo arq = arquivo_analisar(argv[1]);

    if(arq.ptr_arquivo != NULL)
    {
        printf("OK\n");
        Arquivo_imprimir_resultado(&arq, argv[1]);

        Arquivo_fechar(&arq);
    }
    else {
        printf("Falha na analise do arquivo.\n");
        return -1;
    }

    return 0;
}
