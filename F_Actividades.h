#pragma once
#include "Nodo.h"
#include "Alumno.h"
#include "Punto.h"

using namespace std;

template<class T>
class F_Actividades {
private:
	Nodo<T>* tope;
public:
	F_Actividades() { tope = NULL; };
	void push(T v);
	T pop();
	bool estaVacia();
	void show();
};
template<class T>
bool  F_Actividades<T>::estaVacia() { //evalua si esta vacia
	return (tope == NULL);
}
template<class T>
void  F_Actividades<T>::push(T v) {
	if (estaVacia()) {
		tope = new Nodo<T>(v);
	}
	else {
		tope = new Nodo<T>(v, tope);
	}
}
template<class T>
T  F_Actividades<T>::pop() {
	if (estaVacia()) {
		//throw "Error, pila vacía";
		return NULL;
	}
	else {
		T elemento = (T)(tope->dato);
		tope = (Nodo<T>*) tope->siguiente;
		return elemento;
	}
}
template<class T>
void  F_Actividades<T>::show(){

	push(new Actividad("Matematica discreta -\t A distancia" "\nAvance 1"));
	push(new Actividad("Matematica discreta -\t A distancia" "\nEjercicios semana 7"));
	push(new Actividad("Diseño y patrones de Software -\t Presencial" "\nAvance 1"));
	push(new Actividad("Especificacion y analisis de Requerimientos -\t Semiresencial" "\nEntrega de grupos Trabajo final"));
	push(new Actividad("Fisica I -\t A distancia" "\nlaboratorio 6"));
	push(new Actividad("Fisica I  -\t A distancia" "\nlaboratorio 5"));
	push(new Actividad("Matematica discreta -\t A distancia" "\nAntes::GNP"));
	push(new Actividad("Algoritmos y estructuras de Datos -\t Presencial" "\nTrabajo Parcial"));
	push(new Actividad("Diseño y patrones de Software -\t Presencial" "\nAnvance 2"));
	
	Actividad* elem;

	do {
		elem = pop();
		if (elem != NULL)
			cout << elem->toString() << endl;

	} while (elem != NULL);
}

