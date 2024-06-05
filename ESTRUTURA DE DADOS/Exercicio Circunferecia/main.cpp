#include <iostream>
#include <cmath>
using namespace std;
enum comparacao
{
    MENOR,
    IGUAL,
    MAIOR
};
struct Circunferencia
{
    float raio;
    int X, Y;
};
Circunferencia cria (float raio, int X, int Y)
{
    Circunferencia c;
    c.raio = raio;
    c.X = X;
    c.Y = Y;
    return c;
}
float recuperaRaio (Circunferencia c)
{
    return c.raio;
}
int recuperaX (Circunferencia c)
{
    return c.X;
}
int recuperaY (Circunferencia c)
{
    return c.Y;
}
float diametro (Circunferencia c)
{
    return 2 * c.raio;
}
float perimetro (Circunferencia c)
{
    return 2 * M_PI * c.raio;
}
void alteraRaio (Circunferencia& c, float novoRaio)
{
    c.raio = novoRaio;
}
void alteraX (Circunferencia& c, int novoX)
{
    c.X = novoX;
}
void alteraY (Circunferencia& c, int novoY)
{
    c.Y = novoY;
}
comparacao compara (Circunferencia c1, Circunferencia c2)
{
    if (c1.raio == c2.raio)
        return IGUAL;
    else if (c1.raio > c2.raio)
        return MAIOR;
    else
        return MENOR;
}
bool mesmaPosicao (Circunferencia c1, Circunferencia c2)
{
    return ((c1.X == c2.X) && (c1.Y == c2.Y));
}
int main()
{
    Circunferencia c[5];
    int i, j, X, Y;
    float raio;
    for (i = 0; i < 3; i++)
    {
        cout << "circunferencia " << i + 1 << endl;
        cout << "raio = ";
        cin >> raio;
        cout << "coordenada X = ";
        cin >> X;
        cout << "coordenada Y = ";
        cin >> Y;
        c[i] = cria (raio, X, Y);
    }
    c[3] = cria (recuperaRaio(c[0]) + 5, recuperaX(c[0]), recuperaY(c[0]));
    cout << "circunferencia 5" << endl;
    cout << "raio = ";
    cin >> raio;
    cout << "coordenada Y = ";
    cin >> Y;
    c[4] = cria (raio, recuperaY(c[2]) - 10, Y);
    alteraRaio (c[0], recuperaRaio(c[2]) + 3);
    for (i = 0; i < 5; i++)
        cout << "perimetro da circunferencia = " << i + 1 << " = " << perimetro (c[i]) <<
             endl;
    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++)
            if (mesmaPosicao (c[i], c[j]))
                cout << "as circunferencias " << i + 1 << " e " << j + 1 << " tem a mesma posicao" << endl;

    return 0;
}
