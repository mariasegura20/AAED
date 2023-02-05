#include <iostream>
#include <string>
#include "TAD Conocidos/pila_dinamica.hpp"

using namespace std;

void avanzarCursor (PilaDin<char>& izq, PilaDin<char>& der);
void retrasarCursor (PilaDin<char>& izq, PilaDin<char>& der);
void finalLinea (PilaDin<char>& izq, PilaDin<char>& der);
void principioLinea (PilaDin<char>& izq, PilaDin<char>& der);
void borrarCaracterActual (PilaDin<char>& izq, PilaDin<char>& der);
void borrarCaracterAnterior (PilaDin<char>& izq, PilaDin<char>& der);
void insertar (PilaDin<char>& izq, PilaDin<char>& der, string& c);
void sobreescribir (PilaDin<char>& izq, PilaDin<char>& der, string& c);

int main ()
{
    PilaDin<char> izq, der;
    string c = "esto es un ejemplo";
    string d = " para probar las funciones";

    /*Para comprobar las funciones: llamo a distintas funciones y ejecuto el siguiente código */
    principioLinea(izq,der);
    while (!der.vacia())
    {
        cout << der.tope();
        der.pop();
    }

    return 0;
}

void avanzarCursor (PilaDin<char>& izq, PilaDin<char>& der)
{
    izq.push(der.tope());
    der.pop();
}

void retrasarCursor (PilaDin<char>& izq, PilaDin<char>& der)
{
    der.push(izq.tope());
    izq.pop();
}

void finalLinea (PilaDin<char>& izq, PilaDin<char>& der)
{
    while(!der.vacia())
        avanzarCursor(izq, der);
}

void principioLinea (PilaDin<char>& izq, PilaDin<char>& der)
{
    while(!izq.vacia())
        retrasarCursor(izq, der);
}

void borrarCaracterActual (PilaDin<char>& izq, PilaDin<char>& der)
{
    retrasarCursor(izq,der);
    der.pop();
}

void borrarCaracterAnterior (PilaDin<char>& izq, PilaDin<char>& der)
{
    retrasarCursor(izq,der);
    izq.pop();
}

void insertar (PilaDin<char>& izq, PilaDin<char>& der, string& c)
{
    int i = 0;

    while (i < c.length())
    {
        izq.push(c[i]);
        i++;
    }
}

void sobreescribir (PilaDin<char>& izq, PilaDin<char>& der, string& c)
{
    int i = 0;

    while (i < c.length())
    {
        izq.push(c[i]);
        if (!der.vacia())
            der.pop();
        i++;
    }
}