#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"

using namespace std;

class Actividad {
	string curso, act;
public:
	Actividad(string act = " ") :act(act){}

	string toString() {
		ostringstream  ss;
		ss << curso;
		ss << endl << act;
		return(ss.str());
	}
};

