#include "Clsequipos.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

//constructor
Clsequipos::Clsequipos(int iequipo, string sequipo, int ientrenador, int ideporte)
{
    mestablecerIdEquipo(iequipo);
    mestablecernombreEquipo(sequipo);
    mestablecerIdEntrenador(ientrenador);
    mestablecerIdDeporte(ideporte);
}

int Clsequipos::mobtenerIdEquipo() const
{
    return idEquipo;
}

void Clsequipos::mestablecerIdEquipo (int iiequipo)
{
    idEquipo = iiequipo;
}

string Clsequipos::mobtenernombreEquipo() const
{
    return nombreEquipo;
}

void Clsequipos::mestablecernombreEquipo( string scequipo )
{

   const char *sequipo = scequipo.data();
   int ilongitud = strlen( sequipo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( nombreEquipo, sequipo, ilongitud );

   nombreEquipo[ ilongitud ] = '\0';

}

int Clsequipos::mobtenerIdEntrenador() const
{
    return idEntrenador;
}

void Clsequipos::mestablecerIdEntrenador (int iientrenador)
{
    idEntrenador = iientrenador;
}

int Clsequipos::mobtenerIdDeporte() const
{
    return idDeporte;
}

void Clsequipos::mestablecerIdDeporte (int iideporte)
{
    idDeporte = iideporte;
}

Clsequipos::~Clsequipos()
{
    //dtor
}
