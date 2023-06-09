
/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 04/06/2023
FECHA DE MODIFICACIÓN: 04/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente=nullptr;
    Nodo<T>* anterior=nullptr;
public:
    Nodo(T _dato);
    void setDato(T);
    void setSiguiente(Nodo<T>*);
    void setAnterior(Nodo<T>*);
    T getDato();
    Nodo<T>* getSiguiente();
    Nodo<T>* getAnterior();
};

