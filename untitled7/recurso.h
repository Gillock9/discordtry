#ifndef RECURSO_H
#define RECURSO_H
#include <iostream>
#include <profesor.h>
using namespace std;

class Recurso
{
protected:
string _codA;
int _estado;
Profesor _profesorR;
public:
    /** Constructor vacío
                */

    Recurso();
    /** Constructor parametrizado
                */
    Recurso(string codA,int estado, Profesor profesorR);
    /** Destructor
                */
    ~Recurso();

    string getCodA() const;
    int setCodA(string &codA);
    int getEstado() const;
    void setEstado(int value);
    Profesor getProfesorR() const;
    void setProfesorR( Profesor &profesorR);
    int validarcodA(string codA);
    virtual void Display(){}
};

#endif // RECURSO_H
