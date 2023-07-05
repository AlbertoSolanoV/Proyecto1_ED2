#pragma once
#include <string>
using namespace std;

class Canton
{

private:
	string cabecera;
	string nombre;
	int  cantidadPersona;
	string nombreAlcalde;

public:
	//GETS Y SETS
	void setCabecera(string);
	void setNombre(string);
	void setCantidadPersona(int);
	void setNombreAlcalde(string);

	string getCabecera();
	string getNombre();
	int  getCantidadPersona();
	string getNombreAlcalde();

	void modificar(string, int);
};

