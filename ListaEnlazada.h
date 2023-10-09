#pragma once
#include "Nodo.h"

template<typename T>
class ListaEnlazada {
public:
    Nodo<T>* cabeza;
    int longitud;

    ListaEnlazada() {
        cabeza = nullptr;
        longitud = 0;
    }

    void agregarElemento(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        longitud++;
    }
};

