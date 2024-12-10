
#include "AVL.h"
#include <iostream>
#include <string>
using namespace std;

AVL::AVL(){
    this->raiz = nullptr;
}

void AVL::agregar(Operador operador) {
    this->raiz = agregarRec(this->raiz,operador);
}

NodoOperador* AVL::agregarRec(NodoOperador* nodoActual, Operador operador) {

    if(nodoActual == nullptr){
        return new NodoOperador(operador);
    }

    if (nodoActual->getOperador().getOperadorID() == operador.getOperadorID()){
        return nodoActual;
    }

    // if ( dato < nodoActual.dato )
    else if(operador.getOperadorID()  <  nodoActual->getOperador().getOperadorID()){

        // nodoActual.izq ( agregarRec() )
        nodoActual->setIzq( agregarRec( nodoActual->getIzq(), operador ) );
    }


    // if ( dato > nodoActual.dato )
    else if (operador.getOperadorID() > nodoActual->getOperador().getOperadorID() ){
        // nodoActual.der ( agregarRec() )
        nodoActual->setDer( agregarRec( nodoActual->getDer(), operador ) );
    }


    /*
    // Si el dato esta duplicado retorna el mismo Nodo encontrado
    else {
        return nodoActual;
    }
    */

    // Actualizar Altura
    //nodoActual->setAltura(1 + max( getAltura(nodoActual->getIzq()) , getAltura(nodoActual->getIzq()) ) );

    // Obtener factor de balance
    int fb = getFactorBalance(nodoActual);


    // --- Rotacion LL ---
    // if (fb > 1 && dato < nodoActual->izq->dato)
    if (fb > 1 && operador.getOperadorID() < nodoActual->getIzq()->getOperador().getOperadorID() ){
        cout << "Rotacion LL en " << nodoActual->getOperador().getOperadorID() << " con: " << endl;
        cout << "A: " << nodoActual->getOperador().getOperadorID() << "  ";
        cout << "B: " << nodoActual->getOperador().getOperadorID() << "  ";
        if(nodoActual->getIzq()->getIzq()) cout << "Ai: " << nodoActual->getIzq()->getIzq()->getOperador().getOperadorID() << "  ";
        if(nodoActual->getIzq()->getDer()) cout << "Ar: " << nodoActual->getIzq()->getDer()->getOperador().getOperadorID() << "  ";
        if(nodoActual->getDer()) cout << "Br: " << nodoActual->getDer()->getOperador().getOperadorID();
        cout << endl;
        this->mostrarAVL();
        cout << "=====================================================================" << endl;


        return rotarDer(nodoActual);
    }


    // --- Rotacion RR ---
    // if (fb < -1 && dato > nodoActual->der->dato)
    if (fb < -1 && operador.getOperadorID() > nodoActual->getDer()->getOperador().getOperadorID() ){
        cout << "Rotacion RR en " << nodoActual->getOperador().getOperadorID() << " con: " << endl;
        cout << "A: " << nodoActual->getOperador().getOperadorID() << "  ";
        cout << "B: " << nodoActual->getDer()->getOperador().getOperadorID() << "  ";
        if(nodoActual->getIzq()) cout << "Ai: " << nodoActual->getIzq()->getOperador().getOperadorID() << "  ";
        if(nodoActual->getDer()->getIzq()) cout << "Bi: " << nodoActual->getDer()->getIzq()->getOperador().getOperadorID() << "  ";
        if(nodoActual->getDer()->getDer()) cout << "Br: " << nodoActual->getDer()->getDer()->getOperador().getOperadorID();
        cout << endl;
        this->mostrarAVL();
        cout << "=====================================================================" << endl;

        return rotarIzq(nodoActual);
    }


    // --- Rotacion LR ---
    // if (fb > 1 && dato > nodoActual->izq->dato)
    if (fb > 1 && operador.getOperadorID() > nodoActual->getIzq()->getOperador().getOperadorID() ){
        this->mostrarAVL();

        nodoActual->setIzq( rotarIzq( nodoActual->getIzq())  );
        return rotarDer(nodoActual);
    }


    // --- Rotacion RL ---
    // if (fb < -1 && dato < nodoActual->der->dato)
    if (fb < -1 && operador.getOperadorID() < nodoActual->getDer()->getOperador().getOperadorID() ){
        this->mostrarAVL();
        nodoActual->setDer( rotarDer( nodoActual->getDer())  );
        return rotarIzq(nodoActual);
    }

    return nodoActual;
}


// Devuelve el mayor entre 2 numeros
int AVL::max(int a, int b){
    return (a > b) ? a : b;
}

