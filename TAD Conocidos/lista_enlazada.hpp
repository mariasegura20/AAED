// Lista con Implementación Dinámica Simplemente Enlazada
#ifndef _LISTA_ENLAZADA_H_
#define _LISTA_ENLAZADA_H_

#include <cassert>
template <typename T> class ListaEnla {
    struct nodo; 
    public:
        typedef nodo* posicion;
        ListaEnla(); 
        ListaEnla(const ListaEnla<T>& l);
        ListaEnla<T>& operator=(const ListaEnla<T>& l);
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        T& elemento(posicion p);
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const;
        ~ListaEnla();
    private:
        struct nodo {
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = 0)
                : elto(e)
                , sig(p)
            {}
        };
        nodo* L;
        void copiar(const ListaEnla<T>& l);
};

template <typename T>
void ListaEnla<T>::copiar(const ListaEnla<T>& l)
{
    L = new nodo(T());
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig)
    {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T>
inline ListaEnla<T>::ListaEnla() :
    L(new nodo(T()))
{} 

template <typename T>
inline ListaEnla<T>::ListaEnla(const ListaEnla<T>& l)
{
    copiar(l);
}

template <typename T>
ListaEnla<T>& ListaEnla<T>::operator=(const ListaEnla<T>& l)
{
    if (this != &l) { 
        this->~ListaEnla();
        copiar(l);
    }
    return *this;
}

template <typename T>
inline void ListaEnla<T>::insertar(const T& x, ListaEnla<T>::posicion p)
{
    p->sig = new nodo(x, p->sig);
}
template <typename T>
inline void ListaEnla<T>::eliminar(ListaEnla<T>::posicion p)
{
    assert(p->sig);
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

template <typename T>
inline const T& ListaEnla<T>::elemento(ListaEnla<T>::posicion p) const
{
    assert(p->sig);
    return p->sig->elto;
}

template <typename T>
inline T& ListaEnla<T>::elemento(ListaEnla<T>::posicion p)
{
    assert(p->sig);
    return p->sig->elto;
}

template <typename T>
inline typename ListaEnla<T>::posicion ListaEnla<T>::siguiente(ListaEnla<T>::posicion p) const
{
    assert(p->sig);
    return p->sig;
}

template <typename T>
typename ListaEnla<T>::posicion ListaEnla<T>::anterior(ListaEnla<T>::posicion p) const
{
    nodo* q;
    assert(p != L);
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T>
inline typename ListaEnla<T>::posicion ListaEnla<T>::primera() const
{
    return L;
}

template <typename T>
typename ListaEnla<T>::posicion ListaEnla<T>::fin() const
{
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

template <typename T>
ListaEnla<T>::~ListaEnla()
{
    nodo* q;
    while (L)
    {
        q = L->sig;
        delete L;
        L = q;
    }
}
#endif // _LISTA_ENLAZADA_H_