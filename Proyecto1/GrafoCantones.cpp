#include "GrafoCantones.h"
#include <queue>

GrafoCantones::GrafoCantones() {
}


// Agregar un cantón (nodo) al grafo
void GrafoCantones::agregarCanton(const std::string& canton) {
	listaAdyacencia[canton] = std::vector<Arista>();
	this->nodos++;
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

GrafoCantones* GrafoCantones::recubridorMinimo_kruskal() 
{
	GrafoCantones* result = new GrafoCantones();

	unordered_map<string, vector<Arista>> map;
	vector<int> pertenece(this->nodos);
	int i = 0;
	for (const auto& kvp : this->listaAdyacencia) {
		map[kvp.first] = vector<Arista>();
		pertenece[i] = i;
		i++;
	}

	int nodoA;
	int nodoB;
	string nameA;
	string nameB;
	int arcos = 1;

	while (arcos < this->nodos) {
		i = 0; 
		int min = numeric_limits<int>::max(); 
		for (const auto& firstList : this->listaAdyacencia) {
			string cantonActual = firstList.first;
			for (int k = 0; k < this->nodos; k++) {
				
				if (this->listaAdyacencia[cantonActual].size() > k && min > this->listaAdyacencia[cantonActual].at(k).peso && this->listaAdyacencia[cantonActual].at(k).peso != 0 && pertenece[i] != pertenece[k]) {
					min = this->listaAdyacencia[cantonActual].at(k).peso;
					nodoA = i;
					nodoB = k;
					nameA = cantonActual;
					nameB = this->listaAdyacencia[cantonActual].at(k).cantonDestino;
				}
				k++;
			}
			i++;
		}

		if (pertenece[nodoA] != pertenece[nodoB]) {
			map[nameA].push_back({ nameB, min });
			map[nameB].push_back({ nameA, min });
		}

		int temp = pertenece[nodoB];
		pertenece[nodoB] = pertenece[nodoA];
		for (int j = 0; j < this->nodos; j++) {
			if (pertenece[j] == temp) {
				pertenece[j] = pertenece[nodoA];
			}
		}
		arcos++;
	}

	return result;
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