// BICOLA ENLAZADA DINÁMICA
// Una bicola es una secuencia de elementos de un tipo determinado,
// en la cual se pueden hacer inserciones y borrados en ambos extremos,
// llamados frente y final.
// Es dinámica puesto que tiene un número variable de elementos
// almacenados en posiciones de memoria no contiguas y enlazados
// mediante punteros.

#include <cassert>

#ifndef _BICOLA_H_
#define _BICOLA_H_

template <typename T> class Bicola {
    public:
        Bicola();                                   // Constructor
        Bicola(Bicola<T>& B);                       // Constructor de copia
        Bicola<T>& operator=(Bicola<T>& B);         // Sobrecarga del operador =
        bool vacia() const;                         // Observador. Pila vacía?
        const T& frente() const;                    // Observador. Elemento frente
        const T& final() const;                     // Observador. Elemento final
        void pushFrente(const T& x);                // Modificador. Inserta en el frente
        void pushFinal(const T& x);                 // Modificador. Inserta al final
        void popFrente();                           // Modificador. Elimina desde el frente
        void popFinal();                            // Modificador. Elimina desde el final
        ~Bicola();                                  // Destructor
    private:
        struct nodo {
            T elemento;
            nodo * siguiente;
            nodo(T e, nodo * p = nullptr) : elemento(e), siguiente(p) {};
        };
        nodo * inicio;
        nodo * fin;
        void copiar(Bicola<T>& B);
};

// Métodos privados

template <typename T>
void Bicola<T>::copiar(Bicola<T>& B)
{
    if (!B.vacia())
    {
        inicio = fin = new nodo (B.inicio->elemento);
        for (nodo * p = B.inicio->siguiente ; p != nullptr ; p = p->siguiente)
        {
            fin->siguiente = new nodo (p->elemento);
            fin = fin->siguiente;
        }
    }
}

// Métodos públicos

// Postcondiciones: Crea una bicola vacía
template <typename T>
inline Bicola<T>:: Bicola(): inicio(nullptr), fin(nullptr) {}

// Postcondiciones: Crea una copia de la bicola B
template <typename T>
inline Bicola<T>:: Bicola(Bicola<T>& B): inicio(nullptr), fin(nullptr)
{
    copiar(B);
}

// Postcondiciones: Devuelve una copia de la bicola B
template <typename T>
inline Bicola<T>& Bicola<T>::operator=(Bicola<T>& B)
{
    return (copiar(B));
}

// Postcondiciones: Devuelve true si la bicola está vacía
template <typename T>
bool Bicola<T>::vacia() const
{
    return (inicio == nullptr);
}

// Precondiciones: La bicola no está vacía
// Postcondiciones: Devuelve el elemento del frente de la bicola
template <typename T>
inline const T& Bicola<T>::frente() const
{
    assert(!vacia());
    return (inicio->elemento);
}

// Precondiciones: La bicola no está vacía
// Postcondiciones: Devuelve el elemento del final de la bicola
template <typename T>
inline const T& Bicola<T>::final() const 
{
    assert(!vacia());
    return (fin->elemento);
}

// Postcondiciones: Inserta el elemento x en el frente de la bicola y el anterior pasa a ser el siguiente elemento
template <typename T>
void Bicola<T>::pushFrente (const T& x)
{
    nodo * p = new nodo(x);
    if (vacia())
        inicio = fin = p;
    else {
        p->siguiente = inicio;
        inicio = p;
    }
}

// Postcondiciones: Inserta el elemento x en el final de la bicola y el anterior pasa a ser el siguiente elemento
template <typename T>
void Bicola<T>::pushFinal (const T& x)
{
    nodo * p = new nodo(x);
    if (vacia())
        inicio = fin = p;
    else {
        fin->siguiente = p;
        fin = p;
    }
}

// Precondiciones: La bicola no está vacía
// Postcondiciones: Elimina el elemento del frente y el siguiente pasa a ser el nuevo frente
template <typename T>
void Bicola<T>::popFrente()
{
    assert(!vacia());
    if (inicio == fin)
        inicio = fin = nullptr;
    else {
        inicio = inicio->siguiente;
    }
}

// Precondiciones: La bicola no está vacía
// Postcondiciones: Elimina el elemento del final y el siguiente pasa a ser el nuevo final
template <typename T>
void Bicola<T>::popFinal()
{
    assert(!vacia());
    nodo * p;
    if (inicio == fin)
        inicio = fin = nullptr;
    else {
        p = inicio;
        for (p = inicio ; p->siguiente != fin ; p = p->siguiente)
        {
        }
        p->siguiente = nullptr;
        fin = p;
    }
}

// Postcondiciones: Elimina la bicola
template<typename T>
Bicola<T>::~Bicola()
{
    nodo * p;
    while(inicio)
    {
        p = inicio->siguiente;
        delete inicio;
        inicio = p->siguiente;
    }
    fin = nullptr;
}

#endif