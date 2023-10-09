#pragma once
#include <string>
#include "Examen.h"
#include "Lista.h"
using namespace std;

class Clase {
public:
    string nombreClase;
    Lista<Examen*>* examenes;

public:

    Clase(string nombre) {
        nombreClase = nombre;

    }
    Clase() {
        nombreClase = "";
    }
};

