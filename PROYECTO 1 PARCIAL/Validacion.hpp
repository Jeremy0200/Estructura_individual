#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "ListaDoble.h"
using namespace std;

class Validacion
{
public:
    char *integerImput(char const *msj)
    {
        char *dato = new char[0];
        char c;
        int i = 0;
        cout << msj;
        while ((c = getch()) != 13)
        {
            if (c >= '0' && c <= '9')
            {
                cout << c;
                dato[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
        }
        dato[i] = '\0';
        return dato;
    }

    char *charImput(char const *msj)
    {

        char *a = new char[0];
        char c;
        int i = 0;
        cout << msj;
        while ((c = getch()) != 13)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == ' ')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
        }
        a[i] = '\0';
        return a;
    }

    char *ingresoCedula(char const *msj)
    {
        int i = 0;
        char *dato = new char[0];
        char c;
        cout << msj;
        do
        {
            i = 0;
            while ((c = getch()) != 13)
            {
                if (c >= '0' && c <= '9' && i <= 9)
                {
                    cout << c;
                    dato[i++] = c;
                }
                else if (c == '\b')
                {
                    i--;
                    cout << "\b \b";
                }
            }
            if (i < 9)
            {
                cout << "\n\tFaltan " << 9 - i << " digitos" << endl;
            }
        } while (i < 9);
        dato[i] = '\0';
        return dato;
    }

    char *ingresoNombreApellido(char const *msj)
    {
        char *a = new char[0];
        char c;
        int i = 0;
        cout << msj;
        while ((c = getch()) != 13)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
            if (a[0] >= 'a' && a[0] <= 'z')
            {
                a[0] = a[0] - 32;
            }
        }
        a[i] = '\0';
        return a;
    }

    string ingresoDia(char const *msj)
    {

        int dia = 0;
        string entero;

        do
        {
            cout << "Dia: ";
            entero = integerImput(">");
            cout << "\n";
            // cout << "prueba: " << entero << endl;

            dia = atoi(entero.c_str());
        } while (dia > 31);

        return entero;
    }

    string ingresoMes(char const *msj)
    {

        int mes = 0;
        string entero;

        do
        {
            cout << "Mes: ";
            entero = integerImput(">");

            cout << "\n";
            // cout << "prueba: " << entero << endl;
            mes = atoi(entero.c_str());
        } while (mes > 12);

        return entero;
    }

    string ingresoAnio(char const *msj)
    {

        int anio = 0;
        string entero;

        do
        {
            cout << "Anio: ";
            entero = integerImput(">");
            cout << "\n";
            //  cout << "prueba: " << entero << endl;
            anio = atoi(entero.c_str());
        } while (anio > 2023);

        return entero;
    }
    // template <typename T>
    ListaDoble<string> split(string str, char pattern)
    {
    //separa cada palabra con un espacio
        int posInit = 0;
        int posFound = 0;
        string splitted;
        ListaDoble<string> results;
        // vector<string> results;

        while (posFound >= 0)
        {
            posFound = str.find(pattern, posInit);
            splitted = str.substr(posInit, posFound - posInit); // separa informacion en posiciones enteras
            posInit = posFound + 1;
            results.insertarCabeza(splitted);
        }

        return results;
    }

    bool verificarUsuario(string datoBuscar)
    {

        // vector<string> results;
        ListaDoble<string> results;
        Nodo<string> *aux3;

        string line;
        string lectura;
        lectura = leerArchivoTxt();
        char delimitador = '\n';
        stringstream input_stringstream(lectura);

        while (getline(input_stringstream, line, delimitador))
        {

            results = split(line, ' ');
            aux3 = results.getCabeza();
            while (aux3 != nullptr)
            {
                if (aux3->getDato() == datoBuscar)
                {
                    return true;
                }
                aux3 = aux3->getSiguiente();
            }

            // for (int i = 0; i < results.size(); i++)
            // {
            //     // cout << results[i] << endl;
            //     if (results[i] == datoBuscar)
            //     {
            //         return true;
            //     }
            // }
        }
        return false;
    }

    string buscarEnLista(string datoBuscar)
    {

        // vector<string> results;
        ListaDoble<string> results;
        Nodo<string> *aux2;
        string line;
        string lectura;
        lectura = leerArchivoTxt();
        char delimitador = '\n';
        stringstream input_stringstream(lectura);

        while (getline(input_stringstream, line, delimitador))
        {
            results = split(line, ' ');
            aux2 = results.getCabeza();
            while (aux2 != nullptr)
            {
                if (aux2->getDato() == datoBuscar)
                {
                    return line;
                }
                aux2 = aux2->getSiguiente();
            }
            // for (int i = 0; i < results.size(); i++)
            // {
            //     if (results[i] == datoBuscar)
            //     {
            //         return line;
            //     }
            // }
        }
        return line;
    }

    // int charToInt()
    // {
    //     char dato[10];
    //     int valor = 0;
    //     strcpy(dato, integerImput("\n> "));
    //     valor = atoi(dato);
    //     return valor;
    // }

   

    string leerArchivoTxt()
    {
        string texto;
        string lectura;
        ifstream archivo;
        archivo.open("Personas.txt", ios::in);
        if (archivo.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
        archivo.close();
        return lectura;
    }
    string leerArchivoTxtEspecifico(string archivoTxt)
    {
        string texto;
        string lectura;
        ifstream archivo;
        archivo.open(archivoTxt, ios::in);
        if (archivo.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
        archivo.close();
        return lectura;
    }
    // Hora
    string ingresarHora(char const *msj)
    {
        int hora = 0;
        string entero;
        do
        {
            cout << "Hora: ";
            entero = integerImput(">");
            // cout << "prueba: " << entero << endl;
            cout << "\n";
            hora = atoi(entero.c_str());
        } while (hora < 0 || hora > 23);

        return entero;
    }
    // Minuto
    string ingresarMinuto(char const *msj)
    {
        int minuto = 0;
        string entero;
        do
        {
            cout << "Minuto: ";
            entero = integerImput(">");
            // cout << "prueba: " << entero << endl;
            cout << "\n";
            minuto = atoi(entero.c_str());
        } while (minuto < 0 || minuto > 59);

        return entero;
    }
    // Segundo
    string ingresarSegundo(char const *msj)
    {
        int segundo = 0;
        string entero;
        do
        {

            cout << "Segundo: ";
            entero = integerImput(">");
            cout << "\n";
            // cout << "prueba: " << entero << endl;
            segundo = atoi(entero.c_str());
        } while (segundo < 0 || segundo > 59);

        return entero;
    }
    bool isDateValid(const std::string &inputDate, const std::string archivo)
    {
        ListaDoble<string> results;
        Nodo<string> *aux2;
        string line;
        string lectura;
        lectura = leerArchivoTxtEspecifico(archivo);
        char delimitador = '\n';
        stringstream input_stringstream(lectura);

        while (getline(input_stringstream, line, delimitador))
        {
            results = split(line, ' ');
            aux2 = results.getCabeza();
            while (aux2 != nullptr)
            {
                if (aux2->getDato() == inputDate)
                {
                    return true;
                }
                aux2 = aux2->getSiguiente();
            }
        }

        return false;
    }
};
