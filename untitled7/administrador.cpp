///////////////////////////
// Administrador.cpp
///////////////////////////

#include "administrador.h"
#include <iostream>
#include <string>
#include <fstream> //Libreria para flujos de entrada salida de archivos.
using namespace std;


string Administrador::getNIFA() const
{
    return _NIFA;
}

int Administrador::setNIFA(string &nifa)
{
    int valido=0;
    char repetir='N';
    do
    {
        repetir='N';
        valido=Administrador::validarNIFA(nifa);
        if (valido==1)
        {
            _NIFA = nifa;
        }
        else
        {
            cout<<"Desea volver a introducir el NIF? (S/N)"<<endl;
            cin>>repetir;
            if(repetir=='S')
            {
                cout<<"Vuelva a introducir NIF:"<<endl;
                valido=0;
                cin>>nifa;
            }
        }
    }while(repetir=='S');
return valido;

}

int Administrador::validarNIFA(string nifa)
{
    int longitud=0;
    longitud=nifa.length();//Saca el valor de la longitud del nif.
    int valor=0;
    int incorrect=0;
    const char *iden = new char[nifa.length()+1]; //Crea un puntero char de extension del NIF mas el que vamos a añadir.
    iden = nifa.c_str();//incluye un /0 al final de la cadena.
    if (longitud!=7)
    {
        cout<<"Error,el NIF introducido tiene una extension incorrecta.\n"<<endl;
    }
    else{
        for(int i=0; i<7 ; i++)
        {
                if ((iden[i]<65||iden[i]>90)&&(iden[i]<97||iden[i]>122)&&(iden[i]<48||iden[i]>57)) //Comprueba los caracteres en MAYUS del codigo ascii.
                {
                    cout<<"Error, el caracter introducido "<<i+1<<" esta en minuscula."<<endl;
                    incorrect=1;
                    valor=0;
                }
                else
                {
                    if (incorrect!=1) valor=1;
                }
        }
    }
    return valor;
}

/////////
//Constructor vacio
//////////

Administrador::Administrador()
{
    _NIFA="none";
}

///////////////
//Constructor parametrizado
//////////////

Administrador::Administrador(string nifa) {
    int valido=0;
    char repetir='N';
    do
    {
        repetir='N';
        valido=Administrador::validarNIFA(nifa);
        if (valido==1)
        {
            _NIFA = nifa;
        }
        else
        {
            cout<<"Desea volver a introducir el NIF? (S/N)"<<endl;
            cin>>repetir;
            if(repetir=='S')
            {
                cout<<"Vuelva a introducir NIF:"<<endl;
                cin>>nifa;
            }
        }
    }while(repetir=='S');
}

///////////////
//Destructor
//////////////
Administrador::~Administrador(){

}

Administrador &Administrador::operator=(Administrador &P)
{
   _NIFA=P.getNIFA();
   return *this;
}

void Administrador::Display()
{
    cout<<" NIF: "<<_NIFA<<endl;
}

