// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include<stack>
#include<queue>
#include<cstdio>

// Inverter uma pilha usando uma fila
// A estratégia aqui é transferir todos os elementos para a fila,
//   e em seguida transferi-los de volta para a pilha.
// COMPLEXIDADE: O(N) - percorre a pilha e a fila inteiras uma vez cada.
void inverte_A(std::stack<char>* p) {
    std::queue<char> fila;
    while (p->size() > 0) {
        fila.push(p->top());
        p->pop();
    }
    while (fila.size() > 0) {
        p->push(fila.front());
        fila.pop();
    }
}

// Inverter uma pilha usando duas pilhas.
// A estratatégia aqui é transferir todos os elementos da pilha
//  original para a pilha auxiliar p1. Em seguida transferir N - 1
//  elementos de p1 para p2. O primeiro elemento da pilha original está em p1,
//  e deve voltar pra pilha orinal agora. O resto dos elementos estão invertidos
//  em p2 e basta transferi-los de volta para a pilha original.
// COMPLEXIDADE: O(N) - é preciso percorrer cada pilha uma vez.
void inverte_B(std::stack<char>* p) {
    std::stack<char> p1;
    std::stack<char> p2;

    // transferindo da original pra p1 auxiliar.
    while (p->size() > 0) {
        p1.push(p->top());
        p->pop();
    }

    // transferindo N - 1 elementos de p1 pra p2
    while (p1.size() > 1) {
        p2.push(p1.top());
        p1.pop();
    }

    // O elemento restante em p1, volta pra pilha original.
    p->push(p1.top());
    p1.pop();

    // Todo mundo da pilha auxiliar p2 volta pra original.
    while (p2.size() > 0) {
        p->push(p2.top());
        p2.pop();
    }
}

// Inverter uma pilha usando somente outra pilha.
// A estratégia aqui é guardar o topo e transferir N - i elementos
//  para a pilha auxiliar, com i = 0 inicialmente. Em seguida, topo
//  volta para a pilha original, e todos os elementos da pilha
//  auxiliar também voltam pra pilha original. Ao final desse ciclo
//  i é incrementado e seguimos repetindo a operação até que i seja
//  igual a N.
// COMPLEXIDADE: O(N^2)
void inverte_C(std::stack<char>* p) {
    std::stack<char> p1;
    char old_top;
    int i = 0;
    int N = p->size();
    while (i < N) {
        old_top = p->top();
        p->pop();
        while (p->size() > 0) {
            p1.push(p->top());
            p->pop();
        }
        p->push(old_top);
        i++;
        while (p1.size() > 0) {
            p->push(p1.top());
            p1.pop();
        }
    }
}
int main() {
    std::stack<char> minha_pilha;
    minha_pilha.push('1');
    minha_pilha.push('2');
    minha_pilha.push('3');
    minha_pilha.push('4');
    minha_pilha.push('5');
    // inverte_A(&minha_pilha);
    // inverte_B(&minha_pilha);
    inverte_C(&minha_pilha);
    while (minha_pilha.size() > 0) {
        printf("%c \n", minha_pilha.top());
        minha_pilha.pop();
    }
}
