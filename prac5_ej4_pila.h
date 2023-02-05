// PILA IMPLEMENTADA MEDIANTE LA BICOLA ENLAZADA DINÁMICA

#include <cassert>
#include "prac5_ej3.h"

#ifndef _PILA_BICOLA_H_
#define _PILA_BICOLA_H_

template <typename T> class PilaBicola {
    public:
        PilaBicola();
        PilaBicola(PilaBicola<T>& P);
        PilaBicola<T>& operator=(PilaBicola<T>& P);
        bool vacia() const;
        const T& tope() const;
        void push(const T& x);
        void pop();
        ~PilaBicola();
    private:
        Bicola<T> PB;
};

// Postcondiciones: Crea una pila vacía
template<typename T>
inline PilaBicola<T>::PilaBicola()
{
    Bicola<T> B;
    PB = B;
}

// Postcondiciones: Crea una copia de la pila P
template <typename T>
inline PilaBicola<T>::PilaBicola(PilaBicola<T>& P)
{
    PB = P;
}

// Postcondiciones: Devuelve una copia de la pila P
template <typename T>
inline PilaBicola<T>& PilaBicola<T>::operator=(PilaBicola<T>& P)
{
    if (this != &PB)
        PB = P;
}

// Postcondiciones: Devuelve true si la pila está vacía
template <typename T>
inline bool PilaBicola<T>::vacia() const
{
    return(PB.Bicola<T>::vacia());
}

// Precondiciones: La pila no está vacía
// Postcondiciones: Devuelve el tope de la pila
template <typename T>
inline const T& PilaBicola<T>::tope() const
{
    return(PB.Bicola<T>::frente());
}

// Postcondiciones: Inserta el elemento x en el tope de la pila
template <typename T>
inline void PilaBicola<T>::push(const T& x)
{
    PB.Bicola<T>::pushFrente(x);
}

// Precondiciones: La pila no está vacía
// Postcondiciones: Elimina el elemento del tope de la pila y el siguiente pasa a ser el nuevo tope
template <typename T>
inline void PilaBicola<T>::pop()
{
    PB.Bicola<T>::popFrente();
}

// Postcondiciones: Elimina la pila
template <typename T>
inline PilaBicola<T>::~PilaBicola()
{
    PB.Bicola<T>::~Bicola();
}

#endif