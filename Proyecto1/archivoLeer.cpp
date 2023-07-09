#include "archivoLeer.h"
#include <vector>
#include <iomanip>

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
me falta poner los demas datos
*/
void archivoLeer::leerArchivo(ArbolCanton& pArbolCanton, arbolProvinciaCanton& pArbolProvinciaCanton)
{
	ifstream archivo(this->nombreArchivo);

	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			vector<string> datos = split(linea, '-');
			Canton nuevoCanton;
			nuevoCanton.setNombre(datos[0]);
			nuevoCanton.setCabecera(datos[2]);
			datos[4].erase(std::remove_if(datos[4].begin(), datos[4].end(), [](unsigned char c) { return std::isspace(c); }), datos[4].end()); //Para quitar el espacio
			int poblacion = stoi(datos[4]);
			nuevoCanton.setCantidadPersona(poblacion);
			nuevoCanton.setNombreAlcalde(datos[5]);

			pArbolCanton.insertar(nuevoCanton); //Insertamos en provincia Canton
			NodoCanton* nodoCanton = pArbolCanton.buscarPorNombre(datos[0]);
			//Buscamos el nodo del canton registrado
			pArbolProvinciaCanton.insertar(datos[3],datos[0],nodoCanton);

			cout << linea << std::endl;  // Imprime la línea en la consola.
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

