#include "NodoOperador.h"
#include "Operador.h"
using namespace std;

NodoOperador::NodoOperador(Operador& operador){
    this->operador = operador;
    this->altura = 1;

    this->izq = nullptr;
    this->der = nullptr;
}


int NodoOperador::getAltura() {
    return this->altura;
}

Operador NodoOperador::getOperador(){
    return this->operador;
}

NodoOperador* NodoOperador::getDer(){
    return this->der;
}

NodoOperador* NodoOperador::getIzq(){
    return this->izq;
}

void NodoOperador::setAltura(int altura){
    this->altura = altura;
}

void NodoOperador::setOperador(Operador operador){
    this->operador = operador;
}

void NodoOperador::setDer(NodoOperador* der){
    this->der = der;
}

void NodoOperador::setIzq(NodoOperador* izq){
    this->izq = izq;
}