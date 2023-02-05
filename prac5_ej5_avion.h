#ifndef _AVION_HPP_
#define _AVION_HPP_
#include <cassert>
#include <string>

class Avion {
    public:
        Avion(string matricula, char accion): matricula_(matricula), accion_(accion){};
        const string VerMatricula() const { return matricula_ ;};
        const char VerAccion() const { return accion_ ;};
    private:
        string matricula_;
        char accion_;
};

#endif