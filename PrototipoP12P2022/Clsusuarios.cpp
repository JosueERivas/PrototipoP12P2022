#include "Clsusuarios.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

//constructor
Clsusuarios::Clsusuarios(int ivalorIngreso, string svalorUsuario)
{
    mestablecerIngreso(ivalorIngreso);
    mestablecernombreUsuario(svalorUsuario);
}

int Clsusuarios::mobtenerIngreso() const
{
    return m_iingresoUsuario;
}

void Clsusuarios::mestablecerIngreso (int iingreso)
{
    m_iingresoUsuario = iingreso;
}

string Clsusuarios::mobtenernombreUsuario() const
{
    return m_snombreUsuario;
}

void Clsusuarios::mestablecernombreUsuario( string scadenaUsuario )
{

   const char *svalorUsuario = scadenaUsuario.data();
   int ilongitud = strlen( svalorUsuario );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreUsuario, svalorUsuario, ilongitud );


   m_snombreUsuario[ ilongitud ] = '\0';

}

Clsusuarios::~Clsusuarios()
{
    //dtor
}
