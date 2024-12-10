#include <iostream>
#include "MaxHeap.h"
using namespace std;

MaxHeap::MaxHeap() {
    this->tamanio = 3;
    this->cantidad = 0;

    // Crear listaMaxHeap con tamanio 3

    do{
        this->listaMaxHeap= (NodoEvento*) malloc((tamanio)*sizeof(NodoEvento));
    }

    while (!this->listaMaxHeap);


    // Primer elemento reservado //TODO: NO FUNCIONA
    //this->listaMaxHeap[0] = NodoEvento(Evento("","",0)); //TODO: si  se modifica esto cambiar la linea 133
}

void MaxHeap::intercambiar(int valor1, int valor2){
    NodoEvento auxvalor1 = this->listaMaxHeap[valor1];
    this->listaMaxHeap[valor1] = this->listaMaxHeap[valor2];
    this->listaMaxHeap[valor2] =  auxvalor1;
}

//bool MaxHeap::agregar(float valorRegistro) {
bool MaxHeap::agregar(NodoEvento nuevoNodo) {


    // Redimensionar Si la lista esta llena
    if(this->cantidad == this->tamanio-1){
        cout<<"\nExpandir lista MaxHeap!"<<" tamanioactual: "<<tamanio<<endl;
        this->tamanio++;

        cout<<"tamanioCambiado: "<<this->tamanio<<endl;

        NodoEvento *aux = this->listaMaxHeap;
        do{
            this->listaMaxHeap = aux;
            this->listaMaxHeap = (NodoEvento*) realloc(this->listaMaxHeap, this->tamanio*30*sizeof(NodoEvento));

        }
        while (!this->listaMaxHeap);
    }

    this->cantidad++;
    cout<<"Deberia agregar, la cantidad es 1 ya"<<endl;
    // Añadir dato en ultima hoja
    this->listaMaxHeap[cantidad] = nuevoNodo;
    cout<<"Se pudo"<<endl;

    int hijo = cantidad;
    int padre = hijo/2;

    // Si el Hijo es mas grande que el Padre, intercambiar para quedar MaxHeap
    while (padre >= 1){
        if (this->listaMaxHeap[hijo].getEvento().getValorRegistro() > this->listaMaxHeap[padre].getEvento().getValorRegistro()){
            intercambiar(hijo, padre);
        }

        hijo = padre;
        padre = hijo/2;
    }
    //cout<<"tamanio:"<<this->tamanio<<" cantidad:"<<this->cantidad<<endl;
    return true;
}

void MaxHeap::verValoresMaxHeap(){
    cout<<"Lista MaxHeap: [";

    for (int i = 1; i<=cantidad; i++){
        cout <<this->listaMaxHeap[i].getEvento().getValorRegistro()<<",";
    }
    cout<<"]"<<endl;
}



void MaxHeap::reordenar(int raiz){
    int max = raiz;
    int izq = raiz*2;
    int der = raiz*2 + 1;

    if(izq <= this->cantidad && this->listaMaxHeap[izq].getEvento().getValorRegistro() > this->listaMaxHeap[max].getEvento().getValorRegistro()){
        max = izq;
    }
    if (der <= this->cantidad && this->listaMaxHeap[der].getEvento().getValorRegistro() > this->listaMaxHeap[max].getEvento().getValorRegistro()) {
        max = der;
    }
    if (max != raiz){
        intercambiar(max,raiz);
        reordenar(max);
    }
}


/*
void MaxHeap::reordenarHeapSort(int raiz, int limite){
    int max = raiz;
    int izq = raiz * 2;
    int der = raiz * 2 + 1;

    if (izq < limite && this->listaMaxHeap[izq] > this->listaMaxHeap[max]){
        max = izq;
    }
    if (der < limite && this->listaMaxHeap[der] > this->listaMaxHeap[max]){
        max = der;
    }
    if (max != raiz){
        intercambiar(max,raiz);
        reordenarHeapSort(max,limite);
    }
}
*/

/*
void MaxHeap::heapSort(){
    for (int i = cantidad; i>=1; i--){
        intercambiar(1,i);
        reordenarHeapSort(1,i);
    }
}
*/





void MaxHeap::eliminar() {

    if (this->cantidad == 0) {
        return;
    }
    cout<<""<<endl;
    cout << "-- Atencion de evento prioritario ---" << endl;

    cout << "OperadorID: " << this->listaMaxHeap[1].getEvento().getOperadorID() << endl;
    //TODO: mostrar nombre operador, ciudad de recidencia operador
    cout << "EquipoID: " << this->listaMaxHeap[1].getEvento().getEquipoID() << endl;
    cout << "Evento: " << this->listaMaxHeap[1].getEvento().getNombreEvento() << endl;
    cout << "Severidad: " << this->listaMaxHeap[1].getEvento().getValorRegistro() << endl;


    intercambiar(1, this->cantidad);

    this->cantidad--;
    this->tamanio--;
    NodoEvento* aux = this->listaMaxHeap;

    do {
        this->listaMaxHeap = aux;
        this->listaMaxHeap = (NodoEvento*)realloc(this->listaMaxHeap,this->tamanio* sizeof(NodoEvento));
    } while (!this->listaMaxHeap);

    reordenar(1);

    cout <<"\nEvento atendido y eliminado de la lista de espera."<<endl;
}

NodoEvento *MaxHeap::getListaMax() {
    return listaMaxHeap;
}
