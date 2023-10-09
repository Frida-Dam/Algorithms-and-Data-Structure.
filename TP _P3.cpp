#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <vector>
#include "conio.h"
#include "Alumno.h"
#include "Persona.h"
#include "Ingenieria.h"
#include <stdlib.h>
#include "F_Actividades.h"
#include "Nodo.h"
#include "Punto.h"
#include "ListaEnlazada.h"
#include "ArbolNota.h"
#include<time.h>
#include "PromedioCalificaciones.h"
#include "Alumno.h"
#include "Lista.h"
#include "Clase.h"
#include <numeric>
#include "Examen.h"
#include "Profesor.h"
#include "HashTable.h"
#include "Grafo.h"
#include "Mensajes.h"
#include"Foro.h"
#include "ArbolNota.h"
#include <iomanip>
#define amarillo "\033[33m"
#define blanco "\033[0m"

using namespace std;

//variables
string nombre, apellidos, dni, usuario, contrasena;
bool verificado;

Ingenieria* ingenieria;
vector<Alumno*> alumnos;

//Estudiantes
Ingenieria* ingenieria1 = new Ingenieria("Juanito", "Perez", "12345", "U2022", "Juan", true);
vector<Ingenieria*> ingenierias;
vector<string> carrera = { "Facultad de Ingenieria", "Ingenieria de software"};
Ingenieria* verificarAL(string user, string pass) {

	for (int i = 0; i < alumnos.size(); i++) 
	{
		if (alumnos[i]->getUsuario() == user && alumnos[i]->getContrasena() == pass)
		{
			verificado = true;
		}
		else verificado = false;
	}
	return new Ingenieria(nombre, apellidos, dni, usuario, contrasena, verificado);
}

void menu1() {

	cout << "\n::::::::::::MENU:::::::::::::" << endl;
	cout << "1.- Información del estudiante " << endl;
	cout << "2.- Cursos" << endl;
	cout << "3.- Calificaciones" << endl;
	cout << "4.- Flujo de actividades" << endl;
	cout << "5.- Companieros de carrera" << endl;
	cout << "6.- Sedes y alumnos" << endl; //grafo- no se me ocurre un nombre xd
	cout << "7.- Foro" << endl;//ord. avanzado
	cout << "8.- Promedio por ciclo universitario" << endl;// arboles-min-max
	cout << "9.- Salir" << endl;
}
void menu2() {

	cout << "\n::::::::::::MENU:::::::::::::" << endl;
	cout << "a.- Mostrar cursos " << endl;
	cout << "b.- Notas de examenes " << endl;
	cout << "c.- Promedio de cursos " << endl;
}
Alumno* agregarAlumno(string User) {
	// Abre el archivo en modo de lectura
	ifstream archivo("alumnos.txt");

	// Busca el código del alumno en el archivo
	string linea;
	while (getline(archivo, linea)) {
		if (linea.find("User:" + User) != string::npos) {
			// El código ya existe en el archivo, no se agrega el alumno
			archivo.close();
			return 0;
		}
	}

	archivo.close();

	// Abre el archivo en modo de escritura y agrega el alumno al final
	ofstream archivoNuevo;
	archivoNuevo.open("alumnos.txt", ios_base::app);
	for (int i = 0; i < alumnos.size(); i++)
	{
		if(alumnos[i]->getUsuario() == User)
		archivoNuevo << "\nNombre:" << alumnos[i]->getNombre() << "\nApellidos:" << alumnos[i]->getApellidos() << "\nDNI:" << alumnos[i]->getDni() << "\nUsuario:" << alumnos[i]->getUsuario() << "\nContrasena:" << alumnos[i]->getContrasena() << endl;
	}
	archivoNuevo.close();
}

int obtnerN(string curso[]) {
	int num = 0;
	while (curso[num] != " ") {
		num++;
	}
	return num;
}
void imprimir(int e) {
	cout << e << " ";
}

int nota() {

	return rand() % 21;
}


