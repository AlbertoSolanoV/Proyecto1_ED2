#pragma once
#include <string>
using namespace std;

class Canton
{

private:
	string cabecera;
	string nombre;
	float  cantidadPersona;
	string nombreAlcalde;

public:
	//GETS Y SETS
	void setCabecera(string);
	void setNombre(string);
	void setCantidadPersona(float);
	void setNombreAlcalde(string);

	string getCabecera();
	string getNombre();
	float  getCantidadPersona();
	string getNombreAlcalde();

	void modificar(string, int);
};

