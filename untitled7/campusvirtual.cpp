#include <campusvirtual.h>
#include <asignatura.h>
#include <seminario.h>
#include <tfe.h>
#include <typeinfo>
#include <cstdlib> //Libreria para tamaños y ubicacion de memoria.
#include <iostream>
using namespace std;
CampusVirtual::CampusVirtual()
{
}

CampusVirtual::~CampusVirtual()
{
    delete []lista_admins;
    delete []lista_alumnos;
    delete []lista_profesores;
}

Administrador *CampusVirtual::getLista_admins() const
{
    return lista_admins;
}

void CampusVirtual::setLista_admins(Administrador *value)
{
    lista_admins = value;
}

Profesor *CampusVirtual::getLista_profesores() const
{
    return lista_profesores;
}

void CampusVirtual::setLista_profesores(Profesor *value)
{
    lista_profesores = value;
}

Alumno *CampusVirtual::getLista_alumnos() const
{
    return lista_alumnos;
}

void CampusVirtual::setLista_alumnos(Alumno *value)
{
    lista_alumnos = value;
}

vector<Recurso *> CampusVirtual::getLista_recursos() const
{
    return lista_recursos;
}

void CampusVirtual::setLista_recursos(const vector<Recurso *> &value)
{
    lista_recursos = value;
}

int CampusVirtual::getNr() const
{
    return nr;
}

void CampusVirtual::setNr(int value)
{
    nr = value;
}

void CampusVirtual::alta_admin()
{
    string nifa;
    int ok=0,igual=0;
    Administrador aux;
    cout<<"Introduzca el NIF: "<<endl;
    getline(cin,nifa);
    for(int i=0;i<nad;i++)
                        {
                            if(nifa==lista_admins[i].getNIFA())
                            {
                                igual=1;//El NIF ya ha sido registrado antes
                                cout<<"Este NIF ya estaba dado de alta."<<endl;
                            }
                        }
        if(igual==0)
                        {
                            ok=aux.setNIFA(nifa);
                            if(ok==1)
                            {
                                Administrador *auxad= new Administrador[nad+1];//(std::nothrow)
                                for(int i=0;i<nad;i++)
                                {
                                    auxad[i]=lista_admins[i];
                                }
                                auxad[nad].setNIFA(nifa);
                                lista_admins= auxad;
                                cout<<"El administrador ha sido dado de alta."<<endl;
                                //n++;
                                nad++;
                            }
                        }
}

void CampusVirtual::baja_admin()
{
        if(nad>1){
                            string nifa;
                            int encontrado=0;
                            cout<<"Introduzca el NIF del administrador que desea eliminar: "<<endl;
                            cin>>nifa;
                            Administrador *auxad= new Administrador[nad-1];
                            for(int i=0;i<nad;i++)
                            {
                                if(encontrado==0)
                                {
                                    if(nifa==lista_admins[i].getNIFA())
                                    {
                                        encontrado=1;
                                        cout<<"El administrador ha sido eliminado."<<endl;
                                    }
                                    else
                                    {
                                        auxad[i]=lista_admins[i];
                                    }
                                }
                                else
                                {
                                    auxad[i-1]=lista_admins[i];
                                }
                            }
                            if (encontrado==1)
                                            {
                                                //n--;
                                                nad--;
                                                cout<<"Queda(n): "<<nad<<" Administrador(es)"<<endl;
                                                lista_admins=auxad;
                                            }
                            else cout<<"No existe tal administrador."<<endl;

                }
        else cout<<"Solo quedas tu como administrador, no puedes borrarte."<<endl;
}

void CampusVirtual::mostrar_admin()
{
    for(int i=0;i<nad;i++)
    {
        cout<<"---------------------------------------"<<endl;
        cout <<"Administrador "<< i+1;
        lista_admins[i].Display();
        cout<<"---------------------------------------"<<endl;
    }
}

void CampusVirtual::modif_admin()
{
                    int igual=0,ok=0,D=0;
                    string nifa,newnifa;
                    Administrador aux;
                    cout<<"Introduzca el NIF del administrador que quiere modificar: "<<endl;
                    cin>>nifa;
                    for(int i=0;i<nad;i++)
                    {
                        if(lista_admins[i].getNIFA()==nifa)
                        {
                                D=1;
                                cout<<"Introduzca el nuevo NIF"<< endl;
                                cin>>newnifa;
                                ok=aux.setNIFA(newnifa);
                                if(ok==1)
                                {
                                for(int j=0;j<nad;j++)
                                {
                                    if(newnifa==lista_admins[j].getNIFA())
                                    {
                                        igual=1;//El NIF ya ha sido registrado antes
                                        cout<<"Este NIF ya estaba dado de alta."<<endl;
                                    }
                                }
                                if(igual==0)
                                {

                                    lista_admins[i].setNIFA(newnifa);
                                }
                                }
                        }
                        else if(D!=1) cout<<"El NIF introducido no se encuentra registrado."<<endl;
                    }
}
void CampusVirtual::alta_profesor()
{
                       string nifp;
                       int ok=0,igual=0;
                       Profesor aux;
                       cout<<"Introduzca el NIF: "<<endl;
                       getline(cin,nifp);
                       for(int i=0;i<np;i++)
                       {
                       if(nifp==lista_profesores[i].getNIFP())
                           {
                              igual=1;//El NIF ya ha sido registrado antes
                              cout<<"Este NIF ya estaba dado de alta."<<endl;
                           }
                        }
                        if(igual==0)
                           {
                               ok=aux.setNIFP(nifp);
                               if(ok==1)
                                  {
                                      Profesor *auxpr= new Profesor[np+1];//(std::nothrow)
                                      for(int i=0;i<np;i++)
                                         {
                                              auxpr[i]=lista_profesores[i];
                                         }
                                       auxpr[np].setNIFP(nifp);
                                       lista_profesores= auxpr;
                                       cout<<"El profesor ha sido dado de alta."<<endl;
                                       //n++;
                                       np++;
                                    }
                            }
}

void CampusVirtual::baja_profesor()
{
    if(np>0)
    {
                        string nifp;
                        int encontrado=0;
                        cout<<"Introduzca el NIF del profesor que desea eliminar: "<<endl;
                        cin>>nifp;
                        Profesor *auxpr= new Profesor[np-1];
                        for(int i=0;i<np;i++)
                        {
                            if(encontrado==0)
                            {
                                if(nifp==lista_profesores[i].getNIFP())
                                {
                                    encontrado=1;
                                    cout<<"El profesor ha sido eliminado."<<endl;
                                }
                                else
                                {
                                    auxpr[i]=lista_profesores[i];
                                }
                            }
                            else
                            {
                                auxpr[i-1]=lista_profesores[i];
                            }
                        }
                        if (encontrado==1)
                                        {
                                            //n--;
                                            np--;
                                            cout<<"Queda(n): "<<np<<" Profesor(es)"<<endl;
                                            lista_profesores=auxpr;
                                        }
                        else cout<<"No existe tal profesor."<<endl;

                }
    else cout<<"No hay profesores registrados en el sistema."<<endl;
}

void CampusVirtual::mostrar_profesor()
{
    if(np>=1)
    {
    for(int i=0;i<np;i++)
    {
        cout<<"---------------------------------------"<<endl;
        cout <<"Profesor "<< i+1;
        lista_profesores[i].Display();
        cout<<"---------------------------------------"<<endl;
    }
    }
    else cout<<"No existen profesores registrados en el sistema."<<endl;
}

void CampusVirtual::modif_profesor()
{
    int igual=0,ok=0,D=0;
    Profesor aux;
    string nifp,newnifp;
    cout<<"Introduzca el NIF del profesor que quiere modificar: "<<endl;
    cin>>nifp;
    for(int i=0;i<np;i++)
    {
        if(lista_profesores[i].getNIFP()==nifp)
        {
                D=1;
                cout<<"Introduzca el nuevo NIF"<< endl;
                cin>>newnifp;
                ok=aux.setNIFP(newnifp);
                if(ok==1)
                {
                for(int j=0;j<np;j++)
                {
                    if(newnifp==lista_profesores[j].getNIFP())
                    {
                        igual=1;//El NIF ya ha sido registrado antes
                        cout<<"Este NIF ya estaba dado de alta."<<endl;
                    }
                }
                if(igual==0)
                {

                    lista_profesores[i].setNIFP(newnifp);
                }
                }
        }
        else if(D!=1) cout<<"El NIF introducido no se encuentra registrado."<<endl;
    }
}

void CampusVirtual::alta_alumno()
{
    int nia;
    int titulacion;
    int ok=0;
    int igual=0;
    Alumno aux;
    cout<<"Introduzca el NIA del alumno: "<<endl;
    cin>>nia;
    cin.ignore(256,'\n');
    for(int i=0;i<nal;i++)
                    {
                        if(nia==lista_alumnos[i].getNIA())
                        {
                            igual=1;//El NIA ya ha sido registrado antes
                            cout<<"Este NIA ya estaba dado de alta."<<endl;
                        }
                    }
    if(igual==0)
                    {
                        ok=aux.setNIA(nia);
                        if(ok==1)
                        {
                            Alumno *auxal= new Alumno[nal+1];//(std::nothrow)
                            for(int i=0;i<nal;i++)
                            {
                                auxal[i]=lista_alumnos[i];
                            }
                            auxal[nal].setNIA(nia);
                            int valor=0;
                            do{
                            cout<<"---------------------------------------"<<endl;
                            cout<<"Introduzca la titulacion del alumno: "<<endl;
                            cout<<"Industriales: -1- "<<endl;
                            cout<<"Mecanica: -2-"<<endl;
                            cout<<"Electronica: -3-"<<endl;
                            cout<<"---------------------------------------"<<endl;
                            cin>>titulacion;
                            cin.ignore(256,'\n');
                            if(titulacion==1 ||titulacion==2||titulacion==3)
                            {
                                auxal[nal].setTitulacionS(titulacion);
                                lista_alumnos= auxal;
                                cout<<"El alumno ha sido dado de alta."<<endl;
                                //n++;
                                nal++;
                                valor=1;
                            }
                            else
                            {
                             cout<<"Valor incorrecto."<<endl;
                             valor=0;
                            }
                            }while (valor==0);

                            }
                        }
}

