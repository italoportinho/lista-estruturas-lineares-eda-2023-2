// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include<cstdio>
#include "./pilha.hpp"
// Para compilar: g++ main.cpp -o main
int main() {
    Pilha2F pilha = {};
    pilha.cria();
    pilha.empilha('e');
    pilha.empilha('d');
    pilha.empilha('c');
    pilha.empilha('b');
    pilha.empilha('a');
    printf("Tamanho da pilha: %d \n", pilha.tamanho());
    printf("Elemento desempilhado: %c \n", pilha.desempilha());
    printf("Elemento desempilhado: %c  \n", pilha.desempilha());
    printf("Elemento desempilhado: %c  \n", pilha.desempilha());
    printf("Elemento desempilhado: %c  \n", pilha.desempilha());
    printf("Elemento desempilhado: %c  \n", pilha.desempilha());
    printf("Tamanho da pilha: %d \n", pilha.tamanho());
}