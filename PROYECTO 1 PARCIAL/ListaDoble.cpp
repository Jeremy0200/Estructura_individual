
/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES:Milena Maldonado, Jefferson Ulco Alejandro, Cuadrado
FECHA DE CREACIÓN: 04/06/2023
FECHA DE MODIFICACIÓN: 04/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
#include "ListaDoble.h"

template <typename T>
ListaDoble<T>::ListaDoble()
{
    this->primero = NULL;
    this->ultimo = NULL;
    this->tam = 0;
}
template <typename T>
void ListaDoble<T>::insertarCabeza(T _dato)
{
    Nodo<T> *nuevo = new Nodo<T>(_dato);
    if (primero == NULL)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        primero->setAnterior(nuevo);
        nuevo->setSiguiente(primero);
        primero = nuevo;
    }
    tam++;
}
template <typename T>
void ListaDoble<T>::insertarCola(T _dato)
{
    Nodo<T> *nuevo = new Nodo<T>(_dato);
    if (primero == NULL)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
    tam++;
}
template <typename T>
void ListaDoble<T>::insertarPosicion(T _dato, int pos)
{
    Nodo<T> *nuevo = new Nodo<T>(_dato);
    Nodo<T> *aux = primero;
    int contador = 0;
    if (pos == 0)
    {
        insertarCabeza(_dato);
    }
    else if (pos == tam)
    {
        std::cout << "\nPos" << pos << std::endl;
        std::cout << "\nTam" << tam << std::endl;
        insertarCola(_dato);
    }
    else if (pos > 0 && pos < tam)
    {

        while (aux)
        {

            if (pos == contador)
            {
                aux->getAnterior()->setSiguiente(nuevo);
                nuevo->setAnterior(aux->getAnterior());
                aux->setAnterior(nuevo);
                nuevo->setSiguiente(aux);
                break;
            }
            aux = aux->getSiguiente();
            contador++;
        }
        tam++;
    }
    else
    {
        std::cout << "\nNo es valida la posicion" << std::endl;
    }
}

template <typename T>
void ListaDoble<T>::buscar(T _dato)
{
    Nodo<T> *aux = primero;
    while (aux != NULL)
    {
        if (aux->getDato() == _dato)
        {
            cout << "El dato " << _dato << " se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}
template <typename T>
void ListaDoble<T>::eliminar(T _dato)
{
    Nodo<T> *aux = primero;
    while (aux != NULL)
    {
        if (aux->getDato() == _dato)
        {
            if (aux == primero)
            {
                primero = primero->getSiguiente();
                primero->setAnterior(NULL);
            }
            else if (aux == ultimo)
            {
                ultimo = ultimo->getAnterior();
                ultimo->setSiguiente(NULL);
            }
            else
            {
                aux->getAnterior()->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(aux->getAnterior());
            }
            delete aux;
            tam--;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }

        aux = aux->getSiguiente();
    }

    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}
template <typename T>
void ListaDoble<T>::encriptar(string &cadena, char c)
{
    int i;

    for (i = 0; i < cadena.size(); i++)
    {
        cadena[i] = cadena[i] + c;
    }
}

template <typename T>
void ListaDoble<T>::desencriptar(string &cadena, char c)
{
    int i;
    for (i = 0; i < cadena.size(); i++)
    {
        cadena[i] = cadena[i] - c;
    }
}

template <typename T>
void ListaDoble<T>::mostrar()
{
    Nodo<T> *aux = primero;
    while (aux != NULL)
    {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}
template <typename T>
void ListaDoble<T>::cambiarLista(char c)
{
    bool vacio = false;
    Nodo<T> *aux = primero;
    string dato;
    if (primero != NULL)
    {
        while (aux)
        {
            cout << aux->getDato() << " -> ";
            dato = aux->getDato();
            encriptar(dato, c);
            aux->setDato(dato);
            aux = aux->getSiguiente();
        }
        cout << "NULL" << endl;
    }
    else
    {
        cout << "\n\tLista vacia" << endl;
    }
    cout << "La lista tiene " << tam << " elementos " << endl;
}

template <typename T>
void ListaDoble<T>::volverLista(char c)
{
    bool vacio = false;
    Nodo<T> *aux = primero;
    string dato;
    if (primero != NULL)
    {
        while (aux)
        {
            cout << aux->getDato() << " -> ";
            dato = aux->getDato();
            desencriptar(dato, c);
            aux->setDato(dato);
            aux = aux->getSiguiente();
        }
        cout << "NULL" << endl;
    }
    else
    {
        cout << "\n\tLista vacia" << endl;
    }
    cout << "La lista tiene " << tam << " elementos " << endl;
}
template <typename T>
Nodo<T> *ListaDoble<T>::getCabeza(){
    return this->primero;
}