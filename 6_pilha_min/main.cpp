// Copyright (C) 2023 - Italo Portinho
#include<cstdio>
#include "./pilha_min_alt.hpp"

int main() {
    PilhaMin pilha = {};
    pilha.cria();
    pilha.empilha(5);
    pilha.empilha(4);
    pilha.empilha(1);
    pilha.empilha(3);
    pilha.empilha(2);
    printf("Minimo == %d \n", pilha.obterMinimo());
    pilha.desempilha();
    pilha.desempilha();
    pilha.desempilha();
    printf("Minimo == %d \n", pilha.obterMinimo());
}
