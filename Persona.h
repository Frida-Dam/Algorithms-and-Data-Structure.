#pragma once
#include<iostream>
#include<string>
#include "Lista.h"

using namespace std;

class Persona
{
protected:
	string nombre;
	string apellidos;
	string dni;
	string usuario;
	string contrasena;
	string sede;

public:
	Persona() {
		this->nombre = "";
		this->apellidos = "";
		this->dni = "";
		this->usuario = "";
		this->contrasena = "";
		this->sede = "";
	}
	Persona(string nombre, string apellidos, string dni, string usuario, string contrasena, string sede){
		this->nombre = nombre;
		this->apellidos = apellidos;
		this->dni = dni;
		this->usuario = usuario;
		this->contrasena = contrasena;
		this->sede = sede;
	}

	void setNombre(string nombre){ this->nombre = nombre; }
	void setApellidos(string apellidos){ this->apellidos = apellidos; }
	void setDni(string dni){ this->dni = dni; }
	void setUsuario(string usuario){ this->usuario = usuario; }
	void setContrasena(string contrasena){ this->contrasena = contrasena; }
	void setSede(string sede) { this->sede = sede; }

	string getNombre() { return this->nombre; }
	string getApellidos() { return this->apellidos; }
	string getDni() { return this->dni; }
	string getUsuario() { return this->usuario; }
	string getContrasena() { return this->contrasena; }
	string getSede() { return this->sede; }
};

