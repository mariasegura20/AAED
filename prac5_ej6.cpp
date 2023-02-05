#include <iostream>
#include <ctime>
#include <algorithm>
#include "TAD Conocidos/cola_dinamica.hpp"
#include "prac5_ej6_carta.h"

using namespace std;

typedef ColaDin<tCarta> tMonton[10];

bool juegoReyes (tCarta * baraja, tMonton& monton);

int main ()
{
    tCarta baraja[40];
    tMonton monton;

    // Llenar la baraja
    for (int i = 0, palo = OROS ; palo <= BASTOS ; palo++)
        for (int fig = AS ; fig <= REY ; fig++, i++)
            baraja[i] = tCarta(PALOS(palo), FIGURAS(fig));
    
    // Barajar
    srand(time(nullptr));
    random_shuffle(baraja, baraja+40);

    if (juegoReyes(baraja, monton))
        cout << "¡Has ganado!" << endl;
    else{
        cout << "Has perdido..." << endl;
        cout << "El contenido del monton de los reyes es:";
        for (int i = 0 ; i < 4 ; i++)
            cout << " " << monton[REY].frente().figura() ; 
        cout << endl;
    }

    return 0;
}

bool juegoReyes (tCarta * baraja, tMonton& monton)
{
    bool fin = false, victoria = false;
    int mano;
    int contador[10] = {};

    // Repartir las cartas en los 10 montones y contar cuantas están en su posición
    for (int i = 0, j = AS ; j <= REY ; j++){
        for (int k = 0 ; k < 4 ; k++, i++) {
            monton[j].push(baraja[i]);
            if (baraja[i].figura() == j)
                contador[j]++;
        }
    }
    
    // Escoger un monton al azar [0-9]
    int n = rand() % 10;

    while (!fin)
    {
        if (contador[REY] == 4)
            fin = victoria = true;
        else {
            for (int i = AS ; i < REY ; i++)
            {
                if (contador[i] == 4)
                    fin = true;
            }
        }

        mano = monton[n].frente().figura();
        monton[mano].push(monton[n].frente());
        monton[n].pop();
        contador[mano]++;
        n = mano;
    }

    return victoria;
}