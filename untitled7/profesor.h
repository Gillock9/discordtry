////////////////////////////////////////////////////
// Profesor.h
////////////////////////////////////////////////////
#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>

using namespace std;


class Profesor
{
private:
    string _NIFP;
public:
    /** Constructor vacío
                */
    Profesor();
    /** Constructor parametrizado
                */
    Profesor(string NIFP);
    /** Destructor
                */
    ~Profesor();
    Profesor & operator=( Profesor &P);
    int validarNIFP(string nifp);
    void Display();
    string getNIFP() const;
    int setNIFP(string &NIFP);
};

#endif // PROFESOR_H
