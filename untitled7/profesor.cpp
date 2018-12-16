//////////////////////////
// Profesor.cpp
///////////////////////////

#include "profesor.h"
#include <iostream>
using namespace std;

string Profesor::getNIFP() const
{
    return _NIFP;
}

int Profesor::setNIFP(string &NIFP)
{
    char repetir='N';
    int valido=0;
    do
    {
        valido=0;
        repetir='N';
        valido=Profesor::validarNIFP(NIFP);
        if (valido==1)
        {
            _NIFP = NIFP;
        }
        else
        {
            cout<<"NIF incorrecto. Desea volver a introducir el NIF? (S/N)"<<endl;
            cin>>repetir;
            if(repetir=='S')
            {
                cout<<"Vuelva a introducir NIF:"<<endl;
               cin>>NIFP;
            }
        }
    }while(repetir=='S');
return valido;
}
/////////
//Constructor vacio
//////////
Profesor::Profesor()
{
    _NIFP="------";
}

///////////////
//Constructor parametrizado
//////////////

Profesor::Profesor(string NIFP) {
    _NIFP=NIFP;
}

///////////////
//Destructor
//////////////
Profesor::~Profesor(){

}

Profesor &Profesor::operator=(Profesor &P)
{
    _NIFP=P.getNIFP();
    return *this;
}

int Profesor::validarNIFP(string nifp)
{

    int longitud=nifp.length();//Saca el valor de la longitud del nif.
    int valor=0;
    int incorrect=0;
    const char *iden = new char[nifp.length() + 1]; //Crea un puntero char de extension del NIF mas el que vamos a añadir.
    iden = nifp.c_str();//incluye un /0 al final de la cadena.
    if (longitud!=7)
    {
        cout<<"Error el NIF introducido tiene una extension incorrecta."<<endl;
    }
        else
        {
              for(int i=0; i<=6; i++)
              {
                if ((iden[i]<65||iden[i]>90)&&(iden[i]<97||iden[i]>122)&&(iden[i]<48||iden[i]>57)) //Comprueba los caracteres en MAYUS del codigo ascii.
                {
                    cout<<"Error, el caracter introducido "<<i+1<<" esta en minuscula."<<endl;
                    valor=0;
                    incorrect=1;
                }
                else
                {
                    if (incorrect!=1)valor=1;
                }
              }
        }
    return valor;




}

void Profesor::Display()
{
    cout<<" NIF: "<<_NIFP<<endl;
}
