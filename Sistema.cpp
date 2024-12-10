
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits> // TODO: preguntar si se puede usar esto

#include "Sistema.h"
#include "Operador.h"
#include "Evento.h"
#include "NodoEvento.h"
#include "NodoOperador.h"
using namespace std;

Sistema::Sistema() {
}

void Sistema::menu() {

    // Lectura de archivos

    leerArchivoOperadores(); //workers.csv
    //leerArchivoEventos(); //minecare_events.csv
    //leerEquiposAtentidos(); //resumen.txt

    string Respuesta;
    while (true){
        cout << "\n.:.:.:.:.: DRAW-IA .:.:.:.:.:" << endl;
        cout << "[1] Agregar un evento de salud" << endl;
        cout << "[2] Atender un equipo" << endl;
        cout << "[3] Reportabilidad" << endl;
        cout << "[4] Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> Respuesta;

        if(Respuesta == "1") {
            agregarEventoSalud();
        }

        else if(Respuesta == "2"){
            atenderEquipo();
        }

        else if(Respuesta == "3") {
            reportabilidad();
        }

            // --- SALIR DEL SISTEMA --- //
        else if(Respuesta == "4"){
            guardarArchivoResumen();
            guardarArchivoOperadores();
            guardarArchivoEventos();
            return;
        }

        //TODO: ELIMINARLO, SOLO ES TEST
        else if(Respuesta == "5"){
            this->MaxHeapEventos->verValoresMaxHeap();
        }

        else if (Respuesta == "6"){
            this->AVLOperadores->mostrarAVL();
        }
        else{
            cout << "\n[!] Error: Ingrese una opcion valida! \n" << endl;
        }
    }
 }


void Sistema::agregarEventoSalud() {
    while(1) {

        //- OperatorID
        int operadorIDAgregar;
        cout << "Ingrese el ID del operador: ";
        cin >> operadorIDAgregar;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] ¡Error! Ingrese un numero valido." << endl;
        }


        //------------------------------------------------------------

        if(AVLOperadores->buscar(operadorIDAgregar) == false){
            cout << "[!] ¡Error! No existe el ID del operador." << endl;

            string agregar;
            cout << " Desea agregar un operador? (si/no): ";
            cin >> agregar;

            if(agregar == "si" || agregar == "SI" || agregar == "Si" || agregar == "sI"){
                agregarOperador(operadorIDAgregar);
            }
            else if(agregar == "no" || agregar == "NO" || agregar == "No" || agregar == "nO"){
                break;
            }
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "[!] ¡Error! Ingrese si o no" << endl;
                continue;
            }
        }
        //----------------------------------------------------------

        //EquipmentID
        string equipoIDAgregar;
        cout<<"Ingrese el ID del equipo: ";
        cin >> equipoIDAgregar;

        //Event
        string eventoSaludAgregar;
        cin.ignore(); // Limpia la entrada por si quedan caracteres pendientes
        while(1){
            cout<< "Ingrese el evento de salud: ";
            // Input de eventoSaludAgregar
            cin.ignore(); // Limpia la entrada por si quedan caracteres pendientes
            getline(cin, eventoSaludAgregar); // Toma lo que se ingrese como cin, incluso espacios

            // Validacion: Tipos de eventos
            if (eventoSaludAgregar == "Frame Torque Exceeded" || eventoSaludAgregar == "Negative High Peak Frame Bias" || eventoSaludAgregar == "Negative High Peak Frame Pitch" || eventoSaludAgregar == "Negative High Peak Frame Rack" || eventoSaludAgregar == "Positive High Peak Frame Bias" || eventoSaludAgregar == "Positive High Peak Frame Pitch" || eventoSaludAgregar == "Positive High Peak Frame Rack" || eventoSaludAgregar == "Sprung Weinght Exceeded" ){
                break;
            }
            else{
                cin.clear(); // Limpiar el indicador de error para que se pueda seguir leyendo
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
                cout<< "[!] ¡Error! Evento de salud invalido."<<endl;
            }
        }


        //FloatValue
        float valorRegistroAgregar;

        // Bucle hasta ingresar un float value valido
        while(1){

            cout<<"Ingrese el valor de registro: ";
            cin >> valorRegistroAgregar;

            // Error: letras o caracteres no validos

            if (cin.fail()) { // Detecta si se ingresa algo que no sea float

                // Eliminar entradas incorrectas que queden en el buffer para recibir nueva entrada:
                //-Despues del "cin" que entra en Estado de error, se reestablece el "cin" a la normalidad
                cin.clear(); // Limpiar el indicador de error para que se pueda seguir leyendo

                //-Limpiar la entrada para recibir nuevos datos "cin" :
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
                cout << "[!] ¡Error! Ingrese un numero valido." << endl;
            }

            // Error: Float Negativo o 0
            else if (valorRegistroAgregar <= 0) {
                cout << "[!] ¡Error! Valor de registro invalido." << endl;
            }

            // Respuesta valida
            else {
                // Entrada valida, puedes salir del bucle
                break;
            }
        }

        // Crear Evento en un NodoEvento
        Evento *nuevoEvento = new Evento(equipoIDAgregar, operadorIDAgregar, eventoSaludAgregar, valorRegistroAgregar);
        NodoEvento *nuevoNodo = new NodoEvento(*nuevoEvento);

        // Agregar Evento al Arbol MaxHeap de Eventos pendientes por atender
        this->MaxHeapEventos->agregar(*nuevoNodo);
    }
}


