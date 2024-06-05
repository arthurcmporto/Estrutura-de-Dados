#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED
#include <iostream>

using namespace std;

template<typename T>
struct Nodo
{
    T elemento;
    Nodo* subArvoreEsquerda;
    Nodo* subArvoreDireita;
};

template<typename T>
struct ArvoreBinariaBusca
{
    int cardinalidade;
    Nodo<T>* raiz;
};

template<typename T>
void cria(ArvoreBinariaBusca<T> &arvore){
    arvore.cardinalidade = 0;
    arvore.raiz = NULL;
}

template<typename T>
void destroiArvore(Nodo<T>* &raiz)
{
    if(raiz!=NULL)
    {
        destroiArvore(raiz->subArvoreEsquerda);
        destroiArvore(raiz->subArvoreDireita);
        delete(raiz);
    }
}

template<typename T>
void destroi(ArvoreBinariaBusca<T> &arvore)
{
    destroiArvore(arvore.raiz);
    arvore.cardinalidade=0;
}

template<typename T>
bool ehvazia(ArvoreBinariaBusca<T> arvore)
{
    return arvore.cardinalidade==0;
}

template<typename T>
int numeroElem(ArvoreBinariaBusca<T> arvore)
{
    return arvore.cardinalidade;
}

template<typename T>
bool temnaArvore(ArvoreBinariaBusca<T> arvore, T elem)
{
    Nodo<T>* p = arvore.raiz;
    while(p!= NULL){
        if(elem == p->elemento)
            return true;

         else {
            if(elem < p->elemento)
                p = p->subArvoreEsquerda;
            else
                p=p->subArvoreDireita;
            }
        return false;
    }
}


template<typename T>
void insereNaArvore(Nodo<T>* &raiz, T elem)
{
   if(raiz==NULL){
    raiz = new Nodo<T>;
    raiz->elemento = elem;
    raiz->subArvoreEsquerda = NULL;
    raiz->subArvoreDireita = NULL;
   } else if(elem<raiz->elemento)
        insereNaArvore(raiz->subArvoreEsquerda, elem);
    else
        insereNaArvore(raiz->subArvoreDireita, elem);
}

template<typename T>
void insere(ArvoreBinariaBusca<T> &arvore, T elem)
{
    insereNaArvore(arvore.raiz,elem);
    arvore.cardinalidade++;
}


template<typename T>
void mostraArvore(Nodo<T>*raiz){
    if(raiz != NULL){
        mostraArvore(raiz->subArvoreEsquerda);
        cout<<raiz->elemento<<"--";
        mostraArvore(raiz->subArvoreDireita);
    }
}

template<typename T>
void mostra(ArvoreBinariaBusca<T> arvore){
    mostraArvore(arvore.raiz);
    cout<<endl;
}

template<typename T>
int somaElementos(Nodo<T>* nodo){

if(nodo == NULL)
    return 0;

    return nodo->elemento + somaElementos(nodo->subArvoreEsquerda) + somaElementos(nodo->subArvoreDireita);
}

template<typename T>
int soma(ArvoreBinariaBusca<T> arvore) {
    return somaElementos(arvore.raiz);
}

template<typename T>
void multiplicaArvore(Nodo<T>* nodo, int num){
    if(nodo == NULL){
        throw "Arvore vazia";
    } else {
        nodo->elemento *= num;
        if(nodo->subArvoreEsquerda != NULL){
          multiplicaArvore(nodo->subArvoreEsquerda, num);
        }
        if(nodo->subArvoreDireita != NULL){
            multiplicaArvore(nodo->subArvoreDireita, num);
        }
    }
}

template<typename T>
void multiplica(ArvoreBinariaBusca<T> &arvore, int num){
    if(arvore.raiz == NULL){
        throw "arvore vazia";
    }
    multiplicaArvore(arvore.raiz,num);
}



template<typename T>
int multiplicacaoDosImpares(Nodo<T>*nodo){
    if(nodo == NULL)
        return 1;

    if(nodo->elemento % 2 != 0){
        return nodo->elemento * multiplicacaoDosImpares(nodo->subArvoreEsquerda) * multiplicacaoDosImpares(nodo->subArvoreDireita);
    } else {
        return multiplicacaoDosImpares(nodo->subArvoreEsquerda) * multiplicacaoDosImpares(nodo->subArvoreDireita);
    }
}

template<typename T>
int multImpar(ArvoreBinariaBusca<T> arvore){
    if(arvore.raiz == NULL)
        return 0;

    return multiplicacaoDosImpares(arvore.raiz);
}


#endif // EX1_H_INCLUDED
