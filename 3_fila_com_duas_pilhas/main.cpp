// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include<cstdio>
#include "./fila.hpp"

int main() {
    Fila2P fila = {};
    fila.cria();
    fila.enfileira('a');
    fila.enfileira('b');
    fila.enfileira('c');
    fila.enfileira('d');
    fila.enfileira('e');
    printf("Tamanho da fila: %d \n", fila.tamanho());
    printf("Frente da fila: %c \n", fila.front());
    printf("Último da fila: %c \n", fila.back());
    printf("Elemento desemfileirado: %c \n", fila.desenfileira());
    printf("Elemento desemfileirado: %c \n", fila.desenfileira());
    printf("Frente da fila: %c \n", fila.front());
    printf("Último da fila: %c \n", fila.back());
    fila.enfileira('X');
    printf("Frente da fila: %c \n", fila.front());
    printf("Último da fila: %c \n", fila.back());
}