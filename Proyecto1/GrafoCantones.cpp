#include "GrafoCantones.h"
#include <queue>

GrafoCantones::GrafoCantones() {
}


// Agregar un cant�n (nodo) al grafo
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
		std::cout << "Cant�n " << kvp.first << ": ";
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

	// Reconstruir la ruta desde el cant�n de destino hasta el cant�n de inicio
	std::vector<std::string> ruta;
	std::string cantonActual = cantonDestino;

	while (!cantonActual.empty()) {
		ruta.insert(ruta.begin(), cantonActual);
		cantonActual = padres[cantonActual];
	}

	return ruta;
}

/*
Preparaci�n de los datos: Para aplicar Kruskal, necesitas tener las aristas del grafo junto con sus pesos. 
En tu implementaci�n, las aristas se almacenan en std::unordered_map<std::string, std::vector<Arista>> listaAdyacencia;.

Ordenar las aristas: 
Primero, todas las aristas se colocan en una lista y se ordenan en orden ascendente seg�n sus pesos. 
Esto te permite seleccionar las aristas de menor peso primero.

Iniciar estructuras auxiliares: 
Para controlar la conectividad entre los v�rtices, se utilizan estructuras auxiliares. 
En tu caso, se utiliza un diccionario std::unordered_map<std::string, std::string> padres; para rastrear los padres de cada v�rtice.

Iteraci�n por las aristas ordenadas: 
A medida que se recorren las aristas ordenadas, se verifica si unir los v�rtices de la arista no forma un ciclo. 
Esto se hace verificando si los v�rtices ya tienen el mismo padre. Si no tienen el mismo padre, se agrega la arista al �rbol de expansi�n m�nima y 
se actualiza la estructura de padres.

Resultado: Al finalizar, el algoritmo devuelve un conjunto de aristas que forman el �rbol de expansi�n m�nima. 
Cada arista tiene la informaci�n de los v�rtices conectados y el peso de la arista.
*/
std::vector<AristaDetallada> GrafoCantones::kruskal() {
	std::vector<AristaDetallada> mst;
	std::vector<std::pair<int, std::pair<std::string, std::string>>> aristasOrdenadas;

	for (const auto& kvp : listaAdyacencia) {
		for (const auto& arista : kvp.second) {
			aristasOrdenadas.push_back({ arista.peso, { kvp.first, arista.cantonDestino } });
		}
	}

	std::sort(aristasOrdenadas.begin(), aristasOrdenadas.end());

	std::unordered_map<std::string, std::string> padres;
	for (const auto& kvp : listaAdyacencia) {
		padres[kvp.first] = kvp.first;
	}

	for (const auto& aristaInfo : aristasOrdenadas) {
		std::string cantonOrigen = aristaInfo.second.first;
		std::string cantonDestino = aristaInfo.second.second;
		int peso = aristaInfo.first;

		if (encontrarPadre(cantonOrigen, padres) != encontrarPadre(cantonDestino, padres)) {
			mst.push_back({ cantonOrigen, cantonDestino, peso });
			unirPadres(cantonOrigen, cantonDestino, padres);
		}
	}

	return mst;
}
/*
El m�todo encontrarPadre() implementa una t�cnica llamada "compresi�n de ruta", que mejora la eficiencia en la b�squeda de padres. 

*/
std::string GrafoCantones::encontrarPadre(const std::string& canton, std::unordered_map<std::string, std::string>& padres) {
	if (padres[canton] != canton) {
		padres[canton] = encontrarPadre(padres[canton], padres);
	}
	return padres[canton];
}

/*La funci�n unirPadres() se encarga de unir dos subconjuntos (�rboles) en uno solo.*/
void GrafoCantones::unirPadres(const std::string& canton1, const std::string& canton2, std::unordered_map<std::string, std::string>& padres) {
	std::string padreCanton1 = encontrarPadre(canton1, padres);
	std::string padreCanton2 = encontrarPadre(canton2, padres);
	padres[padreCanton1] = padreCanton2;
}
