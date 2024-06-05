#include <iostream>
#include "Ex1.h"

using namespace std;

int main()
{
    ArvoreBinariaBusca<int> A1;
    int n;

    cria(A1);

    insere(A1,3);
    insere(A1,12);
    insere(A1,3);
    insere(A1,4);
    insere(A1,9);

    mostra(A1);

    int s = soma(A1);
    cout << "soma dos elementos da arvore: "<< s <<endl;

    int m = multImpar(A1);
    cout <<"multiplicacao dos elemensot impares: " << m<<endl;


    cout << "Digite um numero para multiplicar a arvore: "; cin>>n;
    multiplica(A1,n);
    mostra(A1);



    destroi(A1);

    return 0;
}
