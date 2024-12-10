// Clase Arbol Binario Max Heap
#ifndef TALLER_3_MAXHEAP_H
#define TALLER_3_MAXHEAP_H

#include "NodoEvento.h"

class MaxHeap {
private:
    NodoEvento *listaMaxHeap;
    int tamanio;
    int cantidad;

public:
    MaxHeap();
    //bool agregar(float valorRegistro);
    bool agregar(NodoEvento nuevoNodo);

    void eliminar();

    void intercambiar(int valor1, int valor2);

    void reordenar(int raiz);

    void verValoresMaxHeap();

    void guardar();

    NodoEvento* getListaMax();

    //void reordenarHeapSort(int raiz, int limite);
    //void heapSort();
    //void mostrardato();


};


#endif //TALLER_3_MAXHEAP_H
