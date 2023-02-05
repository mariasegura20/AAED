// Lista Circular con Implementación Doblemente Enlazada
#ifndef _LISTA_CIRCULAR_H_
#define _LISTA_CIRCULAR_H_
#include <cassert>

template <typename T> class ListaCir {
    struct nodo;  
    public:
        typedef nodo* posicion;
        static const posicion POS_NULA;
        ListaCir();
        ListaCir(const ListaCir<T>& A);
        ListaCir<T>& operator =(const ListaCir<T>& A);
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        posicion inipos() const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        ~ListaCir();
    private:
        struct nodo{
            T elem;
            nodo *ant, *sig;
            nodo(const T& e, nodo* a = POS_NULA, nodo* s = POS_NULA) :
                elem(e), ant(a), sig(s) {}
        };
        nodo* L; 
        void copiar(const ListaCir<T>& lis);
};


template<typename T>
const typename ListaCir<T>::posicion ListaCir<T>::POS_NULA(nullptr); 

template <typename T>
ListaCir<T>::ListaCir():
    L(POS_NULA)
{}

template <typename T>
void ListaCir<T>::copiar(const ListaCir<T>& lis)
{
    L = new nodo(lis.L->elem);
    L->sig = L->ant = L;
    for(nodo *q = lis.L->sig; q != lis.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template<typename T>
ListaCir<T>& ListaCir<T>::operator =(const ListaCir<T>& A)
{
    if(this != &A){
        this->~ListaCir();
        copiar(A);
    }
    return *this;
}

template<typename T>
void ListaCir<T>::insertar(const T& x,posicion p)
{
    if(L == POS_NULA) {
        L = new nodo(x);
        L->sig = L->ant = L;
    }else
        p->sig = p->sig->ant = new nodo(x, p, p->sig);
}

template<typename T>
void ListaCir<T>::eliminar(posicion p)
{
    assert(p != POS_NULA);
    nodo *q;
    if(p->sig == L){
        if(p != L){
            L->sig->ant = p;
            p->sig = L->sig;
            delete L;
            L = p->sig;
        }else{
            delete L;
            L = POS_NULA;
        }    

    }else{
        q = p->sig;
        p->sig = q->sig;
        q->sig->ant = p;
        delete q;
    }
}

template<typename T>
const T& ListaCir<T>::elemento(posicion p)const
{
    assert(p != POS_NULA);
    return p->sig->elem;
}

template<typename T>
typename ListaCir<T>::posicion ListaCir<T>::inipos()const
{
    return L;
}

template<typename T>
typename ListaCir<T>::posicion ListaCir<T>::siguiente(posicion p)const
{
    assert(p!=POS_NULA);
    return p->sig;
}

template<typename T>
typename ListaCir<T>::posicion ListaCir<T>::anterior(posicion p)const
{
    assert(p!= POS_NULA);
    return p->ant;
}

template<typename T>
ListaCir<T>::~ListaCir()
{
    nodo* q;
    if(L){
        while(L != L->sig){
            q = L->sig;
            L->sig = q->sig;
            delete q;
        }
        delete L;
        L = POS_NULA;
    }
}
#endif // _LISTA_CIRCULAR_H_