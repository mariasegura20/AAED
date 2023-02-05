#ifndef _TICTICTOE_HPP_
#define _TICTACTOE_HPP_
#include <cassert>
#include "TAD Conocidos/lista_pseudo.hpp"
#include "TAD Conocidos/lista_enlazada.hpp"

typedef ListaPseudo<jugador>::posicion casilla;
typedef ListaEnla<casilla>::posicion casillaVacia;
typedef enum jugador {VACIA, X, O};

class TicTacToe {
    public:
        TicTacToe();
        void colocarFicha(jugador j, casilla c);
        ListaEnla<casilla>& casillasLibres() const;
        const jugador ficha(casilla c) const;
        bool victoria(jugador j) const;
        bool tablas() const;
        ~TicTacToe();
    private:
        ListaPseudo<jugador> tablero;
};

inline TicTacToe::TicTacToe() : tablero(9)
{
    for (casilla p = tablero.primera() ; p != tablero.fin() ; p = tablero.siguiente(p))
        tablero.insertar(VACIA, p);
}

void TicTacToe::colocarFicha(jugador j, casilla c)
{
    if (tablero.elemento(c) == VACIA)
        tablero.insertar(j, c);
}

ListaEnla<casilla>& TicTacToe::casillasLibres() const
{
    ListaEnla<casilla> Vacias;
    casillaVacia posVacias = Vacias.primera();

    for (casilla p=tablero.primera() ; p != tablero.fin() ; p = tablero.siguiente(p))
    {
        if (tablero.elemento(p) == VACIA) {
            Vacias.insertar(p, posVacias);
            posVacias = Vacias.siguiente(posVacias);
        }
    }

    return Vacias;
}

inline const jugador TicTacToe::ficha (casilla c) const
{
    return(tablero.elemento(c));
}

bool TicTacToe::victoria(jugador j) const
{
    int vTablero[9] = {};
    for (casilla p = tablero.primera(), i = 0; p != tablero.fin() ; p = tablero.siguiente(p), i++) {
        if (tablero.elemento(p) == j)
            vTablero[i] = 1;
    }

    return ((1 == vTablero[0] == vTablero[1] == vTablero[2]) || (1 == vTablero[3] == vTablero[4] == vTablero[5]) || (1 == vTablero[6] == vTablero[7] == vTablero[8]) || (1 == vTablero[0] == vTablero[3] == vTablero[6]) || (1 == vTablero[1] == vTablero[4] == vTablero[7]) || (1 == vTablero[2] == vTablero[5] == vTablero[8]) || (1 == vTablero[0] == vTablero[4] == vTablero[8]) || (1 == vTablero[2] == vTablero[4] == vTablero[6]));
}

bool TicTacToe::tablas() const
{
    return (!victoria(X) && !victoria(O));
}

#endif