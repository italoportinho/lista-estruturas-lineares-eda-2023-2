// Copyright (C) 2023 - Italo Portinho
#include <cstdio>
#include "./deque.hpp"

int main() {
/*
    Deque meu_deque = {};
    meu_deque.cria();
    printf("%d \n", meu_deque.N);
    meu_deque.insereInicio('a');
    meu_deque.insereInicio('b');
    meu_deque.insereInicio('c');
    meu_deque.insereInicio('d');
    meu_deque.insereInicio('e');
    printf("%d \n", meu_deque.N);
    meu_deque.mostraDeque();
    // printf("%c \n", meu_deque.retornaInicio());
    // printf("%c \n", meu_deque.retornaFim());
    meu_deque.removeInicio();
    printf("%d \n", meu_deque.N);
    meu_deque.removeFim();
    meu_deque.mostraDeque();
*/
/*
    PilhaDeque pilha = {};
    Deque deque_pilha = {};
    deque_pilha.cria();
    pilha.d = deque_pilha;
    pilha.empilha('a');
    pilha.empilha('b');
    pilha.empilha('c');
    pilha.empilha('d');
    pilha.empilha('e');
    printf("%c \n", pilha.topo());
    pilha.desempilha();
    printf("%c \n", pilha.topo());
*/
    FilaDeque fila = {};
    Deque deque_fila = {};
    deque_fila.cria();
    fila.d = deque_fila;
    fila.enfileira('a');
    fila.enfileira('b');
    fila.enfileira('c');
    fila.enfileira('d');
    fila.enfileira('e');
    printf("%c \n", fila.frente());
    fila.desenfileira();
    printf("%c \n", fila.frente());
}

