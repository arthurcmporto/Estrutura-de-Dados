#ifndef LISTAESTATICAGENERICA_H_INCLUDED
#define LISTAESTATICAGENERICA_H_INCLUDED

using namespace std;

 template<typename T, int MAX>
 struct ListaEstaticaGenerica{
    int cardinalidade;
    T elementos [MAX];
};

 template<typename T, int MAX>
 void cria(ListaEstaticaGenerica<T, MAX> &lista){
     lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia (ListaEstaticaGenerica<T, MAX> lista){
     return lista.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco (ListaEstaticaGenerica<T, MAX> lista){
     return lista.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroDeElementos (ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento (ListaEstaticaGenerica<T, MAX> lista, T elemento){
     for (int i = 0; i < lista.cardinalidade; i++)
        if (lista.elementos[i] == elemento)
            return true;
     return false;
}

template<typename T, int MAX>
int existePosicao (ListaEstaticaGenerica<T, MAX> lista, int posicao){
    return (posicao >= 1) && (posicao <= lista.cardinalidade);
}

template<typename T, int MAX>
T umElemento (ListaEstaticaGenerica<T, MAX> lista, int posicao){
    if(posicao < 1 || posicao > lista.cardinalidade){
        throw "POSICAO INVALIDA";
    }
    return lista.elementos[posicao - 1];
}

template<typename T, int MAX>
int posicao (ListaEstaticaGenerica<T, MAX> lista, T elemento){
    if (!existeElemento(lista, elemento)){
        throw "ELEMENTO NAO ESTA NA LISTA";
    }
     for (int i = 0; i < lista.cardinalidade; i++)
        if (lista.elementos[i] == elemento)
            return i + 1;
}

template<typename T, int MAX>
void insere (ListaEstaticaGenerica<T, MAX> &lista, T elemento, int posicao){
    if(lista.cardinalidade >= MAX){
        throw "OVERFLOW";
    }
    if(posicao < 1 || posicao > lista.cardinalidade + 1){
        throw "POSICAO INVALIDA";
    }
    for (int i = lista.cardinalidade; i >= posicao; i--)
         lista.elementos[i] = lista.elementos[i - 1];
     lista.elementos[posicao - 1] = elemento;
     lista.cardinalidade++;
}

template<typename T, int MAX>
void retira (ListaEstaticaGenerica<T, MAX> &lista, int posicao){
    if(lista.cardinalidade == 0){
        throw "UNDERFLOW";
    }
     if(posicao < 1 || posicao > lista.cardinalidade){
        throw "POSICAO INVALIDA";
}
    for (int i = posicao; i < lista.cardinalidade; i++)
        lista.elementos[i - 1] = lista.elementos[i];
        lista.cardinalidade--;
}

template<typename T, int MAX>
void mostra (ListaEstaticaGenerica<T, MAX> lista){
    for (int i = 0; i < lista.cardinalidade; i++)
        cout << lista.elementos[i] << " ";
        cout << endl;
}







#endif // LISTAESTATICAGENERICA_H_INCLUDED
