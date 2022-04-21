//Librerias
#include <string>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

//Clases
#include <Clsusuarios.h>
#include <Clsequipos.h>

using namespace std;

//Funciones
void crearArchivoUsuarios();
void usuarioDefault( fstream& );
int obtenerUsuario( const char * const );
int obtenerEquipo( const char * const );
void crearArchivoEquipos();
void nuevoEquipo( fstream& );

int main()
{
    //variables menu consultas
    int sistema=1;

    //variable menu general
    int general=1;

    //variable menu equipo
    int equipo=1;

    //variable crud equipos
    int crudEquipo=1;

    //variable crud jugadores
    int crudJugador=1;

    //Autenticacion variables
    char nusuario[20];
    int contrasena;
    int acceso=1;

    while (sistema!=0)
    {
        system("cls");
        //variable menu general
        general=1;
        //menu comsultas
        cout << "Nombre: Josue Ernesto Rivas De Leon" << endl;
        cout << "Carne No. 9491-21-3133" << endl;
        cout << "Menu Sistema" << endl;
        cout << "1. Acceder al sistema" << endl;
        cout << "2. Consultar deporte" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese opcion [1/2/0]: " << endl;
        cin >> sistema;
        switch (sistema)
        {
        case 1:
            {
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
                    while(general!=0)
                    {
                        //variable menu equipo
                        equipo=1;
                        system("cls");
                        cout << "Nombre: Josue Ernesto Rivas De Leon" << endl;
                        cout << "Carne No. 9491-21-3133" << endl;
                        cout << "Menu Principal" << endl;
                        cout << "1. Gestion de equipo" << endl;
                        cout << "2. Gestion gerencial" << endl;
                        cout << "3. Gestión administrativa" << endl;
                        cout << "0. Regresar" << endl;
                        cout << "Ingrese la opcion a seleccionar [1/2/3/0]: " << endl;
                        cin >> general;
                        switch (general)
                        {
                        case 1:
                            {
                                while(equipo!=0)
                                {
                                    system("cls");
                                    //variable crud equipos
                                    crudEquipo=1;
                                    //variable crud jugadores
                                    crudJugador=1;
                                    cout << "Nombre: Josue Ernesto Rivas De Leon" << endl;
                                    cout << "Carne No. 9491-21-3133" << endl;
                                    cout << "Menu gestion de equipo" << endl;
                                    cout << "1. Equipos" << endl;
                                    cout << "2. Jugadores" << endl;
                                    cout << "0. Regresar" << endl;
                                    cout << "Ingrese la opcion a seleccionar [1/2/0]: " << endl;
                                    cin >> equipo;
                                    switch (equipo)
                                    {
                                    case 1:
                                        {
                                            while(crudEquipo!=0)
                                            {
                                                system("cls");
                                                fstream archivoEquipos("registroequipos.dat", ios::in | ios::out | ios::binary);

                                                // salir del programa si fstream no puede abrir el archivo
                                                if ( !archivoEquipos) {
                                                    cerr << "No se pudo abrir el archivo." << endl;
                                                    crearArchivoEquipos();
                                                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                                    exit ( 1 );
                                                }
                                                cout << "Nombre: Josue Ernesto Rivas De Leon" << endl;
                                                cout << "Carne No. 9491-21-3133" << endl;
                                                cout << "Menu de equipos" << endl;
                                                cout << "1. Creacion de equipos" << endl;
                                                cout << "2. Eliminacion de equipos" << endl;
                                                cout << "3. Modificacion de equipos" << endl;
                                                cout << "4. Lectura de equipos" << endl;
                                                cout << "0. Regresar" << endl;
                                                cout << "Ingrese la opcion a seleccionar [1/2/3/4/0]: " << endl;
                                                cin >> crudEquipo;
                                                switch (crudEquipo)
                                                {
                                                case 1:
                                                    {
                                                        nuevoEquipo(archivoEquipos);
                                                        cout << "guardado con exito." << endl;
                                                        getch();
                                                    }
                                                    break;
                                                case 0 :
                                                    break;
                                                default:
                                                    {
                                                        cout << "Numero ingresado no valido";
                                                        getch();
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    case 2:
                                        {
                                            while(crudJugador!=0)
                                            {
                                                system("cls");
                                                cout << "Nombre: Josue Ernesto Rivas De Leon" << endl;
                                                cout << "Carne No. 9491-21-3133" << endl;
                                                cout << "Menu de Jugadores" << endl;
                                                cout << "1. Equipos" << endl;
                                                cout << "2. Jugadores" << endl;
                                                cout << "0. Regresar" << endl;
                                                cout << "Ingrese la opcion a seleccionar [1/2/0]: " << endl;
                                                cin >> crudJugador;
                                            }
                                        }
                                        break;
                                    case 0:
                                        break;
                                    default:
                                        {
                                            cout << "valor ingresado no valido";
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        case 2:
                            {
                                cout << "gestion gerencial" << endl;
                                getch();
                            }
                            break;
                        case 3:
                            {
                                cout << "gestion administrativa" << endl;
                                getch();
                            }
                            break;
                        case 0:
                            break;
                        default:
                            {
                                cout << "Numero ingresado no valido" << endl;
                                getch();
                            }
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            {
                cout << "Usted esta en consulta" << endl;
                getch();
            }
            break;
        case 0:
            break;
        default:
            {
                cout << "Número Ingresado no válido" << endl;
                getch();
            }
            break;
        }
    }
    cout << "Fin";
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
   int m_iingresoUsuario = 1;

   insertarEnArchivo.seekg(
      ( m_iingresoUsuario - 1 ) * sizeof( Clsusuarios ) );

   // leer el registro del archivo
   Clsusuarios usuarioprincipal;
   insertarEnArchivo.read( reinterpret_cast< char * >( &usuarioprincipal ),
      sizeof( Clsusuarios ) );


      char m_snombreUsuario[ 20 ]="Josue";

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

   do {
      cout << indicador << "Ingrese el password: ";
      cin >> m_iingresoUsuario;

   } while ( m_iingresoUsuario < 100 && m_iingresoUsuario > 999 );

   return m_iingresoUsuario;

}

void crearArchivoEquipos()
{
    ofstream archivoEquipos("registroequipos.dat", ios::out | ios::binary);
    if(!archivoEquipos)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    Clsequipos equipoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEquipos.write(reinterpret_cast<const char * > (&equipoEnBlanco), sizeof(Clsequipos));
    }
}

void nuevoEquipo( fstream &insertarEnArchivo )
{
   int iequipo = obtenerEquipo( "Escriba el numero del equipo" );

   insertarEnArchivo.seekg(
      ( iequipo - 1 ) * sizeof( Clsequipos ) );

   // leer el registro del archivo
   Clsequipos equipo;
   insertarEnArchivo.read( reinterpret_cast< char * >( &equipo ),
      sizeof( Clsequipos ) );

   // crear el registro, si éste no existe ya
   if ( equipo.mobtenerIdEquipo() == 0 ) {

      char nombreEquipo[ 20 ];
      int idEnrenador;
      int idDeporte;

      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> nombreEquipo;
      cout << "Escriba el Id del entrenador: " << endl;
      cin >> idEnrenador;
      cout << "Escriba el Id del Deporte: " << endl;
      cin >> idDeporte;

      equipo.mestablecernombreEquipo( nombreEquipo );
      equipo.mestablecerIdEquipo( iequipo );
      equipo.mestablecerIdEquipo( idEnrenador );
      equipo.mestablecerIdEquipo( idDeporte );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( iequipo - 1 ) *
         sizeof( Clsequipos ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &equipo ),
         sizeof( Clsequipos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta #" << iequipo
           << " ya contiene informacion." << endl;

}

int obtenerEquipo( const char * const indicador )
{
   int equipo;

   do {
      cout << indicador << " (1 - 100): ";
      cin >> equipo;

   } while ( equipo < 1 || equipo > 100 );

   return equipo;

}
