
#ifndef TALLER_3_NODOEVENTO_H
#define TALLER_3_NODOEVENTO_H

using namespace std;
#include "Evento.h"
#include <string>

class NodoEvento {

private:
    Evento evento;
    NodoEvento* der;
    NodoEvento* izq;
public:
    NodoEvento(Evento& evento);

    Evento getEvento();
    NodoEvento* getDer();
    NodoEvento* getIzq();

    void setEvento(Evento evento);
    void setDer(NodoEvento* der);
    void setIzq(NodoEvento* izq);
};


#endif //TALLER_3_NODOEVENTO_H
