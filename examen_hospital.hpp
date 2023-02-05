#ifndef _HOSPITAL_HPP_
#define _HOSPITAL_HPP>
#include <cassert>
#include "TAD Conocidos/lista_doble.hpp"

typedef struct {
    int idPaciente;
    int gravedad;
} Paciente;

class Hospital {
    public:
        Hospital(int cUCI, int cPlanta);
        void ingreso (Paciente p);
        void alta (int idPaciente);
        void muerte (int idPaciente);
        ListaDoble<Paciente>& uci () const;
        ListaDoble<Paciente>& planta() const;
        ListaDoble<Paciente>& gravedad (int g);
        ~Hospital();
    private:
        ListaDoble<Paciente> UCI, Planta;
        int capUCI, capPlanta;
};

inline Hospital::Hospital (int cUCI, int cPlanta): capUCI(cUCI), capPlanta(cPlanta) {}

void Hospital::ingreso (Paciente p)
{
    if (p.gravedad < 6) {
        if (capUCI == 0) {
            if (capPlanta == 0)
                Planta.eliminar(Planta.primera());
            Planta.insertar(UCI.elemento(UCI.primera()), Planta.fin());
        }

        ListaDoble<Paciente>::posicion pos = UCI.primera();
        while (UCI.elemento(pos).gravedad > p.gravedad && pos != UCI.fin())
        {
            pos = UCI.siguiente(pos);
        }
        UCI.insertar(p,pos);
    }
    else {
        if (capPlanta == 0) {
            if (Planta.elemento(Planta.primera()).gravedad > p.gravedad) {
                Planta.eliminar(Planta.primera());
                ListaDoble<Paciente>::posicion pos = Planta.primera();
                while(Planta.elemento(pos).gravedad > p.gravedad && pos != Planta.fin())
                    pos = Planta.siguiente(pos);
                Planta.insertar(p, pos);
            }
        }
        else {
            ListaDoble<Paciente>::posicion pos = Planta.primera();
            while (Planta.elemento(pos).gravedad > p.gravedad && pos != Planta.fin())
                pos = Planta.siguiente(pos);
            Planta.insertar(p, pos);
        }
    }
}

void Hospital::alta(int idPaciente)
{
    ListaDoble<Paciente>::posicion pos = Planta.primera();
    while (Planta.elemento(pos).idPaciente != idPaciente && pos != Planta.fin())
        pos = Planta.siguiente(pos);
    if (Planta.elemento(pos).idPaciente == idPaciente)
        Planta.eliminar(pos);
}

void Hospital::muerte(int idPaciente)
{
    ListaDoble<Paciente>::posicion pos = UCI.anterior(UCI.fin());
    while (UCI.elemento(pos).idPaciente != idPaciente && pos != UCI.primera())
        pos = UCI.anterior(pos);
    if (UCI.elemento(pos).idPaciente == idPaciente)
        UCI.eliminar(pos);
}

ListaDoble<Paciente>& Hospital::uci() const
{
    ListaDoble<Paciente> Ret(UCI);
    return Ret;
}

ListaDoble<Paciente>& Hospital::planta() const
{
    ListaDoble<Paciente> Ret(Planta);
    return Ret;
}

ListaDoble<Paciente>& Hospital::gravedad (int g)
{
    ListaDoble<Paciente> Ret;
    
    if (g < 6) {
        ListaDoble<Paciente>::posicion pos = UCI.primera();
        while(UCI.elemento(pos).gravedad > g && pos != UCI.fin())
            pos = UCI.siguiente(pos);
        if (UCI.elemento(pos).gravedad == g) {
            while (UCI.elemento(pos).gravedad == g) {
                Ret.insertar(UCI.elemento(pos), Ret.primera());
                pos = UCI.siguiente(pos);
            }
        }
    }
    else {
        ListaDoble<Paciente>::posicion pos = Planta.primera();
        while(Planta.elemento(pos).gravedad > g && pos != Planta.fin())
            pos = Planta.siguiente(pos);
        if (Planta.elemento(pos).gravedad == g) {
            while (Planta.elemento(pos).gravedad == g) {
                Ret.insertar(Planta.elemento(pos), Ret.primera());
                pos = Planta.siguiente(pos);
            }
        }
    }

    return Ret;
}

#endif