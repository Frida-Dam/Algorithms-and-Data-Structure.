#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Persona.h"

#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
using namespace std;

class HashTablaA {

private:

	vector<list<Persona>> theLists;   // Tabla

	int currentSize;

public:

	explicit HashTablaA(int size = 17) : currentSize{ 0 } {

		theLists.resize(size);
	}


	bool insert(Persona&& persona)	{
		auto& whichList = theLists[myhash(persona.getUsuario())]; //Obtenemos la lista de elementos según el hash obtenido

		whichList.push_back(persona); //Agregamos el nuevo elemento a la lista

		return true;
	}

	void DispAll() {

		int pos = 0;

		for (auto& thisList : theLists) {

			cout << "Key: " + to_string(pos) << " | ";

			for (auto& persona : thisList) {

				cout << ANSI_RED << "Nombre y Apellido: " << ANSI_RESET << persona.getNombre()<< persona.getApellidos()
				<< "    " << ANSI_RED << "DNI: " << ANSI_RESET << persona.getDni() << "    " << ANSI_RED << "codigo: " << ANSI_RESET << persona.getUsuario();
			}

			cout << endl;

			pos++;

		}

	}

private:
	typedef unsigned int size_t;

	size_t myhash(const string usuario) const {
		const size_t prime = 31; 
		size_t hashVal = 0; 

		for (char c : usuario) { //hash table
			hashVal += hashVal*prime+c; 
		}

		hashVal %= theLists.size();
		return hashVal;

	}

};



