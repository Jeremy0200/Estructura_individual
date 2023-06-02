/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Alejandro Cuadrado
FECHA DE CREACIÓN: 27/05/2023
FECHA DE MODIFICACIÓN: 30/05/2023
Realizar el insertar por cola de una lista simple
 ***********************************************************************/
#include <iostream>
#include <vector>
#include "ordenar.h"
#include "validaciones.h"

int main() {
    std::vector<int> numeros;
    std::string entrada;
    char opcion;

    do {
        bool esValido = false;
        while (!esValido) {
            std::cout << "Ingrese un valor numerico: ";
            std::cin >> entrada;

            if (!esNumero(entrada)) {
                std::cout << "Valor no valido. Debe ingresar un numero." << std::endl;
            } else {
                esValido = true;
            }
        }

        numeros.push_back(std::stoi(entrada));

        esValido = false;
        while (!esValido) {
            std::cout << "Desea ingresar otro valor (s/n): ";
            std::cin >> opcion;

            if (!esOpcionValida(opcion)) {
                std::cout << "Opcion no valida. Debe ingresar 's' o 'n'." << std::endl;
            } else {
                esValido = true;
            }
        }
    } while (opcion == 's' || opcion == 'S');

    std::vector<int> resultado = ordenarNumeros(numeros);

    std::cout << "Numeros ordenados: ";
    for (int numero : resultado) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;
//proyecto listas dobles, la conjunta va en base al proyecto
    return 0;
}
//
