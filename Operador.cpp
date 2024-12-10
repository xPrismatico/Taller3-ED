#include <string>
#include "Operador.h"

Operador::Operador(int operadorID, string nombreOperador, string ciudadOperador) {
    this->operadorID = operadorID;
    this->nombreOperador = nombreOperador;
    this->ciudadOperador = ciudadOperador;
}

Operador::Operador() {}

int Operador::getOperadorID() {
    return operadorID;
}

string Operador::getNombreOperador() {
    return nombreOperador;
}

string Operador::getCiudadOperador() {
    return ciudadOperador;
}