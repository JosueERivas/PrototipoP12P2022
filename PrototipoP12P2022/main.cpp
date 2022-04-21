//Librerias
#include <string>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

//Clases
#include <Clsusuarios.h>

using namespace std;

//Funciones
void crearArchivoUsuarios();
void usuarioDefault( fstream& );
int obtenerUsuario( const char * const );

int main()
{
    //Autenticacion variables
    char nusuario[20];
    int contrasena;
    int acceso=1;

    //Objeto usuario
    Clsusuarios usuario;
    //comprobando usuarios
    fstream archivoUsuarios("registrousuarios.dat", ios::in | ios::out | ios::binary);
    if ( !archivoUsuarios ){
            cerr << "No se pudo abrir el archivo." << endl;
            crearArchivoUsuarios();
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 0 );
        }
    usuarioDefault(archivoUsuarios);

    //Autenticacion
    cout << "Ingrese su usuario" << endl;
    cin >> nusuario;
    string nombreUsuario;
   // obtener el número de cuenta a buscar
   int numeroUsuario = obtenerUsuario("");

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoUsuarios.seekg(
      ( numeroUsuario - 1 ) * sizeof( Clsusuarios ) );

   // leer el primer registro del archivo
   archivoUsuarios.read( reinterpret_cast< char * >( &usuario ),
      sizeof( Clsusuarios ) );



   if ( usuario.mobtenerIngreso() != 0 )
    {
        nombreUsuario=usuario.mobtenernombreUsuario();
    }
   else
   {
       cerr <<"No esta registrado." << endl;
   }
   if (nombreUsuario==nusuario)
    {
        cout<<"Acceso concedido";
        getch();
        acceso=0;
    }
    else
    {
        cout <<"Acceso denegado";
        getch();
    }

    if(acceso==0)
    {
        system("cls");
        cout << "Entraste";
        getch();
    }

    return 0;
}

void crearArchivoUsuarios()
{
    ofstream archivoUsuarios("registrousuarios.dat", ios::out | ios::binary);
    if(!archivoUsuarios)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    Clsusuarios usuarioEnBlanco;
    for(int i=1; i<100; i++)
    {
        archivoUsuarios.write(reinterpret_cast<const char * > (&usuarioEnBlanco), sizeof(Clsusuarios));
    }
    archivoUsuarios.close();
    fstream archivoUsuario("registrousuarios.dat", ios::app | ios::out | ios::binary);
    if ( !archivoUsuario ){
            cerr << "No se pudo abrir el archivo." << endl;
            exit ( 3 );
        }
}

void usuarioDefault( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int m_iingresoUsuario = 1;

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( m_iingresoUsuario - 1 ) * sizeof( Clsusuarios ) );

   // leer el registro del archivo
   Clsusuarios usuarioprincipal;
   insertarEnArchivo.read( reinterpret_cast< char * >( &usuarioprincipal ),
      sizeof( Clsusuarios ) );


      char m_snombreUsuario[ 20 ]="Josue";

      // usar valores para llenar los valores de la clave
      usuarioprincipal.mestablecernombreUsuario( m_snombreUsuario );
      usuarioprincipal.mestablecerIngreso( m_iingresoUsuario );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( m_iingresoUsuario - 1 ) *
         sizeof( Clsusuarios ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &usuarioprincipal ),
         sizeof( Clsusuarios ) );


}

int obtenerUsuario( const char * const indicador )
{
   int m_iingresoUsuario;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << "Ingrese el password: ";
      cin >> m_iingresoUsuario;

   } while ( m_iingresoUsuario < 100 && m_iingresoUsuario > 999 );

   return m_iingresoUsuario;

}
