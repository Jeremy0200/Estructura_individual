/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Alejandro Cuadrado.
FECHA DE CREACIÓN: 11/05/2023
FECHA DE MODIFICACIÓN: 11/05/2023
Enunciado
 ***********************************************************************/
#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "Matriz.h"
template <typename T>
class Operaciones {
public:
    static Matriz<T> potencia(Matriz<T>& matriz, int exponente);
    static Matriz<T> calcularMatrizInversa(Matriz<T>& matriz);
};
#include "Operaciones.cpp"
#endif