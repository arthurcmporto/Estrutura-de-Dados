#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "TrabalhoM1.h"

using namespace std;

int main() {
    char continuar;

    do {
        string NomeArq, linha, palavra;
        int numlinhas = 0, erros = 0;
        Lista<char> letrasUsadas;
        Lista<char> letrasDigitadas;

        cria(letrasUsadas);
        cria(letrasDigitadas);

        cout << "Digite o nome do arquivo: ";
        getline(cin, NomeArq);

        ifstream arquivo(NomeArq);
        if (!arquivo.is_open()) {
            cout << "Arquivo não encontrado" << endl;
            return 1; // Sair se o arquivo não for encontrado
        }

        // Contar o número de linhas no arquivo
        while (getline(arquivo, linha)) {
            numlinhas++;
        }

        // Gerar número aleatório de linha para escolher uma palavra
        srand(time(NULL));
        int linhaAleatoria = rand() % numlinhas + 1;

        arquivo.clear();
        arquivo.seekg(0);

        // Obter a palavra da linha escolhida aleatoriamente
        for (int i = 1; i <= linhaAleatoria; ++i) {
            getline(arquivo, linha);
        }

        palavra = linha;
        arquivo.close();

        // Loop principal do jogo
        while (erros < 6) {
            system("cls");

            mostrarForca(erros);
            mostrarPalavraEscondida(palavra, letrasUsadas);

            if (verificarVitoria(palavra, letrasUsadas)) {
                cout << "Parabéns! Você acertou a palavra: " << palavra << endl;
                break;
            }

            cout << "Letras já digitadas: " << endl;
            MostrarLista(letrasDigitadas);

            cout << "Digite uma letra: ";
            char letra = lerLetra();

            if (!verificarLetra(letra, palavra, letrasUsadas, letrasDigitadas)) {
                erros++;
            }
        }

        if (erros >= 6) {
            system("cls");
            mostrarForca(erros);
            cout << "Você perdeu! A palavra era: " << palavra << endl;
        }

        destroi(letrasUsadas);
        destroi(letrasDigitadas);

        cout << "Deseja jogar de novo? (s/n)" << endl;
        cin >> continuar;
        cin.ignore(); // Limpar o caractere de nova linha do buffer de entrada

    } while (continuar != 'n');

    return 0;
}

