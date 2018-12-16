#include "seminario.h"
#include <iostream>

string Seminario::getponente() const
{
    return _ponente;
}

void Seminario::setPonente(const string &ponente)
{
    _ponente = ponente;
}


void Seminario::setListaAlumnosS(Alumno *listaAlumnosS)
{
    _listaAlumnosS = listaAlumnosS;
}



void Seminario::setPlazas(int plazas)
{
    _plazas = plazas;
}

int Seminario::getday() const
{
    return _day;
}

void Seminario::setDay(int day)
{
    _day = day;
}

int Seminario::getmonth() const
{
    return _month;
}

void Seminario::setMonth(int month)
{
    _month = month;
}

int Seminario::getyear() const
{
    return _year;
}

void Seminario::setYear(int year)
{
    _year = year;
}

void Seminario::Display()
{
    cout<<" con codigo ("<<_codA<<")"<<endl;
    cout<<"----Tipo Seminario----"<<endl;
    cout<<"Estado: "<<_estado<<endl;
    cout<<"Profesor: "<<_profesorR.getNIFP()<<endl;
    cout<<"Ponente: "<<_ponente<<endl;
    cout<<"Capacidad maxima: "<<_plazas<<endl;
    cout<<"Fecha-> Dia: "<<_day<<endl;
    cout<<"\tMes: "<<_month<<endl;
    cout<<"\tAño: "<<_year<<endl;
    if(_n_AlumnosS>0)
    {
        for(int i=0;i<_n_AlumnosS;i++)
        {
        cout<<"Alumno" <<i+1<<":"<<_listaAlumnosS[i].getNIA()<<endl;
        }
    }
    if(_n_AlumnosS==0) cout<<"No hay alumnos apuntados a esta asignatura"<<endl;
}

int Seminario::getPlazas() const
{
    return _plazas;
}

int Seminario::getn_AlumnosS() const
{
    return _n_AlumnosS;
}

void Seminario::setN_AlumnosS(int n_AlumnosS)
{
    _n_AlumnosS = n_AlumnosS;
}

Alumno *Seminario::getListaAlumnosS() const
{
    return _listaAlumnosS;
}

Seminario::Seminario()
{
    _n_AlumnosS=0;
}
Seminario::Seminario(string ponente, int plazas, int day, int month, int year, string codA, int estado, Profesor profesorR): Recurso(codA,estado,profesorR)
{
    _ponente=ponente;
    _plazas=plazas;
    _day=day;
    _month=month;
    _year=year;
}

Seminario::~Seminario()
{
    delete []_listaAlumnosS;
}


