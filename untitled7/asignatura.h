////////////////////////////////////////////////////
// Asignatura.h
////////////////////////////////////////////////////
#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <iostream>
#include <recurso.h>
#include <profesor.h>
#include <alumno.h>
using namespace std;
class Asignatura : public Recurso
{   int _calificada;
    int _titulacionA;
    int _num_creditos;
    Profesor _profesor2;
    Alumno *_lista_alumnosA;
    float *_lista_calificaciones;
    int _n_alumnosA;
public:
    /** Constructor vacío
                */
    Asignatura();
    /** Constructor parametrizado
                */
    Asignatura(int titulacionA, int num_creditos, Profesor profesor2, string codA, int estado, Profesor profesorR);
    /** Destructor
                */
    ~Asignatura();



    int getNum_creditos() const;
    void setNum_creditos(int value);
    int getTitulacionA() const;
    void setTitulacionA(int value);
    Profesor getProfesor2() const;
    void setProfesor2(Profesor &value);
    Alumno *getLista_alumnosA() const;
    void setLista_alumnosA(Alumno *value);
    float *getLista_calificaciones() const;
    void setLista_calificaciones(float *value);
    void Display();
    int getN_alumnosA() const;
    void setN_alumnosA(int n_alumnosA);
    int getCalificada() const;
    void setCalificada(int calificada);
};

#endif // ASIGNATURA_H
