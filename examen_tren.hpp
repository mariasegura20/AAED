#ifndef _TREN_HPP_
#define _TREN_HPP_
#include <cassert>
#include "TAD Conocidos/pila_dinamica.hpp"

typedef struct {
    int idVagon;
} vagon;

class Tren {
    public:
        Tren();
        void desplazarIzq();
        void desplazarDer();
        void eliminarVagonActivo();
        const vagon& vagonActivo() const;
        bool vacio() const;
    private:
        PilaDin<vagon> I, D;
};

inline Tren::Tren() : I(), D() {}

void Tren::desplazarIzq()
{
    if(!D.vacia()) {
        I.push(D.tope());
        D.pop();
    }
}

void Tren::desplazarDer()
{
    D.push(I.tope());
    I.pop();
    if (I.vacia()) {
        I.push(D.tope());
        D.pop();
    }
}

void Tren::eliminarVagonActivo()
{
    I.pop();
    if (!D.vacia()) {
        I.push(D.tope());
        D.pop();
    }
}

inline const vagon& Tren::vagonActivo() const
{
    assert(!vacio());
    return(I.tope());
}

inline bool Tren::vacio() const 
{
    return (I.vacia());
}

#endif //_TREN_H_