﻿#include <iostream>
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
		cout << "0. Insertar valores" << std::endl;
		cout << "1. Modificar canton" << std::endl;
		cout << "2. Consultar para una provincia : la cantidad de cantones y la población total." << std::endl;
		cout << "3. Preguntar informacion detallada de un canton (nombre, poblacion, cabecera, etc)" << std::endl;
		cout << "4. Mostrar detalle de datos de los cantones de una provincia" << std::endl;
		cout << "5. Listar cantones del pais agrupados por provincia (Ordenado por nombre asc)" << std::endl;
		cout << "6. Listar cantones del pais agrupados por provincia desc (Ordenado por nombre desc)" << std::endl;
		cout << "7. Listar de mayor a menor poblacion" << std::endl;
		cout << "8. Listar de menor a mayor poblacion" << std::endl;
		cout << "9. listar por rango(De mayor hasta el rango) poblacion" << std::endl;
		cout << "10. Salir" << std::endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 0:
			leerDatos.setNombreArchivo("cantones.txt");
			leerDatos.leerArchivo(arbolCanton, arbolProvinciaCanton);
			cout << "Archivo leido correctamente." << endl;
			break;
		case 1:
			cout << "Digite el nombre del canton a modificar: ";
			std::cin.ignore();
			std::getline(std::cin, buscarCanton);
			arbolCanton.modifyCanton(buscarCanton);
			cout << endl;
			break;
		case 2:
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
			if(arbolProvinciaCanton.validarProvincia(buscarInfoCantonXprovincia))
				arbolProvinciaCanton.buscarInformacionProvincia(buscarInfoCantonXprovincia);
			else
				cout << "Digito no valido, seleccione del 1 al 7" << std::endl;

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
			cout << "Cantones del pais ASC";
			arbolProvinciaCanton.desplegarCantonesInOrder();
			cout << endl;
			break;
		case 6:
			cout << "Cantones del pais DESC";
			arbolProvinciaCanton.desplegarCantonesInOrderRevez();
			cout << endl;
			break;
		case 7:
			arbolCanton.llenarArbolPoblacion(arbolCantonPoblacion); //Se llena el arbol
			cout << "------------------Menor - Mayor-------------------" << endl;
			arbolCantonPoblacion.mostrarMenor();
			arbolCantonPoblacion = ArbolCantonPoblacion(); //Se elimina el arbol viejo y se crea uno nuevo sin datos
			break;
		case 8:
			arbolCanton.llenarArbolPoblacion(arbolCantonPoblacion);//Se llena el arbol
			cout << "---------------------Mayor - Menor---------------" << endl;
			arbolCantonPoblacion.mostrarMayor();
			arbolCantonPoblacion = ArbolCantonPoblacion();//Se elimina el arbol viejo y se crea uno nuevo sin datos
			break;
		case 9:
			arbolCanton.llenarArbolPoblacion(arbolCantonPoblacion);//Se llena el arbol
			cout << "Defina un rango para la poblacion: " << endl;
			cin >> rangoPoblacion;
			arbolCantonPoblacion.mostrarRango(rangoPoblacion);
			arbolCantonPoblacion = ArbolCantonPoblacion();//Se elimina el arbol viejo y se crea uno nuevo sin datos
			break;
		case 10:
			cout << "Salir, Muchas gracias!" << endl;
			break;
		default:
			cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
			break;
		}

		cout << endl;
	} while (opcion != 10);

	return 0;
}