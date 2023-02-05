// Lista con Implementación Dinámica Doblemente Enlazada
#ifndef _LISTA_DOBLE_H_
#define _LISTA_DOBLE_H_
#include <cassert>

template <typename T> class ListaDoble {
    struct nodo;
    public:
        typedef nodo* posicion;
        ListaDoble(); //constructor
        ListaDoble(const ListaDoble<T>& lis); //constructor de copia
        ListaDoble<T>& operator =(const ListaDoble<T>& lis);
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        T& elemento(posicion p);
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const;
        ~ListaDoble();
    private:
        struct nodo{
            T elem;
            nodo *ant, *sig;
            nodo(const T& e, nodo* a = nullptr, nodo* s = nullptr) :
                elem(e), ant(a), sig(s) {}
        };
        nodo* L; 
        void copiar(const ListaDoble<T>& lis);
};


template <typename T>
void ListaDoble<T>::copiar(const ListaDoble<T>& lis)
{
    L = new nodo(T());
    L->ant = L->sig = L;
    for(nodo* q = lis.L->sig; q != lis.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T>
inline ListaDoble<T>::ListaDoble() : L(new nodo(T()))
{
    L->ant = L->sig = L;
}

template <typename T>
inline ListaDoble<T>::ListaDoble(const ListaDoble<T>& lis)
{
    copiar(lis);
}

template <typename T>
ListaDoble<T>& ListaDoble<T>::operator =(const ListaDoble<T>& lis)
{
    if(this != &lis){
        this->~ListaDoble();
        copiar(lis);
    }
    return *this;
}

template <typename T>
void ListaDoble<T>::insertar(const T& x, ListaDoble<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
}

template <typename T>
inline void ListaDoble<T>::eliminar(ListaDoble<T>::posicion p)
{
    assert(p->sig != L);
    nodo* q = p->sig; 
    p->sig = q->sig; 
    p->sig->ant = p;
    delete q;
}

template <typename T>
inline T& ListaDoble<T>::elemento(ListaDoble<T>::posicion p)
{
    assert(p->sig != L);
    return p->sig->elem;
}

template <typename T>
typename ListaDoble<T>::posicion ListaDoble<T>::siguiente(ListaDoble<T>::posicion p) const
{
    assert(p->sig != L);
    return p->sig;
}

template <typename T>
typename ListaDoble<T>::posicion ListaDoble<T>::anterior(ListaDoble<T>::posicion p) const
{
    assert(p->sig != L);
    return p->ant;
}

template <typename T>
typename ListaDoble<T>::posicion ListaDoble<T>::primera() const
{
    return L;
}

template <typename T>
typename ListaDoble<T>::posicion ListaDoble<T>::fin() const
{
    return L->ant;
}

template <typename T>
ListaDoble<T>::~ListaDoble()
{
    nodo* q;
    while(L->sig != L)
    {
        q = q->sig;
        L->sig = q->sig;
        delete q;
    }
}

#endif //_LISTA_DOBLE_H_