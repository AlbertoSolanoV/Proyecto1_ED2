#pragma once
#include "GrafoCantones.h";
#include "archivoLeer.h"
#include <fstream>
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
	archivoLeer lectura;
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

	void recubridorMinimo_kruskal(); 
	//Valida si la provincia ingresada es valida
	bool validarProvincias(string provincia);

	void leerArchivos();

	//Arreglo de las princias a validar
	static const enum PROVINCIAS {
		SANJOSE = 1,
		ALAJUELA = 2,
		CARTAGO = 3,
		HEREDIA = 4,
		GUNACASTE = 5,
		PUNTARENAS = 6,
		LIMON = 7
	};

	const vector<string> PROVINCIAS_NOMBRES = {
	"San José",
	"Alajuela",
	"Cartago",
	"Guanacaste",
	"Heredia",
	"Limón",
	"Puntarenas"
	};
};

