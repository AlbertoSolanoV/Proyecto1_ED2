#include "GrafoCantonesGestor.h"

void GrafoCantonesGestor::llenarGrafos()
{
	inicializarGrafos();


	//Envia los grafos creados al metodo de lectura de txt
	
	/*Debe de ser cambiado al metedo de lectura
	* Se deben de enviar todos los grafos creados para que se les asigne la data
	*/

// Agregar cantones al grafo
	grafoCantonSjo->agregarCanton("1-San Jose");
	grafoCantonSjo->agregarCanton("1-Heredia");
	grafoCantonSjo->agregarCanton("1-Alajuela");
	grafoCantonSjo->agregarCanton("2-Cartago");
	grafoCantonSjo->agregarCanton("2-Cartago Norte");
	grafoCantonSjo->agregarCanton("1-Tibas");

	// Agregar aristas con peso entre los cantones
	grafoCantonSjo->agregarArista("1-San Jose", "1-Heredia", 10);
	grafoCantonSjo->agregarArista("1-San Jose", "1-Alajuela", 20);
	grafoCantonSjo->agregarArista("1-Heredia", "2-Cartago", 15);
	grafoCantonSjo->agregarArista("2-Cartago", "1-San Jose", 5);
	grafoCantonSjo->agregarArista("1-Heredia", "2-Cartago Norte", 12);
	grafoCantonSjo->agregarArista("1-Tibas", "1-Alajuela", 8);

}

void GrafoCantonesGestor::rutaMasCorta(string provincia, string cantonInicio, string cantonDestino)
{
	ruta = grafoCantonSjo->rutaMasCorta(cantonInicio, cantonDestino);

	// Mostrar la ruta más corta
	cout << "Ruta más corta entre " << cantonInicio << " y " << cantonDestino << ":" << std::endl;
	for (const auto& canton : ruta) {
		cout << canton << " -> ";
	}
	cout << std::endl;
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
