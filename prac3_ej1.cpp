#include <iostream>
#include <random>
#include <ctime>

#include "prac3_polinom.h"

using namespace std;

int main () {
    int op, gradMax1, gradMax2, n;

    cout << "Grado máximo del primer polinomio: " << endl;
    cin >> gradMax1;
    cout << "Grado máximo del segundo polinomio: " << endl;
    cin >> gradMax2;

    polinomio p1(gradMax1), p2(gradMax2), p3(gradMax1 + gradMax2);

    srand(time(nullptr));

    cout << "Primer polinomio generado: " << endl;
    for (int i = gradMax1 ; i >= 0  ; i--)
    {
        n = 1 + rand() % (10);
        p1.coeficiente(i, n);
        cout << p1.coeficiente(i) << "x^" << i << " ";
    }

    cout << "Segundo polinomio generado: " << endl;
    for (int i = 0 ; i <= gradMax2 ; i++)
    {
        n = 1 + rand() % (10);
        p2.coeficiente(i, n);
        cout << p2.coeficiente(i) << "x^" << i << " ";
    }

    cout << "Operaciones disponibles: \n 1) Suma \n 2) Resta \n 3) Multiplicación \n 4) Derivada \nSelección: ";
    cin >> op;

    switch (op)
    {
        case 1: p3 = p1 + p2; break;
        case 2: p3 = p1 - p2; break;
        case 3: p3 = p1 * p2; break;
        case 4: p3 = derivada(p1); break;
    }

    cout << "Solucion: " << endl;

    for (int i = (gradMax1+gradMax2) ; i >= 0 ; i--)
    {
        cout << p3.coeficiente(i) << "x^" << i << " ";
    }

    system("pause");
    return 0;
}