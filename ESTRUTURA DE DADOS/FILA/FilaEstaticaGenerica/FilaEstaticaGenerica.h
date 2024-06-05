#ifndef FILAESTATICAGENERICA_H_INCLUDED
#define FILAESTATICAGENERICA_H_INCLUDED

using namespace std;

 template<typename T, int MAX>
 struct FilaEstaticaGenerica{
    int cardinalidade;
    T elementos [MAX];
};

 template<typename T, int MAX>
 void cria(FilaEstaticaGenerica<T, MAX> &fila){
     fila.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia (FilaEstaticaGenerica<T, MAX> fila){
     return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco (FilaEstaticaGenerica<T, MAX> fila){
     return fila.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroDeElementos (FilaEstaticaGenerica<T, MAX> fila){
    return fila.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento (FilaEstaticaGenerica<T, MAX> fila, T elemento){
     for (int i = 0; i < fila.cardinalidade; i++)
        if (fila.elementos[i] == elemento)
            return true;
     return false;
}

template<typename T, int MAX>
int existePosicao (FilaEstaticaGenerica<T, MAX> fila, int posicao){
    return (posicao >= 1) && (posicao <= fila.cardinalidade);
}

template<typename T, int MAX>
T umElemento (FilaEstaticaGenerica<T, MAX> fila, int posicao){
    if(posicao < 1 || posicao > fila.cardinalidade){
        throw "POSICAO INVALIDA";
    }
    return fila.elementos[posicao - 1];
}

template<typename T, int MAX>
int posicao (FilaEstaticaGenerica<T, MAX> fila, T elemento){
    if (!existeElemento(fila, elemento)){
        throw "ELEMENTO NAO ESTA NA LISTA";
    }
     for (int i = 0; i < fila.cardinalidade; i++)
        if (fila.elementos[i] == elemento)
            return i + 1;
}

template<typename T, int MAX>
void insere (FilaEstaticaGenerica<T, MAX> &fila, T elemento){
    if(fila.cardinalidade >= MAX){
        throw "OVERFLOW";
    }
    fila.cardinalidade += 1;
    fila.elementos[fila.cardinalidade-1] = elemento;
}

template<typename T, int MAX>
void retira (FilaEstaticaGenerica<T, MAX> &fila){
    if(fila.cardinalidade == 0){
        throw "Fila Vazia";
    }

    for (int i=0;i<fila.cardinalidade-1;i++)
        fila.elementos[i] = fila.elementos[i+1];

    fila.cardinalidade--;
}

template<typename T, int MAX>
void mostra (FilaEstaticaGenerica<T, MAX> fila){
    for (int i = 0; i < fila.cardinalidade; i++)
        cout << fila.elementos[i] << " ";
        cout << endl;
}



#endif // FILAESTATICAGENERICA_H_INCLUDED
