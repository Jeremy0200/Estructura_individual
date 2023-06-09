/***********************************************************************
 * Module:  Persona.cpp
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:00:48
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"
//#include "Validacion.hpp"
#include "Fecha.h"

using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getFechaNacimiento()
// Purpose:    Implementation of Persona::getFechaNacimiento()
// Return:     int
////////////////////////////////////////////////////////////////////////

Fecha Persona::getFechaNacimiento(void)
{
   return fechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setFechaNacimiento(int newFechaNacimiento)
// Purpose:    Implementation of Persona::setFechaNacimiento()
// Parameters:
// - newFechaNacimiento
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setFechaNacimiento(Fecha newFechaNacimiento)
{
   fechaNacimiento = newFechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     int
////////////////////////////////////////////////////////////////////////

string Persona::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(int newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setCedula(string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getApellido()
// Purpose:    Implementation of Persona::getApellido()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getApellido(void)
{
   return apellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setApellido(string newApellido)
// Purpose:    Implementation of Persona::setApellido()
// Parameters:
// - newApellido
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setApellido(string newApellido)
{
   apellido = newApellido;
}

//////////////////////////////  METODOS  ///////////////////////////////////////////

string Persona::registrarNombre()
{
   Validacion validacion;
   string newNombre;
   newNombre = validacion.ingresoNombreApellido("> ");
   if (validacion.verificarUsuario(newNombre) == true)
   {
      cout << " La persona ya existe" << endl;
      newNombre = registrarNombre();
   }
   return newNombre;
}
string Persona::registrarApellido()
{
   Validacion validacion;
   string newApellido;
   newApellido = validacion.ingresoNombreApellido("> ");
   if (validacion.verificarUsuario(newApellido) == true)
   {
      cout << " La persona ya existe" << endl;
      newApellido = registrarApellido();
   }
   return newApellido;
}
string Persona::registrarFechaNacimiento()
{
   Validacion validacion;
   Fecha nacimiento;
   string newDia, newMes, newAnio;
   string newFechaN;

   cout << endl
        << " \n Ingrese los datos de su fecha de Nacimiento:" << endl;
   cout << endl
        << " \n Día: " << endl;
   cin >> newDia;
   newDia = validacion.ingresoDia("> ");
   ;
   nacimiento.setDia(newDia);
   cout << endl
        << "\nMes: " << endl;
   newMes = validacion.integerImput("> ");
   ;
   nacimiento.setMes(newMes);
   cout << endl
        << " \nAño: " << endl;
   newAnio = validacion.integerImput("> ");
   ;
   nacimiento.setAno(newAnio);

   //cout << "\nDia de nacimiento: " << newDia << " \nMes nacimiento: " << newMes << "\nAnio de nacimiento: " << newAnio << endl;

   this->setFechaNacimiento(nacimiento);

   return newFechaN;
}
string Persona::validarCedula(string newCedula)
{
   string cedula;
   char cedulaPares[5];
   char cedulaImpares[5];

   int cedulaParte1[5];
   int cedulaParte2[5];

   int sumaPares = 0;
   int sumaImpares = 0;
   int sumaTotal = 0;
   int digitoVerificador = 0;
   cedula = newCedula;
   for (int i = 0; i < 10; i++)
   {
      if (i % 2 == 0)
      {
         cedulaPares[i] = newCedula[i];
         cedulaParte1[i] = atoi(&cedulaPares[i]);
         cedulaParte1[i] = cedulaParte1[i] * 2;
         if (cedulaParte1[i] > 9)
         {
            cedulaParte1[i] = cedulaParte1[i] - 9;
         }
         sumaPares = sumaPares + cedulaParte1[i];
      }
      else if (i % 2 != 0)
      {
         cedulaImpares[i] = newCedula[i];
         cedulaParte2[i] = atoi(&cedulaImpares[i]);

         if (i != 9)
         {
            sumaImpares = sumaImpares + cedulaParte2[i];
         }
      }
      if (i == 9)
      {
         sumaTotal = sumaPares + sumaImpares;
         digitoVerificador = sumaTotal % 10;

         if (digitoVerificador != 0)
         {
            digitoVerificador = 10 - digitoVerificador;
         }
      }
   }

   if (digitoVerificador == atoi(&(newCedula[9])))
   {
      cout << " Cedula Valida" << endl;
   }
   else if (digitoVerificador != atoi(&(newCedula[9])))
   {

      cout << " Cedula Invalida" << endl;
      cedula = "0";
   }
   return cedula;
}

string Persona::registrarCedula()
{
   Validacion validacion;
   char *newCedula;
   string cedulaValidada, aux;
   bool existe = false;
   do
   {
      newCedula = validacion.integerImput("> ");
      aux = newCedula;

      cedulaValidada = validarCedula(aux); // llamamos la funcion de validar cedula

      if (cedulaValidada == "0")
      {
         cout << " Cedula Invalida, Ingrese nuevamente" << endl;
      }
      existe = validacion.verificarUsuario(cedulaValidada);
      if (existe == true)
      {
         cout << "La persona ya existe, ingrese uno valido" << endl;
      }

   } while (aux != cedulaValidada || existe == true);

   return aux;
}

int Persona::calcularEdad()
{
   time_t tiempoActual = time(nullptr);
   tm *fechaActual = localtime(&tiempoActual);

   int diaActual = fechaActual->tm_mday;
   int mesActual = fechaActual->tm_mon + 1;      // Los meses en struct tm van de 0 a 11
   int anioActual = fechaActual->tm_year + 1900; // Se suma 1900 al año en struct tm
   int diaNacimiento = atoi(this->getFechaNacimiento().getDia().c_str());
   int mesNacimiento = atoi(this->getFechaNacimiento().getMes().c_str());
   int anioNacimiento = atoi(this->getFechaNacimiento().getAno().c_str());
   int edad = anioActual - anioNacimiento;

   // Ajustar la edad si aún no se ha cumplido el día y el mes de nacimiento
   if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
   {
      edad--;
   }
   cout << "\nDia de nacimiento: " << diaNacimiento << " Mes nacimiento" << mesNacimiento << "Anio de nacimiento" << anioNacimiento << endl;
   cout << "\nedad: " << edad << endl;
   return edad;
}




void Persona::getInformacion()
{
   cout << "Nombre: " << nombre << endl;
   cout << "Apellido: " << apellido << endl;
   cout << "Cedula: " << cedula << endl;
   cout << "Fecha de Nacimiento: " << fechaNacimiento.getDia() << "/" << fechaNacimiento.getMes() << "/" << fechaNacimiento.getAno() << endl;
   // cout<<"EdadActual: "<<horasExtra<<endl;
}

void Persona::registroPersona()
{
   string newNombre, newApellido, newCedula;
   string datos;
   Registro registro;
   cout << endl
        << " \nIngrese la cedula: " << endl;
   newCedula = registrarCedula();
   this->setCedula(newCedula);
   cout << endl
        << "\nIngrese el nombre " << endl;
   newNombre = registrarNombre();
   this->setNombre(newNombre);
   cout << endl
        << " \nIngrese el apellido:" << endl;
   newApellido = registrarApellido();
   this->setApellido(newApellido);
   cout << " \nPersona registrada con exito" << endl;
   datos= newCedula + " "+ newNombre+" " + newApellido+" " + "\n";
   registrarFechaNacimiento();
   calcularEdad();
   registro.guardarTXT(datos, "Personas.txt");
}

void Persona::editarRegistroPersona(std::string registroAntiguo, std::string registroNuevo)
{
   std::ifstream archivo("Personas.txt");
   std::string contenido, linea;

   
   while (std::getline(archivo, linea))
   {
      contenido += linea+"\n";
   }
   archivo.close();

   size_t posicionNombre = contenido.find(registroAntiguo);
   while (posicionNombre != std::string::npos)
   {
      contenido.replace(posicionNombre, registroAntiguo.length(), registroNuevo);
      posicionNombre = contenido.find(registroAntiguo, posicionNombre + registroNuevo.length());
   }


   std::ofstream archivo_salida("Personas.txt");
   archivo_salida << contenido;
   archivo_salida.close();

   cout<<"Se ha editado el registro"<<endl;
}


void Persona::mostrarRegistroPersona()
{
    string line;
    string lectura;
    Validacion validacion;
    lectura = validacion.leerArchivoTxt();
    stringstream input_stringstream(lectura);
    cout << "Cedula    Nombre    Apellido   Fecha" << endl;
    cout << "===========================================================================" << endl;
    while (getline(input_stringstream, line, '\n'))
    {
        cout << line << endl;
    }
    cout << "===========================================================================" << endl;
}

void Persona::buscarRegistroPersona(string busqueda)
{
   
   string resultado;
   Validacion validacion;
   resultado = validacion.buscarEnLista(busqueda);
   cout<<resultado<<endl;

}

void Persona::eliminarRegistroPersona(string busqueda)
{
    std::ifstream archivo("Personas.txt");
    std::vector<std::string> lineas;
    std::string linea;

    
    while (std::getline(archivo, linea)) {
        lineas.push_back(linea);
    }
    archivo.close();

    
    for (auto it = lineas.begin(); it != lineas.end(); ) {
        if ((*it).find(busqueda) != std::string::npos) {
            it = lineas.erase(it);
            std::cout << "Linea eliminada." << std::endl;
        } else {
            ++it;
        }
    }

    
    std::ofstream archivo_salida("Personas.txt");
    for (const std::string& linea : lineas) {
        archivo_salida << linea << std::endl;
    }
    archivo_salida.close();


}