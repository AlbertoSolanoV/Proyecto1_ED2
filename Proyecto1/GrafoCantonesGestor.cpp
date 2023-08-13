#include "GrafoCantonesGestor.h"

void GrafoCantonesGestor::llenarGrafos()
{
	inicializarGrafos();


	//Envia los grafos creados al metodo de lectura de txt
	vector<shared_ptr<GrafoCantones>> listaObjs;
	listaObjs.push_back(std::make_shared<GrafoCantones>("hola"));
	/*Debe de ser cambiado al metedo de lectura
	* Se deben de enviar todos los grafos creados para que se les asigne la data
	*/

// Agregar cantones al grafo
	grafoCantonSjo->agregarCanton("San José");
	grafoCantonSjo->agregarCanton("Heredia");
	grafoCantonSjo->agregarCanton("Alajuela");
	grafoCantonSjo->agregarCanton("Cartago");
	grafoCantonSjo->agregarCanton("Cartago Norte");
	grafoCantonSjo->agregarCanton("Tibas");

	// Agregar aristas con peso entre los cantones
	grafoCantonSjo->agregarArista("San José", "Heredia", 10);
	grafoCantonSjo->agregarArista("San José", "Alajuela", 20);
	grafoCantonSjo->agregarArista("Heredia", "Cartago", 15);
	grafoCantonSjo->agregarArista("Cartago", "San José", 5);
	grafoCantonSjo->agregarArista("Heredia", "Cartago Norte", 12);
	grafoCantonSjo->agregarArista("Tibas", "Alajuela", 8);

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

bool GrafoCantonesGestor::validarProvincias(string provincia)
{
	return std::find(PROVINCIAS.begin(), PROVINCIAS.end(), provincia) != PROVINCIAS.end();
}

//inicializa los grafos
void GrafoCantonesGestor::inicializarGrafos()
{
	grafoCantonSjo = new GrafoCantones("sanjose.csv");
	grafoCantonAla = new GrafoCantones("alajuela.csv");
	grafoCantonCar = new GrafoCantones("cartago.csv");
	grafoCantonHer = new GrafoCantones("heredia.csv");
	grafoCantonPun = new GrafoCantones("puntarenas.csv");
	grafoCantonLim = new GrafoCantones("limon.csv");
	grafoCantonGua = new GrafoCantones("guanacaste.csv");
}

GrafoCantonesGestor::GrafoCantonesGestor()
{
}
