#include "GrafoCantonesGestor.h"

void GrafoCantonesGestor::llenarGrafos()
{
	inicializarGrafos();


	//Envia los grafos creados al metodo de lectura de txt
	lectura.setNombreArchivo("distancias.txt");

	lectura.leerCSVProvincia(*grafoCantonSjo, *grafoCantonHer, *grafoCantonCar, *grafoCantonAla, *grafoCantonPun, *grafoCantonGua, *grafoCantonLim);

}

void GrafoCantonesGestor::rutaMasCorta(string provincia, string cantonInicio, string cantonDestino)
{
	//validar la pricia y el canton
	if (validarProvincias(provincia)) {
		ruta = grafoCantonSjo->rutaMasCorta(cantonInicio, cantonDestino);

		// Mostrar la ruta más corta
		cout << "Ruta más corta entre " << cantonInicio << " y " << cantonDestino << ":" << std::endl;
		for (const auto& canton : ruta) {
			cout << canton << " -> ";
		}
		cout << std::endl;
	}
	else
	{
		cout << "La provincia ingresada no es valida" << endl;
	}
}

void GrafoCantonesGestor::fibraOptica(string provincia)
{
	//validar la pricia y el canton
	if (validarProvincias(provincia)) {

		std::vector<AristaDetallada> redFibra = grafoCantonCar->kruskal();
		for (const auto& arista : redFibra) {
			std::cout << "Arista: " << arista.cantonOrigen << " - " << arista.cantonDestino << " (Peso: " << arista.peso << ")\n";
		}
	}
	else
	{
		cout << "La provincia ingresada no es valida" << endl;
	}
}

bool GrafoCantonesGestor::validarProvincias(string provincia)
{
	return std::find(PROVINCIAS_NOMBRES.begin(), PROVINCIAS_NOMBRES.end(), provincia) != PROVINCIAS_NOMBRES.end();
}

//inicializa los grafos
void GrafoCantonesGestor::inicializarGrafos()
{
	grafoCantonSjo = new GrafoCantones();
	grafoCantonAla = new GrafoCantones();
	grafoCantonCar = new GrafoCantones();
	grafoCantonHer = new GrafoCantones();
	grafoCantonPun = new GrafoCantones();
	grafoCantonLim = new GrafoCantones();
	grafoCantonGua = new GrafoCantones();
}

GrafoCantonesGestor::GrafoCantonesGestor()
{
}
