/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Alejandro Cuadrado
FECHA DE CREACIÓN: 11/05/2023
FECHA DE MODIFICACIÓN: 11/05/2023
Enunciado
 ***********************************************************************/
#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matriz {
private:
    T** matriz;
    int dimension;
//esta realizado con Templates
public:
    Matriz(int dim);
    ~Matriz();
    void generarAleatorios();
    void imprimir();
    int obtenerDimension();
    T obtenerElemento(int fila, int columna);
    void establecerElemento(int fila, int columna, T valor);
};

#include "Matriz.cpp"

#endif  
