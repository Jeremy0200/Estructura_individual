/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Alejandro Cuadrado
FECHA DE CREACIÓN: 11/05/2023
FECHA DE MODIFICACIÓN: 11/05/2023
Enunciado
 ***********************************************************************/
#ifndef MATRIZ_CPP
#define MATRIZ_CPP
#include "Matriz.h"

template <typename T>
Matriz<T>::Matriz(int dim) {
    dimension = dim;
    matriz = new T*[dimension];
    for (int i = 0; i < dimension; i++) {
        matriz[i] = new T[dimension];
    }
}

template <typename T>
Matriz<T>::~Matriz() {
    for (int i = 0; i < dimension; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

template <typename T>
void Matriz<T>::generarAleatorios() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matriz[i][j] = std::rand() % 10; // Genera números aleatorios entre 0 y 9
        }
    }
}

template <typename T>
void Matriz<T>::imprimir() {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Matriz<T>::obtenerDimension() {
    return dimension;
}

template <typename T>
T Matriz<T>::obtenerElemento(int fila, int columna) {
    return matriz[fila][columna];
}

template <typename T>
void Matriz<T>::establecerElemento(int fila, int columna, T valor) {
    matriz[fila][columna] = valor;
}

#endif  
