#include <iostream>
#include <string>
#include "ArbolCanton.h"
#include "ArbolCantonPoblacion.h"
#include "arbolProvinciaCanton.h"
#include "Canton.h"
#include "archivoLeer.h"

using namespace std;

int main()
{
	ArbolCantonPoblacion arbolCantonPoblacion;
	ArbolCanton arbolCanton;
	arbolProvinciaCanton arbolProvinciaCanton;
	int opcion;
	archivoLeer leerDatos;
	string buscarCanton;
	string buscarInfoCantonXprovincia;
	int rangoPoblacion;

	do {
		cout << "==== Menu ====" << std::endl;
		cout << "1. Insertar valores" << std::endl;
		cout << "==== Menu del arbol AVL  Canton ====" << std::endl;
		cout << "2. Realizar recorrido inorden" << std::endl;
		cout << "3. Preguntar informacion detallada de un canton (nombre, poblacion, cabecera, etc)" << std::endl;
		cout << "7. Modificar canton" << std::endl;
		cout << "==== Menu del arbol RojoNegro ProvinciaCanton ====" << std::endl;
		cout << "4. Consultar informacion de los Cantones de una provincia" << std::endl;
		cout << "5. listar por rango" << std::endl;
		cout << "==== Menu del arbol CantonPoblacion ====" << std::endl;
		cout << "8. Listar de mayor a menor poblacion" << std::endl;
		cout << "9. Listar de menor a mayor poblacion" << std::endl;
		cout << "10. listar por rango(De mayor hasta el rango) poblacion" << std::endl;
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
			arbolCanton.buscarPorNombre(buscarCanton, true);
			cout << endl;
			break;
		case 4:
			cout << "Digite el numero de la provincia de la que desea extrear los datos cantonales" << std::endl;
			cout << "1. San Jose" << std::endl;
			cout << "2.Alajuela" << std::endl;
			cout << "3.Cartago" << std::endl;
			cout << "4.Heredia" << std::endl;
			cout << "5.Guanacaste" << std::endl;
			cout << "6.Puntarenas" << std::endl;
			cout << "7.Limon" << std::endl;
			cout << "Digite el numero de la provincia de la que desea extrear los datos cantonales" << std::endl;
			std::cin.ignore();
			std::getline(std::cin, buscarInfoCantonXprovincia);
			arbolProvinciaCanton.infoXprovincia(buscarInfoCantonXprovincia);
			

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
		case 8:
			arbolCanton.llenarArbolPoblacion(arbolCantonPoblacion); //Se llena el arbol
			cout << "------------------Menor - Mayor-------------------" << endl;
			arbolCantonPoblacion.mostrarMenor();
			arbolCantonPoblacion = ArbolCantonPoblacion(); //Se elimina el arbol viejo y se crea uno nuevo sin datos
			break;
		case 9:
			arbolCanton.llenarArbolPoblacion(arbolCantonPoblacion);//Se llena el arbol
			cout << "---------------------Mayor - Menor---------------" << endl;
			arbolCantonPoblacion.mostrarMayor();
			arbolCantonPoblacion = ArbolCantonPoblacion();//Se elimina el arbol viejo y se crea uno nuevo sin datos
			break;
		case 10:
			arbolCanton.llenarArbolPoblacion(arbolCantonPoblacion);//Se llena el arbol
			cout << "Defina un rango para la poblacion: "<<endl;
			cin >> rangoPoblacion;
			arbolCantonPoblacion.mostrarRango(rangoPoblacion);
			arbolCantonPoblacion = ArbolCantonPoblacion();//Se elimina el arbol viejo y se crea uno nuevo sin datos
			break;
		default:
			cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
			break;
		}

		cout << endl;
	} while (opcion != 6);

	return 0;
}