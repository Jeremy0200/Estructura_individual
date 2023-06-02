/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Alejandro Cuadrado
FECHA DE CREACIÓN: 27/05/2023
FECHA DE MODIFICACIÓN: 30/05/2023
Realizar el insertar por cola de una lista simple
 ***********************************************************************/
#include "ordenar.h"

std::vector<int> ordenarNumeros(const std::vector<int>& lista) {
    std::vector<int> pares;
    std::vector<int> impares;

    for (int numero : lista) {
        if (numero % 2 == 0) {
            pares.push_back(numero); //permite añadir al final de la colección un nuevo dato
        } else {
            impares.push_back(numero);
        }
    }
//tda, operadores sobrecargados, templates. 
    std::vector<int> resultado;
    resultado.reserve(impares.size() + pares.size());
    resultado.insert(resultado.end(), pares.begin(), pares.end());
    resultado.insert(resultado.end(), impares.begin(), impares.end());

    return resultado;
}