// Copyright (C) 2023 - Italo Portinho
#include<stack>

// Implementação de uma fila usando duas pilhas.
class Fila2P {
 public:
    std::stack<char> p1;
    std::stack<char> p2;
    int N;
    char _back;
    void cria() {
        N = 0;
        _back = ' ';
    }

// Para enfileirar, passaremos todos os elementos para p2.
//  Colocamos o novo elemento em p1, em seguida passamos
//  todo mundo de p2 de volta para p1. Dessa forma, o método top()
//  da pilha vai poder se usado como o método front() da fila.
// Para saber quem está no final da fila, método back(), sempre
//  atualizamos esse valor ao enfileirar alguém.
// COMPLEXIDADE: O(N)
    void enfileira(char dado) {
        int i = 0;
        while (i < N) {
            p2.push(p1.top());
            p1.pop();
            i++;
        }

        p1.push(dado);

        i = 0;
        while (i < N) {
            p1.push(p2.top());
            p2.pop();
            i++;
        }
        N++;
        _back = dado;
    }

// Com nossa implementação o topo da pilha coincide com a
//  frente da fila.
// Guardamos o topo para retornar. Esse elemento sai da pilha e
//  atualizamos nosso N.
// COMPLEXIDADE: O(1)
    char desenfileira() {
        char valor = p1.top();
        p1.pop();
        N--;
        return valor;
    }

// Com nossa implementação o topo da pilha coincide com a
//  frente da fila.
// COMPLEXIDADE: O(1)
    char front() {
        return p1.top();
    }

// Basta retornar o valor que guardamos sempre alguém
//  entra na fila.
// COMPLEXIDADE: O(1)
    char back() {
        return this->_back;
    }

// Função auxiliar para mostrar o tamanho da fila.
    int tamanho() {
        return p1.size();
    }
};
