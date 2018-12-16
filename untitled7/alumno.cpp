///////////////////////////
// Alumno.cpp
///////////////////////////

#include "alumno.h"
#include <iostream>
using namespace std;
/////////
//Constructor vacio
//////////
int Alumno::setNIA(int NIA)
{
    int valido=0;
    char repetir='N';
    do
    {
        repetir='N';
        valido=Alumno::validarNIA(NIA);
        if (valido==1)
        {
            _NIA = NIA;
        }
        else
        {
            cout<<"NIA incorrecto. Desea volver a introducir el NIA? (S/N)"<<endl;
            cin>>repetir;
            if(repetir=='S')
            {
                cout<<"Vuelva a introducir NIA:"<<endl;
                cin>>NIA;
            }
        }
    }while(repetir=='S');
return valido;
}

int Alumno::getTitulacionS() const
{
    return _titulacionS;
}

void Alumno::setTitulacionS(int titulacionS)
{
    _titulacionS = titulacionS;
}

int Alumno::getApuntado() const
{
    return _apuntado;
}

void Alumno::setApuntado(int apuntado)
{
    _apuntado = apuntado;
}

Alumno::Alumno()
{
    _NIA=0;
    _apuntado=0;
}

///////////////
//Constructor parametrizado
//////////////

Alumno::Alumno(int NIA, int titulacionS) {
    _NIA=NIA;
    _titulacionS=titulacionS;
}

///////////////
//Destructor
//////////////
Alumno::~Alumno(){

}

Alumno &Alumno::operator=(Alumno &P)
{
    _NIA=P.getNIA();
    _titulacionS=P.getTitulacionS();
    _apuntado=P.getApuntado();
    return *this;

}

void Alumno::Display()
{
    cout<<" NIA: "<<_NIA<<endl;
    switch (_titulacionS)
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


int Alumno::validarNIA(int nia)
{
    int valor=0;
    if (nia<10000000 && nia>999999)
    {
        valor=1;
    }
        else
        {

                cout<<"Error el NIA introducido tiene una extension incorrecta."<<endl;


        }
    return valor;
}
