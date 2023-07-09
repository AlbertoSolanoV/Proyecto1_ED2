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
		cout << "==== Menú ====" << std::endl;
		cout << "1. Insertar valores" << std::endl;
		cout << "==== Menú del Árbol AVL  Canton ====" << std::endl;
		cout << "2. Realizar recorrido inorden" << std::endl;
		cout << "3. Buscar canton por nombre" << std::endl;
		cout << "==== Menú del Árbol RojoNegro ProvinciaCanton ====" << std::endl;
		cout << "4. Insertar valor" << std::endl;
		cout << "5. Realizar recorrido inorden" << std::endl;
		cout << "6. Salir" << std::endl;
		cout << "Ingrese una opción: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerDatos.setNombreArchivo("cantones.txt");
			leerDatos.leerArchivo(arbolCanton, arbolProvinciaCanton);
			cout << "Archivo leido correctamente." << endl;
			break;
		case 2:
			cout << "Recorrido inorden del Árbol AVL: ";
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

			break;
		case 5:
		
			break;
		case 6:
			cout << "¡Hasta luego!" << endl;
			break;
		default:
			cout << "Opción inválida. Por favor, intente nuevamente." << endl;
			break;
		}

		cout << endl;
	} while (opcion != 6);

	return 0;
}
