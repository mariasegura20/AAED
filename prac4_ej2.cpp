#include <iostream>
#include <string>
#include "TAD Conocidos/pila_dinamica.hpp"

using namespace std;

bool cadenaInversa (string& cadena);
bool secuenciasCadenasInversa (string& cadena);

int main () {
    string c = "abc&cba#dfg&gfd";

    if (secuenciasCadenasInversa(c))
        printf("Inversa");
    else
        printf("No inversa");

    return 0;
}

// Postcondición: devuelve true si la cadena recibida es de la forma X&Y donde X es una cadena de caracteres e Y es la cadena inversa, o false en caso contrario
bool cadenaInversa (string& cadena)
{
    PilaDin<char> p;
    bool ret = true;
    int i = 0;

    while (i < cadena.length() && cadena[i] != '&')
    {
        p.push(cadena[i]);
        i++;
    }

    i++;

    while (ret && !p.vacia())
    {
        if (p.tope() != cadena[i]) {
            ret = false;
        }

        p.pop();
        i++;
    }

    if (cadena[i] != '\0')
        ret = false;

    return ret;
}

// Postcondición: devuelve true si la cadena es de la forma A#B#C... donde A,B,C... son de la forma X&Y (siendo Y la cadena inversa de X)
bool secuenciasCadenasInversa (string& cadena)
{
    bool ret = true;
    int i = 0;
    string c;

    while (ret && i < cadena.length())
    {    
        while (cadena[i] != '#' && i < cadena.length())
        {
            c += cadena[i];
            i++;
        }

        ret = cadenaInversa(c);
        c.clear();
        i++;
    }

    return ret;    
}