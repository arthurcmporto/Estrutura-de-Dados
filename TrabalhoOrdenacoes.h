#ifndef TRABALHOORDENACOES_H_INCLUDED
#define TRABALHOORDENACOES_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct FilaEstaticaGenerica
{
    int cardinalidade;
    T elementos [MAX];
};

template<typename T, int MAX>
void cria(FilaEstaticaGenerica<T, MAX> &fila)
{
    fila.cardinalidade = 0;
}

template<typename T, int MAX>
void insere(FilaEstaticaGenerica<T, MAX> &fila, T elemento)
{
    if (fila.cardinalidade >= MAX)
        throw "Overflow.";

    fila.cardinalidade += 1;
    fila.elementos[fila.cardinalidade - 1] = elemento;
}

template<typename T, int MAX>
void mostra(FilaEstaticaGenerica<T, MAX> fila)
{
    for (int i = 0; i < fila.cardinalidade; i++)
        cout << fila.elementos[i] << " ";
    cout << endl;
}

// 1

template<typename T, int MAX>
void oddEvenSort(FilaEstaticaGenerica<T, MAX> &fila)
{
    bool sorted = false;
    int passos = 0;

    while (!sorted)
    {
        sorted = true;

        for (int i = 1; i <= fila.cardinalidade - 2; i = i + 2)
            if (fila.elementos[i] > fila.elementos[i + 1])
            {
                swap(fila.elementos[i], fila.elementos[i + 1]);
                sorted = false;
                passos++;
            }

        cout << "Passo odd: ";
        mostra(fila);

        for (int i = 0; i <= fila.cardinalidade - 2; i = i + 2)
            if (fila.elementos[i] > fila.elementos[i + 1])
            {
                swap(fila.elementos[i], fila.elementos[i + 1]);
                sorted = false;
                passos++;
            }

        cout << "Passo even: ";
        mostra(fila);
    }

    cout << endl;
    cout << "Número de passos: " << passos << endl;
    cout << endl;
}

template<typename T, int MAX> // e - esquerda | m - meio | d - direita
void merge(FilaEstaticaGenerica<T, MAX> &fila, int e, int m, int d, int &passos)
{
    int n1 = m - e + 1;
    int n2 = d - m;

    T L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = fila.elementos[e + i];
    for (int j = 0; j < n2; j++)
        R[j] = fila.elementos[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = e;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            fila.elementos[k] = L[i];
            i++;
        }
        else
        {
            fila.elementos[k] = R[j];
            j++;
        }
        k++;
        passos++;
    }

    while (i < n1)
    {
        fila.elementos[k] = L[i];
        i++;
        k++;
        passos++;
    }

    while (j < n2)
    {
        fila.elementos[k] = R[j];
        j++;
        k++;
        passos++;
    }

    cout << "Merge passo (e = " << e << ", m = " << m << ", d = " << d << "): ";
    mostra(fila);
}

template<typename T, int MAX> // e - esquerda | d - direita
void mergeSort(FilaEstaticaGenerica<T, MAX> &fila, int e, int d, int &passos)
{
    if (e < d)
    {
        int m = e + (d - e) / 2;

        mergeSort(fila, e, m, passos);
        mergeSort(fila, m + 1, d, passos);

        merge(fila, e, m, d, passos);
    }
}

template<typename T, int MAX>
void heapify(FilaEstaticaGenerica<T, MAX> &fila, int n, int i, int &passos)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && fila.elementos[esq] > fila.elementos[maior])
        maior = esq;

    if (dir < n && fila.elementos[dir] > fila.elementos[maior])
        maior = dir;

    if (maior != i)
    {
        swap(fila.elementos[i], fila.elementos[maior]);
        heapify(fila, n, maior, passos);
        passos++;
    }
}

template<typename T, int MAX>
void heapSort(FilaEstaticaGenerica<T, MAX> &fila)
{
    int passos = 0;
    for (int i = fila.cardinalidade / 2 - 1; i >= 0; i--)
        heapify(fila, fila.cardinalidade, i, passos);

    for (int i = fila.cardinalidade - 1; i > 0; i--)
    {
        swap(fila.elementos[0], fila.elementos[i]);
        cout << "Heap Sort passo: ";
        mostra(fila);
        heapify(fila, i, 0, passos);
        passos++;
    }

    cout << endl;
    cout << "Número de passos: " << passos << endl;
    cout << endl;
}

// 2

template<typename T, int MAX>
int partition(FilaEstaticaGenerica<T, MAX> &fila, int low, int high)
{
    T pivot = fila.elementos[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (fila.elementos[j] <= pivot)
        {
            i++;
            swap(fila.elementos[i], fila.elementos[j]);
        }

    swap(fila.elementos[i + 1], fila.elementos[high]);
    return i + 1;
}

template<typename T, int MAX>
T quickSelect(FilaEstaticaGenerica<T, MAX> &fila, int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(fila, low, high);

        // O pivô está na posição correta
        if (pi == k)
            return fila.elementos[pi];

        // Se o pivô está à esquerda do k-ésimo menor
        if (pi > k)
            return quickSelect(fila, low, pi - 1, k);

        // Se o pivô está à direita do k-ésimo menor
        return quickSelect(fila, pi + 1, high, k);
    }

    return -1; // Essa linha nunca deve ser alcançada se k for válido
}

template<typename T, int MAX>
T findSort(FilaEstaticaGenerica<T, MAX> &fila, int k)
{
    if (k < 1 || k > fila.cardinalidade)
        throw "Posição inválida.";

    return quickSelect(fila, 0, fila.cardinalidade - 1, k - 1); // k-1 porque os índices começam em 0
}

// 3

template<typename T, int MAX>
void insertionSortSequencial(FilaEstaticaGenerica<T, MAX> &fila, int &comparacoes)
{
    for (int i = 1; i < fila.cardinalidade; i++)
    {
        T key = fila.elementos[i];
        int j = i - 1;

        while (j >= 0 && fila.elementos[j] > key)
        {
            fila.elementos[j + 1] = fila.elementos[j];
            j--;
            comparacoes++; // Conta a comparação ao mover elementos
        }

        fila.elementos[j + 1] = key;
        comparacoes++; // Conta a comparação ao posicionar key
    }
}

template<typename T, int MAX>
int buscaBinaria(FilaEstaticaGenerica<T, MAX> &fila, T key, int low, int high, int &comparacoes)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        comparacoes++;
        if (fila.elementos[mid] == key)
            return mid + 1;
        else if (fila.elementos[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

template<typename T, int MAX>
void insertionSortBinario(FilaEstaticaGenerica<T, MAX> &fila, int &comparacoes)
{
    for (int i = 1; i < fila.cardinalidade; i++)
    {
        T key = fila.elementos[i];
        int loc = buscaBinaria(fila, key, 0, i - 1, comparacoes);

        for (int j = i - 1; j >= loc; j--)
        {
            fila.elementos[j + 1] = fila.elementos[j];
            comparacoes++; // Conta a comparação ao mover elementos
        }

        fila.elementos[loc] = key;
        comparacoes++; // Conta a comparação ao posicionar key
    }
}

#endif // TRABALHOORDENACOES_H_INCLUDED
