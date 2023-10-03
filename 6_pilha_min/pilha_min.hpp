// Copyright (C) 2023 - Italo Portinho


// Obter o menor elemento de uma pilha em tempo constante;
// Vamos manter  uma variável com o valor mínimo e na hora de
//  empilhar um elemento, fazemos uma comparação para atualizar
//  o mínimo, se for necessário. Essa estratégia funciona, porém
//  surge um problema quando desempilhamos o elemento mínimo. Como
//  encontrar o novo valor mínimo?
// Qualquer abordagem que usasse alguma estrutura para manter os
//  valores ordenados, ou guardar os mínimos com ponteiros para
//  o próximo mínimo exigiria percorrer a estrutura, o que
//  violaria a regra de tempo constante. Portanto se faz necessário
//  uma estratégia na qual seja possível obter o novo mínimo somente
//  com uma operação matemática, ou uma função de complexidade O(1).
//  Essa função deve relacionar o novo valor mínimo com o valor mínimo
//  anterior na hora de empilhar esse valor. Temos então:
//
//  topo = new_min - old_min
//

class NoPilhaMin {
 public:
    int dado;
    NoPilhaMin* prox;
};

class PilhaMin {
 public:
    int N;
    NoPilhaMin* inicio;
    int min;
    int aux;
    int old_min;
    void cria() {
        this->N = 0;
        this->min = 99999999;
        this->inicio = 0;
        this->aux = 0;
        this->old_min = 0;
    }
    int topo() {
        return this->inicio->dado;
    }
    void empilha(int novo) {
        NoPilhaMin* no = new NoPilhaMin{ .dado = novo, .prox = this->inicio };
        // Se a pilha estiver vazia, apenas atualizamos o minimo para esse valor
        if (this-> N == 0) {
            this->min = no->dado;
        } else {
            if (no->dado < this->min) {
                // o valor a ser empilhado é uma função que relaciona
                //  o novo valor mínimo com o antigo valor mínimo.
                this->aux = no->dado;
                no->dado = no->dado - this->min;
                this->min = this->aux;
            }
        }
        this->inicio = no;
        N++;
    }

    // Agora se o elemento desempilhado for menor do que o mínimo, entao sabemos
    //  q ele é o mínimo e podemos obter o novo mínimo com a função:
    //  min - old_min => old_min = min - topo
    int desempilha() {
        int valor = 0;
        if (this->topo() < this->min) {
            valor = this->min;
            this->old_min = this->min - this->topo();
            this->min = this->old_min;
        } else {
            valor = this->topo();
        }
        NoPilhaMin* no = this->inicio->prox;
        delete inicio;
        this->inicio = no;
        this->N--;
        return valor;
    }

    int obterMinimo() {
        return this->min;
    }
};
