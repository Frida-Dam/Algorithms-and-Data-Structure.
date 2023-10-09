#pragma once
#include <string>
#include "iostream"
#include <vector>

using namespace std;

class Carrera{
public:
    string nombre;
    vector<string> carreras;

    // Constructor
    Carrera(string nombre, vector<string> carreras)  {
        this->nombre = nombre;
        this->carreras = carreras;
    }
    // Función recursiva para mostrar las clases que ha dictado un profesor
    void mostrar_carrera(Carrera carrera, int i = 0) {
        if (i < carrera.carreras.size()) {
            // Imprimimos el nombre de la clase actual
            cout << carrera.carreras[i] << endl;
            // Llamamos a la función recursivamente para mostrar la siguiente clase en la lista
            mostrar_carrera(carrera, i + 1);
        }
    }
};


