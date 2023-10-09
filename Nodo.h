#pragma once
#include <string>
#include <iostream>
#include <sstream>

template<class T>
class Nodo {
public:
	T dato;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
};