void CampusVirtual::baja_alumno()
{
    if(nal>0){
                        int nia;
                        int encontrado=0;
                        cout<<"Introduzca el NIA del alumno que desea eliminar: "<<endl;
                        cin>>nia;
                        Alumno *auxal= new Alumno[nal-1];
                        for(int i=0;i<nal;i++)
                        {
                            if(encontrado==0)
                            {
                                if(nia==lista_alumnos[i].getNIA())
                                {
                                    encontrado=1;
                                    cout<<"El alumno ha sido eliminado."<<endl;
                                }
                                else
                                {
                                    auxal[i]=lista_alumnos[i];
                                }
                            }
                            else
                            {
                                auxal[i-1]=lista_alumnos[i];
                            }
                        }
                        if (encontrado==1)
                                        {
                                            //n--;
                                            nal--;
                                            cout<<"Queda(n): "<<nal<<" Alumno(s)"<<endl;
                                        lista_alumnos=auxal;
                                        }
                        else cout<<"No existe tal alumno."<<endl;

            }
    else cout<<"No hay alumnos registrados en el sistema."<<endl;
}

void CampusVirtual::mostrar_alumno()
{
    if(nal>=1)
    {
    for(int i=0;i<nal;i++)
    {
        cout<<"Alumno "<< i+1;
        lista_alumnos[i].Display();
    }
    }
    else cout<<"No existen alumnos registrados en el sistema."<<endl;
}

void CampusVirtual::modif_alumno()
{
    int mod=0,igual=0,titulacion=0,ok=0,D=0,T=0;
    int nia,newnia;
    Alumno aux;
    do{
    cout<<"---------------------------------------"<<endl;
    cout<<"Indique la operacion que quiere realizar: \n1.Modificar NIA\n2.Modificar titulacion \n3.Salir"<<endl;
    cout<<"---------------------------------------"<<endl;
    cin>>mod;
    if (mod==1)
    {
    cout<<"Introduzca el NIA del alumno que quiere modificar: "<<endl;
    cin>>nia;
    for(int i=0;i<nal;i++)
    {
                        if(lista_alumnos[i].getNIA()==nia)
                        {
                                D=1;
                                cout<<"Introduzca el nuevo NIA"<< endl;
                                cin>>newnia;
                                ok=aux.setNIA(newnia);
                                if (ok==1)
                                {
                                    for(int j=0;j<nal;j++)
                                    {
                                        if(newnia==lista_alumnos[j].getNIA())
                                        {
                                            igual=1;//El NIA ya ha sido registrado antes
                                            cout<<"Este NIA ya estaba dado de alta"<<endl;
                                        }
                                    }
                                    if(igual==0)
                                    {

                                        lista_alumnos[i].setNIA(newnia);
                                    }
                                }
                         }
                        else if(D!=1) cout<<"El NIA introducido no se encuentra registrado."<<endl;
      }
   }
                        else if(mod==2)
                        {
                            int valor=0;
                            do
                            {
                            cout<<"---------------------------------------"<<endl;
                            cout<<"Introduzca la nueva titulacion del alumno: "<<endl;
                            cout<<"Industriales: -1- "<<endl;
                            cout<<"Mecanica: -2-"<<endl;
                            cout<<"Electronica: -3-"<<endl;
                            cout<<"---------------------------------------"<<endl;
                            cin>>titulacion;
                            for(int i=0;i<nal;i++)
                            {
                            if(titulacion==1 ||titulacion==2||titulacion==3)
                            {
                            lista_alumnos[i].setTitulacionS(titulacion);
                            valor=1;
                            }
                            else
                            {
                                cout<<"Valor incorrecto."<<endl;
                                valor=0;
                            }
                            }
                            }while (valor==0);

                        }
                        else if(mod==3){
                        T=1;}
                        else cout<<"Opcion incorrecta."<<endl;
    }while(T!=1);
}

void CampusVirtual::alta_recurso()
{
    string codA="";
    string nifprofesorRas="";
    Profesor profesorRas,aux1;
    Recurso aux;
    int ok=0,ok1=0;
    int estadoas=0;
    int igual=0;
    int select=0;

                    cout<<"Introduzca el codigo del nuevo recurso:"<<endl;
                    getline(cin,codA);
                    for(int i=0;i<nr;i++)
                    {
                    if(codA==lista_recursos[i]->getCodA())
                    {
                        igual=1;
                    }
                    }
                    if(igual==0)
                    {
                        ok=aux.setCodA(codA);
                        if(ok==1)
                        {
                        cout <<"Introduzca el NIF del profesor principal: "<< endl;
                        getline(cin,nifprofesorRas);
                        ok1=aux1.setNIFP(nifprofesorRas);
                        if(ok1==1)
                        {
                        int C=0;
                        for(int j=0;j<np;j++)
                        {
                            if(nifprofesorRas==lista_profesores[j].getNIFP())
                            {
                                C=1;
                                profesorRas.setNIFP(nifprofesorRas);
                                cout<<"---------------------------------------"<<endl;
                                cout<<"Introduzca el estado del recurso:\n 1.Creado\n 2.Iniciado\n 3.Finalizado "<<endl;
                                cout<<"---------------------------------------"<<endl;
                                cin>>estadoas;

                                if(estadoas>0 && estadoas<4)
                                {
                                    select=0;
                                    cout<<"---------------------------------------"<<endl;
                                    cout<<"Introduzca que tipo de recurso quiere crear:\n 1.Asignatura\n 2.Seminario\n 3.TFE "<<endl;
                                    cout<<"---------------------------------------"<<endl;
                                    cin>>select;
                                    switch(select)
                                    {
                                    case 1:
                                    {int titulacionas=0;
                                        int num_creditosas=0;
                                        string nifprofesor2as;
                                        Profesor profesor2as;
                                        cout<<"---------------------------------------"<<endl;
                                        cout<<"Introduzca la titulacion a la que pertenece la asignatura: \n1.Industriales \n2.Mecanica \n3.Electronica"<<endl;
                                        cout<<"---------------------------------------"<<endl;
                                        cin>>titulacionas;
                                        if(titulacionas>0 && titulacionas<4)
                                        {
                                            cout<<"Introduzca el numero de creditos de la asignatura:"<<endl;
                                            cin>>num_creditosas;
                                            cout<<"Introduzca el NIF del otro profesor de la asignatura:"<<endl;
                                            cin.ignore(256,'\n');
                                            getline(cin,nifprofesor2as);
                                            if(nifprofesor2as.compare(nifprofesorRas)!=0)
                                            {
                                            int B=0;
                                            for(int i=0;i<np;i++)
                                            {
                                            if(nifprofesor2as==lista_profesores[i].getNIFP())
                                            {
                                                B=1;
                                                profesor2as.setNIFP(nifprofesor2as);
                                                Asignatura *aus=new Asignatura(titulacionas, num_creditosas, profesor2as,codA,estadoas,profesorRas);
                                                lista_recursos.push_back(aus); //Añade un recurso aus del tipo asignatura al final de la lista de recursos
                                                nr++;
                                                cout<<"La asignatura ha sido dada de alta."<<endl;
                                            }
                                            }
                                            if(B!=1) cout <<"NIF del segundo profesor invalido."<<endl;
                                        }else cout<<"El profesor introducido ya se encuentra registrado en esta asignatura."<<endl;
                                        }
                                        else cout<<"Titulacion invalida."<<endl;
                                        break;}
                                    case 2:
                                    {int plazas=0;
                                        string ponente;
                                        int dia=0;
                                        int mes=0;
                                        int ano=0;
                                        cout<<"Introduzca el numero maximo de plazas del seminario:"<<endl;
                                        cin>>plazas;
                                        cout<<"Introduzca el nombre del ponente del seminario:"<<endl;
                                        cin>>ponente;
                                        cout<<"---------------------------------------"<<endl;
                                        cout<<"Introduzca la fecha del seminario: "<<endl;
                                        cout<<"Año -> ";
                                        cin>>ano;
                                        cout<<endl<<"Mes -> ";
                                        cin>>mes;
                                        cout<<endl<<"Dia -> ";
                                        cin>>dia;
                                        cout<<"---------------------------------------"<<endl;
                                        cin.ignore(256,'\n');
                                        Seminario *aus=new Seminario(ponente,plazas,dia,mes,ano,codA,estadoas,profesorRas);
                                        lista_recursos.push_back(aus);//Añade un recurso aus del tipo seminario al final de la lista de recursos
                                        nr++;
                                        cout<<"El seminario ha sido dado de alta."<<endl;
                                        break;}
                                      case 3:
                                       { int titulaciontfe=0;
                                        Profesor cotutor;
                                        string nifcotutor;
                                        cout<<"---------------------------------------"<<endl;
                                        cout<<"Introduzca la titulacion a la que pertenece el TFE:\n1.Industriales \n2.Mecanica \n3.Electronica"<<endl;
                                        cout<<"---------------------------------------"<<endl;
                                        cin>>titulaciontfe;
                                        if(titulaciontfe>0 && titulaciontfe<4)
                                        {
                                            cout<<"---------------------------------------"<<endl;
                                            cout<<"Desea introducir un cotutor al TFE? \n1.SI \n2.NO"<<endl;
                                            cout<<"---------------------------------------"<<endl;
                                            int A=0;
                                            cin>>A;
                                            cin.ignore(256,'\n');
                                            if(A==1)
                                            {
                                            cout<<"Introduzca el NIF del cotutor del TFE:"<<endl;
                                            getline(cin,nifcotutor);
                                            cin.ignore(256,'\n');
                                            if (nifcotutor.compare(nifprofesorRas)!=0)
                                            {
                                            int L=0;
                                            for(int i=0;i<np;i++)
                                            {
                                            if(nifcotutor==lista_profesores[i].getNIFP())
                                            {
                                                L=1;
                                                cotutor.setNIFP(nifcotutor);
                                                TFE *aus=new TFE(titulaciontfe,cotutor,codA,estadoas,profesorRas);
                                                lista_recursos.push_back(aus); //Añade un recurso aus del tipo TFE al final de la lista de recursos
                                                nr++;
                                            }
                                            }
                                            if(L!=1) cout <<"NIF del segundo tutor introducido invalido."<<endl;
                                            }else cout<<"El profesor introducido ya esta registrado en este TFE."<<endl;
                                            }else if(A==2)
                                            {
                                                TFE *aus=new TFE(titulaciontfe,cotutor,codA,estadoas,profesorRas);
                                                lista_recursos.push_back(aus);
                                                nr++;
                                            }
                                            else cout<<"Opcion incorrecta."<<endl;
                                        }
                                        else cout<<"Titulación invalida."<<endl;
                                        break;}
                                    default:
                                    {cout<<"Opcion invalida."<<endl;
                                        break;}
                                    }

                                }else cout<<"El valor del estado introducido es incorrecto."<<endl;

                               }else if(C!=1) cout<<"El NIF del profesor introducido no existe.  "<<endl;
                           }
                        }
                        }else cout<<"El codigo del recurso introducido es incorrecto."<<endl;
                    }else cout<<"El codigo del recurso introducido ya existe."<<endl;
}

