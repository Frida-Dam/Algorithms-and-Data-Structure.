#pragma once
#include <string>

using namespace std;
class Examen {
public:
    float nota;
    string nombreExamen;

public:
    Examen(float nota, std::string nombreExamen) {
        this->nota = nota;
        this->nombreExamen = nombreExamen;
    }
    Examen() {
        nota = 0.0;
        nombreExamen = "";
    }
    ~Examen() {}

};

