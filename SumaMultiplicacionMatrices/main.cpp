/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Alejandro Cuadrado
FECHA DE CREACIÓN: 22/05//2023
FECHA DE MODIFICACIÓN: 22/05/2023
Enunciado
 ***********************************************************************/
#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"

int main() {
    int dimension;
    int exponente;
    std::cout << "Ingrese la dimension de las matrices: ";
    std::cin >> dimension;
    //------------------------------------------------------------------------------------------------------------------//    
/*ESTE CODIGO ERA DE LA SUMA Y MULTIPLICACION que le probe pero no debia utilizar no le elimine de aqui por si en el futuro 
llegara a utilizar de mismo modo en operaciones.cpp y .h las elimine para dejar solo la potencia 
    Matriz<int> matriz1(dimension);
    Matriz<int> matriz2(dimension);

    matriz1.generarAleatorios();
    matriz2.generarAleatorios();

    std::cout << "Matriz 1:" << std::endl;
    matriz1.imprimir();

    std::cout << "Matriz 2:" << std::endl;
    matriz2.imprimir();

    Matriz<int> resultado_suma = Operaciones<int>::suma(matriz1, matriz2);
    std::cout << "Suma de matrices:" << std::endl;
    resultado_suma.imprimir();

    Matriz<int> resultado_multiplicacion = Operaciones<int>::multiplicacion(matriz1, matriz2);
    std::cout << "Multiplicacion de matrices:" << std::endl;
    resultado_multiplicacion.imprimir(); */
//----------------------------------------------------------------------------------------------/
    std::cout << "Ingrese el exponente: ";//1
    std::cin >> exponente;

    Matriz<int> matriz(dimension);
    matriz.generarAleatorios();

    std::cout << "Matriz inicial:" << std::endl;
    matriz.imprimir();

    Matriz<int> resultado_potencia = matriz;
    for (int i = 1; i < exponente; i++) {
        resultado_potencia = Operaciones<int>::multiplicacion(resultado_potencia, matriz);
    }

    std::cout << "Matriz elevada a la potencia " << exponente << ":" << std::endl;
    resultado_potencia.imprimir();//2
    return 0;
}