void CampusVirtual::baja_recurso()
{
    if(nr>0)
    {
        string codA;
        int D=0;
        cout<<"Introduzca el codigo del recurso que desea eliminar: "<<endl;
        cin>>codA;
        for(int i=0;i<nr;i++)
        {
            if(codA==lista_recursos[i]->getCodA())
            {
                lista_recursos.erase(lista_recursos.begin()+i);//elimina el recurso de la lista de recursos de el principio de la lista +i
                nr--;
                D=1;
                cout<<"El recurso ha sido eliminado."<<endl;
            }
        }
    if(D==0) cout<<"El recurso no ha sido encontrado. "<<endl;
    }
    else cout<<"No existe ningun recurso."<<endl;
}

void CampusVirtual::mostrar_recurso()
{
    if(nr==0)
    {
        cout<<"No existe ningun recurso aun."<<endl;
    }
    else
    {
        for(int i=0;i<nr;i++)
        {
            cout<<"---------------------------------------"<<endl;
            cout<<"Recurso "<< i+1;
            lista_recursos[i]->Display();
            cout<<"---------------------------------------"<<endl;
        }
    }
}

void CampusVirtual::modif_recurso_admin()
{
   string codA="";
   string nifprofesorRas="";
   Profesor profesorRas,aux1;
   Recurso aux;
   int ok=0,ok1=0;
   int estadoas=0;
   int igual=0;
   string clase;
   int T=0, select=0;

                   cout<<"Introduzca el codigo del recurso que desea modificar:"<<endl;
                   getline(cin,codA);
                   for(int i=0;i<nr;i++)
                   {
                   if(codA==lista_recursos[i]->getCodA())
                   {
                       igual=1;
                       T=i;
                   }
                   }
                   if(igual==1)
                   {
                       ok=aux.setCodA(codA);
                       if(ok==1)
                       {
                       cout <<"Introduzca el NIF del profesor principal: "<< endl;
                       getline(cin,nifprofesorRas);
                       ok1=aux1.setNIFP(nifprofesorRas);
                       if(ok1==1)
                       {
                       int C=0;
                       for(int j=0;j<np;j++)
                       {
                           if(nifprofesorRas==lista_profesores[j].getNIFP())
                           {
                               C=1;
                               profesorRas.setNIFP(nifprofesorRas);
                               cout<<"---------------------------------------"<<endl;
                               cout<<"Introduzca el estado del recurso:\n 1.Creado\n 2.Iniciado\n 3.Finalizado "<<endl;
                               cout<<"---------------------------------------"<<endl;
                               cin>>estadoas;

                               if(estadoas>0 && estadoas<4)
                               {
                                   clase=typeid(*lista_recursos[T]).name();
                                   if(clase[0]=='1') select=1;
                                   if(clase[0]=='9') select=2;
                                   if(clase[0]=='3') select=3;
                                   switch(select)
                                   {
                                   case 1:
                                   {int titulacionas=0;
                                       int num_creditosas=0;
                                       string nifprofesor2as;
                                       Profesor profesor2as;
                                       cout<<"---------------------------------------"<<endl;
                                       cout<<"Introduzca la titulacion a la que pertenece la asignatura: \n1.Industriales \n2.Mecanica \n3.Electronica"<<endl;
                                       cout<<"---------------------------------------"<<endl;
                                       cin>>titulacionas;
                                       if(titulacionas>0 && titulacionas<4)
                                       {
                                           cout<<"Introduzca el numero de creditos de la asignatura:"<<endl;
                                           cin>>num_creditosas;
                                           cout<<"Introduzca el NIF del otro profesor de la asignatura:"<<endl;
                                           cin.ignore(256,'\n');
                                           getline(cin,nifprofesor2as);
                                           if(nifprofesor2as.compare(nifprofesorRas)!=0)
                                           {
                                           int B=0;
                                           for(int i=0;i<np;i++)
                                           {
                                           if(nifprofesor2as==lista_profesores[i].getNIFP())
                                           {
                                               B=1;
                                               profesor2as.setNIFP(nifprofesor2as);
                                               Asignatura *aus=new Asignatura(titulacionas, num_creditosas, profesor2as,codA,estadoas,profesorRas);
                                               Asignatura* aus2;
                                               aus2=dynamic_cast<Asignatura*>(lista_recursos[T]);
                                               aus->setN_alumnosA(aus2->getN_alumnosA());
                                               aus->setCalificada(aus2->getCalificada());
                                               if(aus->getN_alumnosA()>0)
                                               {
                                               aus->setLista_alumnosA(aus2->getLista_alumnosA());
                                               if(aus->getCalificada()==1)
                                               {
                                                   aus->setLista_calificaciones(aus2->getLista_calificaciones());
                                               }
                                               }
                                               lista_recursos[T]=aus;
                                               cout<<"La asignatura ha sido modificada."<<endl;
                                           }
                                           }
                                           if(B!=1) cout <<"NIF del segundo profesor invalido."<<endl;
                                       }else cout<<"El profesor introducido ya se encuentra registrado en esta asignatura."<<endl;
                                       }
                                       else cout<<"Titulacion invalida."<<endl;
                                       break;}
                                   case 2:
                                   {int plazas=0;
                                       string ponente;
                                       int dia=0;
                                       int mes=0;
                                       int ano=0;
                                       cout<<"Introduzca el numero maximo de plazas del seminario:"<<endl;
                                       cin>>plazas;
                                       cout<<"Introduzca el nombre del ponente del seminario:"<<endl;
                                       cin>>ponente;
                                       cout<<"---------------------------------------"<<endl;
                                       cout<<"Introduzca la fecha del seminario: "<<endl;
                                       cout<<"Año -> ";
                                       cin>>ano;
                                       cout<<endl<<"Mes -> ";
                                       cin>>mes;
                                       cout<<endl<<"Dia -> ";
                                       cin>>dia;
                                       cout<<"---------------------------------------"<<endl;
                                       cin.ignore(256,'\n');
                                       Seminario *aus=new Seminario(ponente,plazas,dia,mes,ano,codA,estadoas,profesorRas);
                                       Seminario* aus2;
                                       aus2=dynamic_cast<Seminario*>(lista_recursos[T]);
                                       aus->setN_AlumnosS(aus2->getn_AlumnosS());
                                       if(aus->getn_AlumnosS()>0)
                                       {
                                       aus->setListaAlumnosS(aus2->getListaAlumnosS());
                                       }
                                       lista_recursos[T]=aus;
                                       cout<<"El seminario ha sido modificado."<<endl;
                                       break;}
                                     case 3:
                                      { int titulaciontfe=0;
                                       Profesor cotutor;
                                       string nifcotutor;
                                       cout<<"---------------------------------------"<<endl;
                                       cout<<"Introduzca la titulacion a la que pertenece el TFE:\n1.Industriales \n2.Mecanica \n3.Electronica"<<endl;
                                       cout<<"---------------------------------------"<<endl;
                                       cin>>titulaciontfe;
                                       if(titulaciontfe>0 && titulaciontfe<4)
                                       {
                                           cout<<"---------------------------------------"<<endl;
                                           cout<<"Desea introducir un cotutor al TFE? \n1.SI \n2.NO"<<endl;
                                           cout<<"---------------------------------------"<<endl;
                                           int A=0;
                                           cin>>A;
                                           cin.ignore(256,'\n');
                                           if(A==1)
                                           {
                                           cout<<"Introduzca el NIF del cotutor del TFE:"<<endl;
                                           getline(cin,nifcotutor);
                                           cin.ignore(256,'\n');
                                           if (nifcotutor.compare(nifprofesorRas)!=0)
                                           {
                                           int L=0;
                                           for(int i=0;i<np;i++)
                                           {
                                           if(nifcotutor==lista_profesores[i].getNIFP())
                                           {
                                               L=1;
                                               cotutor.setNIFP(nifcotutor);
                                               TFE *aus=new TFE(titulaciontfe,cotutor,codA,estadoas,profesorRas);
                                               TFE* aus2;
                                               aus2=dynamic_cast<TFE*>(lista_recursos[T]);
                                               aus->setAdjudicado(aus2->getAdjudicado());
                                               if(aus2->getAdjudicado()==1){
                                                   Alumno alumtfe=aus2->getAlumnoTFE();
                                                   aus->setAlumnoTFE(alumtfe);}
                                               lista_recursos[T]=aus;
                                           }
                                           }
                                           if(L!=1) cout <<"NIF del segundo tutor introducido invalido."<<endl;
                                           }else cout<<"El profesor introducido ya esta registrado en este TFE."<<endl;
                                           }else if(A==2)
                                           {
                                               TFE *aus=new TFE(titulaciontfe,cotutor,codA,estadoas,profesorRas);
                                               lista_recursos.push_back(aus);
                                               nr++;
                                           }
                                           else cout<<"Opcion incorrecta."<<endl;
                                       }
                                       else cout<<"Titulación invalida."<<endl;
                                       break;}
                                   default:
                                   {cout<<"Opcion invalida."<<endl;
                                       break;}
                                   }

                               }else cout<<"El valor del estado introducido es incorrecto."<<endl;

                              }else if(C!=1) cout<<"El NIF del profesor introducido no existe.  "<<endl;
                          }
                       }
                       }else cout<<"El codigo del recurso introducido es incorrecto."<<endl;
                   }else cout<<"El codigo del recurso introducido no existe."<<endl;
}

