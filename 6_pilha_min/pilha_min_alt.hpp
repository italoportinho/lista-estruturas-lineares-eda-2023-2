// Copyright (C) 2023 - Italo Portinho
//
// Obter o menor elemento de uma pilha em tempo constante;
//      Vamos manter  uma variável com o valor mínimo e na hora de
//  empilhar um elemento, fazemos uma comparação para atualizar
//  o mínimo, se for necessário. Essa estratégia funciona, porém
//  surge um problema quando desempilhamos o elemento mínimo. Como
//  encontrar o novo valor mínimo?
//      A estratégia é criar um tipo NoMin para o valor mínimo. Assim
// podemos ter um ponteiro para o mínimo anterior ao empilhar um novo
// mínimo. Ao desempilhar, basta atualizar o mínimo para esse valor.
//
// COMPLEXIDADE:
// topo: O(1)
// empilha: O(1)
// desempilha: O(1)
// obterMinimo: O(1)

class NoPilhaMin {
 public:
    int dado;
    NoPilhaMin* prox;
};

class NoMin {
 public:
    int dado;
    NoMin* previous_min;
};

class PilhaMin {
 public:
    int N;
    NoPilhaMin* inicio;
    NoMin* min;

    void cria() {
        this->N = 0;
        this->inicio = 0;
    }
    int topo() {
        return this->inicio->dado;
    }
    void empilha(int novo) {
        // Atualiza o minimo
        if (this->N == 0) {
            NoMin* new_min = new NoMin { .dado = novo, .previous_min = 0 };
            min = new_min;
        } else {
            if (novo < this->min->dado) {
                NoMin* new_min = new NoMin { .dado = novo, .previous_min = this->min };
                this->min = new_min;
            }
        }
        // Atualiza o topo
        NoPilhaMin* no = new NoPilhaMin { .dado = novo, .prox = this->inicio };
        this->inicio = no;
        this->N++;
    }

    //      Ao desempilhar temos que testar se o mínimo precisa ser atualizado.
    // Basta apontar para o mínimo anterior.
    int desempilha() {
        if (this->inicio->dado == this->min->dado) {
            NoMin* new_min = this->min->previous_min;
            delete this->min;
            this->min = new_min;
        }
        NoPilhaMin* no = this->inicio->prox;
        int valor = this->inicio->dado;
        delete inicio;
        this->inicio = no;
        this->N--;
        return valor;
    }

    int obterMinimo() {
        return this->min->dado;
    }
};
