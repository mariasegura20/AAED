#include <iostream>
#include "TAD Conocidos/pila_dinamica.hpp"

using namespace std;

void invertirSecuencia(PilaDin<int>& p, int a, int b);

int main () 
{
    PilaDin<int> p;
    p.push(0);
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);
    p.push(6);
    p.push(7);

    invertirSecuencia(p, 5, 2);
    
    while (!p.vacia())
    {
        cout << p.tope();
        p.pop();
    }
}

void invertirSecuencia(PilaDin<int>& p, int a, int b)
{
    PilaDin<int> pAux, pSecuencia;
    while (p.tope() != a)
    {
        pAux.push(p.tope());
        p.pop();
    }

    while (p.tope() != b)
    {
        pSecuencia.push(p.tope());
        p.pop();
    }

    pSecuencia.push(p.tope());
    p.pop();

    while (!pSecuencia.vacia())
    {
        pAux.push(pSecuencia.tope());
        pSecuencia.pop();
    }

    while (!pAux.vacia())
    {
        p.push(pAux.tope());
        pAux.pop();
    }
}