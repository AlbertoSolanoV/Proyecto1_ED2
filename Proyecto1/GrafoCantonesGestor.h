#pragma once
#include "GrafoCantones.h";
using namespace std;

class GrafoCantonesGestor
{
private:
	/* private members */
	GrafoCantones* grafoCantonSjo;
	GrafoCantones* grafoCantonAla;
	GrafoCantones* grafoCantonCar;
	GrafoCantones* grafoCantonPun;
	GrafoCantones* grafoCantonHer;
	GrafoCantones* grafoCantonGua;
	GrafoCantones* grafoCantonLim;
	vector<std::string> ruta;
	void inicializarGrafos();

public:
    /* public members */

	// Default constructor
	GrafoCantonesGestor();

	//llena de informacion los grafos
    void llenarGrafos();

	//Dada una provincia la ruta mas corta del canton
	void rutaMasCorta(string provincia, string cantonInicio, string cantonDestino);

	//Valida si la provincia ingresada es valida
	bool validarProvincias(string provincia);

	//Arreglo de las princias a validar
	const vector<string> PROVINCIAS  = {
		"San José",
		"Alajuela",
		"Cartago",
		"Guanacaste",
		"Heredia",
		"Limón",
		"Puntarenas"
	};
};

