// Copyright (C) 2023 - Italo Portinho
#include <iostream>

// Primeiramente vamos definir o tipo do nó a ser usado no Deque:
class NoDeque {
 public:
    char dado;
    NoDeque* prox;
    // Inicialmente implementei sem o ponteiro ant
    // Porém seria necessário percorrer o deque todo para remover
    //  um elemento do fim do deque.
    // (para saber o elemento anterior a ele e poder atualizar o fim)
    NoDeque* ant;
};

//---------------------------------------------------------------
// 1a)
//---------------------------------------------------------------
class Deque {
 public:
    NoDeque* inicio;
    NoDeque* fim;
    int N;

    // Função para inicializar o deque
    // COMPLEXIDADE: O(1)
    void cria() {
        this->N = 0;
        this->inicio = 0;
        this->fim = 0;
    }

    // Função para retornar o elemento inicio do Deque
    // COMPLEXIDADE: O(1)
    char retornaInicio() {
        return this->inicio->dado;
    }

    // Função para retornar o elemento final do Deque
    // COMPLEXIDADE: O(1)
    char retornaFim() {
        return this->fim->dado;
    }

    // Função para inserir elemento no inicio do Deque
    // Cria-se um nó com o ponteiro prox apontando para o inicio do deque.
    //  e ponteiro ant para 0.
    // SE for o primeiro nó a ser inserido, o fim tb é o inicio.
    // SENAO for o primeiro no a ser inserido, o ant do antigo inicio tem que
    //  apontar para o novo no (sera promovido à inicio).
    // Após, atualizamos o inicio para ser esse nó recém criado
    // Atualizamos também o tamanho N do deque.
    // COMPLEXIDADE: O(1)
    void insereInicio(char novo) {
        NoDeque* no = new NoDeque {
                .dado = novo
                , .prox = this->inicio
                , .ant = 0
        };
        if (N == 0) {
            this->fim = no;
        } else {
            this->inicio->ant = no;
        }
        this->inicio = no;
        this->N++;
    }

    // Função para inserir elemento no fim do Deque
    // Cria-se um nó com o ponteiro prox apontando para 0.
    //  e ponteiro ant(anterior) apontando para o fim.
    // Após, atualizamos o ponteiro prox do ultimo elemento do deque(this->fim)
    //  para este nó recém criado.
    // Atualizamos o fim do deque para este nó recém criado.
    // Atualizamos também o tamanho N do deque.
    // COMPLEXIDADE: O(1)
    void insereFim(char novo) {
        NoDeque* no = new NoDeque { .dado = novo, .prox = 0, .ant = this->fim };
        if (N > 0) {
            this->fim->prox = no;
        } else {
            no->ant = 0;
            this->inicio = no;
        }
        this->fim = no;
        this->N++;
    }

    // Função para remover elemento do início do Deque
    // Guardamos o ponteiro prox para depois atualizar o inicio
    // Guardamos o dado do elemento inicio, para retornar ao final.
    // Deletamos o nó inicio antigo, e atualizamos o inicio para o nó guardado.
    // COMPLEXIDADE: O(1)
    char removeInicio() {
        NoDeque* no = this->inicio->prox;
        char dado = this->inicio->dado;
        delete this->inicio;
        this->N--;
        this->inicio = no;
        return dado;
    }

    // Função para remover elemento do fim do Deque.
    // Obs.:
    // Foi adotada um implementação duplamente encadeada para esta função
    //  ser executada em tempo constante O(1), do contrário seria necessário
    //  percorrer todo o deck (até N - 1) para poder remover o último elemento
    //  e atualizar o penultimo para último, com complexidade O(N) .
    // -----------------------------------------------------------------------
    // Guardamos o ponteiro anterior do final (para depois promove-lo ao fim).
    // Este nó terá seu prox para 0, pois vamos deletar para onde ele aponta.
    // Guardamos o dado do fim para poder retornar.
    // Deletemos o fim e atualizamos this->fim para o nó guardado.
    // Retornamos o dado.
    // COMPLEXIDADE: O(1)
    char removeFim() {
        NoDeque* no = this->fim->ant;
        no->prox = 0;
        char dado = this->fim->dado;
        delete this->fim;
        this->N--;
        this->fim = no;
        return dado;
    }


    // Função auxiliar para mostrar o deque para fins de teste.
    void mostraDeque() {
        NoDeque* head = this->inicio;
        printf("\n");
        for ( ; head; head = head->prox ) {
            printf("%c \n", head->dado);
        }
        printf("\n");
    }
};

//---------------------------------------------------------------
// 1b)
//---------------------------------------------------------------
//      Para implementar uma pilha usando o deque, inserimos e removemos
// no fim do deque.
//      COMPLEXIDADE:
// empilha: a mesma complexidade de insereFim, O(1).
// desempilha: a mesma complexidade de removeFim, O(1).
// topo: O(1).
// tamanho: O(1).
class PilhaDeque {
 public:
    Deque d;
    char topo() {
        return d.fim->dado;
    }
    void empilha(char novo) {
        d.insereFim(novo);
    }
    char desempilha() {
        return d.removeFim();
    }
    int tamanho() {
        return d.N;
    }
};

//---------------------------------------------------------------
// 1c)
//---------------------------------------------------------------
//      Para implementar um fila usando o deque, devemos inserir e remover
// em extremos opostos do deque. Aqui vou inserir no fim e remover do inicio.
//      COMPLEXIDADE:
// enfileira: a mesma complexidade de insereFim, O(1).
// desenfileira: a mesma complexidade de removeInicio, O(1).
// frente: O(1).
// fim: O(1)
// tamanho: O(1).
class FilaDeque {
 public:
    Deque d;
    char frente() {
        return d.inicio->dado;
    }
    char fim() {
        return d.fim->dado;
    }
    void enfileira(char novo) {
        d.insereFim(novo);
    }
    char desenfileira() {
        return d.removeInicio();
    }
    int tamanho() {
        return d.N;
    }
};
