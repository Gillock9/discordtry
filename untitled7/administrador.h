////////////////////////////////////////////////////
// Administrador.h
////////////////////////////////////////////////////
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>

using namespace std;


class Administrador
{
private:
        string _NIFA;
public:
    /** Constructor vacío
                */
    Administrador();
    /** Constructor parametrizado
                */
    Administrador(string nifa);
    /** Destructor
                */
    ~Administrador();
    Administrador & operator=( Administrador &P);
    void Display();
    string getNIFA() const ;
    int setNIFA(string &nifa);
    int validarNIFA(string nifa);
};

#endif // ADMINISTRADOR_H
