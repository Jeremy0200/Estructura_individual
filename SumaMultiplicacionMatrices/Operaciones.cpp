#ifndef OPERACIONES_CPP
#define OPERACIONES_CPP
#include "Operaciones.h"
//Aqui implementamos la potencia con un exponente X que vayamos a colocar
template <typename T>
Matriz<T> Operaciones<T>::potencia(Matriz<T>& matriz, int exponente) {
    int dimension = matriz.obtenerDimension();
    Matriz<T> resultado(dimension);

    if (exponente == 0) {
        // La matriz resultante es la matriz identidad
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (i == j) {
                    resultado.establecerElemento(i, j, 1);
                } else {
                    resultado.establecerElemento(i, j, 0);
                }
            }
        }
    } else if (exponente > 0) {
        // Calcula la potencia utilizando el método de exponenciación rápida
        Matriz<T> base = matriz;
        while (exponente > 0) {
            if (exponente % 2 == 1) {
                resultado = multiplicacion(resultado, base);
            }
            base = multiplicacion(base, base);
            exponente /= 2;
        }
    } else {
        // Calcula la potencia negativa de la matriz inversa
        Matriz<T> matriz_inversa = calcularMatrizInversa(matriz);
        resultado = potencia(matriz_inversa, -exponente);
    }

    return resultado;
}
//2
template <typename T>
Matriz<T> Operaciones<T>::calcularMatrizInversa(Matriz<T>& matriz) {
    // Implementa el cálculo de la matriz inversa
    // ...
}

#endif
