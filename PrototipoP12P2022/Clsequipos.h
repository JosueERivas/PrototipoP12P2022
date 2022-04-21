#ifndef CLSEQUIPOS_H
#define CLSEQUIPOS_H

//librerias
#include<string>
#include<iostream>

using std::string;


class Clsequipos
{
    public:
        Clsequipos(int = 0, string = "", int = 0, int = 0);

        void mestablecerIdEquipo( int ) ;
        int mobtenerIdEquipo() const;

        void mestablecernombreEquipo( string );
        string mobtenernombreEquipo() const;

        void mestablecerIdEntrenador( int ) ;
        int mobtenerIdEntrenador() const;

        void mestablecerIdDeporte( int ) ;
        int mobtenerIdDeporte() const;

        virtual ~Clsequipos();

    protected:

    private:
        int idEquipo;
        char nombreEquipo[50];
        int idEntrenador;
        int idDeporte;
};

#endif // CLSEQUIPOS_H
