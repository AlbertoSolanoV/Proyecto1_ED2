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
		GrafoCantones& result = getGrafoBasedOnProv();

		ruta = result.rutaMasCorta(cantonInicio, cantonDestino);

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

		GrafoCantones& result = getGrafoBasedOnProv();

		std::vector<AristaDetallada> redFibra = result.kruskal();
		for (const auto& arista : redFibra) {
			std::cout << "Arista: " << arista.cantonOrigen << " - " << arista.cantonDestino << " (Peso: " << arista.peso << ")\n";
		}
	}
	else
	{
		cout << "La provincia ingresada no es valida" << endl;
	}
}

void GrafoCantonesGestor::cantonesVecinos(string provincia, string canton)
{
	//validar la pricia y el canton
	if (validarProvincias(provincia)) {

		GrafoCantones& result = getGrafoBasedOnProv();

		result.mostrarGrafo(provincia);

		/*std::vector<AristaDetallada> redFibra = result.kruskal();
		for (const auto& arista : redFibra) {
			if (arista.cantonOrigen.compare(canton) == 0 || arista.cantonDestino.compare(canton) == 0)
				std::cout << "Cantones: " << arista.cantonOrigen << " - " << arista.cantonDestino << " (Distancia: " << arista.peso << ")\n";
		}*/
	}
	else
	{
		cout << "La provincia ingresada no es valida" << endl;
	}
}

bool GrafoCantonesGestor::validarProvincias(string provincia)
{
	bool exist = false;
	for (int i = 0; i < PROVINCIAS_NOMBRES.size(); i++) {
		if (PROVINCIAS_NOMBRES[i].compare(provincia) == 0)
		{
			exist = true;
			setCurrentProvincia(to_string(i));
			break;
		}
	}

	return exist;
}

string GrafoCantonesGestor::getCurrentProvincia()
{
	return this->currentProvincia;
}

void GrafoCantonesGestor::setCurrentProvincia(const std::string& newValue)
{
	this->currentProvincia = newValue;
}

GrafoCantones& GrafoCantonesGestor::getGrafoBasedOnProv()
{
	GrafoCantones nullGrafo;
	//valida el numero de la provicia para agregar al grafo
	switch (stoi(getCurrentProvincia())) {
	case GrafoCantonesGestor::SANJOSE:
		return *grafoCantonSjo;

		break;
	case GrafoCantonesGestor::ALAJUELA:
		return *grafoCantonAla;

		break;
	case GrafoCantonesGestor::CARTAGO:
		return *grafoCantonCar;

		break;
	case GrafoCantonesGestor::HEREDIA:
		return *grafoCantonHer;

		break;
	case GrafoCantonesGestor::GUNACASTE:
		return *grafoCantonGua;

		break;
	case GrafoCantonesGestor::PUNTARENAS:
		return *grafoCantonPun;

		break;
	case GrafoCantonesGestor::LIMON:
		return *grafoCantonLim;
		break;
	default:
		std::cout << "Invalid value entered. Please enter a value between 1 and 7. getGrafoBasedOnProv" << std::endl;
		return nullGrafo;
		break;
	}
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