//Obtiene el peso de un arbol dado
int AVL::getAltura(NodoOperador* nodoActual) {
    if (nodoActual == nullptr){
        return 0;
    }

    int alturaIzq = getAltura(nodoActual->getIzq());
    int alturaDer = getAltura(nodoActual->getDer());


    if (alturaIzq > alturaDer) return alturaIzq + 1;
    else return alturaDer + 1;
}

int AVL::getFactorBalance(NodoOperador* nodoActual){
    if (nodoActual == nullptr){
        return 0;
    }

    return this->getAltura(nodoActual->getIzq()) - this->getAltura(nodoActual->getDer());
}


// --- ROTACIONES ---

// RR
NodoOperador* AVL::rotarIzq(NodoOperador* nodoActual){
    NodoOperador* nuevaRaiz = nodoActual->getDer();
    NodoOperador* aux = nuevaRaiz->getIzq();

    // Se hace la rotacion
    nuevaRaiz->setIzq( nodoActual );
    nodoActual->setDer( aux );

    // Actualiza alturas
    //nodoActual->setAltura(   max( getAltura(nodoActual->getIzq()) , getAltura(nodoActual->getDer()) ) +1  );
    //nuevaRaiz->setAltura(   max( getAltura(nuevaRaiz->getIzq()) , getAltura(nuevaRaiz->getDer()) ) +1  );

    return nuevaRaiz;
}

// LL
NodoOperador* AVL::rotarDer(NodoOperador* nodoActual){
    NodoOperador* nuevaRaiz = nodoActual->getIzq();
    NodoOperador* aux = nuevaRaiz->getDer();

    // Se hace la rotacion
    nuevaRaiz->setDer( nodoActual );
    nodoActual->setIzq( aux );

    // Actualiza alturas
    //nodoActual->setAltura(   max( getAltura(nodoActual->getIzq()) , getAltura(nodoActual->getDer()) ) +1  );
    //nuevaRaiz->setAltura(   max( getAltura(nuevaRaiz->getIzq()) , getAltura(nuevaRaiz->getDer()) ) +1  );

    return nuevaRaiz;
}

// --- BUSQUEDA ---

void AVL::mostrarAVL() {
    cout<<"--- ARBOL AVL ---"<<endl;
    mostrarAVLRec(this->raiz,0);
}
void AVL::mostrarAVLRec(NodoOperador* nodo, int profundidad){

    if (nodo == nullptr){
        return;
    }

    //if (nodo->getDer() != nullptr){
        //mostrarAVLRec(nodo->getDer(), profundidad);
    //}
    profundidad+=2;
    mostrarAVLRec(nodo->getDer(),profundidad);
    for (int i=2; i < profundidad; i++){
        cout<<"  ";
    }
    cout<<"("<<nodo->getOperador().getOperadorID()<<")"<<endl;
    mostrarAVLRec(nodo->getIzq(), profundidad);
}

bool AVL::buscar(int idOperador) {
    if(this->buscarRec(this->raiz, idOperador)) {
        cout<<"Existe"<<endl;
        return true;
    }else {
        cout<<"No existe"<<endl;
        return false;
    }
}

bool AVL::buscarRec(NodoOperador* nodoActual, int idOperador) {
    if(nodoActual == nullptr){
        return false;
    }

    //dato encontrado
    else if(idOperador == nodoActual->getOperador().getOperadorID()){
        return true;
    }

    //dato menor que el que se esta comparando
    else if(idOperador < nodoActual->getOperador().getOperadorID()){
        return buscarRec(nodoActual->getIzq(), idOperador);
    }

    //dato mayor al que se esta comparando
    else{
        return buscarRec(nodoActual->getDer(), idOperador);
    }
}


//NodoOperador* AVL::getNodoMaximo(NodoOperador* nodo){
    //NodoOperador* actual = nodo;
//}

/*
NodoOperador *AVL::agregarRecursivo(int operadorID, NodoOperador* nodo) {

    if(!nodo){
       return new NodoOperador(int operadorID);
    }

    if(nodo->getOperador().getOperadorID() == operadorID){
        return nodo;
    }

    else if(operadorID < nodo->getOperador().getOperadorID()){
        nodo->setIzq(this->agregarRecursivo(operadorID, nodo->getIzq()));
    }

    else{
        nodo->setDer(this->agregarRecursivo(operadorID,nodo->getDer()));
    }

    int balance = this->getBalance(nodo);

    if(balance > 1 && operadorID < nodo->getIzq()->getOperador().getOperadorID()){
        if(mostrarRotacion){

        }

        return rotarDer(nodo);
    }

    if(balance < -1 && operadorID < nodo->getDer()->getOperador().getOperadorID()){
        if(mostrarRotacion){

        }

        return rotarIzq(nodo);
    }
}
*/