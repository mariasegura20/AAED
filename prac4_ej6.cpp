#include <iostream>
#include <ctime>
#include <algorithm>
#include "TAD Conocidos/pila_dinamica.hpp"
#include "prac4_ej6_carta.h"

using namespace std;

typedef int tBase[4]; // Oros, Copas, Espadas y Bastos
typedef PilaDin<tCarta> tMazo;
typedef PilaDin<tCarta> tMonton;

bool solitario (tCarta * baraja, tBase& base);

int main ()
{
    tCarta baraja[40];
    tBase base;

    // Llenar la baraja
    for(int i = 0, palo = OROS ; palo <= BASTOS ; palo++){
		for(int fig = AS ; fig <= REY ; fig++, i++)
			baraja[i] = tCarta(PALOS(palo),FIGURAS(fig));
	}

    // Barajar
    srand(time(nullptr));
    random_shuffle(baraja, baraja+40);

    // Bases vacías
    for (int i = 0 ; i < 4 ; i++)
        base[i] = VACIO;

    // Juego
    if (solitario(baraja, base))
        cout << "¡Has ganado!" << endl;
    else {
        cout << "Has perdido..." << endl;
        cout << "La última carta colocada en cada base es: " << base[0] << " de ORO, " << base[1] << " de COPA, " << base[2] << " de ESPADA y " << base[3] << " de BASTO. " << endl;
    }

    return 0;
}

bool solitario (tCarta * baraja, tBase& base)
{
    bool fin = false, victoria, cartaColocadaRonda, cartaColocadaMazo;
    unsigned i;
    tMazo mazo;
    tMonton monton;

    // Pongo las cartas barajadas en el mazo
    for (i = 0 ; i < 40 ; i++)
        mazo.push(baraja[i]);

    while (!fin)
    {
        cartaColocadaRonda = false;
        cartaColocadaMazo = false;

        // Si el mazo está vacío, paso todas las cartas del montón de descartes al mazo
        if (mazo.vacia()) {
            while (!monton.vacia())
            {
                mazo.push(monton.tope());
                monton.pop();
            }
        }

        // Pongo las dos primeras cartas del mazo en el monton de descarte
        for (i = 0 ; i < 2 ; i++)
        {
            monton.push(mazo.tope());
            mazo.pop();
        }

        // Compruebo si la puedo poner en la base
        while(!monton.vacia() && !cartaColocadaMazo)
        {
            if (base[monton.tope().palo()] == monton.tope().figura() - 1) {
                base[monton.tope().palo()] = monton.tope().figura();
                monton.pop();
                cartaColocadaRonda = true;
            }
            else
                cartaColocadaMazo = true;
        }

        // Compruebo si he terminado la partida
        victoria = true;
        i = 0;
        while(victoria && i < 4)
        {
            if (base[i] != REY)
                victoria = false;
            i++;
        }
        if (victoria || (!cartaColocadaRonda && mazo.vacia()))
            fin = true;
    }

    return victoria;
}