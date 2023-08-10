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



	//Enum de
	enum PROVINCIAS {
		SJO = 1,
		ALA = 2,
		CAR = 3,
		HER = 4,
		GUA = 5,
		PUN = 6,
		LIM = 7
	};
};

