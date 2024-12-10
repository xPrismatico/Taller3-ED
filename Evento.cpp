
#include "Evento.h"

Evento::Evento() {}

Evento::Evento(string equipoID, int operadorID, string nombreEvento, float valorRegistro) {
    this->equipoID = equipoID;
    this->operadorID = operadorID;
    this->nombreEvento = nombreEvento;
    this->valorRegistro = valorRegistro;
}

//----GETS DE LA CLASE----
string Evento::getEquipoID() {
    return equipoID;
}

int Evento::getOperadorID() {
    return operadorID;
}

string Evento::getNombreEvento() {
    return nombreEvento;
}

float Evento::getValorRegistro() {
    return valorRegistro;
}





//---- SETS DE LA CLASE----
void Evento:: setEquipoID(string equipoID){
    this->equipoID = equipoID;
}

void Evento:: setOperadorID(int operadorID){
    this->operadorID = operadorID;
}

void Evento:: setNombreEvento(string nombreEvento){
    this->nombreEvento = nombreEvento;
}

void Evento:: setValorRegistro(float valorRegistro){
    this->valorRegistro = valorRegistro;
}