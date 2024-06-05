#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

using namespace std;

template <typename T>
struct Nodo {
    T elemento;
    Nodo<T>*anterior;
};

template<typename T>
struct PilhaDinamicaGenerica {
    int topo;
    Nodo<T>*fim;
};

template<typename T>
void cria(PilhaDinamicaGenerica<T>&pilha) {
    pilha.topo = 0;
    pilha.fim = NULL;
}

template<typename T>
void destroi(PilhaDinamicaGenerica<T>&pilha) {
    Nodo<T>*p;

    while (pilha.fim != NULL) {
        p = pilha.fim;
        pilha.fim = pilha.fim->anterior;
        delete p;
    }
}

template<typename T>
bool ehVazia(PilhaDinamicaGenerica<T> pilha) {
    return pilha.topo == 0;
}

template<typename T>
bool existePosicao(PilhaDinamicaGenerica<T> pilha, int posicao) {
    return (posicao >= 1) && (posicao <= pilha.topo);
}

template<typename T>
bool existeElemento(PilhaDinamicaGenerica<T> pilha, T elemento) {
    while (pilha.fim != NULL) {
        if (pilha.fim->elemento == elemento)
            return true;

        pilha.fim = pilha.fim->anterior;
    }

    return false;
}

template<typename T>
int recuperaQuantia(PilhaDinamicaGenerica<T> pilha) {
    return pilha.topo;
}

template<typename T>
T recuperaElemento(PilhaDinamicaGenerica<T> pilha, int posicao) {
    int i = 1;

    if (ehVazia(pilha))
        throw "PILHA VAZIA";
    else if (posicao < 1 || posicao > pilha.topo + 1)
        throw "POSICAO INVALIDA";

    while (i >= 1) {
        if (i == posicao)
            return pilha.fim->elemento;

        i += 1;
        pilha.fim = pilha.fim->anterior;
    }
}

template<typename T>
void empilha(PilhaDinamicaGenerica<T>&pilha, T elemento) {
    Nodo<T>*p = new Nodo<T>;
    p->elemento = elemento;
    p->anterior = pilha.fim;

    pilha.fim = p;
    pilha.topo += 1;
}

template<typename T>
void desempilha(PilhaDinamicaGenerica<T>&pilha) {
    if (ehVazia(pilha))
        throw "LISTA VAZIA";

    Nodo<T>*p = pilha.fim;
    pilha.fim = pilha.fim->anterior;

    delete p;
    pilha.topo -= 1;
}

template<typename T>
T recuperaTopo(PilhaDinamicaGenerica<T> pilha) {
    return pilha.fim->elemento;
}

template<typename T>
void recuperaOcorrencias(PilhaDinamicaGenerica<int>&ocorrencias, PilhaDinamicaGenerica<T> pilha, T elemento) {
    int posicao = pilha.topo;

    while (pilha.fim != NULL) {
        if (pilha.fim->elemento == elemento)
            empilha(ocorrencias, posicao);

        pilha.fim = pilha.fim->anterior;
        posicao -= 1;
    }
}

template<typename T>
void mostra(PilhaDinamicaGenerica<T> pilha) {
    if (ehVazia(pilha))
        throw "LISTA VAZIA";

    while (pilha.fim != NULL) {
        cout << pilha.fim->elemento << endl;

        pilha.fim = pilha.fim->anterior;
    }
}

#endif // PILHA_H_INCLUDED
