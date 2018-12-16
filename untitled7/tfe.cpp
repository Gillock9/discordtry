#include "tfe.h"
#include <iostream>
using namespace std;

int TFE::getTitulacionT() const
{
    return _titulacionT;
}

void TFE::setTitulacionT(int titulacionT)
{
    _titulacionT = titulacionT;
}

Profesor TFE::getCotutor() const
{
    return _Cotutor;
}

void TFE::setCotutor( Profesor &Cotutor)
{
    _Cotutor = Cotutor;
}

Alumno TFE::getAlumnoTFE() const
{
    return _AlumnoTFE;
}

void TFE::setAlumnoTFE(Alumno &AlumnoTFE)
{
    _AlumnoTFE = AlumnoTFE;
}

void TFE::Display()
{
    cout<<" con codigo ("<<_codA<<")"<<endl;
    cout<<"----Tipo TFE----"<<endl;
    cout<<"Estado: "<<_estado<<endl;
    cout<<"Tutor: "<<_profesorR.getNIFP()<<endl;
    cout<<"Cotutor: "<<_Cotutor.getNIFP()<<endl;
    switch (_titulacionT)
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
    if(_AlumnoTFE.getNIA()!=0){
    cout<<"Alumno: "<<_AlumnoTFE.getNIA()<<endl;
    }
    else cout<<"No hay ningun alumno apuntado en el TFE."<<endl;
}

int TFE::getAdjudicado() const
{
    return _adjudicado;
}

void TFE::setAdjudicado(int adjudicado)
{
    _adjudicado = adjudicado;
}

TFE::TFE()
{
    _adjudicado=0;
}

TFE::TFE(int titulacionT, Profesor Cotutor, string codA, int estado, Profesor profesorR): Recurso (codA,estado,profesorR)
{
    _titulacionT=titulacionT;
    _Cotutor=Cotutor;

}
TFE::~TFE()
{

}


