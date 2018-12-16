

#ifndef TFE_H
#define TFE_H

#include <iostream>
#include "profesor.h"
#include "alumno.h"
#include <recurso.h>
class TFE : public Recurso
{
private:
    int _titulacionT;
    Profesor _Cotutor;
    Alumno _AlumnoTFE;
    int _adjudicado;
public:
    TFE();
    TFE(int titulacionT, Profesor Cotutor, string codA, int estado, Profesor profesorR);
    ~TFE();

    int getTitulacionT() const;
    void setTitulacionT(int titulacionT);
    Profesor getCotutor() const;
    void setCotutor(Profesor &Cotutor);
    Alumno getAlumnoTFE() const;
    void setAlumnoTFE(Alumno &AlumnoTFE);
    void Display();
    int getAdjudicado() const;
    void setAdjudicado(int adjudicado);
};

#endif // TFE_H