void CampusVirtual::modif_recurso_profesor(string nifpr){
   string codA="";
   string nifprofesorRas="";
   Profesor profesorRas,aux1;
   Recurso aux;
   int ok=0,ok1=0;
   int estadoas=0;
   int igual=0;
   string clase;
   int T=0, select=0;

                   cout<<"Introduzca el codigo del recurso que desea modificar:"<<endl;
                   getline(cin,codA);
                   for(int i=0;i<nr;i++)
                   {
                   if(codA==lista_recursos[i]->getCodA())
                   {
                       igual=1;
                       T=i;
                   }
                   }
                   if(nifpr.compare(lista_recursos[T]->getProfesorR().getNIFP())==0)
                   {
                       if(igual==1)
                       {
                           ok=aux.setCodA(codA);
                           if(ok==1)
                           {
                               cout <<"Introduzca el NIF del profesor principal: "<< endl;
                               getline(cin,nifprofesorRas);
                               ok1=aux1.setNIFP(nifprofesorRas);
                               if(ok1==1)
                               {
                                   int C=0;
                                   for(int j=0;j<np;j++)
                                   {
                                       if(nifprofesorRas==lista_profesores[j].getNIFP())
                                       {
                                           C=1;
                                           profesorRas.setNIFP(nifprofesorRas);
                                           cout<<"---------------------------------------"<<endl;
                                           cout<<"Introduzca el estado del recurso:\n 1.Creado\n 2.Iniciado\n 3.Finalizado "<<endl;
                                           cout<<"---------------------------------------"<<endl;
                                           cin>>estadoas;

                                           if(estadoas>0 && estadoas<4)
                                           {
                                               clase=typeid(*lista_recursos[T]).name();
                                               if(clase[0]=='1') select=1;
                                               if(clase[0]=='9') select=2;
                                               if(clase[0]=='3') select=3;
                                               switch(select)
                                               {
                                               case 1:
                                               {int titulacionas=0;
                                                   int num_creditosas=0;
                                                   string nifprofesor2as;
                                                   Profesor profesor2as;
                                                   cout<<"---------------------------------------"<<endl;
                                                   cout<<"Introduzca la titulacion a la que pertenece la asignatura: \n1.Industriales \n2.Mecanica \n3.Electronica"<<endl;
                                                   cout<<"---------------------------------------"<<endl;
                                                   cin>>titulacionas;
                                                   if(titulacionas>0 && titulacionas<4)
                                                   {
                                                       cout<<"Introduzca el numero de creditos de la asignatura:"<<endl;
                                                       cin>>num_creditosas;
                                                       cout<<"Introduzca el NIF del otro profesor de la asignatura:"<<endl;
                                                       cin.ignore(256,'\n');
                                                       getline(cin,nifprofesor2as);
                                                       if(nifprofesor2as.compare(nifprofesorRas)!=0)
                                                       {
                                                           int B=0;
                                                           for(int i=0;i<np;i++)
                                                           {
                                                               if(nifprofesor2as==lista_profesores[i].getNIFP())
                                                               {
                                                                   B=1;
                                                                   profesor2as.setNIFP(nifprofesor2as);
                                                                   Asignatura *aus=new Asignatura(titulacionas, num_creditosas, profesor2as,codA,estadoas,profesorRas);
                                                                   Asignatura* aus2;
                                                                   aus2=dynamic_cast<Asignatura*>(lista_recursos[T]);
                                                                   aus->setN_alumnosA(aus2->getN_alumnosA());
                                                                   aus->setCalificada(aus2->getCalificada());
                                                                   if(aus->getN_alumnosA()>0)
                                                                   {
                                                                       aus->setLista_alumnosA(aus2->getLista_alumnosA());
                                                                       if(aus->getCalificada()==1)
                                                                       {
                                                                           aus->setLista_calificaciones(aus2->getLista_calificaciones());
                                                                       }
                                                                   }
                                                                   lista_recursos[T]=aus;
                                                                   cout<<"La asignatura ha sido modificada."<<endl;
                                                               }
                                                           }
                                                           if(B!=1) cout <<"NIF del segundo profesor invalido."<<endl;
                                                       }else cout<<"El profesor introducido ya se encuentra registrado en esta asignatura."<<endl;
                                                   }
                                                   else cout<<"Titulacion invalida."<<endl;
                                                   break;}
                                               case 2:
                                               {int plazas=0;
                                                   string ponente;
                                                   int dia=0;
                                                   int mes=0;
                                                   int ano=0;
                                                   cout<<"Introduzca el numero maximo de plazas del seminario:"<<endl;
                                                   cin>>plazas;
                                                   cout<<"Introduzca el nombre del ponente del seminario:"<<endl;
                                                   cin>>ponente;
                                                   cout<<"---------------------------------------"<<endl;
                                                   cout<<"Introduzca la fecha del seminario: "<<endl;
                                                   cout<<"Año -> ";
                                                   cin>>ano;
                                                   cout<<endl<<"Mes -> ";
                                                   cin>>mes;
                                                   cout<<endl<<"Dia -> ";
                                                   cin>>dia;
                                                   cout<<"---------------------------------------"<<endl;
                                                   cin.ignore(256,'\n');
                                                   Seminario *aus=new Seminario(ponente,plazas,dia,mes,ano,codA,estadoas,profesorRas);
                                                   Seminario* aus2;
                                                   aus2=dynamic_cast<Seminario*>(lista_recursos[T]);
                                                   aus->setN_AlumnosS(aus2->getn_AlumnosS());
                                                   if(aus->getn_AlumnosS()>0)
                                                   {
                                                       aus->setListaAlumnosS(aus2->getListaAlumnosS());
                                                   }
                                                   lista_recursos[T]=aus;
                                                   cout<<"El seminario ha sido modificado."<<endl;
                                                   break;}
                                               case 3:
                                               { int titulaciontfe=0;
                                                   Profesor cotutor;
                                                   string nifcotutor;
                                                   cout<<"---------------------------------------"<<endl;
                                                   cout<<"Introduzca la titulacion a la que pertenece el TFE:\n1.Industriales \n2.Mecanica \n3.Electronica"<<endl;
                                                   cout<<"---------------------------------------"<<endl;
                                                   cin>>titulaciontfe;
                                                   if(titulaciontfe>0 && titulaciontfe<4)
                                                   {
                                                       cout<<"---------------------------------------"<<endl;
                                                       cout<<"Desea introducir un cotutor al TFE? \n1.SI \n2.NO"<<endl;
                                                       cout<<"---------------------------------------"<<endl;
                                                       int A=0;
                                                       cin>>A;
                                                       cin.ignore(256,'\n');
                                                       if(A==1)
                                                       {
                                                           cout<<"Introduzca el NIF del cotutor del TFE:"<<endl;
                                                           getline(cin,nifcotutor);
                                                           cin.ignore(256,'\n');
                                                           if (nifcotutor.compare(nifprofesorRas)!=0)
                                                           {
                                                               int L=0;
                                                               for(int i=0;i<np;i++)
                                                               {
                                                                   if(nifcotutor==lista_profesores[i].getNIFP())
                                                                   {
                                                                       L=1;
                                                                       cotutor.setNIFP(nifcotutor);
                                                                       TFE *aus=new TFE(titulaciontfe,cotutor,codA,estadoas,profesorRas);
                                                                       TFE* aus2;
                                                                       aus2=dynamic_cast<TFE*>(lista_recursos[T]);
                                                                       aus->setAdjudicado(aus2->getAdjudicado());
                                                                       if(aus2->getAdjudicado()==1){
                                                                           Alumno alumtfe=aus2->getAlumnoTFE();
                                                                           aus->setAlumnoTFE(alumtfe);}
                                                                       lista_recursos[T]=aus;
                                                                   }
                                                               }
                                                               if(L!=1) cout <<"NIF del segundo tutor introducido invalido."<<endl;
                                                           }else cout<<"El profesor introducido ya esta registrado en este TFE."<<endl;
                                                       }else if(A==2)
                                                       {
                                                           TFE *aus=new TFE(titulaciontfe,cotutor,codA,estadoas,profesorRas);
                                                           lista_recursos.push_back(aus);
                                                           nr++;
                                                       }
                                                       else cout<<"Opcion incorrecta."<<endl;
                                                   }
                                                   else cout<<"Titulación invalida."<<endl;
                                                   break;}
                                               default:
                                               {cout<<"Opcion invalida."<<endl;
                                                   break;}
                                               }

                                           }else cout<<"El valor del estado introducido es incorrecto."<<endl;

                                       }else if(C!=1) cout<<"El NIF del profesor introducido no existe.  "<<endl;
                                   }
                               }
                           }else cout<<"El codigo del recurso introducido es incorrecto."<<endl;
                       }else cout<<"El codigo del recurso introducido no existe."<<endl;
                   }else cout<<"Usted no tiene permiso para modificar este recurso"<<endl;
}

