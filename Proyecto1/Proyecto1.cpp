#include <iostream>
#include <string>
#include "ArbolCanton.h"
#include "arbolProvinciaCanton.h"
#include "Canton.h"
#include "archivoLeer.h"

using namespace std;

int main()
{
	ArbolCanton arbolCanton;
	arbolProvinciaCanton arbolProvinciaCanton;
	int opcion;
	archivoLeer leerDatos;
	string buscarCanton;

	do {
		cout << "==== Menu ====" << std::endl;
		cout << "1. Insertar valores" << std::endl;
		cout << "==== Menu del arbol AVL  Canton ====" << std::endl;
		cout << "2. Realizar recorrido inorden" << std::endl;
		cout << "3. Preguntar informacion detallada de un canton (nombre, poblacion, cabecera, etc)" << std::endl;
		cout << "7. Modificar canton" << std::endl;
		cout << "==== Menu del arbol RojoNegro ProvinciaCanton ====" << std::endl;
		cout << "4. Insertar valor" << std::endl;
		cout << "5. listar" << std::endl;
		cout << "6. Salir" << std::endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerDatos.setNombreArchivo("cantones.txt");
			leerDatos.leerArchivo(arbolCanton, arbolProvinciaCanton);
			cout << "Archivo leido correctamente." << endl;
			break;
		case 2:
			cout << "Recorrido inorden del arbol AVL: ";
			arbolCanton.mostrar();
			cout << endl;
			break;
		case 3:
			cout << "Digite el nombre del canton a buscar: ";
			std::cin.ignore();
			std::getline(std::cin, buscarCanton);
			arbolCanton.buscarPorNombre(buscarCanton);
			cout << endl;
			break;
		case 4:
			//arbolProvinciaCanton.insertar();
			break;
		case 5:
			arbolProvinciaCanton.listar();
			break;
		case 6:
			cout << "Hasta luego!" << endl;
			break;
		case 7:
			cout << "Digite el nombre del canton a modificar: ";
			std::cin.ignore();
			std::getline(std::cin, buscarCanton);
			arbolCanton.modifyCanton(buscarCanton);
			cout << endl;
			break;
		default:
			cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
			break;
		}

		cout << endl;
	} while (opcion != 6);

	return 0;
}