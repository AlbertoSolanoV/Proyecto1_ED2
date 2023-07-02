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
0. numero de provincia
1. Cabecera de canton
2. NombreCanton
3. Cantidad Poblacion
me falta poner los demas datos
*/
void archivoLeer::leerArchivo(ArbolCanton& pArbolCanton)
{
	ifstream archivo(this->nombreArchivo);

	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			vector<string> datos = split(linea, ',');
			Canton nuevoCanton;
			nuevoCanton.setCabecera(datos[1]);
			nuevoCanton.setNombre(datos[2]);

			float poblacion = stof(datos[3]);
			nuevoCanton.setCantidadPersona(poblacion);

			pArbolCanton.insertar(nuevoCanton);

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