void CampusVirtual::inicio()
{
    CampusVirtual campus;
    char opcion;
    cout<<"Quiere recuperar los datos del fichero (presione S o s si los quiere recuperar)"<<endl;
    cin>>opcion;
    if(opcion=='S'||opcion=='s')//Si los queremos recuperar leemos el fichero
    {
        campus.leer_fichero();
    }
    else //En cualquier otro caso
    {
        cout<<"No leemos el fichero"<<endl;
    }
                                int ident=0;
                                while(ident!=4)
                                {
                                cout<<"---------------------------------------"<<endl;
                                cout<<"Indique la operacion que quiere realizar: \n1.Gestion alumnos \n2.Gestion profesores \n3.Gestion administradores \n4.Guardar ficheros \n5.Salir del programa"<< endl;
                                cout<<"---------------------------------------"<<endl;
                                cin>>ident;
                                switch(ident)
                                {
                                case 1:
                                {int k=1,S=0;
                                do
                                {
                                  int nia;
                                  cout<<"Introduzca su NIA: "<<endl;
                                  cin>>nia;
                                  cout<<nal<<endl;
                                  for(int i=0;i<nal;i++)
                                                  {
                                                      if(nia==lista_alumnos[i].getNIA())
                                                      {
                                                          k=0;
                                                          cout<<"NIF correcto."<<endl;
                                                      }
                                                  }
                                }while(k!=0);
                                while(S!=3)
                                {
                                    int R=0,A=0;
                                    cout<<"---------------------------------------"<<endl;
                                    cout<<"Que operacion quiere realizar? \n1.Darse de alta en un recurso. \n2.Darse de baja en un recurso. \n3.Salir"<<endl;
                                    cout<<"---------------------------------------"<<endl;
                                    cin>>S;
                                    switch(S){
                                    case 1:
                                    {
                                        while (R!=4)
                                        {
                                            cout<<"---------------------------------------"<<endl;
                                        cout<<"Indique el tipo de recurso al que se quiere apuntar: \n1.Asignatura \n2.Seminario \n3.TFE \n4.Salir"<<endl;
                                        cout<<"---------------------------------------"<<endl;
                                        cin>>R;
                                        switch(R)
                                        {
                                        case 1:
                                           CampusVirtual::apuntar_asig();
                                            break;
                                        case 2:
                                            CampusVirtual::apuntar_semi();
                                            break;
                                        case 3:
                                            CampusVirtual::apuntar_TFE();
                                          break;
                                        case 4:
                                           cout<<"Saliendo del programa."<<endl;
                                           break;
                                        default:
                                             cout<<"Opcion incorrecta."<<endl;
                                            break;
                                        }
                                        }
                                        break;}
                                    case 2:
                                    {
                                        while (A!=4)
                                        {
                                            cout<<"---------------------------------------"<<endl;
                                        cout<<"Indique el tipo de recurso al que se quiere desapuntar: \n1.Asignatura \n2.Seminario \n3.TFE \n4.Salir"<<endl;
                                        cout<<"---------------------------------------"<<endl;
                                        cin>>A;
                                        switch(A)
                                        {
                                        case 1:
                                           CampusVirtual::desapuntar_asig();
                                            break;
                                        case 2:
                                            CampusVirtual::desapuntar_semi();
                                            break;
                                        case 3:
                                            CampusVirtual::desapuntar_TFE();
                                          break;
                                        case 4:
                                           cout<<"Saliendo del programa."<<endl;
                                           break;
                                        default:
                                             cout<<"Opcion incorrecta."<<endl;
                                            break;
                                        }
                                        }
                                        break;}
                                    case 3:
                                       cout<<"Saliendo del programa."<<endl;
                                       break;
                                    default:
                                         {cout<<"Opcion incorrecta."<<endl;
                                        break;}
                                    }
                                }
                                break;}

                                case 2:
                                {string nifp;
                                    int igual2=1,selecc=0;
                                    do{
                                    cout<<"Introduzca su NIF: "<<endl;
                                    cin.ignore(256,'\n');
                                    getline(cin,nifp);
                                    for(int i=0;i<np;i++)
                                                    {
                                                        if(nifp==lista_profesores[i].getNIFP())
                                                        {
                                                            igual2=0;
                                                            cout<<"NIF correcto."<<endl;
                                                        }
                                                    }
                                    }while(igual2!=0);
                                    while(selecc!=4)
                                    {
                                    int p=0;
                                    cout<<"---------------------------------------"<<endl;
                                    cout<<"¿Que desea gestionar?\n 1.Modificar un recurso \n 2.Mostrar listados \n 3.Calificar \n4.Salir"<< endl;
                                    cout<<"---------------------------------------"<<endl;
                                    cin>>selecc;
                                        switch(selecc)
                                        {
                                        case  1:
                                               CampusVirtual::modif_recurso_profesor(nifp);
                                            break;
                                        case 2:

                                            while(p!=6)
                                            {
                                                cout<<"---------------------------------------"<<endl;
                                            cout<<"Indique el tipo de listado que quiere mostrar: \n1.Recursos \n2.Alumnos \n3.Profesores \n4.Administradores \n5.Calificaciones \n6.Salir"<<endl;
                                            cout<<"---------------------------------------"<<endl;
                                            cin>>p;
                                            switch(p)
                                            {
                                            case 1:
                                                CampusVirtual::mostrar_recurso();
                                                break;
                                            case 2:
                                                CampusVirtual::mostrar_alumno();
                                                break;
                                            case 3:
                                                CampusVirtual::mostrar_profesor();
                                                break;
                                            case 4:
                                                CampusVirtual::mostrar_admin();
                                                break;
                                            case 5:
                                                CampusVirtual::mostrar_calif();
                                                break;
                                            case 6:
                                               cout<<"Saliendo del programa."<<endl;
                                               break;
                                            default:
                                              cout<<"Opcion incorrecta."<<endl;
                                                break;
                                            }
                                            }
                                            break;
                                        case 3:
                                               CampusVirtual::Calificar();
                                            break;
                                        case 4:
                                           cout<<"Saliendo del programa."<<endl;
                                           break;
                                        default:
                                        cout<<"Opcion incorrecta."<<endl;
                                            break;
                                        }
                                    }
                                        break;}
                                case 3:
                                {string nifa;
                                int igual=1,selec=0;
                                do{
                                cout<<"Introduzca su NIF: "<<endl;
                                cin.ignore(256,'\n');
                                getline(cin,nifa);
                                for(int i=0;i<nad;i++)
                                                {
                                                    if(nifa==lista_admins[i].getNIFA())
                                                    {
                                                        igual=0;
                                                        cout<<"NIF correcto."<<endl;
                                                    }
                                                }
                                }while(igual!=0);
                                while(selec!=3)
                                {
                                cout<<"---------------------------------------"<<endl;
                                cout<<"¿Que desea gestionar?\n 1.Usuarios\n 2.Recursos \3.Salir"<< endl;
                                cout<<"---------------------------------------"<<endl;
                                cin>>selec;
                                    switch(selec)
                                    {
                                    case  1:
                                    {int opc=0;
                                    while(opc!=4)
                                    {
                                    cout<<"---------------------------------------"<<endl;
                                    cout<<"¿Que tipo de usuario quiere gestionar?\n 1.Administrador\n 2.Profesor\n 3.Alumno \n4.Salir"<< endl;
                                    cout<<"---------------------------------------"<<endl;
                                    cin >>opc;
                                            switch(opc)
                                            {
                                            case 1:
                                               { int oper=0;
                                                while(oper!=5)
                                                {
                                                cout<<"---------------------------------------"<<endl;
                                                cout<<"¿Que operacion quiere realizar?\n 1.Dar de alta\n 2.Dar de baja\n 3.Mostrar\n 4.Modificar \n5.Salir"<<endl;
                                                cout<<"---------------------------------------"<<endl;
                                                cin >>oper;
                                                cin.ignore(256,'\n');
                                                switch(oper){
                                                case 1:
                                                CampusVirtual::alta_admin();
                                                    break;
                                                    case 2:
                                                    CampusVirtual::baja_admin();
                                                    break;
                                                    case 3:
                                                    CampusVirtual::mostrar_admin();
                                                    break;
                                                        case 4:
                                                    CampusVirtual::modif_admin();
                                                    break;
                                                    case 5:
                                                    cout<<"Saliendo del programa."<<endl;
                                                    break;
                                                    default:
                                                    cout<<"Opcion incorrecta."<<endl;
                                                    break;}
                                            }
                                            break;}
                                            case 2:
                                            {int oper=0;
                                                while(oper!=5)
                                                {
                                            cout<<"---------------------------------------"<<endl;
                                            cout<<"¿Que operacion quiere realizar?\n 1.Dar de alta\n 2.Dar de baja\n 3.Mostrar\n 4.Modificar \n5.Salir"<<endl;
                                            cout<<"---------------------------------------"<<endl;
                                            cin >>oper;
                                            cin.ignore(256,'\n');
                                                switch(oper){
                                                case 1:
                                                CampusVirtual::alta_profesor();
                                                break;
                                                    case 2:
                                                    CampusVirtual::baja_profesor();
                                                    break;
                                                    case 3:
                                                CampusVirtual::mostrar_profesor();
                                                    break;
                                                    case 4:
                                                CampusVirtual::modif_profesor();
                                                break;
                                                case 5:
                                                   cout<<"Saliendo del programa."<<endl;
                                                   break;
                                                default:
                                                cout<<"Opcion incorrecta."<<endl;
                                                break;}
                                            }
                                                break;}
                                            case 3:
                                            {
                                             int oper=0;
                                             while(oper!=5)
                                             {
                                             cout<<"---------------------------------------"<<endl;
                                             cout<<"¿Que operacion quiere realizar?\n 1.Dar de alta\n 2.Dar de baja\n 3.Mostrar\n 4.Modificar \n5.Salir"<<endl;
                                             cout<<"---------------------------------------"<<endl;
                                             cin >>oper;
                                             cin.ignore(256,'\n');
                                             switch(oper){
                                             case 1:
                                             CampusVirtual::alta_alumno();
                                             break;
                                             case 2:
                                             CampusVirtual::baja_alumno();
                                             break;
                                             case 3:
                                             CampusVirtual::mostrar_alumno();
                                             break;
                                             case 4:
                                             CampusVirtual::modif_alumno();
                                             break;
                                             case 5:
                                                cout<<"Saliendo del programa."<<endl;
                                                break;
                                             default:
                                             cout<<"Opcion incorrecta."<<endl;
                                             break;}
                                             }
                                             break;}
                                            case 4:
                                               cout<<"Saliendo del programa."<<endl;
                                               break;
                                            default:
                                             {cout<<"Opcion incorrecta."<<endl;
                                             break;}
                                             }
                                     }
                                        break;}
                                    case 2:
                                     {int oper=0;
                                     while(oper!=5)
                                     {
                                     cout<<"---------------------------------------"<<endl;
                                     cout<<"¿Que operacion quiere realizar?\n 1.Dar de alta\n 2.Dar de baja\n 3.Mostrar\n 4.Modificar \n5.Salir"<<endl;
                                     cout<<"---------------------------------------"<<endl;
                                     cin >>oper;
                                     cin.ignore(256,'\n');
                                     switch(oper){
                                                    case 1:
                                                    CampusVirtual::alta_recurso();
                                                    break;
                                                    case 2:
                                                    CampusVirtual::baja_recurso();
                                                    break;
                                                    case 3:
                                                    CampusVirtual::mostrar_recurso();
                                                    break;
                                                    case 4:
                                                    CampusVirtual::modif_recurso_admin();
                                                    break;
                                                    case 5:
                                                    cout<<"Saliendo del programa."<<endl;
                                                    break;
                                                    default:
                                                    cout<<"Opcion incorrecta."<<endl;
                                                    break;}
                                        }
                                     break;}
                                    case 3:
                                       cout<<"Saliendo del programa."<<endl;
                                       break;
                                    default:
                                     {cout<<"Opcion incorrecta."<<endl;
                                     break;}}

                                     }
                                }
                                case 4:
                                    CampusVirtual::guardar_fichero();
                                    break;
                                case 5:
                                    cout<<"Saliendo del programa."<<endl;
                                    break;
                                default:
                                    cout<<"Opcion incorrecta."<<endl;
                                    break;
                                }
                                }
}

