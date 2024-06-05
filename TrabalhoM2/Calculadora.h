#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED
#include "Pilha.h"

#include "Pilha.h"

using namespace std;

template<typename T>
void zera(PilhaDinamicaGenerica<T>&pilha) {
    while(!ehVazia(pilha)) {
        desempilha(pilha);
    }
}

template<typename T>
void soma(PilhaDinamicaGenerica<T>&pilha, T elemento) {
    empilha(pilha, recuperaTopo(pilha) + elemento);
}

template<typename T>
void subtrai(PilhaDinamicaGenerica<T>&pilha, T elemento) {
    empilha(pilha, recuperaTopo(pilha) - elemento);
}

template<typename T>
void multiplica(PilhaDinamicaGenerica<T>&pilha, T elemento) {
    empilha(pilha, recuperaTopo(pilha) * elemento);
}

template<typename T>
void divide(PilhaDinamicaGenerica<T>&pilha, T elemento) {
    empilha(pilha, recuperaTopo(pilha) / elemento);
}

template<typename T>
void parcelas(PilhaDinamicaGenerica<T> pilha) {
    int contador = recuperaQuantia(pilha);

    while (contador >= 3) {
        cout << recuperaElemento(pilha, contador) << endl;
    }
}

#endif // CALCULADORA_H_INCLUDED
