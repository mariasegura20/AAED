#include <cassert>
#include "TAD Conocidos/pila_dinamica.hpp"

#ifndef _SIMBOLO_HPP_
#define _SIMBOLO_HPP_

typedef enum trazo {D, I, S, B};

class Simbolo {
    public:
        Simbolo();
        void anadirTrazo(trazo t);
        void deshacerTrazos(int n);
        const Simbolo& simetricoX () const;
        const Simbolo& simetricoY () const;
        const Simbolo& simetricoXY () const;
    private:
        PilaDin<trazo> P;
};

inline Simbolo::Simbolo() {}

inline void Simbolo::anadirTrazo(trazo t)
{
    P.push(t);
}

void Simbolo::deshacerTrazos(int n)
{
    assert(n>0 && !P.vacia());
    while (n > 0 && !P.vacia())
    {
        P.pop();
        n--;
    }
}

const Simbolo& Simbolo::simetricoX () const
{
    PilaDin<trazo> Inversa(P), Aux;
    Simbolo X;

    while (!Inversa.vacia())
    {
        if (Inversa.tope() == D)
            Aux.push(I);
        else if (Inversa.tope() == I)
            Aux.push(D);
        else
            Aux.push(Inversa.tope());
        Inversa.pop();
    }
    while (!Aux.vacia()) {
        X.anadirTrazo(Aux.tope());
        Aux.pop();
    }

    return X;
}

const Simbolo& Simbolo::simetricoY () const
{
    PilaDin<trazo> Inversa(P), Aux;
    Simbolo Y;

    while (!Inversa.vacia())
    {
        if (Inversa.tope() == D)
            Aux.push(I);
        else if (Inversa.tope() == I)
            Aux.push(D);
        else
            Aux.push(Inversa.tope());
        Inversa.pop();
    }
    while (!Aux.vacia()) {
        Y.anadirTrazo(Aux.tope());
        Aux.pop();
    }

    return Y;
}

const Simbolo& Simbolo::simetricoXY() const
{
    PilaDin<trazo> Inversa(P), Aux;
    Simbolo XY;

    while (!Inversa.vacia()) {
        Aux.push(Inversa.tope());
        Inversa.pop();
    }
    
    while (!Aux.vacia()) {
        XY.anadirTrazo(Aux.tope());
        Aux.pop();
    }

    XY = XY.simetricoX();
    XY = XY.simetricoY();
    return XY;
}

#endif