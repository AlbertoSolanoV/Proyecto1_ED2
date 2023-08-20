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
	string currentProvincia;

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

	void leerArchivos();

	//Dada una provincia la ruta para realizar una instalacion de fibra optica
	void fibraOptica(string provincia);
	//Para los cantones vecinos
	void cantonesVecinos(string provincia, string canton);

	// Getter method
	string getCurrentProvincia();

	GrafoCantones& getGrafoBasedOnProv();

	int convertNameToNumber();

	// Setter method
	void setCurrentProvincia(const std::string& newValue);

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
	"algoRandom",
	"San José",
	"Alajuela",
	"Cartago",
	"Heredia",
	"Guanacaste",
	"Puntarenas",
	"Limón",
	};
};

