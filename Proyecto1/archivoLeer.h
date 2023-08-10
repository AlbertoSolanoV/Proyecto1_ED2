#pragma once
#include "ArbolCanton.h"
#include "arbolProvinciaCanton.h"
#include "GrafoCantones.h"
#include "Canton.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class archivoLeer
{
private:
	string nombreArchivo;

public:
	void setNombreArchivo(string);
	string getNombreArchivo();

	void leerArchivo(ArbolCanton&, arbolProvinciaCanton&);
	vector<string> split(const std::string& cadena, char delimitador);

};

