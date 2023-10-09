#ifndef __ARBOLBB_HPP__
#define __ARBOLBB_HPP__
#include <functional>
using namespace std;

template<class T>
class NodoA {
public:
	T elemento;
	NodoA* izq;
	NodoA* der;
};

template<class T>
class ArbolNota {
	//Función lambda: Función de comparación
	typedef function<int(T, T)> Comp;
	//puntero a función
	void(*procesar)(T);
	NodoA<T>* raiz;
	Comp comparar;
	int i = 0;

private:
	bool _buscar(NodoA<T> *nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0)return true;
			else if (r < 0) {
				return _buscar(nodo->der, e);
			}
			else {
				return _buscar(nodo->izq, e);
			}
		}
	}
	bool _insertar(NodoA<T> *&nodo, T e) {
		if (nodo == nullptr) {
			nodo = new NodoA<T>();
			nodo->elemento = e;
			return true;
		}
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0)return false; //no se acepta nodos con elemento igual
			else if (r < 0) {
				return _insertar(nodo->der, e);
			}
			else {
				return _insertar(nodo->izq, e);
			}
		}
	}
	void _enOrden(NodoA<T>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		cout << endl;
		procesar(nodo->elemento);
		i++;
		if (i == 1) { cout << "Promedio mas bajo "; } 
		if (i == 5) { cout << "Promedio mas alto "; } 
		_enOrden(nodo->der);
			
		
		
	}
public:
	ArbolNota(void(*nuevoProcesar)(T)) {
		this->procesar = nuevoProcesar;
		this->comparar = [](T a, T b)->int {return a - b;};
		this->raiz = nullptr;
	}
	bool Buscar(T e) {
		return _buscar(raiz, e);
	}
	bool Insertar(T e) {
		return _insertar(raiz, e);
	}
	void EnOrden() {
		_enOrden(raiz);
	}
	
};

#endif // !__ARBOLBB_HPP__

