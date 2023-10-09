#pragma once
#include <functional>

using namespace std;

template <typename T>

struct nodo {
    T val;
    nodo* sig;
    ~nodo() {
        delete val;
    }
};

template <typename T>
class Lista {
public:
    nodo<T>* ini;
    int    lon; // número de valentos en la lista

public:
    Lista() {
        ini = NULL;
        lon = 0;
    }
    ~Lista() {
        nodo<T>* aux = ini;
        nodo<T>* aux1 = ini->sig;
        for (int i = 0; i < lon; i++) {
            delete aux;
            aux = aux1;
            if (aux1 != nullptr) {
                aux1 = aux1->sig;
            }
        }
    }


    int    longitud();

    bool    esVacia();

    void    agregaInicial(T val);
    /*void    agregaPos(T val, int pos);
    void    agregaFinal(T val);

    void    modificarInicial(T val);
    void    modificarPos(T val, int pos);
    void    modificarFinal(T val);

    void    eliminaInicial();
    void    eliminaPos(int pos);
    void    eliminaFinal();
    */
    T       obtenerInicial();
    T       obtenerPos(int pos);
};

template <typename T>
int Lista<T>::longitud() {
    return lon;
}

template <typename T>
bool Lista<T>::esVacia() {
    return lon == 0;
}

template <typename T>
void Lista<T>::agregaInicial(T val) {
    if (lon == 0) {
        nodo<T>* aux = new nodo<T>();
        aux->val = val;
        aux->sig = NULL;
        ini = aux;
    }
    else {
        nodo<T>* aux = new nodo<T>();
        aux->val = val;
        aux->sig = ini;
        ini = aux;
    }
    lon++;
}

template <typename T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}

template <typename T>
T Lista<T>::obtenerPos(int pos) {
    if (pos >= lon) {
        return 0;
    }
    nodo<T>* aux = ini;
    for (int i = 1; i < pos + 1; i++) {
        aux = aux->sig;
    }
    return aux->val;
}


