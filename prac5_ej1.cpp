#include <iostream>
#include "TAD Conocidos/pila_dinamica.hpp"
#include "TAD Conocidos/cola_dinamica.hpp"

using namespace std;

bool isomorfica (PilaDin<char> p, ColaDin<char> c);

int main ()
{
    PilaDin<char> p;
    ColaDin<char> c;

    p.push('a');
    p.push('b');
    p.push('a');
    p.push('c');
    p.push('a');
    p.push('d');

    c.push('a');
    c.push('b');
    c.push('a');
    c.push('c');
    c.push('a');
    c.push('d');

    if (isomorfica(p,c))
        cout << "Son isomorficas" << endl;
    else
        cout << "No son isomorficas" << endl;

    return 0;
}

bool isomorfica (PilaDin<char> p, ColaDin<char> c)
{
    bool iso = true;
    int contP=0, contC=0;
    // Invierto la pila para que en el tope esté la primera posición
    PilaDin<char> p2;
    while (!p.vacia())
    {
        p2.push(p.tope());
        p.pop();
    }

    while (!p2.vacia() && !c.vacia() && iso)
    {
        // Para no comparar las posiciones impares
        p2.pop();
        c.pop();

        // Comparación de la pila y la cola en las posiciones pares
        if (p2.tope() != c.frente())
            iso = false;
        else {
            p2.pop();
            c.pop();
        }
    }

    // Compruebo si las pilas están vacías o con un único elemento
    if (!p2.vacia()) {
        while(!p2.vacia())
        {
            p2.pop();
            contP++;
        }
    } else {
        if (!c.vacia()) {
            c.pop();
            contC++;
        }
    }

    if (contP > 1 || contC > 1)
        iso = false;
    
    return iso;
}