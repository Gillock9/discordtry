#ifndef CAMPUSVIRTUAL_H
#define CAMPUSVIRTUAL_H
#include <iostream>
#include <administrador.h>
#include <profesor.h>
#include <alumno.h>
#include <recurso.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <fstream>

class CampusVirtual
{ private:
    int nad=0, np=0, nal=0, nr=0;
    Administrador *lista_admins;
    Profesor *lista_profesores;
    Alumno *lista_alumnos;
    vector <Recurso*> lista_recursos;

public:
    void alta_admin();
    void baja_admin();
    void mostrar_admin();
    void modif_admin();

    void alta_profesor();
    void baja_profesor();
    void mostrar_profesor();
    void modif_profesor();

    void alta_alumno();
    void baja_alumno();
    void mostrar_alumno();
    void modif_alumno();

    void alta_recurso();
    void baja_recurso();
    void mostrar_recurso();
    void modif_recurso_admin();
    void modif_recurso_profesor(string nifpr);

    void inicio();
    void Calificar();
    void mostrar_calif();

    void apuntar_asig();
    void apuntar_semi();
    void apuntar_TFE();

    void desapuntar_asig();
    void desapuntar_semi();
    void desapuntar_TFE();

    void guardar_fichero();
    void leer_fichero();

    CampusVirtual();
    ~CampusVirtual();

    Administrador *getLista_admins() const;
    void setLista_admins(Administrador *value);

    Profesor *getLista_profesores() const;
    void setLista_profesores(Profesor *value);

    Alumno *getLista_alumnos() const;
    void setLista_alumnos(Alumno *value);

    vector<Recurso *> getLista_recursos() const;
    void setLista_recursos(const vector<Recurso *> &value);
    int getNr() const;
    void setNr(int value);
};


#endif // CAMPUSVIRTUAL_H
