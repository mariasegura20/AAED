#include <iostream>
#include <string>
#include "TAD Conocidos/pila_dinamica.hpp"

using namespace std;

bool cadenaInversa (string& cadena);

int main () {
    string c = "abc&cba";

    if (cadenaInversa(c))
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