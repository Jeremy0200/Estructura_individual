/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 27/05/2023
FECHA DE MODIFICACIÓN: 30/05/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
/***********************************************************************
 * Module:  Fecha.cpp
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:05:56
 * Purpose: Implementation of the class Fecha
 ***********************************************************************/

#include "Fecha.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>

using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getSegundos()
// Purpose:    Implementation of Fecha::getSegundos()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Fecha::getSegundos(void)
{
   return segundos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setSegundos(string newSegundos)
// Purpose:    Implementation of Fecha::setSegundos()
// Parameters:
// - newSegundos
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setSegundos(string newSegundos)
{
   segundos = newSegundos;
}



////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getAno()
// Purpose:    Implementation of Fecha::getAno()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Fecha::getAno(void)
{
   return ano;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setAno(string newAno)
// Purpose:    Implementation of Fecha::setAno()
// Parameters:
// - newAno
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setAno(string newAno)
{
   ano = newAno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getMes()
// Purpose:    Implementation of Fecha::getMes()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Fecha::getMes(void)
{
   return mes;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setMes(string newMes)
// Purpose:    Implementation of Fecha::setMes()
// Parameters:
// - newMes
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setMes(string newMes)
{
   mes = newMes;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getDia()
// Purpose:    Implementation of Fecha::getDia()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Fecha::getDia(void)
{
   return dia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setDia(string newDia)
// Purpose:    Implementation of Fecha::setDia()
// Parameters:
// - newDia
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setDia(string newDia)
{
   dia = newDia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getHora()
// Purpose:    Implementation of Fecha::getHora()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Fecha::getHora(void)
{
   return hora;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setHora(string newHora)
// Purpose:    Implementation of Fecha::setHora()
// Parameters:
// - newHora
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setHora(string newHora)
{
   hora = newHora;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::Fecha()
// Purpose:    Implementation of Fecha::Fecha()
// Return:     
////////////////////////////////////////////////////////////////////////
string Fecha::getMinutos(void){
   return minutos;
}
void Fecha::setMinutos(string newMinutos){
   minutos = newMinutos;
}
Fecha::Fecha()
{
}


Fecha::Fecha(string newDia, string newMes, string newAno)
{

   this->dia= newDia;
   this->mes= newMes;
   this->ano= newAno;
   this->hora= "00";
   this->minutos= "00";
   this->segundos= "00";
}

