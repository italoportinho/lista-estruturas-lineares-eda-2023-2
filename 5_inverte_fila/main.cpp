// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include<stack>
#include<queue>
#include<cstdio>

// ----------------------------------------------------------------
//          Inverter uma fila usando somente uma pilha.
// ----------------------------------------------------------------
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

// ----------------------------------------------------------------
//          Inverter uma fila usando somente duas filas.
// ----------------------------------------------------------------
// A estratégia aqui é passar N - 1 elementos para a fila auxiliar f1,
//  e o elemento restante para a fila f2. Quem foi para f1 retorna para
//  a fila original e repetimos o cicloaté que todos os elementos estejam
//  em f2, já invertidos. Depois é só transferir os elementos de volta de
//  f2 para a fila original.
// COMPLEXIDADE: O(N^2) - cada loop interno percorre a fila inteira uma vez.
//  Esse ciclo é repetido N vezes (loop externo).
void inverte_B(std::queue<char>* f) {
    std::queue<char> f1;
    std::queue<char> f2;
    int i = 0;
    int N = f->size();

    while (i < N) {
        // Passamos todos os elementos, menos o final da original, para f1.
        while (f->size() > 1) {
            f1.push(f->front());
            f->pop();
        }

        // O final da fila original vai para f2.
        f2.push(f->front());
        f->pop();

        // Quem estava em f1 retorna para a fila original.
        while (f1.size() > 0) {
            f->push(f1.front());
            f1.pop();
        }
        i++;
    }

    // Devolvemos os elementos para a fila original, agora invertidos.
    while (f2.size() > 0) {
        f->push(f2.front());
        f2.pop();
    }
}

int main() {
    std::queue<char> minha_fila;
    minha_fila.push('1');
    minha_fila.push('2');
    minha_fila.push('3');
    minha_fila.push('4');
    minha_fila.push('5');
    // inverte_A(&minha_fila);
    inverte_B(&minha_fila);
    while (minha_fila.size() > 0) {
        printf("%c \n", minha_fila.front());
        minha_fila.pop();
    }
}
