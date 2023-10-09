#pragma once
#include "Persona.h"
#include "Clase.h"
#include "Lista.h"

class Alumno : public Persona
{
public:
	Lista<Clase*>* clases;

	Alumno(string nombre, string apellidos, string dni, string usuario, string contrasena, bool verificado): Persona( nombre, apellidos, dni, usuario, contrasena,sede){ clases = new Lista<Clase*>(); }
	~Alumno(){}

	virtual void imprimir(){
		cout << endl;
		cout << "Nombre(s):                     \t" << getNombre() << endl;
		cout << "Apellido(s):                   \t" << getApellidos() << endl;
		cout << "DNI:                           \t" << getDni() << endl;
		cout << "Usuario:                       \t" << getUsuario() << endl;
	}

};
