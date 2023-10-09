#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Mensajes {
public:
	string alumno;
	string contenido;
	string fechapubli;
	//contructor
	Mensajes(string alum, string contenido, string fecha) {
		this->alumno = alum;
		this->contenido = contenido;
		this->fechapubli = fecha;
	}
	string getAlumno() {
		return alumno;
	}
	string getContenido() {
		return contenido;
	}
	string getFecha() {
		return fechapubli;
	}
	void mostrarMensaje() {
		cout << "Fecha de publicacion: " << fechapubli << endl;
		cout << "Alumno: " << alumno << endl;
		cout << "Contenido: " << contenido << endl;
		cout << "-----------------------------" << endl;
	}
};