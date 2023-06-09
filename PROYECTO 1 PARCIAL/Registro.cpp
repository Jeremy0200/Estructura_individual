
/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 04/06/2023
FECHA DE MODIFICACIÓN: 04/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
/***********************************************************************
 * Module:  Registro.cpp
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:25:42
 * Purpose: Implementation of the class Registro
 ***********************************************************************/
#include "Fecha.h"
#include "Registro.h"
#include "Validacion.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Registro::registrarEntrada()
// Purpose:    Implementation of Registro::registrarEntrada()
// Return:     int
////////////////////////////////////////////////////////////////////////
void Registro::registrarEntrada(void)
{
   Validacion validacion;
   Fecha fecha;
   string cedula, dia, mes, anio, hora, minutos, segundos, fechaActualS;
   bool bandera = false;
   bool bandera2 = false;

   do
   {
      cout << "Ingrese la cedula: " << endl;
      cin >> cedula;
      bandera = validacion.verificarUsuario(cedula);
      if (bandera == false)
      {
         cout << "Usuario no registrado" << endl;
      }
   } while (bandera == false);

   cout << "Ingrese el dia: " << endl;
   dia = validacion.ingresoDia("INgrese");
   cout << "Ingrese el mes: " << endl;
   mes = validacion.ingresoMes("INgrese");
   cout << "Ingrese el anio: " << endl;
   anio = validacion.ingresoAnio("INgrese");

   cout << "Ingrese la hora: " << endl;
   hora = validacion.ingresarHora("INgrese");
   cout << "Ingrese los minutos: " << endl;
   minutos = validacion.ingresarMinuto("INgrese");
   cout << "Ingrese los segundos: " << endl;
   segundos = validacion.ingresarSegundo("INgrese");

   fecha.setDia(dia);
   fecha.setMes(mes);
   fecha.setAno(anio);
   fecha.setHora(hora);
   fecha.setMinutos(minutos);
   fecha.setSegundos(segundos);
   string texto = cedula + " " + fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno() + " " + fecha.getHora() + ":" + fecha.getMinutos() + ":" + fecha.getSegundos() + "\n";

   fechaActualS = fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno();
   bandera2 = validacion.isDateValid(fechaActualS, "RegistroEntrada.txt");

   if (bandera2 == true)
   {
      cout << "Fecha no valida" << endl;
   }
   else
   {
      guardarTXT(texto, "RegistroEntrada.txt");
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::registrarSalida()
// Purpose:    Implementation of Registro::registrarSalida()
// Return:     int
////////////////////////////////////////////////////////////////////////

void Registro::registrarSalida(void)
{
   Validacion validacion;
   Fecha fecha;
   string cedula, dia, mes, anio, hora, minutos, segundos, fechaActualS;
   bool bandera = false;
   bool bandera2 = false;

   do
   {
      cout << "Ingrese la cedula: " << endl;
      cin >> cedula;
      bandera = validacion.verificarUsuario(cedula);
      if (bandera == false)
      {
         cout << "Usuario no registrado" << endl;
      }
   } while (bandera == false);

   cout << "Ingrese el dia: " << endl;
   dia = validacion.ingresoDia("INgrese");
   cout << "Ingrese el mes: " << endl;
   mes = validacion.ingresoMes("INgrese");
   cout << "Ingrese el anio: " << endl;
   anio = validacion.ingresoAnio("INgrese");

   cout << "Ingrese la hora: " << endl;
   hora = validacion.ingresarHora("INgrese");
   cout << "Ingrese los minutos: " << endl;
   minutos = validacion.ingresarMinuto("INgrese");
   cout << "Ingrese los segundos: " << endl;
   segundos = validacion.ingresarSegundo("INgrese");

   fecha.setDia(dia);
   fecha.setMes(mes);
   fecha.setAno(anio);
   fecha.setHora(hora);
   fecha.setMinutos(minutos);
   fecha.setSegundos(segundos);
   string texto = cedula + " " + fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno() + " " + fecha.getHora() + ":" + fecha.getMinutos() + ":" + fecha.getSegundos() + "\n";

   fechaActualS = dia + "/" + mes + "/" + anio;
   bandera2 = validacion.isDateValid(fechaActualS, "RegistroSalida.txt");
   cout << "FECHA ACTUAL:" << fechaActualS << endl;
   if (bandera2 == true)
   {
      cout << "Fecha no valida" << endl;
   }
   else
   {
      guardarTXT(texto, "RegistroSalida.txt");
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::registrarPersona()
// Purpose:    Implementation of Registro::registrarPersona()
// Return:     int
////////////////////////////////////////////////////////////////////////

// int Registro::registrarPersona(void)
// {
//    // TODO : implement
//    return 0;
// }

////////////////////////////////////////////////////////////////////////
// Name:       Registro::guardarTXT()
// Purpose:    Implementation of Registro::guardarTXT()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Registro::guardarTXT(std::string texto, std::string nombreArchivo)
{
   std::ofstream archivo;
   archivo.open(nombreArchivo, ios::app);
   if (archivo.fail())
   {
      cout << "No se pudo abrir el archivo";
      exit(1);
   }
   archivo << texto + "\n";
   archivo.close();
}

void Registro::registrarEntradaAutomatico()
{
   Validacion validacion;
   Fecha fecha;
   string cedula, dia, mes, anio, hora, minutos, segundos, fechaActualS;
   bool bandera = false;
   bool bandera2 = false;

   time_t tiempoActual = time(nullptr);
   tm *fechaActual = localtime(&tiempoActual);

   int diaActual = fechaActual->tm_mday;
   int mesActual = fechaActual->tm_mon + 1;
   int anioActual = fechaActual->tm_year + 1900;
   int horaActual = fechaActual->tm_hour;
   int minutosActual = fechaActual->tm_min;
   int segundosActual = fechaActual->tm_sec;

   do
   {
      cout << "Ingrese la cedula: " << endl;
      cin >> cedula;
      bandera = validacion.verificarUsuario(cedula);
      if (bandera == false)
      {
         cout << "Usuario no registrado" << endl;
      }
   } while (bandera == false);

   dia = to_string(diaActual);

   mes = to_string(mesActual);
   anio = to_string(anioActual);
   hora = to_string(horaActual);
   minutos = to_string(minutosActual);
   segundos = to_string(segundosActual);

   fecha.setDia(dia);
   fecha.setMes(mes);
   fecha.setAno(anio);
   fecha.setHora(hora);
   fecha.setMinutos(minutos);
   fecha.setSegundos(segundos);
   string texto = cedula + " " + fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno() + " " + fecha.getHora() + ":" + fecha.getMinutos() + ":" + fecha.getSegundos() + "\n";
   fechaActualS = fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno();
   cout << "FECHA ACTUAL:" << fechaActualS << endl;
   bandera2 = validacion.isDateValid(fechaActualS, "RegistroEntrada.txt");
  
      guardarTXT(texto, "RegistroEntrada.txt");
   
}

void Registro::registrarSalidaAutomatico()
{
   Validacion validacion;
   Fecha fecha;
   string cedula, dia, mes, anio, hora, minutos, segundos, fechaActualS;
   bool bandera = false;
   bool bandera2 = false;

   time_t tiempoActual = time(nullptr);
   tm *fechaActual = localtime(&tiempoActual);

   int diaActual = fechaActual->tm_mday;
   int mesActual = fechaActual->tm_mon + 1;
   int anioActual = fechaActual->tm_year + 1900;
   int horaActual = fechaActual->tm_hour;
   int minutosActual = fechaActual->tm_min;
   int segundosActual = fechaActual->tm_sec;

   do
   {
      cout << "Ingrese la cedula: " << endl;
      cin >> cedula;
      bandera = validacion.verificarUsuario(cedula);
      if (bandera == false)
      {
         cout << "error invalida" << endl;
      }
   } while (bandera == false);

   dia = to_string(diaActual);

   mes = to_string(mesActual);
   anio = to_string(anioActual);
   hora = to_string(horaActual);
   minutos = to_string(minutosActual);
   segundos = to_string(segundosActual);

   fecha.setDia(dia);
   fecha.setMes(mes);
   fecha.setAno(anio);
   fecha.setHora(hora);
   fecha.setMinutos(minutos);
   fecha.setSegundos(segundos);
   string texto = cedula + " " + fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno() + " " + fecha.getHora() + ":" + fecha.getMinutos() + ":" + fecha.getSegundos() + "\n";
   fechaActualS = fecha.getDia() + "/" + fecha.getMes() + "/" + fecha.getAno();
   bandera2 = validacion.isDateValid(fechaActualS, "RegistroSalida.txt");

      guardarTXT(texto, "RegistroSalida.txt");
   
}
void Registro::mostrarRegistrosEntrada(){
   string line;
    string lectura;
    Validacion validacion;
    lectura = validacion.leerArchivoTxtEspecifico("RegistroEntrada.txt");
    stringstream input_stringstream(lectura);
    cout<<"REGISTROS DE ENTRADA"<<endl;
    cout << "Cedula    Fecha" << endl;
    cout << "===========================================================================" << endl;
    while (getline(input_stringstream, line, '\n'))
    {
        cout << line << endl;
    }
    cout << "===========================================================================" << endl;
}
void Registro::mostrarRegistrosSalida(){
   string line;
    string lectura;
    Validacion validacion;
    lectura = validacion.leerArchivoTxtEspecifico("RegistroSalida.txt");
    stringstream input_stringstream(lectura);
    cout<<"REGISTROS DE SALIDA"<<endl;
    cout << "Cedula    Fecha" << endl;
    cout << "===========================================================================" << endl;
    while (getline(input_stringstream, line, '\n'))
    {
        cout << line << endl;
    }
    cout << "===========================================================================" << endl;
}
