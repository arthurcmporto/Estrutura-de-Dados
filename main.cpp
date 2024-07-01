#include <iostream>
#include <algorithm>
#include <locale.h>
#include "TrabalhoOrdenacoes.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    FilaEstaticaGenerica<int, 100> f;
    FilaEstaticaGenerica<string, 100> f_str;

    cria(f);
    cria(f_str);

    int vet[] = {6, 30, 18, 15, 22, 7, 3, 19, 25, 12, 18, 9, 21, 22};

    int vet2[] = {50, 4, 21, 33, 11, 8, 7, 55, 19, 27};

    string frutas[] = {"uva", "laranja", "pera", "maracuja", "banana", "limao", "kiwi", "abacate",
                       "amora", "framboesa", "caqui", "acerola", "jabuticaba", "tangerina", "melao",
                       "ameixa", "melancia", "pitaia", "caju", "cacau", "pessego" };

    int tamanho = sizeof(vet) / sizeof(vet[0]);
    int tamanho2 = sizeof(vet2) / sizeof(vet2[0]);
    int tamanho_frutas = sizeof(frutas) / sizeof(frutas[0]);

    for (int i = 0; i < tamanho; i++)
        insere(f, vet[i]);

    cout << "Inteiros para ordenação: ";
    mostra(f);
    cout << endl;

    system("PAUSE");

    cout << "Odd Even:" << endl;
    oddEvenSort(f);
    cout << "Odd Even resultado: ";
    mostra(f);

    system("PAUSE");
    system("cls");

    cria(f);
    for (int i = 0; i < tamanho; i++)
        insere(f, vet[i]);

    cout << "Inteiros para ordenação: ";
    mostra(f);
    cout << endl;

    int passos = 0;
    cout << "Merge Sort:" << endl;
    mergeSort(f, 0, f.cardinalidade - 1, passos);
    cout << endl;
    cout << "Número de passos: " << passos << endl;
    cout << endl;
    cout << "Merge Sort resultado: ";
    mostra(f);

    system("PAUSE");
    system("cls");

    cria(f);
    for (int i = 0; i < tamanho; i++)
        insere(f, vet[i]);

    cout << "Inteiros para ordenação: ";
    mostra(f);
    cout << endl;

    cout << "Heap Sort:" << endl;
    heapSort(f);
    cout << "Heap Sort resultado: ";
    mostra(f);

    system("PAUSE");
    system("cls");

    cria(f);
    for (int i = 0; i < tamanho2; i++)
        insere(f, vet2[i]);

    cout << "Exemplo de vetor para busca de k-ézimo elemento: ";
    mostra(f);
    cout << endl;

    int k;
    do {
        cout << "Digite o k-ézimo elemento que deseja encontrar (1 a " << f.cardinalidade << "): ";
        cin >> k;

        if (cin.fail()) { // Se a entrada não for um número inteiro
            cin.clear(); // Limpa o estado do cin
            cin.ignore();
        }
    }
    while (k <= 0 || k > f.cardinalidade);

    int elementoK = findSort(f, k);
    cout << k << "º menor elemento é: " << elementoK << endl;

    system("PAUSE");
    system("cls");

    for (int i = 0; i < tamanho_frutas; i++)
        insere(f_str, frutas[i]);

    cout << "Strings para ordenação: ";
    mostra(f_str);
    cout << endl;

    int comparacoesSeq = 0;
    insertionSortSequencial(f_str, comparacoesSeq);
    cout << "Insertion Sort Sequencial: ";
    mostra(f_str);
    cout << endl;
    cout << "Número de passos: " << comparacoesSeq << endl;

    system("PAUSE");
    system("cls");

    cria(f_str);
    for (int i = 0; i < tamanho_frutas; i++)
        insere(f_str, frutas[i]);

    cout << "Strings para ordenação: ";
    mostra(f_str);
    cout << endl;

    int comparacoesBin = 0;
    insertionSortBinario(f_str, comparacoesBin);
    cout << "Insertion Sort com Busca Binária: ";
    mostra(f_str);
    cout << endl;
    cout << "Número de passos: " << comparacoesBin << endl;

    return 0;
}