void CampusVirtual::Calificar()
{
   Asignatura* asigal;
      string codig;
      string nifp;
      int L=0,D=0,S=0,T=0;
      cout<<"Introduzca su NIF de profesor: "<<endl;
      getline(cin,nifp);
      cin.ignore(256,'\n');
      cout<<"Introduzca el codigo de la asignatura a calificar: "<<endl;
      getline(cin,codig);
      for(int i=0;i<nr;i++)
      {
              if(codig==lista_recursos[i]->getCodA())
              {
                  L=1;
              }

          if(nifp.compare(lista_recursos[i]->getProfesorR().getNIFP()) && L==1)//Compara el NIF introducido con el del profesor de la asignatura indicada
              {
              D=1;
              asigal=dynamic_cast<Asignatura*>(lista_recursos[T]);
              float *auxlistacalif=new float[asigal->getN_alumnosA()];
              float nota=0;
              for(int j=0;j<asigal->getN_alumnosA();j++)
               {
                   do{
                      S=0;
                      cout<<"Introduzca la calificacion del alumno -> NIA: "<<asigal->getLista_alumnosA()[j].getNIA()<<endl;
                      cout<<"Calificacion: "<<endl;
                      cin>>nota;
                      cin.ignore(256,'\n');
                      if(nota>=0&&nota<=10)
                      {
                      S=1;
                      auxlistacalif[j]=nota;
                      cout<<"El alumno ha sido calificado."<<endl;
                      }
                      if(S==0) cout<<"La calificacion introducida no se encuentra entre 0-10. Intentelo de nuevo"<<endl;

                      }while(S==0);
                }
                 asigal->setCalificada(1);
                 asigal->setLista_calificaciones(auxlistacalif);
                 lista_recursos[T]=dynamic_cast<Recurso*>(asigal);
              }
      }

          if(D==0 && L==1) cout<<"NIF incorrecto. Usted no es el profesor de la asignatura a calificar."<<endl;
          if(L==0) cout<<"El codigo introducido no se encuentra registrado."<<endl;
}

void CampusVirtual::mostrar_calif()
{
   int Q=0;
   Asignatura* asigal;
   string codigo1;
   cout<<"Introduzca el codigo de la asignatura calificada: "<<endl;
   getline(cin,codigo1);

   for(int i=0;i<nr;i++)
   {
   if(codigo1==lista_recursos[i]->getCodA())
   {
       Q=1;
       asigal=dynamic_cast<Asignatura*>(lista_recursos[i]);
       for(int j=0;j<asigal->getN_alumnosA();j++)
       {
           cout<<"---NIA: "<<asigal->getLista_alumnosA()[j].getNIA()<<" --- Nota: "<<asigal->getLista_calificaciones()[j]<<" ---"<<endl;
       }
       lista_recursos[i]=dynamic_cast<Recurso*>(asigal);
   }
   }
   if(Q==0) cout<<"La asignatura introducida no se encuentra registrada."<<endl;


}


void CampusVirtual::apuntar_asig()
{
        string codAasig;
        Asignatura* asigal;
        int niaalumap=0;
        int D=0,L=0;
        Alumno alumap;
        cout<<"Vuelva a introducir su NIA"<<endl;
        cin>>niaalumap;
        cin.ignore(256,'\n');
        for(int i=0;i<nal;i++)
        {
            if(niaalumap==lista_alumnos[i].getNIA())
            {
                alumap=lista_alumnos[i];
            }
        }
        cout<<"Introduzca el codigo de la asignatura:"<<endl;
        cin>>codAasig;
        for(int j=0;j<nr;j++)
        {
        if(codAasig==lista_recursos[j]->getCodA())
        {
        L=1;
        asigal=dynamic_cast<Asignatura*>(lista_recursos[j]);
        if(alumap.getTitulacionS()==asigal->getTitulacionA())
        {
        D=1;
        Alumno *auxlistaal=new Alumno[asigal->getN_alumnosA()+1];
                for(int k=0;k<asigal->getN_alumnosA();k++)
                    {
                        auxlistaal[k]=asigal->getLista_alumnosA()[k];
                    }
        auxlistaal[asigal->getN_alumnosA()]=alumap;
        asigal->setLista_alumnosA(auxlistaal);
        asigal->setN_alumnosA(asigal->getN_alumnosA()+1);
        lista_recursos[j]=dynamic_cast<Recurso*>(asigal);
        }
        }
        }
        if(L==0) cout<<"La asignatura no se encuentra registrada."<<endl;
        if(D==0)cout<<"La Asignatura seleccionada no pertenece a tu titulacion."<<endl;
}

