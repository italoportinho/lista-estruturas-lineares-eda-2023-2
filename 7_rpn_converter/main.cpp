// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include<stack>
#include<queue>
#include<cstdio>
#include <cstring>
#include <string>

//      Transformar uma expressão matemática para RPN, notação polonesa
//  reversa.
//      A expressão é dividida em tokens e armazenada em um array de char.
//      Os tokens são lidos um a um, ações são tomadas após classificar os
// tokens em três grupos.
//      - Se for um "(" ou operador "+,-,*,/", apenas colocamos na pilha.
//      - Se for um operando, armazenamos em uma pilha auxiliar. Se essa pilha
// já tiver um elemento, transferimos este para o buffer de saída e empilhamos
// o novo elemento. Essa pilha deve ter no máximo um elemento.
//     - Se for um ")", havendo alguém na pilha de operandos, transferimos para
// o buffer de saída. Em seguida desempilhamos operadores da pilha principal até
// encontrarmos o "(" correspondente.
// COMPLEXIDADE:
//      Cada token é lido , empilhado ou desempilhado somente uma vez. Portanto
// a complexidade é O(N), o que é condizendo com o fato da solução apresentada
// ser uma implementação do algoritmo Shunting yard, que tem complexidade
// linear.
int main() {
    char const ABRE_PARENTESES = '(';
    char const FECHA_PARENTESES = ')';
    char const OPERADOR_SOMA = '+';
    char const OPERADOR_SUBTRACAO = '-';
    char const OPERADOR_MULTIPLICACAO = '*';
    char const OPERADOR_DIVISAO = '/';
    char token;
    std::stack<char> pilha_1;  // parenteses e operadores.
    std::stack<char> pilha_2;  // operandos.
    std::queue<char> saida_rpn;  // saida na notação polonesa reversa (rpn)
    std::string expressao = "((A+B)*(C-(F/D)))";
    // "((A+B)*C)";

    char* char_array = new char[expressao.length() + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, expressao.c_str());
    for (int i = 0; i < expressao.length(); i++) {
        printf("%c", char_array[i]);
    }
    printf("\n", ' ');
    bool continuar = true;
    for (int i = 0; i < expressao.length(); i++) {
        token = char_array[i];
        switch (token) {
            case ABRE_PARENTESES:
            case OPERADOR_SOMA:
            case OPERADOR_SUBTRACAO:
            case OPERADOR_MULTIPLICACAO:
            case OPERADOR_DIVISAO:
                printf("E operador ou abre parenteses: %c \n", token);
                pilha_1.push(token);
                break;
            case FECHA_PARENTESES:
                // desempilhar até encontrar um parenteses esquerdo
                //  e colocar na fila
                printf("E fecha parenteses: %c \n", token);
                if (pilha_2.size() > 0) {
                    saida_rpn.push(pilha_2.top());
                    pilha_2.pop();
                }
                continuar = true;
                while (continuar) {
                    char topo = pilha_1.top();
                    if (!(topo == ABRE_PARENTESES)) {
                        saida_rpn.push(topo);
                    } else {
                        continuar = false;
                    }
                    pilha_1.pop();
                    printf("Saiu da pilha_1: %c \n", topo);
                }
                break;
            default:
                // É um operando
                printf("E operando: %c \n", token);
                if (pilha_2.size() > 0) {
                    saida_rpn.push(pilha_2.top());
                    pilha_2.pop();
                }
                pilha_2.push(token);
                break;
        }
    }

    while (saida_rpn.size() > 0) {
        printf("%c", saida_rpn.front());
        saida_rpn.pop();
    }
}
