// Lista con Implementación Pseudoestática
#ifndef _LISTA_PSEUDO_H_
#define _LISTA_PSEUDO_H_
#include <cassert>
#include <iostream>

template<typename T> class ListaPseudo {
    public:
        typedef size_t posicion;
        explicit ListaPseudo(size_t TamMax);
        ListaPseudo(const ListaPseudo<T>& L);
        ListaPseudo<T>& operator =(const ListaPseudo<T>& L);
        void insertar(const T& x, posicion p); 
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        T& elemento(posicion p);
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const;
        ~ListaPseudo();
    private:
        T *elementos;
        size_t Lmax;
        size_t n;
};

template <typename T>
inline ListaPseudo<T>::ListaPseudo(size_t TamMax) :
    elementos(new T[TamMax]), Lmax(TamMax), n(0)
{}

template <typename T>
ListaPseudo<T>::ListaPseudo(const ListaPseudo<T>& L) :
    elementos(new T[L.Lmax]), Lmax(L.Lmax), n(L.n)
{
    for(ListaPseudo<T>::posicion p = 0; p < n; ++p)
        elementos[p] = L.elementos[p];
}

template <typename T>
ListaPseudo<T>& ListaPseudo<T>::operator =(const ListaPseudo<T>& L)
{
    if (this != &L){
        delete [] elementos;
        Lmax = L.Lmax;
        elementos = new T[Lmax];
    }
    n = L.n;
    for(ListaPseudo<T>::posicion p = 0; p < n; ++p)
        elementos[p] = L.elementos[p];
    return *this;
}

template <typename T>
void ListaPseudo<T>::insertar(const T& x, ListaPseudo<T>::posicion p)
{
    assert(p >= 0 && p <= n);
    assert(n < Lmax);
    for(ListaPseudo<T>::posicion q = n; q > p; q--)
        elementos[q] = elementos[q-1];
    elementos[p] = x;
    n++;
}


template <typename T>
void ListaPseudo<T>::eliminar(ListaPseudo<T>::posicion p)
{
    assert(p > 0 && p < n);
    n--;
    for(ListaPseudo<T>::posicion q = p; q < n; q++)
        elementos[q] = elementos[q+1];
}

template <typename T>
inline const T& ListaPseudo<T>::elemento(ListaPseudo<T>::posicion p) const
{
    assert(p >= 0 && p < n);
    return elementos[p];
}

template <typename T>
inline T& ListaPseudo<T>::elemento(ListaPseudo<T>::posicion p)
{
    assert(p >=0 && p < n);
    return elementos[p];
}

template <typename T>
typename ListaPseudo<T>::posicion ListaPseudo<T>::siguiente(ListaPseudo<T>::posicion p) const
{
    assert(p >= 0 && p < n);
    return p+1;
}

template <typename T>
typename ListaPseudo<T>::posicion ListaPseudo<T>::anterior(ListaPseudo<T>::posicion p) const
{
    assert(p > 0 && p <= n);
    return p-1;
}

template <typename T>
inline typename ListaPseudo<T>::posicion ListaPseudo<T>::primera() const
{
    return 0;
} 

template <typename T>
inline typename ListaPseudo<T>::posicion ListaPseudo<T>::fin() const
{
    return n;
}

template <typename T>
inline ListaPseudo<T>::~ListaPseudo()
{
    delete[] elementos;
}

#endif //_LISTA_PSEUDO_H_