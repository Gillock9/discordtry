///////////////////////////
// Asignatura.cpp
///////////////////////////

#include "asignatura.h"
#include <iostream>

/////////
//Constructor vacio
//////////

int Asignatura::getTitulacionA() const
{
    return _titulacionA;
}

void Asignatura::setTitulacionA(int value)
{
    _titulacionA = value;
}

Profesor Asignatura::getProfesor2() const
{
    return _profesor2;
}

void Asignatura::setProfesor2( Profesor &value)
{
    _profesor2 = value;
}

Alumno *Asignatura::getLista_alumnosA() const
{
    return _lista_alumnosA;
}

void Asignatura::setLista_alumnosA(Alumno *value)
{
    _lista_alumnosA = value;
}

float *Asignatura::getLista_calificaciones() const
{
    return _lista_calificaciones;
}

void Asignatura::setLista_calificaciones(float *value)
{
    _lista_calificaciones = value;
}

void Asignatura::Display()
{
    cout<<" con codigo ("<<_codA<<")"<<endl;
    cout<<"----Tipo Asignatura----"<<endl;
    cout<<"Estado: "<<_estado<<endl;
    cout<<"Profesor principal: "<<_profesorR.getNIFP()<<endl;
    cout<<"Profesor adjunto: "<<_profesor2.getNIFP()<<endl;
    cout<<"Numero de creditos: "<<_num_creditos<<endl;
    if(_n_alumnosA>0)
    {
        for(int i=0;i<_n_alumnosA;i++)
        {
        cout<<"Alumno" <<i+1<<":"<<_lista_alumnosA[i].getNIA()<<endl;
        }
    }
    else cout<<"No hay alumnos apuntados a esta asignatura"<<endl;

    switch (_titulacionA)
    {
        case 1:
                cout<<"Titulacion: Industriales"<<endl;
        break;
        case 2:
            cout<<"Titulacion: Mecanica"<<endl;
        break;
        case 3:
            cout<<"Titulacion: Electronica"<<endl;
        break;
    }
}

int Asignatura::getN_alumnosA() const
{
    return _n_alumnosA;
}

void Asignatura::setN_alumnosA(int n_alumnosA)
{
    _n_alumnosA = n_alumnosA;
}

int Asignatura::getCalificada() const
{
    return _calificada;
}

void Asignatura::setCalificada(int calificada)
{
    _calificada = calificada;
}

Asignatura::Asignatura()
{
    _n_alumnosA=0;
    _calificada=0;
}

///////////////
//Constructor parametrizado
//////////////
Asignatura::Asignatura(int titulacionA, int num_creditos, Profesor profesor2,string codA, int estado, Profesor profesorR) :Recurso (codA,estado,profesorR)
{
_titulacionA=titulacionA;
_num_creditos=num_creditos;
_profesor2=profesor2;

}

///////////////
//Destructor
//////////////
Asignatura::~Asignatura()
{
    delete []_lista_alumnosA;
    delete []_lista_calificaciones;
}




int Asignatura::getNum_creditos() const
{
    return _num_creditos;
}

void Asignatura::setNum_creditos(int value)
{
    _num_creditos = value;
}

