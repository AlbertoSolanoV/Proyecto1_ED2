#include <iostream>
#include <string>
#include "ArbolCanton.h"
#include "Canton.h"
#include "archivoLeer.h"

using namespace std;

int main()
{
	ArbolCanton arbol;
	int opcion;
	archivoLeer leerDatos;
	string buscarCanton;

	do {
		cout << "==== Menú del Árbol AVL ====" << std::endl;
		cout << "1. Insertar valor" << std::endl;
		cout << "2. Realizar recorrido inorden" << std::endl;
		cout << "3. Buscar canton por nombre" << std::endl;
		cout << "4. Salir" << std::endl;
		cout << "Ingrese una opción: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerDatos.setNombreArchivo("cantones.txt");
			leerDatos.leerArchivo(arbol);
			cout << "Archivo leido correctamente." << endl;
			break;
		case 2:
			cout << "Recorrido inorden del Árbol AVL: ";
			arbol.mostrar();
			cout << endl;
			break;
		case 3:
			cout << "Digite el nombre del canton a buscar: ";
			
			std::cin.ignore(); 
			std::getline(std::cin, buscarCanton);
			

			arbol.buscarPorNombre(buscarCanton);
			cout << endl;
			break;
		case 4:
			cout << "¡Hasta luego!" << endl;
			break;
		default:
			cout << "Opción inválida. Por favor, intente nuevamente." << endl;
			break;
		}

		cout << endl;
	} while (opcion != 4);

	return 0;
}
