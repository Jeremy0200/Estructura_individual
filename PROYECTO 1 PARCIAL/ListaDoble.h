/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 27/05/2023
FECHA DE MODIFICACIÓN: 30/05/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
#pragma once
#include "Nodo.cpp"
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class ListaDoble {
private:
    Nodo<T>* primero=nullptr;
    Nodo<T>* ultimo=nullptr;
    int tam=0 ;
public:
    ListaDoble();
    void insertarCabeza(T);
    void insertarCola(T);
    void insertarPosicion(T _dato, int pos);
    void encriptar(string &cadena, char c);
    void desencriptar(string &cadena, char c);
    void buscar(T);
    void eliminar(T);
    void mostrar();
    void cambiarLista(char c);
    void volverLista(char c);
    Nodo<T>* getCabeza();

};