void Sistema::atenderEquipo() {

    if(this->cantidadEventos == 0){
        cout <<"No hay equipos que hayan registrado eventos de salud"<<endl;
        return;
    }

    this->MaxHeapEventos->eliminar();

}


void Sistema::reportabilidad() {

}


void Sistema::agregarOperador(int operadorID) {
    //- Operator ID
    // Se consulta previamente en la pregunta

    //- OperatorName
    string nombreOperadorAgregar;
    cout<< "Ingrese el nombre del operador: ";
    cin >> nombreOperadorAgregar;

    if(cin.fail()){
        cin.clear(); // Limpiar el indicador de error para que se pueda seguir leyendo
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
        cout<< "[!] ¡Error! Nombre de operador invalido"<<endl;
    }


    //- OperatorCity
    string ciudadOperadorAgregar;
    cout<< "Ingrese la ciudad de recidencia del operador: ";
    // Input de ciudadOperadorAgregar
    cin.ignore(); // Limpia la entrada por si quedan caracteres pendientes
    getline(cin, ciudadOperadorAgregar); // Toma lo que se ingrese como cin, incluso espacios

    if(cin.fail()){
        cin.clear(); // Limpiar el indicador de error para que se pueda seguir leyendo
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
        cout<< "[!] ¡Error! Ciudad de operador invalido"<<endl;
    }

    Operador *nuevoOperador = new Operador(operadorID, nombreOperadorAgregar, ciudadOperadorAgregar);
    NodoOperador *nuevoNodo = new NodoOperador(*nuevoOperador);

    //TODO: Agregar Operador a la listaOperadores
    //this->AVLOperadores->agregarRecursivo(operadorID, nuevoNodo);

}



void Sistema::guardarArchivoOperadores() {

    ofstream archivoSalida;

    archivoSalida.open("workers.csv");

    for (int i=1 ; i <= this->cantidadEventos; i++){
        // Jugar con los punteros * y podria funcionar
        string equipoID = MaxHeapEventos->getListaMax()[i].getEvento().getEquipoID();
        int operadorID = MaxHeapEventos->getListaMax()[i].getEvento().getOperadorID();
        string nombreEvento = MaxHeapEventos->getListaMax()[i].getEvento().getNombreEvento();
        float valorRegistro = MaxHeapEventos->getListaMax()[i].getEvento().getValorRegistro();

        archivoSalida << equipoID << "," << operadorID << "," << nombreEvento << "" << valorRegistro << ","  <<"\n";
    }
    archivoSalida.close();

    cout << "\nSe han guardado los cambios del archivo de lugares"<< endl;
/*
     //liberar memoria
    free(listaSalas);
    listaSalas = nullptr;
    */

}

void Sistema::guardarArchivoEventos() {
    ofstream archivoSalida;

    archivoSalida.open("minecare_events.csv");

    for (int i=1 ; i <= this->cantidadOperadores; i++){
        string equipoID;
        int operadorID;
        string nombreEvento;
        float valorRegistro;
        /*
        // Jugar con los punteros * y podria funcionar

        archivoSalida << equipoID << "," << operadorID << "," << nombreEvento << "" << valorRegistro << ","  <<"\n";
         */
    }
    archivoSalida.close();

    cout << "\nSe han guardado los cambios del archivo de lugares"<< endl;
}

