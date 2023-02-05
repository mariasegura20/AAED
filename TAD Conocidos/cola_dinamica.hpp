// Cola con Implementación Dinámica
#ifndef _COLA_DINAMICA_H_
#define _COLA_DINAMICA_H_
#include <cassert>

template <typename T> class ColaDin {
    public:
        ColaDin();
        ColaDin(const ColaDin<T>& C);
        ColaDin<T>& operator=(const ColaDin<T>& C);
        bool vacia() const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~ColaDin();

    private:
        struct nodo {
            T elem;
            nodo* sig;
            nodo(const T& x, nodo* p = 0)
                : elem(x)
                , sig(p)
            {
            }
        };
        nodo* inicio;
        nodo* fin;
        void copiar(const ColaDin<T>& C);
};

template <typename T>
inline ColaDin<T>::ColaDin():
    inicio(0), fin(0)
{}

template <typename T>
inline ColaDin<T>::ColaDin(const ColaDin<T>& C):
    inicio(0), fin(0)
{
    copiar(C);
}

template <typename T>
ColaDin<T>& ColaDin<T>::operator=(const ColaDin<T>& C)
{
    if (this != &C) {
        this->~ColaDin();
        copiar(C);
    }
    return *this;
}

template <typename T>
bool ColaDin<T>::vacia() const
{
    return (inicio == 0);
}

template <typename T>
const T& ColaDin<T>::frente() const
{
    assert(!vacia());
    return (inicio->elem);
}

template <typename T>
void ColaDin<T>::pop()
{
    assert(!vacia());
    nodo* p = inicio;
    inicio = p->sig;
    if (!inicio)
        fin = 0;
    delete p;
}

template <typename T>
void ColaDin<T>::push(const T& x)
{
    nodo* p = new nodo(x);
    if (inicio == 0) {
        inicio = fin = p;
    } else {
        fin = fin->sig = p;
    }
}

template <typename T>
void ColaDin<T>::copiar(const ColaDin<T>& C)
{
    if (C.inicio) {
        inicio = fin = new nodo(C.inicio->elem);
    
        for (nodo* p = C.inicio->sig; p; p = p->sig) {
            fin->sig = new nodo(p->elem);
            fin = fin->sig;
        }
    }
}

template <typename T>
ColaDin<T>::~ColaDin()
{
    nodo* p;
    while (inicio) {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    fin = 0;
}

#endif // _COLA_DINAMICA_H_