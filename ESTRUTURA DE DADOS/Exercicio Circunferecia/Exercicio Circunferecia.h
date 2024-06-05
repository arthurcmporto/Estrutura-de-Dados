#ifndef EXERCICIO_CIRCUNFERECIA_H_INCLUDED
#define EXERCICIO_CIRCUNFERECIA_H_INCLUDED

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


#endif // EXERCICIO_CIRCUNFERECIA_H_INCLUDED
