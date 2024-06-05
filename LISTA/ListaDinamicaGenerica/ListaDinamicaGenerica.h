#ifndef LISTADINAMICAGENERICA_H_INCLUDED
#define LISTADINAMICAGENERICA_H_INCLUDED
#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T>* prox;
};

template<typename T>
struct ListaSimplesmenteEncadeada{
    int cardinalidade;
    Nodo<T>* inicio;

};

template<typename T>
void cria(ListaSimplesmenteEncadeada<T> &lista){
    lista.cardinalidade = 0;
    lista.inicio=NULL;

}

template<typename T>
void destroi(ListaSimplesmenteEncadeada<T> &lista){
    Nodo<T>*p;
    while(lista.inicio !=NULL){
        p=lista.inicio;
        lista.inicio = lista.inicio->prox;
        delete p;
    }
    lista.cardinalidade = 0;
}

template<typename T>
bool ehVazia(ListaSimplesmenteEncadeada<T> lista){
 return lista.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(ListaSimplesmenteEncadeada<T> lista){
 return lista.cardinalidade;
}

template<typename T>
bool existeElemento(ListaSimplesmenteEncadeada<T> lista, T elemento){

    Nodo<T>*p = lista.inicio;
    while(p!=NULL){
        if(p->elemento == elemento)
            return true;
        p=p->prox;
    }
    return false;

}

template<typename T>
bool existePosicao (ListaSimplesmenteEncadeada<T> lista, int posicao){
 return ((posicao >= 1) && (posicao <= lista.cardinalidade));
}

template<typename T>
T umElemento(ListaSimplesmenteEncadeada<T> lista, int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    int contador = 1;
    Nodo<T>* p = lista.inicio;
    while (contador < posicao)
    {
        contador++;
        p = p->proximo;
    }
    return p->elemento;
}

template<typename T>
int posicao(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    if (!existeElemento(lista, elemento))
    {
        throw "ELEMENTO NAO ESTA NA LISTA";
    }
    int contador = 1;
    Nodo<T>* p = lista.inicio;
    while (p->elemento != elemento)
    {
        contador++;
        p = p->proximo;
    }
    return contador;
}

template<typename T>
void insere(ListaSimplesmenteEncadeada<T> &lista, T elemento, int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade + 1)
    {
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = NULL;
    if (lista.inicio == NULL)
        lista.inicio = q;
    else
    {
        if (posicao == 1)
        {
            q->proximo = lista.inicio;
            lista.inicio = q;
        }
        else
        {
            Nodo<T>* p = lista.inicio;
            int contador = 1;
            while (contador != posicao - 1)
            {
                p = p->proximo;
                contador++;
            }
            q->proximo = p->proximo;
            p->proximo = q;
        }
    }
    lista.cardinalidade++;
}

template<typename T>
void retira (ListaSimplesmenteEncadeada<T> &lista, int posicao)
{
    if(lista.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = lista.inicio;
    if (posicao == 1)
        lista.inicio = lista.inicio->proximo;
    else
    {
        Nodo<T>* p = lista.inicio;
        int contador = 1;
        while (contador != posicao - 1)
        {
            p = p->proximo;
            contador++;
        }
        q = p->proximo;
        p->proximo = q->proximo;
    }
    delete q;
    lista.cardinalidade--;
}

template<typename T>
void mostra(ListaSimplesmenteEncadeada<T> lista)
{
    Nodo<T>* p = lista.inicio;
    while(p != NULL)
        cout << p->elemento << " ";
    cout << endl;
}




#endif // LISTADINAMICAGENERICA_H_INCLUDED