void CampusVirtual::apuntar_TFE()
{

   string codTFE;
   TFE* TFEal;
   int niaalumap;
   int L=0,D=0,V=0,T=0;
   Alumno alumap;
   cout<<"Vuelva a introducir su NIA"<<endl;
   cin>>niaalumap;
   cin.ignore(256,'\n');
   for(int i=0;i<nal;i++)
   {
       if(niaalumap==lista_alumnos[i].getNIA())
       {
           alumap=lista_alumnos[i];
           T=i;
       }
   }
   if(alumap.getApuntado()==0)
   {
   V=1;
   cout<<"Introduzca el codigo del TFE:"<<endl;
   cin>>codTFE;
   for(int j=0;j<nr;j++)
   {
   if(codTFE==lista_recursos[j]->getCodA())
   {
   L=1;
   TFEal=dynamic_cast<TFE*>(lista_recursos[j]);
   if(TFEal->getAlumnoTFE().getNIA()==0)
   {
   D=1;
   alumap.setApuntado(1);
   TFEal->setAlumnoTFE(alumap);
   TFEal->setAdjudicado(1);
   lista_alumnos[T]=alumap;
       }
   if(D==0) cout<<"El TFE ya ha sido asignado."<<endl;
   lista_recursos[j]=dynamic_cast<Recurso*>(TFEal);
   }

   }
 if(V==1 && L==0) cout<<"No se ha encontrado el TFE introducido."<<endl;
   }
 if(V==0) cout<<"Ya se te ha asignado un TFE, no te puedes apuntar a otro."<<endl;
   }




void CampusVirtual::apuntar_semi()
{
    string codSemi;
    Seminario* semial;
    int niaalumap;
    int L=0;
    Alumno alumap;
    cout<<"Vuelva a introducir su NIA"<<endl;
    cin>>niaalumap;
    cin.ignore(256,'\n');
    for(int i=0;i<nal;i++)
    {
        if(niaalumap==lista_alumnos[i].getNIA())
        {
            alumap=lista_alumnos[i];
        }
    }
    cout<<"Introduzca el codigo del seminario:"<<endl;
    cin>>codSemi;
    for(int j=0;j<nr;j++)
    {
    if(codSemi==lista_recursos[j]->getCodA())
    {
    L=1;
    semial=dynamic_cast<Seminario*>(lista_recursos[j]);
    if(semial->getPlazas()>semial->getn_AlumnosS())
    {
    Alumno *auxlistaal=new Alumno[semial->getn_AlumnosS()+1];
    for(int k=0;k<semial->getn_AlumnosS();k++)
    {
        auxlistaal[k]=semial->getListaAlumnosS()[k];
    }
    auxlistaal[semial->getn_AlumnosS()]=alumap;
    semial->setListaAlumnosS(auxlistaal);
    semial->setN_AlumnosS(semial->getn_AlumnosS()+1);
    lista_recursos[j]=dynamic_cast<Recurso*>(semial);
    }
    else cout<<"No hay plazas disponibles en el seminario introducido."<<endl;
    }
    }
    if(L==0) cout<<"No se ha encontrado el seminario introducido."<<endl;
}

void CampusVirtual::desapuntar_asig()
{

    string codAasig;
    Asignatura* asigal;
    int niaalumap;
    int L=0;
    Alumno alumap;
    int alencontrado=0;
    cout<<"Vuelva a introducir su NIA: "<<endl;
    cin>>niaalumap;
    cin.ignore(256,'\n');
    for(int i=0;i<nal;i++)
    {
        if(niaalumap==lista_alumnos[i].getNIA())
        {
            alumap=lista_alumnos[i];
        }
    }
    cout<<"Introduzca el codigo de la asignatura:"<<endl;
    cin>>codAasig;
    for(int j=0;j<nr;j++)
    {
    if(codAasig==lista_recursos[j]->getCodA())
    {
    L=1;
    asigal=dynamic_cast<Asignatura*>(lista_recursos[j]);
    Alumno *auxlistaal=new Alumno[asigal->getN_alumnosA()-1];
    for(int tr=0;tr<asigal->getN_alumnosA();tr++)
    {
        if(alencontrado==0)
        {
                if(asigal->getLista_alumnosA()[tr].getNIA()==alumap.getNIA())
                { alencontrado=1;
                cout<<"Te has desapuntado de la asignatura."<<endl;
                }
                else auxlistaal[tr]=asigal->getLista_alumnosA()[tr];
    }
    else auxlistaal[tr-1]=asigal->getLista_alumnosA()[tr];
        if(alencontrado==1)
        {
        asigal->setLista_alumnosA(auxlistaal);
        asigal->setN_alumnosA(asigal->getN_alumnosA()-1);
        }
    lista_recursos[j]=dynamic_cast<Recurso*>(asigal);
    }
    if(alencontrado==0)cout<<"No estas apuntado a esa asignatura."<<endl;
    }
    }
    if(L==0) cout<<"La asignatura no se encuentra registrada."<<endl;
}

void CampusVirtual::desapuntar_semi()
{
    string codAsemi;
    Seminario* semial;
    int niaalumap;
    int L=0;
    Alumno alumap;
    int alencontrado=0;
    cout<<"Vuelva a introducir su NIA: "<<endl;
    cin>>niaalumap;
    cin.ignore(256,'\n');
    for(int i=0;i<nal;i++)
    {
        if(niaalumap==lista_alumnos[i].getNIA())
        {
            alumap=lista_alumnos[i];
        }
    }
    cout<<"Introduzca el codigo del seminario:"<<endl;
    cin>>codAsemi;
    for(int j=0;j<nr;j++)
    {
    if(codAsemi==lista_recursos[j]->getCodA())
    {
    L=1;
    semial=dynamic_cast<Seminario*>(lista_recursos[j]);
    Alumno *auxlistaal=new Alumno[semial->getn_AlumnosS()-1];
    for(int tr=0;tr<semial->getn_AlumnosS();tr++)
    {
        if(alencontrado==0)
        {
                if(semial->getListaAlumnosS()[tr].getNIA()==alumap.getNIA())
                { alencontrado=1;
                cout<<"Te has desapuntado del seminario."<<endl;
                }
                else auxlistaal[tr]=semial->getListaAlumnosS()[tr];
    }
    else auxlistaal[tr-1]=semial->getListaAlumnosS()[tr];
        if(alencontrado==1)
        {
        semial->setListaAlumnosS(auxlistaal);
        semial->setN_AlumnosS(semial->getn_AlumnosS()-1);
        }
    lista_recursos[j]=dynamic_cast<Recurso*>(semial);
    }
    if(alencontrado==0)cout<<"No estas apuntado a ese seminario."<<endl;
    }
    }
    if(L==0) cout<<"El seminario no se encuentra registrado."<<endl;
}

void CampusVirtual::desapuntar_TFE()
{
   string codATFE;
   TFE* TFEal;
   int niaalumap;
   int L=0,D=0;
   Alumno alumap;
   int alencontrado=0;
   cout<<"Vuelva a introducir su NIA: "<<endl;
   cin>>niaalumap;
   cin.ignore(256,'\n');
   for(int i=0;i<nal;i++)
   {
       if(niaalumap==lista_alumnos[i].getNIA())
       {	alencontrado=i;
           alumap=lista_alumnos[i];
           D=1;
       }
   }
   cout<<"Introduzca el codigo del TFE:"<<endl;
   cin>>codATFE;
   for(int j=0;j<nr;j++)
   {
       if(codATFE==lista_recursos[j]->getCodA())
           {
           L=1;
           alumap.setApuntado(0);
           lista_alumnos[alencontrado]=alumap;
           TFEal=dynamic_cast<TFE*>(lista_recursos[j]);
           Alumno vacio;
           TFEal->setAlumnoTFE(vacio);
           TFEal->setAdjudicado(0);
           }
   }
   if(D==0)cout<<"No estas apuntado a ese seminario."<<endl;
   if(L==0) cout<<"El TFE no se encuentra registrado."<<endl;
}



