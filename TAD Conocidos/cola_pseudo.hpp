// Cola con Implementación Pseudoestática Circular
#ifndef _COLA_PSEUDO_H_
#define _COLA_PSEUDO_H_
#include <cassert>

template<typename T> class ColaPseudo {
    public:
        ColaPseudo(unsigned Tam);
        ColaPseudo(const ColaPseudo<T>& C);
        ColaPseudo<T>& operator =(const ColaPseudo<T>& C);
        bool vacia()const;
        bool llena()const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~ColaPseudo();
    private:
        T *elementos;
        int fin,inicio;
        int Lmax;
};

template<typename T>
inline ColaPseudo<T>::ColaPseudo(unsigned Tam):
    elementos(new T[Tam+1]), Lmax(Tam+1), inicio(0), fin(Tam)
{}

template<typename T>
inline ColaPseudo<T>::ColaPseudo(const ColaPseudo<T> &C):
    elementos(new T[C.Lmax]), Lmax(C.Lmax), inicio(C.inicio), fin(C.fin)
{
    if(!C.vacia()){
        for(int i=inicio;i!=(fin+1)%Lmax;i=(i+1)%Lmax){
            elementos[i]=C.elementos[i];
        }
    }
}

template<typename T>
ColaPseudo<T>& ColaPseudo<T>::operator =(const ColaPseudo<T>& C)
{
    if(this!=&C){
        inicio=C.inicio;
        fin=C.fin;
        if(Lmax!=C.Lmax){
            delete[] elementos;
            Lmax=C.Lmax;
            elementos=new T[C.Lmax];
        }
        if(!C.vacia()){
            for(int i=inicio;i!=(fin+1)%Lmax;i=(i+1)%Lmax){
                elementos[i]=C.elementos[i];
            }
        }
    }
    return *this;
}

template<typename T>
bool ColaPseudo<T>::vacia()const
{
    return(inicio==(fin+1)%Lmax);
}

template<typename T>
bool ColaPseudo<T>::llena() const
{
    return(inicio==(fin + 2)%Lmax);
}

template<typename T>
const T& ColaPseudo<T>::frente()const
{
    assert(!vacia());
    return(elementos[inicio]);
}

template<typename T>
void ColaPseudo<T>::pop()
{
    assert(!vacia());
    inicio=(inicio+1)%Lmax;
}

template<typename T>
void ColaPseudo<T>::push(const T& x)
{
    assert(!llena());
    fin=(fin+1)%Lmax;
    elementos[fin]=x;

}

template<typename T>
ColaPseudo<T>::~ColaPseudo()
{
    delete[] elementos;
}

#endif //_COLA_PSEUDO_H_