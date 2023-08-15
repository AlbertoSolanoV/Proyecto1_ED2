#include "archivoLeer.h"
#include <vector>
#include <iomanip>
#include "GrafoCantonesGestor.h"
void archivoLeer::setNombreArchivo(string pNombreArchivo)
{
	this->nombreArchivo = pNombreArchivo;
}

string archivoLeer::getNombreArchivo()
{
	return this->nombreArchivo;
}
/*
En el vector datos el orden es:
0. Canton
1. Nombre Provincia
2. Cabecera de canton // Distrito
3. Numero de provincia
4. cantidad poblacion
5. Nombre alcalde
*/
void archivoLeer::leerArchivo(ArbolCanton& pArbolCanton, arbolProvinciaCanton& pArbolProvinciaCanton)
{
	ifstream archivo(this->nombreArchivo);

	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			vector<string> datos = split(linea, '-');
			Canton* nuevoCanton = new Canton();
			
			nuevoCanton->setNombre(datos[0]);
			nuevoCanton->setCabecera(datos[2]);
			datos[4].erase(std::remove_if(datos[4].begin(), datos[4].end(), [](unsigned char c) { return std::isspace(c); }), datos[4].end()); //Para quitar el espacio
			int poblacion = stoi(datos[4]);
			nuevoCanton->setCantidadPersona(poblacion);
			nuevoCanton->setNombreAlcalde(datos[5]);

			pArbolCanton.insertar(nuevoCanton); //Insertamos en provincia Canton
			NodoCanton* nodoCanton = pArbolCanton.buscarPorNombre(datos[0], false);
			
			//Buscamos el nodo del canton registrado
			pArbolProvinciaCanton.insertar(datos[3],datos[0], nodoCanton);

			cout << "Canton: " <<datos[0] << " ingresado correctamente." << std::endl;  // Imprime la línea en la consola.
		}
		archivo.close();  // Cierra el archivo después de leerlo.
	}
	else {
		cout << "No se pudo abrir el archivo." << std::endl;
	}

}

vector<string> archivoLeer::split(const std::string& cadena, char delimitador)
{
	vector<string> tokens;
	size_t inicio = 0;
	size_t fin = cadena.find(delimitador);

	while (fin != string::npos) {
		std::string token = cadena.substr(inicio, fin - inicio);
		tokens.push_back(token);
		inicio = fin + 1;
		fin = cadena.find(delimitador, inicio);
	}

	std::string ultimoToken = cadena.substr(inicio);
	tokens.push_back(ultimoToken);

	return tokens;
}


void archivoLeer::leerCSVProvincia(GrafoCantones& grafoSJ, GrafoCantones& grafoH, GrafoCantones& grafoC, GrafoCantones& grafoA, GrafoCantones& grafoP, GrafoCantones& grafoG, GrafoCantones& grafoL) {


	//recorre agregando los cantones
	ifstream archivo(this->nombreArchivo);

	if (archivo.is_open()) {
		string linea;

		vector<string> cantAgregados;

		
		//recorre el archivo
		while (getline(archivo, linea)) {
			
			//recorre la linea del archivo
			vector<string> datos = split(linea, ',');
			
			bool existe = find(cantAgregados.begin(), cantAgregados.end(), datos[1]) != cantAgregados.end();

			if (!existe)
			{
				cantAgregados.push_back(datos[1]);

				//valida el numero de la provicia para agregar al grafo
				switch (stoi(datos[0])) {
				case GrafoCantonesGestor::SANJOSE:
					grafoSJ.agregarCanton(datos[1]);
					break;
				case GrafoCantonesGestor::ALAJUELA:
					grafoA.agregarCanton(datos[1]);
					break;
				case GrafoCantonesGestor::CARTAGO:
					grafoC.agregarCanton(datos[1]);
					break;
				case GrafoCantonesGestor::HEREDIA:
					grafoH.agregarCanton(datos[1]);
					break;
				case GrafoCantonesGestor::GUNACASTE:
					grafoG.agregarCanton(datos[1]);
					break;
				case GrafoCantonesGestor::PUNTARENAS:
					grafoP.agregarCanton(datos[1]);
					break;
				case GrafoCantonesGestor::LIMON:
					grafoL.agregarCanton(datos[1]);
					break;
				default:
					std::cout << "Invalid value entered. Please enter a value between 1 and 7." << std::endl;
					break;
				}
			}

		}
		archivo.close();  // Cierra el archivo después de leerlo.
	}
	else {
		cout << "No se pudo abrir el archivo." << std::endl;
	}


	//recorre agregando las aristas
		//recorre agregando los cantones
	ifstream archivoAristas(this->nombreArchivo);

	if (archivoAristas.is_open()) {
		string linea;


		//recorre el archivo
		while (getline(archivoAristas, linea)) {

			//recorre la linea del archivo
			vector<string> datos = split(linea, ',');

			//valida el numero de la provicia para agregar al grafo
			switch (stoi(datos[0])) {
			case GrafoCantonesGestor::SANJOSE:
				grafoSJ.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			case GrafoCantonesGestor::ALAJUELA:
				grafoA.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			case GrafoCantonesGestor::CARTAGO:
				grafoC.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			case GrafoCantonesGestor::HEREDIA:
				grafoH.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			case GrafoCantonesGestor::GUNACASTE:
				grafoG.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			case GrafoCantonesGestor::PUNTARENAS:
				grafoP.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			case GrafoCantonesGestor::LIMON:
				grafoL.agregarArista(datos[1], datos[2], stoi(datos[3]));
				break;
			default:
				std::cout << "Invalid value entered. Please enter a value between 1 and 7." << std::endl;
				break;
			}
		}

		archivo.close();  // Cierra el archivo después de leerlo.
	}
	else {
		cout << "No se pudo abrir el archivo." << std::endl;
	}
}

