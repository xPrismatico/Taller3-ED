
#include "NodoEvento.h"

NodoEvento::NodoEvento(Evento& evento){
    this->evento = evento;

    this->izq = nullptr;
    this->der = nullptr;
}


Evento NodoEvento::getEvento(){
    return this->evento;
}

NodoEvento* NodoEvento::getDer(){
    return this->der;
}

NodoEvento* NodoEvento::getIzq(){
    return this->izq;
}

void NodoEvento::setEvento(Evento evento){
    this->evento = evento;
}

void NodoEvento::setDer(NodoEvento* der){
    this->der = der;
}

void NodoEvento::setIzq(NodoEvento* izq){
    this->izq = izq;
}