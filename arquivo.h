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

#endif // ARQUIVO_H