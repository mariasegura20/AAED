#ifndef _COCINA_HPP_
#define _COCINA_HPP_
#include <cassert>
#include "TAD Conocidos/lista_doble.hpp"

typedef struct {
    int idMueble;
    int pos;
    int ancho;
} Mueble;

class Cocina {
    public:
        Cocina(int tamMax);
        bool colocable (Mueble m) const;
        void anadirMueble (Mueble m);
        const Mueble& consultarMueble(int i) const;
        void eliminarMueble(int i);
        void moverMueble(int i);
        ~Cocina();
    private:
        ListaDoble<Mueble> lCocina;
        int n_elto;
        int tam;
};

Cocina::Cocina(int tamMax) : n_elto(0), tam(tamMax) {}

bool Cocina::colocable (Mueble m) const
{
    bool ret = false;
    Mueble mAnterior, mPosterior;
    // Busco el mueble que se encuentra justo antes y justo después de la posicion de m
    ListaDoble<Mueble>::posicion p = lCocina.primera();
    while (lCocina.elemento(p).pos < m.pos && p != lCocina.fin())
        p = lCocina.siguiente(p);
    mAnterior = lCocina.elemento(lCocina.anterior(p));

    if (p != lCocina.fin()){
        mPosterior = lCocina.elemento(p);
        ret = (mAnterior.pos + mAnterior.ancho < m.pos && mPosterior.pos > m.pos + m.ancho);
    }
    else 
        ret = (mAnterior.pos + mAnterior.ancho < m.pos && m.pos + m.ancho < tam);
    
    return ret;
}

void Cocina::anadirMueble(Mueble m)
{
    ListaDoble<Mueble>::posicion p = lCocina.primera();
    if(colocable(m)) {
        while (lCocina.elemento(p).pos < m.pos)
            p = lCocina.siguiente(p);
        lCocina.insertar(m, lCocina.anterior(p));
        n_elto++;
    }
}

const Mueble& Cocina::consultarMueble(int i) const
{
    if (i <= n_elto) {
        ListaDoble<Mueble>::posicion p = lCocina.primera();
        Mueble m;
        if (i == 1)
            m = lCocina.elemento(lCocina.primera());
        else {
            for (int j = 1 ; j < i ; j++)
                p = lCocina.siguiente(p);
            m = lCocina.elemento(p);
        }

        return m;
    }
}

void Cocina::eliminarMueble(int i)
{
    if (i <= n_elto) {
        ListaDoble<Mueble>::posicion p = lCocina.primera();
        if (i == 1)
            lCocina.eliminar(lCocina.primera());
        else {
            for (int j = 1 ; j < i ; j++)
                p = lCocina.siguiente(p);
            lCocina.eliminar(p);
        }
    }
}

void Cocina::moverMueble(int i)
{
    if (i <= n_elto) {
        ListaDoble<Mueble>::posicion p = lCocina.primera();
        if (i == 1)
            lCocina.elemento(p).pos=0;
        else {
            for (int j = 1 ; j < i ; j++)
                p = lCocina.siguiente(p);
            lCocina.elemento(p).pos = lCocina.elemento(lCocina.anterior(p)).pos + lCocina.elemento(lCocina.anterior(p)).ancho;
        }
    }
}

#endif