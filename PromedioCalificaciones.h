#pragma once
#include "iostream"
#include "ListaEnlazada.h"

using namespace std;
template<typename T>
class PromedioCalificaciones {
private:
    ListaEnlazada<T> calificaciones;

public:
    void agregarCalificacion(T calificacion) {
        calificaciones.agregarElemento(calificacion);
    }

    T obtenerPromedio(Nodo<T>* actual, T suma) {
        if (actual == nullptr) {
            return suma / calificaciones.longitud;
        }
        suma += actual->dato;
        return obtenerPromedio(actual->siguiente, suma);
    }

    T MostrarPromedio() {
        return obtenerPromedio(calificaciones.cabeza, 0);
    }
};

