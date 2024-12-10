
#ifndef TALLER_3_AVL_H
#define TALLER_3_AVL_H

#include "NodoOperador.h"
#include "Operador.h"

class AVL {
private:
    NodoOperador* raiz;

    //bool mostrarRotacion;

public:
    AVL();
    void agregar(Operador operador);
    bool buscar(int idOperador);

    NodoOperador* agregarRec(NodoOperador* nodoActual, Operador operador);
    bool buscarRec(NodoOperador* nodoActual, int idOperador);

    int max(int a, int b); // Devuelve el mayor entre 2 numeros

    int getAltura(NodoOperador* nodoActual); //Obtiene el peso de un arbol dado

    int getFactorBalance(NodoOperador* nodoActual);

    NodoOperador* rotarIzq(NodoOperador* nodoActual);
    NodoOperador* rotarDer(NodoOperador* nodoActual);


    void mostrarAVL();
    void mostrarAVLRec(NodoOperador* nodo, int profundidad);

    // ----AVL Segun MaxHeap (borrar)-----
    /*
    NodoOperador* agregarRecursivo(int operadorID, NodoOperador* nuevoNodo);


    NodoOperador* buscarRecursivo(int dato, NodoOperador* nodo);
    NodoOperador* borrarRecursivo(int dato, NodoOperador* nodo);

    NodoOperador* getMinimo(NodoOperador* nuevoNodo);

    int getBalance(NodoOperador* a);

    NodoOperador* rotarIzq(NodoOperador* pivote);
    NodoOperador* rotarDer(NodoOperador* pivote);
    */
    //-----------------------
};


#endif //TALLER_3_AVL_H
