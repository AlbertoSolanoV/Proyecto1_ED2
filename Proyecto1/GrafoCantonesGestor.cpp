#include "GrafoCantonesGestor.h"

void GrafoCantonesGestor::llenarGrafos()
{
	inicializarGrafos();


	//Envia los grafos creados al metodo de lectura de txt
	//vector<shared_ptr<GrafoCantones>> listaObjs;
	//listaObjs.push_back(std::make_shared<GrafoCantones>("hola"));
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

void GrafoCantonesGestor::recubridorMinimo_kruskal()
{
	cout << "Cual provincia quiere saber el recubridor minimo para la instalacion de la fibra?" << endl;
	cout << "1. San Jose" << endl;
	cout << "2. Alajuela" << endl;
	cout << "3. Cartago" << endl;
	cout << "4. Heredia" << endl;
	cout << "5. Puntarenas" << endl;
	cout << "6. Limon" << endl;
	cout << "7. Guanacaste" << endl;
	bool incorrect = true;
	int opcion;
	string opcionString;
	do {
		try {
			cout << "Ingrese una opcion: ";
			std::getline(std::cin, opcionString);
			opcion = stoi(opcionString);
			incorrect = false;
		}
		catch (const std::exception e) {
			cout << "Debe de ser un numero! Nuevamente: " << endl;
		}
	} while (incorrect);

	switch (opcion)
	{
	case 1:
		grafoCantonSjo->recubridorMinimo_kruskal();
		break;
	case 2:
		grafoCantonAla->recubridorMinimo_kruskal();
		break;
	case 3:
		grafoCantonCar->recubridorMinimo_kruskal();
		break;
	case 4:
		grafoCantonHer->recubridorMinimo_kruskal();
		break;
	case 5:
		grafoCantonPun->recubridorMinimo_kruskal();
		break;
	case 6:
		grafoCantonLim->recubridorMinimo_kruskal();
		break;
	case 7:
		grafoCantonGua->recubridorMinimo_kruskal();
		break;
	default:
		cout << "La provincia no existe. " << endl;
		break;
	}
}

void imprimirRespuesta() {

}

bool GrafoCantonesGestor::validarProvincias(string provincia)
{
	return std::find(PROVINCIAS.begin(), PROVINCIAS.end(), provincia) != PROVINCIAS.end();
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
