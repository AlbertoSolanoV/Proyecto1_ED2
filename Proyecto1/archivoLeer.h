#pragma once
#include "ArbolCanton.h"
#include "arbolProvinciaCanton.h"
#include "GrafoCantones.h"
#include "Canton.h"
#include <string>
#include <fstream>
#include <vector>
#include <memory> // Necesario para std::shared_ptr

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

	/*lee una lista de objetos
	* reference_wrapper -> se utiliza para poder tener referencia a los objetos
	* mejora la gestion de memoria por las referencias
	*/
	void leerCSVProvincia(GrafoCantones& grafoSJ, GrafoCantones& grafoH, GrafoCantones& grafoC, GrafoCantones& grafoA, GrafoCantones& grafoP, GrafoCantones& grafoG, GrafoCantones& grafoL);

};

