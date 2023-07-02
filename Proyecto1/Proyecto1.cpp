#include <iostream>
#include "ArbolCanton.h"
#include "Canton.h"
#include "archivoLeer.h"

using namespace std;

int main()
{
	ArbolCanton arbol;
	int opcion;
	archivoLeer leerDatos;

	do {
		std::cout << "==== Menú del Árbol AVL ====" << std::endl;
		std::cout << "1. Insertar valor" << std::endl;
		std::cout << "2. Realizar recorrido inorden" << std::endl;
		std::cout << "3. Salir" << std::endl;
		std::cout << "Ingrese una opción: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			leerDatos.setNombreArchivo("cantones.txt");
			leerDatos.leerArchivo(arbol);
			std::cout << "Archivo leido correctamente." << std::endl;
			break;
		case 2:
			std::cout << "Recorrido inorden del Árbol AVL: ";
			arbol.mostrar();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "¡Hasta luego!" << std::endl;
			break;
		default:
			std::cout << "Opción inválida. Por favor, intente nuevamente." << std::endl;
			break;
		}

		std::cout << std::endl;
	} while (opcion != 3);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
