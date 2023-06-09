
/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 04/06/2023
FECHA DE MODIFICACIÓN: 04/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
/***********************************************************************
 * Module:  Persona.h
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:00:48
 * Purpose: Declaration of the class Persona
 ***********************************************************************/
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>
#include <ctime>
#include "Fecha.cpp"
using namespace std;
#if !defined(__ClassProyecto_1_Persona_h)
#define __ClassProyecto_1_Persona_h

class Persona
{
public:
   Persona();
   Fecha getFechaNacimiento(void);
   void setFechaNacimiento(Fecha newFechaNacimiento);
   string getCedula(void);
   void setCedula(string newCedula);
   string getNombre(void);
   void setNombre(string newNombre);
   string getApellido(void);
   void setApellido(string newApellido);
   //void calcularEdad();
   string registrarNombre();
   string registrarApellido();
   char registrarEdad();
   int calcularEdad();
   void getInformacion();
   string validarCedula(string newCedula);
   string registrarCedula();
   string registrarFechaNacimiento();
   void registroPersona();
   void editarRegistroPersona(std::string registroAntiguo, std::string registroNuevo);
   void mostrarRegistroPersona();
   void buscarRegistroPersona(string busqueda);
   void eliminarRegistroPersona(string busqueda);

protected:
private:
   string cedula;
   string nombre;
   string apellido;
   Fecha fechaNacimiento;


};

#endif