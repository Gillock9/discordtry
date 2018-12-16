///////////////////////////
// Recurso.cpp
///////////////////////////

#include "recurso.h"
#include <iostream>

/////////
//Constructor vacio
//////////
Recurso::Recurso()
{
    _codA="none";
}
///////////////
//Constructor parametrizado
//////////////
Recurso::Recurso(string codA, int estado, Profesor profesorR)
{
    _codA=codA;
 _estado=estado;
 _profesorR=profesorR;

}

///////////////
//Destructor
//////////////
Recurso::~Recurso(){
}

string Recurso::getCodA() const
{
        return _codA;
}

int Recurso::setCodA(string &codA)
{
    char repetir='N';
    int valido=0;
    do
    {
        valido=0;
        repetir='N';
        valido=Recurso::validarcodA(codA);
        if (valido==1)
        {
            _codA=codA;
        }
        else
        {
            cout<<"Codigo incorrecto. Desea volver a introducir el codigo? (S/N)"<<endl;
            cin>>repetir;
            if(repetir=='S')
            {
                cout<<"Vuelva a introducir codigo:"<<endl;
               cin>>codA;
            }
        }
    }while(repetir=='S');
return valido;
}
int Recurso::validarcodA(string codA)
{
    int longitud=codA.length();//Saca el valor de la longitud del codigo.
    int valor=0;
    const char *iden = new char[codA.length() + 1]; //Crea un puntero char de extension del codigo mas el que vamos a añadir.
    iden = codA.c_str();//incluye un /0 al final de la cadena.
    if (longitud!=7)
    {
        cout<<"Error el codigo introducido tiene una extension incorrecta."<<endl;
    }
        else
        {
              for(int i=0; i<=2; i++)
              {
                if ((iden[i]<65||iden[i]>90)&&(iden[i]<97||iden[i]>122)) //Comprueba los caracteres del codigo ascii.
                {
                    cout<<"Error, el caracter introducido "<<i+1<<" no es una letra."<<endl;
                    valor=0;
                }
                else
                {
                    for(i=3;i<=6;i++)
                    {
                        if(iden[i]<48||iden[i]>57)
                        {
                             cout<<"Error, el caracter introducido "<<i+1<<" no es un numero."<<endl;
                             valor=0;
                        }
                        else{
                        valor=1;
                        }
                    }
                }
              }
        }
    return valor;
}


int Recurso::getEstado() const
{
    return _estado;
}

void Recurso::setEstado(int value)
{
    _estado = value;
}
Profesor Recurso::getProfesorR() const
{
    return _profesorR;
}

void Recurso::setProfesorR(Profesor &profesorR)
{
    _profesorR = profesorR;
}
