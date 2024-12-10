
#ifndef TALLER_3_OPERADOR_H
#define TALLER_3_OPERADOR_H

#include <string>

using namespace std;

class Operador {

private:
    int operadorID;
    string nombreOperador;
    string ciudadOperador;

public:

    Operador(int operadorID, string nombreOperador, string ciudadOperador);
    Operador();

    int getOperadorID();
    string getNombreOperador();
    string getCiudadOperador();
};


#endif //TALLER_3_OPERADOR_H
