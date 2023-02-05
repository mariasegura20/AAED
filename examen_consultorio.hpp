#ifndef _CONSULTORIO_HPP_
#define _CONSULTORIO_HPP_
#include <cassert>
#include "TAD Conocidos/lista_enlazada.hpp"
#include "TAD Conocidos/cola_dinamica.hpp"

typedef struct {
    int idPaciente;
} Paciente;

typedef struct {
    int idMedico;
    ColaDin<Paciente> cPaciente;
} Medico;

class Consultorio {
    public:
        Consultorio();
        ListaEnla<Medico>::posicion& buscar(int idMed);
        void AltaMedico(int idMed);
        void BajaMedico(int idMed);
        void nuevoPacienteListaEspera(int idPac, int idMed);
        const Paciente& consultaPaciente(int idMed);
        void atenderPaciente(int idMed);
        bool espera(int idMed);
    private:
        ListaEnla<Medico> lMedico;
};

inline Consultorio::Consultorio() : lMedico() {}

ListaEnla<Medico>::posicion& Consultorio::buscar(int idMed)
{
    ListaEnla<Medico>::posicion p = lMedico.primera();
    bool encontrado;
    for (encontrado = false ; p->sig && encontrado ; p = p->sig)
    {
        if(p->sig->elto.idMedico== idMed)
            encontrado = true;
    }

    if(!encontrado)
        p = nullptr;

    return p;
}

void Consultorio::AltaMedico(int idMed)
{

}

void Consultorio::BajaMedico(int idMed)
{
    ListaEnla<Medico>::posicion p = buscar(idMed);
    if (p != nullptr)
        lMedico.eliminar(p);
}

void Consultorio::nuevoPacienteListaEspera(int idPac, int idMed)
{
    ListaEnla<Medico>::posicion p = buscar(idMed);
    if(p != nullptr) {
        Paciente pac;
        pac.idPaciente = idPac;
        lMedico.elemento(p).cPaciente.push(pac);
    }
}

const Paciente& Consultorio::consultaPaciente(int idMed)
{
    ListaEnla<Medico>::posicion p = buscar(idMed);
    if (p != nullptr) {
        return (lMedico.elemento(p).cPaciente.frente());
    }
}

void Consultorio::atenderPaciente(int idMed)
{
    ListaEnla<Medico>::posicion p = buscar(idMed);
    if (p != nullptr) {
        lMedico.elemento(p).cPaciente.pop();
    }
}

bool Consultorio::espera(int idMed)
{
    ListaEnla<Medico>::posicion p = buscar(idMed);
    if(p != nullptr) {
        return(lMedico.elemento(p).cPaciente.vacia());
    }
}
#endif