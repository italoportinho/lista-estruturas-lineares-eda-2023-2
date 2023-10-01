// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include<stack>
#include<queue>
#include<cstdio>

// Inverter uma fila usando somente uma pilha.
// A estratégia aqui é todos os transferir os elementos da fila
//  para a pilha. Em seguida transferir de volta para a fila e,
//  os elementos estarão com a ordem invertida. A estratégia funciona
//  porque na fila inserimos no final da estrutura, e na pilha inserimos
//  no início, antes do primeiro elemento.
// COMPLEXIDADE: O(N) - percorremos a fila/pilha inteira uma vez cada.
void inverte_A(std::queue<char>* f) {
    std::stack<char> p1;
    while (f->size() > 0) {
        p1.push(f->front());
        f->pop();
    }
    while (p1.size() > 0) {
        f->push(p1.top());
        p1.pop();
    }
}

// Inverter uma fila usando somente duas filas.
void inverte_B(std::queue<char>* f) {
    std::queue<char> f1;
    std::queue<char> f2;
}

int main() {
    std::queue<char> minha_fila;
    minha_fila.push('1');
    minha_fila.push('2');
    minha_fila.push('3');
    minha_fila.push('4');
    minha_fila.push('5');
    inverte_A(&minha_fila);
    while (minha_fila.size() > 0) {
        printf("%c \n", minha_fila.front());
        minha_fila.pop();
    }
}