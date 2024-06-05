#ifndef TRABALHOM1_H_INCLUDED
#define TRABALHOM1_H_INCLUDED

using namespace std;

template <typename T>
struct Nodo{
    T elem;
    Nodo<T>* prox;
    Nodo<T>* ant;
};

template<typename T>
struct Lista{
int n;
Nodo<T>*inicio;
Nodo<T>*fim;

};

template<typename T>
void cria(Lista<T> &l){

    l.n = 0;
    l.inicio = NULL;
    l.fim = NULL;

}

template<typename T>
void destroi(Lista<T> &l) {
    Nodo<T>* p = l.inicio;
    Nodo<T>* temp;
    while (p != NULL) {
        temp = p;
        p = p->prox;
        delete temp;
    }
    l.n = 0;
    l.inicio = NULL;
    l.fim = NULL;
}

template<typename T>
bool ehvazia(Lista<T> l){

    return l.n == 0;
}

template<typename T>
int tamanho(Lista<T> l){

    return l.n;
}

template<typename T>
bool ExisteElem(Lista<T> &l, T elemento){
    Nodo<T>* p = l.inicio;
    if(p==NULL)
        return false;

    do{
        if(p->elem == elemento)
            return true;
        p = p->prox;
    } while(p!=l.inicio);

        return false;

}

template<typename T>
void InsereElem(Lista<T> &l, T elemento, int posicao)
{
    if(posicao < 1 || posicao > l.n + 1)
    {
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = new Nodo<T>;
    q->elem = elemento;
    q->prox = NULL;
    q->ant = NULL;
    if (l.inicio == NULL) {
        l.inicio = q;
        l.fim = q;
        q->prox = q;
        q->ant = q;
    } else {
        if (posicao == 1) {
            q->prox = l.inicio;
            q->ant = l.fim;
            l.inicio->ant = q;
            l.inicio = q;
            l.fim->prox = q;
        } else {
            Nodo<T>* p = l.inicio;
            int contador = 1;
            while (contador != posicao - 1)
            {
                p = p->prox;
                contador++;
            }
            q->prox = p->prox;
            q->ant = p;
            if (p->prox != NULL) {
                p->prox->ant = q;
            } else {
                l.fim = q;
            }
            p->prox = q;
        }
    }
    l.n++;
}

template<typename T>
void RetiraElem(Lista<T> &l, T elemento){

    Nodo<T>* p = l.inicio;
    Nodo<T>* anterior = NULL;

        if(p==NULL)
            throw "Lista Vazia";

        do {
        if (p->elem == elemento) {
            if (anterior == NULL) {
                l.inicio = p->prox;
                l.fim->prox = p->prox;
                p->prox->ant = l.fim;
                delete p;
                cout << "Elemento apagado";
                l.n--;
                return;
            } else {
                anterior->prox = p->prox;
                p->prox->ant = anterior;
                if (p == l.fim)
                    l.fim = anterior;
                delete p;
                cout << "Elemento apagado";
                l.n--;
                return;
            }
        }
        anterior = p;
        p = p->prox;
    } while(p != l.inicio);

    throw "Elemento não encontrado na lista";
}

template<typename T>
void MostrarLista(Lista<T> l) {
    Nodo<T>* p = l.inicio;

    if (p == NULL) {
        return;
    }

    do {
        cout << p->elem << " ";
        p = p->prox;
    } while (p != l.inicio);
    cout << endl;
}

#endif // LISTADUPLAMENTEENCADEADACIRCULAR_H_INCLUDED

void mostrarForca(int erros) {
    cout << " ______" << endl;
    cout << "|     |" << endl;
    cout << "|     " << (erros >= 1 ? "O" : "") << endl;
    cout << "|    " << (erros >= 3 ? "/" : "") << (erros >= 2 ? "|" : "") << (erros >= 4 ? "\\" : "") << endl;
    cout << "|    " << (erros >= 5 ? "/" : "") << " " << (erros >= 6 ? "\\" : "") << endl;
    cout << "|__" << endl;
}

void mostrarPalavraEscondida(string palavra, Lista<char> letrasUsadas) {
    for (char c : palavra) {
        if (ExisteElem(letrasUsadas, c)) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool verificarLetra(char letra, string palavra, Lista<char> &letrasUsadas, Lista<char> &letrasDigitadas) {
    if (ExisteElem(letrasDigitadas, letra)) {
        cout << "Voce ja tentou essa letra" << endl;
        mostrarPalavraEscondida(palavra, letrasUsadas);
        return true;
    }

    InsereElem(letrasDigitadas, letra, tamanho(letrasDigitadas) + 1);

    bool acerto = false;
    for (char c : palavra) {
        if (c == letra) {
            InsereElem(letrasUsadas, letra, tamanho(letrasUsadas) + 1);
            acerto = true;
        }
    }

    if (!acerto) {
        cout << "Letra incorreta!" << endl;
        return false; // Letra incorreta, não acerta
    }

    return true; // Letra correta, acerta
}

bool verificarVitoria(string palavra, Lista<char> letrasUsadas) {
    for (char c : palavra) {
        if (!ExisteElem(letrasUsadas, c)) {
            return false;
        }
    }
    return true;
}

char lerLetra() {
    string letra;
    bool validado;

    do {
        validado = true;

        getline(cin, letra);

        if (letra == "" || letra.size() > 1)
            validado = false;
        else if (!isalpha(letra[0]))
            validado = false;

        if (!validado)
            cout << "Letra invalida, tente novamente.\n";
    } while(!validado);

    return letra[0];
}


