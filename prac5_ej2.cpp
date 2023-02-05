#include <iostream>
#include "TAD Conocidos/cola_dinamica.hpp"
#include "TAD Conocidos/pila_dinamica.hpp"

using namespace std;

void invertirSecuencia (ColaDin<int>& c, int a, int b);

int main ()
{
    ColaDin<int> c;
    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    c.push(5);
    c.push(6);
    c.push(7);

    invertirSecuencia(c,3,5);

    while(!c.vacia())
    {
        cout << c.frente() << endl;
        c.pop();
    }

    return 0;
}

void invertirSecuencia (ColaDin<int>& c, int a, int b)
{
    PilaDin<int> pAux;
    ColaDin<int> cAux;
    while (c.frente() != a)
    {
        cAux.push(c.frente());
        c.pop();
    }

    while (c.frente() != b)
    {
        pAux.push(c.frente());
        c.pop();
    }
    pAux.push(c.frente());
    c.pop();

    while (!pAux.vacia())
    {
        cAux.push(pAux.tope());
        pAux.pop();
    }

    while (!c.vacia())
    {
        cAux.push(c.frente());
        c.pop();
    }

    while (!cAux.vacia())
    {
        c.push(cAux.frente());
        cAux.pop();
    }
}