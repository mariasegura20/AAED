// COLA IMPLEMENTADA MEDIANTE LA BICOLA ENLAZADA DINÁMICA

#include <cassert>
#include "prac5_ej3.h"

#ifndef _COLA_BICOLA_H_
#define _COLA_BICOLA_H_

template <typename T> class ColaBicola {
    public:
        ColaBicola();                                       // Constructor
        ColaBicola(ColaBicola<T>& C);                       // Constructor de copia    
        ColaBicola<T>& operator= (ColaBicola<T>& C);        // Sobrecarga del operador =
        bool vacia() const;                                 // Observador. Cola vacia?
        const T& frente() const;                            // Observador. Elemento del frente
        void push(const T& x);                              // Modificador. Inserta un elemento al final de la cola
        void pop();                                         // Modificador. Elimina el primer elemento de la cola
        ~ColaBicola();                                      // Destructor.
    private:
        Bicola<T> CB;
};

// Postcondiciones: Crea una cola vacía
template <typename T>
inline ColaBicola<T>::ColaBicola()
{
    Bicola<T> B;
    CB = B;
}

// Postcondiciones: Crea una copia de la cola P
template <typename T>
inline ColaBicola<T>::ColaBicola(ColaBicola<T>& C)
{
    CB = C;
}

// Postcondiciones: Devuelve una copia de la cola C
template <typename T>
inline ColaBicola<T>& ColaBicola<T>::operator=(ColaBicola<T>& C)
{
    return(Bicola<T>::copiar(C));
}

// Postcondiciones: Devuelve true si la pila está vacía
template <typename T>
bool ColaBicola<T>::vacia() const
{
    return(CB.Bicola<T>::vacia());
}

// Precondiciones: La cola no está vacía
// Postcondiciones: Devuelve el frente de la cola
template <typename T>
const T& ColaBicola<T>::frente() const
{
    return (CB.Bicola<T>::frente());
}

// Postcondiciones: Inserta el elemento x al final de la cola
template <typename T>
void ColaBicola<T>::push(const T& x)
{
    CB.Bicola<T>::pushFinal(x);
}

// Precondiciones: La cola no está vacía
// Postcondiciones: Elimina el elemento del frente de la cola y el siguiente pasa a ser el nuevo frente
template <typename T>
void ColaBicola<T>::pop()
{
    CB.Bicola<T>::popFrente();
}

// Postcondiciones: Elimina la cola
template <typename T>
ColaBicola<T>::~ColaBicola()
{
    Bicola<T>::~Bicola();
}

#endif