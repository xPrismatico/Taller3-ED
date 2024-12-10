
#ifndef TALLER_3_NODOOPERADOR_H
#define TALLER_3_NODOOPERADOR_H
using namespace std;
#include "Operador.h"
#include <string>

class NodoOperador {

private:

    int altura;
    Operador operador;
    NodoOperador* izq;
    NodoOperador* der;


public:
    NodoOperador(Operador& operador);
    NodoOperador();

    int getAltura();
    Operador getOperador();
    NodoOperador* getDer();
    NodoOperador* getIzq();


    void setAltura(int altura);
    void setOperador(Operador operador);
    void setDer(NodoOperador* der);
    void setIzq(NodoOperador* izq);

};


#endif //TALLER_3_NODOOPERADOR_H
