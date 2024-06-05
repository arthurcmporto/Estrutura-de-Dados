#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Pilha.h"
#include "Calculadora.h"
using namespace std;

void validaComando(string&);
void separaString(string, string&, float&);

int main() {
    string msg, aux;
    bool validaInicio = false;
    float valor;
    PilhaDinamicaGenerica<float> pilha;

    do {
        cout << "Qual operacao deseja realizar?" << endl;
        cout << "INICIO" << endl;
        cout << "ZERA" << endl;
        cout << "SOMA (valor)" << endl;
        cout << "SUBTRAI (valor)" << endl;
        cout << "MULTIPLICA (valor)" << endl;
        cout << "DIVIDE (valor)" << endl;
        cout << "PARCELAS" << endl;
        cout << "IGUAL" << endl;
        cout << "FIM" << endl;

        while (validaInicio != true) {
            validaComando(msg);

            if (msg == "INICIO") {
                validaInicio = true;
                cria(pilha);
                cout << "Calculadora Iniciada." << endl;
            }
            else
                cout << "Comece com INICIO" << endl;
        }

        validaComando(msg);
        separaString(msg, aux, valor);

        if (aux == "ZERA")
            zera(pilha);
        else if (aux == "SOMA")
            soma(pilha, valor);
        else if (aux == "SUBTRAI")
            subtrai(pilha, valor);
        else if (aux == "MULTIPLICA")
            multiplica(pilha, valor);
        else if (aux == "DIVIDE")
            divide(pilha, valor);
        else if (aux == "PARCELAS")
            parcelas(pilha);
        else if (aux == "IGUAL")
            recuperaTopo(pilha);
        else
            destroi(pilha);
    } while (msg != "FIM");

    return 0;
}

void validaComando(string&msg) {
    bool validado = false;
    float valor;
    string aux;

    do {
        getline(cin,msg);

        if (msg == "INICIO" || msg == "ZERA" || msg == "PARCELAS" || msg == "IGUAL" || msg == "FIM") {
            validado = true;
            aux = msg;
        }
        else {
            try {
                separaString(msg, aux, valor);
            }
            catch (const char* mensagem) {
                if (strcmp(mensagem, "MENSAGEM VAZIA") == 0) {
                    cerr << "ERRO: Comando digitado de forma indevida." << endl;
                }
                else if(strcmp(mensagem, "FLOAT INVALIDO") == 0) {
                    cerr << "ERRO: Valor digitado de forma indevida." << endl;
                }
                else {
                    cerr << "ERRO: Algum erro inesperado encontrado." << endl;
                }
            }

            if (aux == "SOMA" || aux == "SUBTRAI" || aux == "MULTIPLICA" || aux == "DIVIDE") {
                validado = true;
            }
        }
    } while (!validado);
}

void separaString(string msg, string&comando, float&valor) {
    int i = 0, j = 0;
    string aux;
    bool ponto = false; //Enqaunto (ponto == false), 'ponto' não foi encontrado em 'msg'.

    if (msg == "")
        throw "MENSAGEM VAZIA";
    else {
        while (i < msg.size() && msg[i] != ' ') {
            comando[i] = msg[i];
            i += 1;
        }

        if ((comando == "SOMA" || comando == "SUBTRAI" || comando == "MULTIPLICA" || comando == "DIVIDE")) {
            if (i == msg.size())
                throw "FLOAT INVALIDO";
            for (i = comando.size(); i < msg.size(); i++) {
                if (!isdigit(msg[i]) || msg[i] != '.' || (msg[i] == '.' && ponto))
                    throw "FLOAT INVALIDO";
                else if (msg[i] == '.')
                    ponto = true;
            }

            aux[j] = msg[i];
            j += 1;

            valor = atof(aux.c_str());
        }
    }
}

