// Copyright (C) 2023 - Italo Portinho
#include <queue>

//---------------------------------------------------------------
// 2)
//---------------------------------------------------------------

// Implementação de uma pilha usando duas filas f1 e f2.
// Para a função empilhar, basta apenas inserir na fila.
// Para o topo usamos a função back da implementação nativa de fila
//  da linguagem C++.
// Para a função desempilhar transferimos N - 1 elementos para a fila f2.
//  Resta na fila f1 o topo da pilha, e retornamos ele. Depois, transferimos
//  de volta todos os elementos de f2 para f1.
// COMPLEXIDADE:
//    topo: O(1) - assumindo que std::queue ter ponteiro para o final da fila.
//    empilha: O(1) - assumindo complexidade constante de push (como no deque).
//    desempilha: O(N)

class Pilha2F {
 public:
    std::queue<char> f1;
    std::queue<char> f2;
    int N;
    void cria() {
        N = 0;
    }
    char topo() {
        return f1.back();
    }
    void empilha(char dado) {
        f1.push(dado);
        N++;
    }
    char desempilha() {
        int i = N;
        char valor;
        // Todos os elementos menos o primeiro são transferidos para a fila 2.
        // Agora na fila 1 resta somente o topo da pilha. Guardamos esse valor
        //  para retornar depois, damos pop, e atualizamos N1.
        while (i < N - 1) {
            f2.push(f1.front());
            f1.pop();
            i++;
        }
        valor = f1.front();
        f1.pop();
        N--;

        // Agora retornamos todos os elementos da fila 2 para a fila 1.
        i = N;
        while (i < N) {
            f1.push(f2.front());
            f2.pop();
        }
        return valor;
    }

    // Função auxiliar para mostrar o tamanho da pilha.
    int tamanho() {
        return this->N;
    }
};
