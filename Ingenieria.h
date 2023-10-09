#include "Alumno.h"

class Ingenieria : public Alumno {

protected:

	bool verificado;

public:

	Ingenieria(string nombre, string apellidos, string dni, string usuario, string contrasena, bool verificado): Alumno(nombre, apellidos, dni, usuario, contrasena, verificado)
	{
		if (verificado == true || verificado == false)
		{
			this->verificado = verificado;
		}
		else {
			this->verificado = false;
		}

	}
	~Ingenieria() {}

	void imprimir() {
	Alumno::imprimir();
	}


};