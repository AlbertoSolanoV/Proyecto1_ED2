#include "GrafoCantones.h"
#include <queue>

GrafoCantones::GrafoCantones() {
}

GrafoCantones::GrafoCantones(string nombreArchivo) {
}

// Agregar un cantón (nodo) al grafo
void GrafoCantones::agregarCanton(const std::string& canton) {
	listaAdyacencia[canton] = std::vector<Arista>();
}

// Agregar una arista (con peso) entre dos cantones existentes en el grafo
void GrafoCantones::agregarArista(const std::string& canton1, const std::string& canton2, int peso) {
	listaAdyacencia[canton1].push_back({ canton2, peso });
	listaAdyacencia[canton2].push_back({ canton1, peso }); 
}

// Mostrar el grafo
void GrafoCantones::mostrarGrafo() {
	for (const auto& kvp : listaAdyacencia) {
		std::cout << "Cantón " << kvp.first << ": ";
		for (const auto& arista : kvp.second) {
			std::cout << "(" << arista.cantonDestino << ", " << arista.peso << ") ";
		}
		std::cout << std::endl;
	}
}

std::vector<std::string>  GrafoCantones::rutaMasCorta(const std::string& cantonInicio, const std::string& cantonDestino) {
	std::unordered_map<std::string, int> distancias;
	std::unordered_map<std::string, std::string> padres;

	for (const auto& kvp : listaAdyacencia) {
		distancias[kvp.first] = std::numeric_limits<int>::max();
	}

	std::queue<std::string> cola;
	cola.push(cantonInicio);
	distancias[cantonInicio] = 0;
	padres[cantonInicio] = "";

	while (!cola.empty()) {
		std::string cantonActual = cola.front();
		cola.pop();

		for (const auto& arista : listaAdyacencia[cantonActual]) {
			int distanciaNueva = distancias[cantonActual] + arista.peso;
			if (distanciaNueva < distancias[arista.cantonDestino]) {
				distancias[arista.cantonDestino] = distanciaNueva;
				padres[arista.cantonDestino] = cantonActual;
				cola.push(arista.cantonDestino);
			}
		}
	}

	// Reconstruir la ruta desde el cantón de destino hasta el cantón de inicio
	std::vector<std::string> ruta;
	std::string cantonActual = cantonDestino;

	while (!cantonActual.empty()) {
		ruta.insert(ruta.begin(), cantonActual);
		cantonActual = padres[cantonActual];
	}

	return ruta;
}

string GrafoCantones::getNombreArchivo() {
	return nombreArchivo;
}


void GrafoCantones::setNombreArchivo(const string & value) {
	nombreArchivo = value;
}