int main() {
	srand(time(NULL));
	//Pila flujo de actividad
	F_Actividades<Actividad*>* actividades;
	//lista de clases de alumno
	Lista<Clase*>* cursos = new Lista<Clase*>();

	//Generador de database
	srand(time(0)); // Inicializar la semilla del generador de números aleatorios
	const int numNotas = 1000;
	ofstream archivo("notas.txt"); // Crear el archivo "notas.txt"

	if (archivo.is_open()) {
		for (int i = 0; i < numNotas; i++) {
			int nota = rand() % 21; // Generar una nota aleatoria entre 0 y 20
			archivo << nota << endl; // Escribir la nota en el archivo
		}

		archivo.close(); // Cerrar el archivo
		
	}
	else {
		cout << "No se pudo abrir el archivo." << endl;
		return 1;
	}


	alumnos.push_back(ingenieria1);
	string user, pass;
	int contar = 0, opcion;

	PromedioCalificaciones<int> promedio;
	Carrera carreras("Alumno ", carrera);

	cursos->agregaInicial(new Clase("Programacion"));
	cursos->agregaInicial(new Clase("Matematica discreta"));
	cursos->agregaInicial(new Clase("Fisica"));
	cursos->agregaInicial(new Clase("Diseño y Patrones de software"));
	cursos->agregaInicial(new Clase("Especificaciones y analisis de requerimientos"));
	
	//Arbol
	ArbolNota<int>* objArbolNota = new ArbolNota<int>(imprimir);

	objArbolNota->Insertar(15);
	objArbolNota->Insertar(20);
	objArbolNota->Insertar(17);
	objArbolNota->Insertar(19);
	objArbolNota->Insertar(18);


	//hash table
	HashTablaA ht = HashTablaA();
	Persona alumno1("Mar     ", "Domte  ", "76431264", "U20201234","sss","Monterrico"); ht.insert(move(alumno1));
	Persona alumno2("Luis    ", "Guerti ", "73237123", "U202021343", "sss", "Monterrico"); ht.insert(move(alumno2));
	Persona alumno3("Tamy    ", "Marcos ", "93242312", "U20201212", "sss", "Monterrico"); ht.insert(move(alumno3));
	Persona alumno4("Sasha   ", "Dante  ", "13423245", "U20202311", "sss", "Monterrico"); ht.insert(move(alumno4));
	Persona alumno5("Ale     ", "Facci  ", "73231349", "U20212341", "sss", "Villa"); ht.insert(move(alumno5));
	Persona alumno6("Leo     ", "Ferrero", "74359382", "U20221234", "sss", "Villa"); ht.insert(move(alumno6));
	Persona alumno7("Teo     ", "Huaraz ", "73294053", "U20222345", "sss", "Villa"); ht.insert(move(alumno7));
	Persona alumno8("Mia     ", "Vela   ", "94343204", "U20223456", "sss", "Villa"); ht.insert(move(alumno8));
	Persona alumno9("Cami    ", "Marte  ", "93424532", "U20225567", "sss", "Villa"); ht.insert(move(alumno9));
	Persona alumno10("Mateo  ", "Herrera", "73342823", "U20225678", "sss", "San Isidro"); ht.insert(move(alumno10));
	Persona alumno11("Gian   ", "Gal    ", "73243234", "U20221789", "sss", "San Isidro"); ht.insert(move(alumno11));
	Persona alumno12("Carlos ", "Monte  ", "95424843", "U202267899", "sss", "San Isidro"); ht.insert(move(alumno12));
	Persona alumno13("Mariana", "Jeep   ", "74840213", "U202278989", "sss", "San Isidro"); ht.insert(move(alumno13));
	Persona alumno14("Perla  ", "Terra  ", "74839299", "U20221235", "sss", "San Miguel"); ht.insert(move(alumno14));
	Persona alumno15("Dome   ", "Rodri  ", "93428943", "U20222346", "sss", "San Miguel"); ht.insert(move(alumno15));
	Persona alumno16("Abril  ", "Louly  ", "74399843", "U20228789", "sss", "San Miguel"); ht.insert(move(alumno16));
	Persona alumno17("Marce  ", "Tella  ", "74393432", "U20201235", "sss", "San Miguel"); ht.insert(move(alumno17));
	
	//Grafo
	CGrafo<string>* G = new CGrafo<string>(); 
	G->adicionarVertice("Monterrico"); 
	G->adicionarVertice("Villa");
	G->adicionarVertice("San Isidro");
	G->adicionarVertice("San Miguel");

	G->adicionarArco(1, 0,"19");
	G->adicionarArco(2, 0, "12");
	G->adicionarArco(3, 0, "17");
	G->adicionarArco(2, 1, "16");
	G->adicionarArco(3, 1, "21");
	G->adicionarArco(3, 2, "7,4");

		
	//ordenamiento avanzado -merge
	Foro foro;
	foro.agregarMensaje("Maria Merce", "Contenido 1", "2023-06-20");
	foro.agregarMensaje("Juan Padro", "Contenido 2", "2023-06-20");
	foro.agregarMensaje("Roberto Peresi", "Contenido 3", "2023-05-21");
	foro.agregarMensaje("Luica Menso", "Contenido 4", "2023-03-20");
	foro.agregarMensaje("Martina Linares", "Contenido 5", "2023-06-11");
	foro.agregarMensaje("Doris Marco", "Contenido 6", "2023-06-09");
	//
	
	actividades = new F_Actividades<Actividad*>();
	

	while (verificado == false && contar != 4) {

		cout << "Ingrese usuario: " << endl;
		cin >> user;
		cout << "Ingrese contrasena: " << endl;
		cin >> pass;

		verificarAL(user, pass);
		contar++;
	}

	if (verificado == true) {
		for (int i = 0; i < alumnos.size(); i++)
		{
			if (alumnos[i]->getUsuario() == user)
			{
				cout << "Bienvenido: " << alumnos[i]->getNombre() << " " << alumnos[i]->getApellidos() << endl << endl;
				do {
					menu1();

					cout << "Ingrese su opcion: ";
					cin >> opcion;
					switch (opcion)
					{
						//informacion del estudiante  
					case 1: {

						cout << "\n" << carreras.nombre << ":" << endl;
						carreras.mostrar_carrera(carreras);
						alumnos[i]->imprimir(); cout << endl; break;

					}
						  //Cursos del estudiante
					case 2: {
						char op2;
						menu2();
						cin >> op2;
						switch (op2)
						{
							//mostrar curso
						case 'a': {

							// Código para la opción 2
							for (int i = 0; i < 5; i++) {
								cout << "\n Nombre del curso: " << cursos->obtenerPos(i)->nombreClase << endl;
							}
							break;
						}
								//mostrar examenes
						case 'b': {
							//examenes notas
							Lista<Examen*>* exam = new Lista<Examen*>();
							exam->agregaInicial(new Examen(19.0, ":"));
							exam->agregaInicial(new Examen(20.0, "DD2:"));
							exam->agregaInicial(new Examen(17.0, "DD1:"));
							exam->agregaInicial(new Examen(15.0, "pc3:"));
							exam->agregaInicial(new Examen(11.0, "pc2:"));
							exam->agregaInicial(new Examen(20.0, "pc1:"));
							exam->agregaInicial(new Examen(16.0, "pc3:"));
							exam->agregaInicial(new Examen(16.0, "pc2:"));
							exam->agregaInicial(new Examen(18.0, "pc1:"));
							exam->agregaInicial(new Examen(15.0, "pc3:"));
							exam->agregaInicial(new Examen(11.0, "pc2:"));
							exam->agregaInicial(new Examen(20.0, "pc1:"));
							exam->agregaInicial(new Examen(12.0, "pc3:"));
							exam->agregaInicial(new Examen(16.0, "pc2:"));
							exam->agregaInicial(new Examen(10.0, "pc1:"));

							int cont = 0;

							// Código para la opción 2
							for (int i = 0; i < 15; i++) {
								if ((i == 0) || (i == 3) || (i == 6) || (i == 9) || (i == 12)) {
									cout << "\n Nombre del curso: " << cursos->obtenerPos(cont)->nombreClase << endl;
									cont++;
								}
								cout << "\n Nota de examen: " << exam->obtenerPos(i)->nombreExamen << " " << exam->obtenerPos(i)->nota << endl;

							}
							break;
							
						}

						case 'c':
						{
							vector<vector<float>> calificaciones1 = {
							{19.0, 20.0, 17.0, 15.0, 11.0}, // Calificaciones del curso 1
							{20.0, 16.0, 16.0, 18.0, 15.0}, // Calificaciones del curso 2
							{11.0, 20.0, 12.0, 16.0, 10.0}, // Calificaciones del curso 3
							};

							//asignación de calificaciones según curso
							for (int i = 0; i < calificaciones1.size(); i++) {
								//lambda
								float promedio = accumulate(calificaciones1[i].begin(), calificaciones1[i].end(), 0.0,
									[](float acumulado, float calificacion) {return acumulado + calificacion; }) / calificaciones1[i].size();

								cout << "El promedio del curso " << i + 1 << " es: " << promedio << endl;
							}
							break;
							
						}
						break;
						}
						break;
					}
						  
						  //calificaciones
					case 3: {
						
						ifstream archivoLectura("notas.txt"); // Abrir el archivo en modo lectura

						if (archivoLectura.is_open()) {
							string linea;
							cout << "Promedio de los estudiantes de ingenieria de Software:" << endl;
							while (getline(archivoLectura, linea)) {
								cout << linea << endl; // Imprimir cada línea del archivo
							}

							archivoLectura.close(); // Cerrar el archivo de lectura
						}
						else {
							cout << "No se pudo abrir el archivo para lectura." << endl;
							return 1;
						}
						
						break;
					}
						  //Flujo de actividades
					case 4: { //Pilas 10 actividades como ejemplo
						actividades->show();
						break;

					}
					case 5: {
						cout << "Vista de la tabla Hash:" << endl;

						ht.DispAll();
						break;
					}
					case 6: {
						//Imprimir los vértices con sus arcos
						cout << amarillo << G->obtenerVertice(0)<< " -> " << blanco << G->obtenerVertice(1) << "        | " << G->obtenerArco(1, 0)<<"km" << endl;
						cout << amarillo << "Monterrico-> " << blanco << G->obtenerVertice(2) << "  | " << G->obtenerArco(2, 0) << "km" << endl;
						cout << amarillo << "Monterrico-> " << blanco << G->obtenerVertice(3) << "  | " << G->obtenerArco(3, 0) << "km" << endl;
						cout << amarillo << "Villa-> " << blanco << G->obtenerVertice(2) << "       | " << G->obtenerArco(2, 1) << "km" << endl;
						cout << amarillo << "Villa-> " << blanco << G->obtenerVertice(3) << "       | " << G->obtenerArco(3, 1) << "km" << endl;
						cout << amarillo << "San Isidro-> " << blanco << G->obtenerVertice(3) << "  | " << G->obtenerArco(3, 2) << "km" << endl;
						
						break;
					}
					case 7: {
						//Imprimir los vértices con sus arcos
						
						foro.mergeSortForo(foro.mensajes); 
						foro.mostrar(); 

						break;
					}
					case 8: {
						cout << endl;
						cout << amarillo<< "En 05 ciclos academicos has obtenido los siguientes promedios: " << blanco<< endl;
						objArbolNota->EnOrden(); cout << endl;
						break;
					}
					}

				} while (opcion != 9);

			}
		}
	}

	/*agregarAlumno(Alumno* alumno);*/
	agregarAlumno(user);
	if (contar == 4) {
		cout << "Se excedió la cantidad de intentos ";
	}

	cin.get();
	return 0;
}
