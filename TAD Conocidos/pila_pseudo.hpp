// Pila con Implementación Pseudoestática
#ifndef _PILA_PSEUDO_H_
#define _PILA_PSEUDO_H_
#include <cassert>

template <typename tElemento> class PilaPseudo {
    public:
        explicit PilaPseudo(unsigned TamaMax); 
        PilaPseudo(const PilaPseudo &p);
        PilaPseudo& operator =(const PilaPseudo& p);
        bool vacia() const;
        bool llena() const;
        const tElemento &tope() const;
        void pop();
        void push(const tElemento& x);
        ~PilaPseudo();
    private:
        tElemento *elementos;
        int Lmax; 
        int tope_; 
};

template <typename tElemento>
inline PilaPseudo<tElemento>::PilaPseudo(unsigned TamaMax):
    elementos(new tElemento[TamaMax]), Lmax(TamaMax), tope_(-1)
{}

template <typename tElemento>
PilaPseudo<tElemento>::PilaPseudo(const PilaPseudo<tElemento>& p):
    elementos(new tElemento[p.Lmax]), Lmax(p.Lmax), tope_(p.tope_)
{
    for(int i = 0; i <= tope_; i++)
        elementos[i] = p.elementos[i];
}

template <typename tElemento>
PilaPseudo<tElemento>& PilaPseudo<tElemento>::operator =(const PilaPseudo<tElemento>& p)
{
    if (this != &p) {
        if (Lmax != p.Lmax) {
            delete[] elementos;
            Lmax = p.Lmax;
            elementos = new tElemento[Lmax];
        }
        tope_ = p.tope_;
        for (int i = 0; i <= tope_; i++)
            elementos[i] = p.elementos[i];
    }
    return *this;
}

template <typename tElemento>
inline bool PilaPseudo<tElemento>::vacia() const
{
    return (tope_ == -1);
}

template <typename tElemento>
inline bool PilaPseudo<tElemento>::llena() const
{
    return (tope_ == Lmax - 1);
}

template <typename tElemento>
inline const tElemento &PilaPseudo<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento>
inline void PilaPseudo<tElemento>::pop()
{
    assert(!vacia());
    --tope_;
}

template <typename tElemento>
inline void PilaPseudo<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

template <typename tElemento>
inline PilaPseudo<tElemento>::~PilaPseudo()
{
    delete[] elementos;
}

#endif //_PILA_PSEUDO_H_