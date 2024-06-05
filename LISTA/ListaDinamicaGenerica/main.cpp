#include <iostream>
#include "ListaDinamicaGenerica.h"

using namespace std;

// Função para exibir o menu
void exibirMenu() {
    cout << "=== MENU ===" << endl;
    cout << "1. Criar lista" << endl;
    cout << "2. Verificar se a lista esta vazia" << endl;
    cout << "4. Obter o numero de elementos na lista" << endl;
    cout << "5. Verificar se um elemento existe na lista" << endl;
    cout << "6. Verificar se uma posicao eh valida na lista" << endl;
    cout << "7. Obter um elemento da lista" << endl;
    cout << "8. Encontrar a posicao de um elemento na lista" << endl;
    cout << "9. Inserir elemento na lista" << endl;
    cout << "10. Retirar elemento da lista" << endl;
    cout << "11. Mostrar todos os elementos da lista" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    ListaSimplesmenteEncadeada<int> lista;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cria(lista);
                cout << "Lista criada." << endl;
                break;
            case 2:
                cout << (ehVazia(lista) ? "A lista esta vazia." : "A lista nao esta vazia.") << endl;
                break;
            case 4:
                cout << "Numero de elementos na lista: " << numeroDeElementos(lista) << endl;
                break;
            // Adicione os casos para as outras opções aqui...
            case 11:
                cout << "Elementos da lista: ";
                mostra(lista);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção invalida. Por favor, escolha uma opcao valida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
