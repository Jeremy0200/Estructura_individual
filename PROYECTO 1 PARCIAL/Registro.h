
/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 04/06/2023
FECHA DE MODIFICACIÓN: 04/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
/***********************************************************************
 * Module:  Registro.h
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:25:42
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#if !defined(__ClassProyecto_1_Registro_h)
#define __ClassProyecto_1_Registro_h

#include <cstring>
#include <string>
#include <ctime>
class Registro
{
public:

   void registrarEntrada(void);
   void registrarSalida(void);
   int registrarPersona(void);
   int registrarAsistencia(void);
   void registrarEntradaAutomatico(void);
   void registrarSalidaAutomatico(void);
   void mostrarRegistrosEntrada(void);
   void mostrarRegistrosSalida(void);


   
   void guardarTXT(std::string texto,std::string nombreArchivo);

protected:
private:


};

#endif