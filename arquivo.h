#pragma once
#ifndef ARQUIVO_H
#define ARQUIVO_H
#include<stdio.h>

typedef struct {
    FILE* ptr_arquivo;
    long tamanho;
    int linhas;
    int palavras;
} Arquivo;

Arquivo arquivo_analisar(const char* caminho);
void Arquivo_imprimir_resultado(Arquivo* arq, const char* caminho);
void Arquivo_fechar(Arquivo* arq);

#endif // ARQUIVO_H
