#ifndef CLSUSUARIOS_H
#define CLSUSUARIOS_H

//librerias
#include<string>
#include<iostream>

using std::string;

class Clsusuarios
{
    public:
        Clsusuarios( int = 0, string = "");


        void mestablecerIngreso( int ) ;
        int mobtenerIngreso() const;

        void mestablecernombreUsuario( string );
        string mobtenernombreUsuario() const;

        virtual ~Clsusuarios();

    protected:

    private:

        //Atributos
        int m_iingresoUsuario;
        char m_snombreUsuario[ 20 ];
};

#endif // CLSUSUARIOS_H
