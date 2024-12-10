
#ifndef TALLER_3_EVENTO_H
#define TALLER_3_EVENTO_H

#include <string>
using namespace std;


class Evento {
private:
    string equipoID;
    int operadorID;
    string nombreEvento;
    float valorRegistro;

public:
    /**
     * Constructor vacio de la clase
     */
    Evento();

    /**
     * Constructor para Eventos que contengan todos los datos de este  //TODO TERMINAR DE DOCUMENTAR
     * @param identificadorEquipo
     * @param identificadorOperador
     * @param nombreEvento
     * @param valorRegistro
     */
    Evento(string equipoID, int operadorID, string nombreEvento, float valorRegistro);


    string getEquipoID();
    int getOperadorID();
    string getNombreEvento();
    float getValorRegistro();


    void setEquipoID(string equipoID);
    void setOperadorID(int operadorID);
    void setNombreEvento(string nombreEvento);
    void setValorRegistro(float valorRegistro);
};


#endif //TALLER_3_EVENTO_H
