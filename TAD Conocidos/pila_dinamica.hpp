// Pila con Implementación Dinámica
#ifndef _PILA_DINÁMICA_H_
#define _PILA_DINÁMICA_H_
#include <cassert>

template <typename T> class PilaDin {
    public:
        PilaDin();
        PilaDin(const PilaDin<T>& P);
        PilaDin<T>& operator =(const PilaDin<T>& P);
        bool vacia() const;
        const T& tope() const;
        void pop();
        void push(const T& x);
        ~PilaDin();
    private:
        struct nodo{
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = 0) : elto(e), sig(p) {}
        };
        nodo* tope_;
        void copiar(const PilaDin<T>& P);
};

template <typename T>
inline PilaDin<T>::PilaDin():
    tope_(0)
{}

template <typename T>
PilaDin<T>::PilaDin(const PilaDin<T>& P):
    tope_(0)
{
    copiar(P);
}

template <typename T>
PilaDin<T>& PilaDin<T>::operator =(const PilaDin<T>& P)
{
    if(this != &P){
        this->~PilaDin();
        copiar(P);
    }
    return *this;
}

template <typename T>
inline bool PilaDin<T>::vacia() const
{
    return (!tope_);
}

template <typename T>
inline const T& PilaDin<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void PilaDin<T>::pop()
{
    assert(!vacia());
    nodo* p  = tope_;
    tope_ = p->sig;
    delete p;
}

template <typename T>
inline void PilaDin<T>::push(const T& x)
{
    tope_ = new nodo(x,tope_);
}

template <typename T>
PilaDin<T>::~PilaDin()
{
    nodo* p;
    while(tope_)
    {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}

template <typename T>
void PilaDin<T>::copiar(const PilaDin<T>& P)
{
    if(!P.vacia()){
        tope_ = new nodo(P.tope());
        nodo* p = tope_;
        nodo* q = P.tope_->sig;
        while(q)
        {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}
#endif //_PILA_DINÁMICA_H_