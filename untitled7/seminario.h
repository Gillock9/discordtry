////////////////////////////////////////////////////
// Seminario.h
////////////////////////////////////////////////////
#ifndef SEMINARIO_H
#define SEMINARIO_H

#include <iostream>
#include "alumno.h"
#include <recurso.h>
#include <iostream>

using namespace std;


class Seminario : public Recurso
{
private:
    string _ponente;
    Alumno *_listaAlumnosS;
    int _plazas;
    int _day;
    int _month;
    int _year;
    int _n_AlumnosS;



public:
    /** Constructor vacío
                */
    Seminario();
    /** Constructor parametrizado
                */
    Seminario(string ponente, int plazas, int day, int month, int year, string codA, int estado, Profesor profesorR);
    /** Destructor
                */
    ~Seminario();

    string getponente() const;
    void setPonente(const string &ponente);
    Alumno *getListaAlumnosS() const;
    void setListaAlumnosS(Alumno *listaAlumnosS);
    void setPlazas(int plazas);
    int getday() const;
    void setDay(int day);
    int getmonth() const;
    void setMonth(int month);
    int getyear() const;
    void setYear(int year);
    void Display();
    int getPlazas() const;
    int getn_AlumnosS() const;
    void setN_AlumnosS(int n_AlumnosS);

};

#endif // SEMINARIO_H
