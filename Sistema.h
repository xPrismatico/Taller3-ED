using namespace std;

#ifndef TALLER_3_SISTEMA_H
#define TALLER_3_SISTEMA_H

#include "MaxHeap.h"
#include "AVL.h"

class Sistema {
private:
    MaxHeap* MaxHeapEventos;
    AVL* AVLOperadores;
    int cantidadEventos = 0;
    int cantidadOperadores = 0;

public:

    Sistema();

    //TODO: Saltarse la primera linea que son titulos para los 3 documentos (en el CSV de ejemplo sale eso)
    void leerArchivoOperadores(); //workers.csv
    void leerArchivoEventos(); //minecare_events.csv
    //TODO: Lectura de Resumen y primera linea de titulos NO se lee
    void leerEquiposAtentidos(); //resumen.txt



    void menu(); //listo


    //TODO: verificar operadorID en listaOperadores y validaciones varias
    void agregarEventoSalud();

    //TODO: Falta agregar a la listaOperadores
    void agregarOperador(int operadorID);

    void atenderEquipo(); //listo

    //TODO:
    void reportabilidad();

    //TODO:
    int calcularRestantes();
    //TODO:
    int promediarSeveridad();
    //TODO:
    void ListaOperadoresListos(); //Operadores que NO estan en el Arbol MaxHeap de Eventos Pendientes


    //TODO:
    void guardarArchivoOperadores();
    //TODO:
    void guardarArchivoEventos();
    //TODO: Guardar informacion de atentidos como resumen y Escribir primera linea de Titulos, si ya esta no crearla entonces
    void guardarArchivoResumen();



};


#endif //TALLER_3_SISTEMA_H
