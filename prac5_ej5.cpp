#include <iostream>
#include "TAD Conocidos/cola_pseudo.hpp"
#include "TAD Conocidos/cola_dinamica.hpp"
#include "prac5_ej5_avion.h"

using namespace std;

int main ()
{
    int cont = 0;
    ColaPseudo<Avion> aerodromo(12);
    ColaDin<Avion> espera, esperaAux;

    // Datos del avión solicitado
    string matricula;
    char accion;
    cout << "Matricula: ";
    cin >> matricula;
    cout << endl << "Acción (E/S): ";
    cin >> accion;
    cout << endl;
    Avion A(matricula, accion);

    // Estacionamiento
    if (A.VerAccion() == 'E') {
        if (!aerodromo.llena())
            aerodromo.push(A);
        else
            espera.push(A);
    }
    // Salida
    else if (A.VerAccion() == 'S') {
        // Búsqueda en el aeródromo
        int i = 0;
        while(aerodromo.frente().VerMatricula() != A.VerMatricula() && i < 12)
        {
            Avion Aux(aerodromo.frente().VerMatricula(), aerodromo.frente().VerAccion());
            aerodromo.pop();
            aerodromo.push(Aux);
            i++;
        }

        if (aerodromo.frente().VerMatricula() == A.VerMatricula()){
            aerodromo.pop();
            if (!espera.vacia())
                aerodromo.push(espera.frente());
        }

        // Búsqueda en espera
        else {
            while(espera.frente().VerMatricula() != A.VerMatricula() && !espera.vacia())
            {
                esperaAux.push(espera.frente());
                espera.pop();
            }

            if (espera.frente().VerMatricula() == A.VerMatricula())
                espera.pop();
            else
                cout << "El avión no estaba en el aerodromo ni en espera" << endl;
            
            while(!esperaAux.vacia()) {
                espera.push(esperaAux.frente());
                esperaAux.pop();
            }
        }
    }
    
    return 0;
}