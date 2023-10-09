#pragma once
#include <vector>
#include<string>
#include <iostream>
#include "Mensajes.h"
using namespace std;
class Foro {
public:
	vector<Mensajes>mensajes;
	void agregarMensaje(const string& alumno, const string& contenido, const string& fecha_publicacion) {
		Mensajes mensaje(alumno, contenido, fecha_publicacion);
		mensajes.push_back(mensaje);
	}
	void mostrar() {
		cout << "FORO DEL AULA VIRTUAL" << endl;
		cout << "MENSAJE DEL FORO" << endl;
		for (auto& mensaje : mensajes) {
			mensaje.mostrarMensaje();
		}
	}
	//ordenamiento bubuja
	void ordenamientomensajefecha() {
		int n = mensajes.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (mensajes[j].getFecha() > mensajes[j + 1].getFecha()) {
					// se debe de intercambiar los mensajes
					swap(mensajes[j], mensajes[j + 1]);
				}
			}
		}
	}
	bool comparar(string izquierdo, string derecho) {
		// anho
		string anho = "";
		for (int i = 0; i < 4; i++) {
			anho = anho + izquierdo[i];
		}
		int anho1 = stoi(anho);//de string a int
		anho = "";
		for (int i = 0; i < 4; i++) {
			anho = anho + derecho[i];
		}
		int anho2 = stoi(anho);//de string a int

		if (anho1 != anho2) return anho1 > anho2;//como es booleano sale true o false
		
		// mes
		string mes = "";
		for (int i = 5; i < 7; i++) {
			mes = mes + izquierdo[i];
		}
		int mes1 = stoi(mes);
		mes = "";
		for (int i = 5; i < 7; i++) {
			mes = mes + derecho[i];
		}
		int mes2 = stoi(mes);

		if (mes1 != mes2) return mes1 > mes2;

		// dia
		string dia = "";
		for (int i = 8; i < 10; i++) {
			dia = dia + izquierdo[i];
		}
		int dia1 = stoi(dia);
		dia = "";
		for (int i = 8; i < 10; i++) {
			dia = dia + derecho[i];
		}
		int dia2 = stoi(dia);

		if (dia1 != dia2) return dia1 > dia2;

		return true;
	}
	void MergeForo(vector<Mensajes>& A1, vector<Mensajes>& A2, vector<Mensajes>& A) {
		int i = 0, j = 0, k = 0;
		int mitad = A.size() / 2;
		while (i < mitad && j < A.size() - mitad) {
			if (comparar(A1[i].getFecha(), A2[j].getFecha())) {
				A[k] = A1[i];
				i++;
				k++;
			}
			else {
				A[k] = A2[j];
				j++;
				k++;
			}
		}
		while (i < mitad) {
			A[k] = A1[i];
			i++;
			k++;
		}
		while (j < A.size() - mitad) {
			A[k] = A2[j];
			j++;
			k++;
		}
	}
	void mergeSortForo(vector<Mensajes>& A) {
		if (A.size() > 1) {
			int mitad = A.size() / 2;
			vector<Mensajes> A1 = vector<Mensajes>();
			vector<Mensajes> A2 = vector<Mensajes>();
			// Crear A1
			for (int i = 0; i < mitad; i++) {
				A1.push_back(A[i]);
			}
			// Crear A2
			for (int i = mitad; i < A.size(); i++) {
				A2.push_back(A[i]);
			}
			mergeSortForo(A1);
			mergeSortForo(A2);
			MergeForo(A1, A2, A);
		}
	}

};

