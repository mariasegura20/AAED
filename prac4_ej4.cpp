#include <iostream>
#include <fstream>
#include <string>
#include "TAD Conocidos/pila_dinamica.hpp"

using namespace std;

void suma (string& archivo);
fstream& operator >> (fstream& fe, PilaDin<int>& P);
fstream& operator << (fstream& fs, PilaDin<int> P);

string nombre = "archivo.txt";

int main ()
{
    suma(nombre);
    return 0;
}

void suma (string& archivo)
{
    fstream f (archivo);
    PilaDin<int> P,Q,R;
    int acarreo = 0, sum = 0;

    f >> P >> Q;

    while (!P.vacia() || !Q.vacia())
    {
        if (P.vacia()) {
            sum = Q.tope() + acarreo;
            Q.pop();
        }
        else {
            if (Q.vacia()) {
                sum = P.tope() + acarreo;
                P.pop();
            }
            else {
                sum = P.tope() + Q.tope() + acarreo;
                P.pop();
                Q.pop();
            }
        }
        
        if (sum > 9) {
            acarreo = 1;
            sum %=10;
        } else
            acarreo = 0;
        
        R.push(sum);
    }

    if (acarreo)
        R.push(acarreo);

    f << R;

    f.close();
}

fstream& operator >> (fstream& fe, PilaDin<int>& P)
{
    char cifra;
    
    while (fe.get(cifra) && cifra != '\n')
        P.push(cifra -= '0');
    
    return fe;
}

fstream& operator << (fstream& fs, PilaDin<int> P)
{
    while (!P.vacia())
    {
        fs << P.tope();
        P.pop();
    }

    fs << endl;    
    return fs;
}