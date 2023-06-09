
/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 27/05/2023
FECHA DE MODIFICACIÓN: 7/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
/***********************************************************************
 * Module:  Fecha.h
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:05:56
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__ClassProyecto_1_Fecha_h)
#define __ClassProyecto_1_Fecha_h
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>
using namespace std;
class Fecha
{
public:
   string getSegundos(void);
   void setSegundos(string newSegundos);
   string getAno(void);
   void setAno(string newAno);
   string getMes(void);
   void setMes(string newMes);
   string getDia(void);
   void setDia(string newDia);
   string getHora(void);
   void setHora(string newHora);
   string getMinutos(void);
   void setMinutos(string newMinutos);
   Fecha();
   Fecha(string newDia, string newMes, string newAno);
protected:
private:
   string ano;
   string mes;
   string dia;
   string hora;
   string minutos;
   string segundos;


};

#endif