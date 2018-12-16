////////////////////////////////////////////////////
// Alumno.h
////////////////////////////////////////////////////
#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>

using namespace std;


class Alumno
{
private:
    int _NIA;
    int _titulacionS;
    int _apuntado;
public:
    /** Constructor vacío
                */
    Alumno();
    /** Constructor parametrizado
                */
    Alumno(int NIA, int titulacionS);
    /** Destructor
                */
    ~Alumno();
    Alumno & operator=( Alumno &P);
void Display();
int validarNIA(int nia);
int getNIA(){return _NIA;}
int setNIA(int NIA);
int getTitulacionS() const;
void setTitulacionS(int titulacionS);
int getApuntado() const;
void setApuntado(int apuntado);
};

#endif // ADMINISTRADOR_H