void Sistema::guardarArchivoResumen() {}




void Sistema::leerArchivoOperadores() {

    ifstream archivo;
    archivo.open("workers.csv"); // Abrir CSV

    if(archivo.fail()){ // Error si no está
        cout<<"\n[!] No se pudo abrir el archivo\n"<< endl;
        exit(1);
    }

    // Crear Arbol Max Heap
    this->AVLOperadores = new AVL();



    // RECORRER ARCHIVO LINEA POR LINEA
    string linea;
    int contadorLinea = 0;

    while (getline(archivo, linea)) {
        int operadorID;
        string operadorIDString;
        string nombreOperador;
        string ciudadOperador;


        // Tomar la linea como Dato moldeable
        stringstream input_ss(linea);

        // Obtener de la Linea lo que hay entre "," como Strings
        getline(input_ss, operadorIDString , ','); // OperatorID en String
        operadorID = stoi(operadorIDString); // casteo a int -> OperatorID
        getline(input_ss, nombreOperador , ','); // OperatorName
        getline(input_ss, ciudadOperador , ','); // OperatorCity


        // Imprimir datos
        //contadorLinea++;
        //cout <<contadorLinea<<": ";
//
        //cout<<operadorID<<","; // OperatorID
        //cout<<nombreOperador<<","; // OperatorName
        //cout<<ciudadOperador<<","; // OperatorCity

        // Crear un nuevo Operador con los datos de la linea

        Operador* nuevoOperador = new Operador(operadorID, nombreOperador, ciudadOperador);

        //NodoOperador* nuevoNodo = new NodoOperador(*nuevoOperador);


        this->AVLOperadores->agregar(*nuevoOperador);
        this->cantidadOperadores++;

        cout<<nuevoOperador->getOperadorID()<<" "<<nuevoOperador->getNombreOperador()<<" "<<nuevoOperador->getCiudadOperador()<<endl;
    }
    archivo.close();
}


void Sistema::leerArchivoEventos() {

    ifstream archivo;
    archivo.open("minecare_events.csv"); // Abrir CSV

    if(archivo.fail()){ // Error si no está
        cout<<"\n[!] No se pudo abrir el archivo\n"<< endl;
        exit(1);
    }

    // Crear Arbol Max Heap
    this->MaxHeapEventos = new MaxHeap();

    // RECORRER ARCHIVO LINEA POR LINEA
    string linea;
    int contadorLinea = 0;

    while (getline(archivo, linea)) {
        string equipoID;
        string operadorIDString;
        int operadorID;
        string nombreEvento;
        float valorRegistro;


        // Tomar la linea como Dato moldeable
        stringstream input_ss(linea);

        //input_ss >> equipoID; // EquipmentID
        //input_ss.ignore(); //ignora la ,
        //input_ss >> operadorID; //OperatorID

        // Obtener de la Linea lo que hay entre "," como Strings
        getline(input_ss, equipoID , ','); // EquipmentID

        getline(input_ss, operadorIDString , ','); // OperatorID String
        operadorID = stoi(operadorIDString); // OperatorID

        getline(input_ss, nombreEvento , ','); // Event

        //Obtener el ultimo dato como float
        input_ss >> valorRegistro; // FloatValue

        // Imprimir datos
        contadorLinea++;
        cout <<contadorLinea<<": ";
        cout<<equipoID<<","; // EquipmentID
        cout<<operadorID<<","; // OperatorID
        cout<<nombreEvento<<","; // Event
        cout<<valorRegistro; // FloatValue
        cout<<""<<endl;

        // Crear un nuevo Evento con los datos de la linea y guardarlo en un Nodo
        Evento* nuevoEvento = new Evento(equipoID, operadorID, nombreEvento, valorRegistro);
        NodoEvento* nuevoNodo = new NodoEvento(*nuevoEvento);

        this->cantidadEventos++;

        // Agregar Valor FloatValue al Arbol
        //this->MaxHeapEventos->agregar(valorRegistro);
        this->MaxHeapEventos->agregar(*nuevoNodo);

        // Printear lista MaxHeap
        this->MaxHeapEventos->verValoresMaxHeap();

    }
    archivo.close();
}