void CampusVirtual::guardar_fichero()
{
    if(nad==0)
    {
        cout<<"No hay administradores que guardar."<<endl;
    }
    else
    {
        ofstream admin;
        admin.open("C:/Users/Luis Vicente/Desktop/FicheroAD.txt");//Cuando usemos el ordena de la uni habrá que cambiar la ruta de accceso

        if(admin.is_open())
        {
            admin<<nad<<endl;//numero de administradores
            for(int i=0;i<nad;i++)
            {
                admin<<lista_admins[i].getNIFA()<<endl;

            }
            cout<<"Datos de administradores guardados correctamente."<<endl;
        }
        else
        {
        cout<< "Error al abrir el fichero de administradores." << endl;
        }
        admin.close();
    }
    if(np==0)
    {
        cout<<"No hay profesores que guardar."<<endl;
    }
    else
    {
        ofstream profe;
        profe.open("C:/Users/Luis Vicente/Desktop/FicheroP.txt");//Cuando usemos el ordena de la uni habrá que cambiar la ruta de accceso

        if(profe.is_open())
        {
            profe<<np<<endl;//numero de profesores
            for(int i=0;i<np;i++)
            {
                profe<<lista_profesores[i].getNIFP()<<endl;

            }
            cout<<"Datos de profesores guardados correctamente."<<endl;
        }
        else
        {
        cout<< "Error al abrir el fichero de profesores." << endl;
        }
        profe.close();
    }
    if(nal==0)
    {
        cout<<"No hay alumnos que guardar."<<endl;
    }
    else
    {
        ofstream alum;
        alum.open("C:/Users/Luis Vicente/Desktop/FicheroAL.txt");//Cuando usemos el ordena de la uni habrá que cambiar la ruta de accceso

        if(alum.is_open())
        {
            alum<<nal<<endl;//numero de alumnos
            for(int i=0;i<nal;i++)
            {
                alum<<lista_alumnos[i].getNIA()<<endl;
                alum<<lista_alumnos[i].getTitulacionS()<<endl;
                alum<<lista_alumnos[i].getApuntado()<<endl;

            }
            cout<<"Datos de alumnos guardados correctamente."<<endl;
        }
        else
        {
        cout<< "Error al abrir el fichero de alumnos." << endl;
        }
        alum.close();
    }



    if(nr==0)
    {
        cout<<"No hay recursos que guardar."<<endl;
    }
    else
    {
        ofstream recur;
        recur.open("C:/Users/Luis Vicente/Desktop/FicheroR.txt");//Cuando usemos el ordena de la uni habrá que cambiar la ruta de accceso

        if(recur.is_open())
        {
            recur<<nr<<endl;//numero de recursos
            for(int i=0;i<nr;i++)
            {
                string clase=typeid(*lista_recursos[i]).name();
                if(clase[0]=='1')    //Asignatura
                {
                    Asignatura* aux;
                    recur<<lista_recursos[i]->getCodA()<<endl;
                    recur<<lista_recursos[i]->getEstado()<<endl;
                    recur<<lista_recursos[i]->getProfesorR().getNIFP()<<endl;
                    recur<<"Asignatura"<<endl;
                    aux=dynamic_cast<Asignatura*>(lista_recursos[i]);
                    recur<<aux->getProfesor2().getNIFP()<<endl;
                    recur<<aux->getNum_creditos()<<endl;
                    recur<<aux->getTitulacionA()<<endl;
                    recur<<aux->getN_alumnosA()<<endl;
                    recur<<aux->getCalificada()<<endl;
                    for(int j=0;j<aux->getN_alumnosA();j++)
                    {
                        recur<<aux->getLista_alumnosA()[j].getNIA()<<endl;
                        recur<<aux->getLista_alumnosA()[j].getTitulacionS()<<endl;
                        recur<<aux->getLista_alumnosA()[j].getApuntado()<<endl;
                       if(aux->getCalificada()==1) recur<<aux->getLista_calificaciones()[j]<<endl;
                    }
                lista_recursos[i]=dynamic_cast<Asignatura*>(aux);
                }
                else if(clase[0]=='9')   //Seminario
                {
                    Seminario* aux1;
                    recur<<lista_recursos[i]->getCodA()<<endl;
                    recur<<lista_recursos[i]->getEstado()<<endl;
                    recur<<lista_recursos[i]->getProfesorR().getNIFP()<<endl;
                    recur<<"Seminario"<<endl;
                    aux1=dynamic_cast<Seminario*>(lista_recursos[i]);
                    recur<<aux1->getponente()<<endl;
                    recur<<aux1->getPlazas()<<endl;
                    recur<<aux1->getyear()<<endl;
                    recur<<aux1->getmonth()<<endl;
                    recur<<aux1->getday()<<endl;
                    recur<<aux1->getn_AlumnosS()<<endl;
                    for(int k=0;k<aux1->getn_AlumnosS();k++)
                    {
                    recur<<aux1->getListaAlumnosS()[k].getNIA()<<endl;
                    recur<<aux1->getListaAlumnosS()[k].getTitulacionS()<<endl;
                    }
                    lista_recursos[i]=dynamic_cast<Seminario*>(aux1);
                }
                else if(clase[0]=='3')   //TFE
                {
                    TFE* aux2;
                    recur<<lista_recursos[i]->getCodA()<<endl;
                    recur<<lista_recursos[i]->getEstado()<<endl;
                    recur<<lista_recursos[i]->getProfesorR().getNIFP()<<endl;
                    recur<<"TFE"<<endl;
                    aux2=dynamic_cast<TFE*>(lista_recursos[i]);
                    recur<<aux2->getTitulacionT()<<endl;
                    recur<<aux2->getCotutor().getNIFP()<<endl;
                    recur<<aux2->getAlumnoTFE().getNIA()<<endl;
                    recur<<aux2->getAlumnoTFE().getTitulacionS()<<endl;
                    lista_recursos[i]=dynamic_cast<TFE*>(aux2);
                }

            }
            cout<<"Datos de recursos guardados correctamente."<<endl;
        }
        else
        {
        cout<< "Error al abrir el fichero de recursos." << endl;
        }
        recur.close();
    }

}

void CampusVirtual::leer_fichero()
{
    nad=0,nal=0,np=0,nr=0;
    int tel=0;
    ifstream admin("C:/Users/Luis Vicente/Desktop/FicheroAD.txt");
    if(admin.is_open())
    {
        string nifad,line;
        getline(admin,line,'\n');
        nad=atoi(line.c_str());//convierte string en entero
        cout<<"Se cargan "<<nad<<" administrador/es. "<<endl;
        lista_admins=new Administrador [nad];
        for(int i=0;i<nad;i++)
        {
            getline(admin,nifad,'\n');
            lista_admins[i].setNIFA(nifad);
        }
    }
    else
    {
    cout << "Error abriendo el fichero de administradores." << endl;
    }
    admin.close();

    ifstream profe("C:/Users/Luis Vicente/Desktop/FicheroP.txt");
    if(profe.is_open())
    {
        string nifpr,linea;
        getline(profe,linea,'\n');
        np=atoi(linea.c_str());//convierte string en entero
        cout<<"Se cargan "<<np<<" profesor/es. "<<endl;
        lista_profesores=new Profesor [np];
        for(int i=0;i<np;i++)
        {
            getline(profe,nifpr,'\n');
            lista_profesores[i].setNIFP(nifpr);
        }
    }
    else
    {
    cout << "Error abriendo el fichero de profesores." << endl;
    }
    profe.close();

    ifstream alum("C:/Users/Luis Vicente/Desktop/FicheroAL.txt");
    if(alum.is_open())
    {
        int nifal,titulacionAl,apuntado;
        string line1,line2;
        getline(alum,line1,'\n');
        nal=atoi(line1.c_str());//convierte string en entero
        cout<<"Se cargan "<<nal<<" alumno/s. "<<endl;
        lista_alumnos=new Alumno [nal];
        for(int i=0;i<nal;i++)
        {
            getline(alum,line2,'\n');
            nifal=atoi(line2.c_str());
            getline(alum,line2,'\n');
            titulacionAl=atoi(line2.c_str());
            getline(alum,line2,'\n');
            apuntado=atoi(line2.c_str());
            lista_alumnos[i].setNIA(nifal);
            lista_alumnos[i].setTitulacionS(titulacionAl);
            lista_alumnos[i].setApuntado(apuntado);
        }
    }
    else
    {
    cout << "Error abriendo el fichero de alumnos." << endl;
    }
    alum.close();

    ifstream recur("C:/Users/Luis Vicente/Desktop/FicheroR.txt");
    if(recur.is_open())
    {
        Asignatura* auxi=new Asignatura;
        string lines;
        getline(recur,lines,'\n');
        nr=atoi(lines.c_str());//convierte string en entero
        cout<<"Se cargan "<<nr<<" recurso/s. "<<endl;
        for(int i=0;i<nr;i++)
        {
            string nifprofesorR,codA,lines2;
            Profesor profesorR;
            int estadoA;
            getline(recur,lines2,'\n');//codA
            codA=lines2;
            getline(recur,lines2,'\n');
            estadoA=atoi(lines2.c_str());
            getline(recur,nifprofesorR,'\n');//ProfesorR
            profesorR.setNIFP(nifprofesorR);
            getline(recur,lines2,'\n');
            if(lines2=="Asignatura")
            {
                int creditos,titulacionA,titulacionAS,nalumA,niaalumA,apuntado,calificada;
                float calif;
                string nifProfesor2,lines3;
                Profesor profesor2;
                getline(recur,nifProfesor2,'\n');
                profesor2.setNIFP(nifProfesor2);
                getline(recur,lines3,'\n');
                creditos=atoi(lines3.c_str());
                getline(recur,lines3,'\n');
                titulacionAS=atoi(lines3.c_str());
                getline(recur,lines3,'\n');
                nalumA=atoi(lines3.c_str());
                getline(recur,lines3,'\n');
                calificada=atoi(lines3.c_str());
                float *listacalif=new float[nalumA];
                Alumno *alumnoA=new Alumno[nalumA];
                if(nalumA>0)
                {
                for(int j=0;j<nalumA;j++)
                {
                    getline(recur,lines2,'\n');
                    niaalumA=atoi(lines2.c_str());
                    alumnoA[j].setNIA(niaalumA);
                    getline(recur,lines2,'\n');
                    titulacionA=atoi(lines2.c_str());
                    alumnoA[j].setTitulacionS(titulacionA);
                    getline(recur,lines2,'\n');
                    apuntado=atoi(lines2.c_str());
                    alumnoA[j].setApuntado(apuntado);
                   if(calificada==1)
                   {
                    getline(recur,lines2,'\n');
                    calif=atof(lines2.c_str());
                    listacalif[j]=calif;
                   }
                }
                }
                Asignatura aux(titulacionAS,creditos,profesor2,codA,estadoA,profesorR);
                aux.setN_alumnosA(nalumA);
                if (nalumA>0)
                {
                aux.setLista_alumnosA(alumnoA);

                    if(calificada==1)
                    {
                    aux.setLista_calificaciones(listacalif);
                    }
                }
                auxi=&aux;
                lista_recursos.push_back(auxi);
                tel=i;
                //lista_recursos[i]->Display();
            }


        }
    }
    else
    {
    cout << "Error abriendo el fichero de recursos." << endl;
    }
    recur.close();
}
