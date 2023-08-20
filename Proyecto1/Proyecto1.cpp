#include "Micelaneos.h"
#include <iostream>
#include <string>
#include "ArbolCanton.h"
#include "ArbolCantonPoblacion.h"
#include "arbolProvinciaCanton.h"
#include "Canton.h"
#include "archivoLeer.h"
#include "GrafoCantonesGestor.h"
using namespace std;

int main()
{
	ArbolCantonPoblacion arbolCantonPoblacion;
	ArbolCanton arbolCanton;
	arbolProvinciaCanton arbolProvinciaCanton;
	int opcion;
	string opcionString;
	archivoLeer leerDatos;
	string buscarCanton;
	string buscarInfoCantonXprovincia;
	string provinciaGrafo;
	string rangoPoblacion;
	string G_cantonInicio;
	string G_cantonDestino;
	Micelaneos micelaneos;
	GrafoCantonesGestor* gestor;

	//variables para los grafos
	string consultaProvincia;
	std::string cantonInicio;
	std::string cantonDestino;
	gestor = new GrafoCantonesGestor();

	do {
		cout << "==== Menu Arboles ====" << std::endl;
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
		cout << "==== Menu Grafos ====" << std::endl;
		cout << "11. Llenar grafos" << std::endl;
		cout << "12. Mostrar la ruta mas corta entre 2 cantones" << std::endl;
		cout << "13. Mostrar red de comunicacion de fibra optica dada una provincia" << std::endl;
		cout << "14. Mostrar cantones vecinos de un canton en especifico" << std::endl;
		cout << "15. Mostrar Guia de tour iniciando desde un canton en especifico" << std::endl;
		cout << "10. Salir" << std::endl;
		bool incorrect = true;
		do {
			try {
				cout << "Ingrese una opcion: ";
				std::getline(std::cin, opcionString);
				opcion = stoi(opcionString);
				incorrect = false;
			}
			catch (const std::exception e) {
				cout << "Debe de ser un numero! Nuevamente: " << endl;
			}
		} while (incorrect);

		switch (opcion) {
		case 0:
			leerDatos.setNombreArchivo("cantones.txt");
			leerDatos.leerArchivo(arbolCanton, arbolProvinciaCanton);
			cout << "Archivo leido correctamente." << endl;
			break;
		case 1:
			cout << "Digite el nombre del canton a modificar: ";
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
			std::getline(std::cin, buscarInfoCantonXprovincia);
			if (arbolProvinciaCanton.validarProvincia(buscarInfoCantonXprovincia))
				arbolProvinciaCanton.buscarInformacionProvincia(buscarInfoCantonXprovincia);
			else
				cout << "Digito no valido, seleccione del 1 al 7" << std::endl;

			break;
		case 3:
			cout << "Digite el nombre del canton a buscar: ";
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
			std::getline(std::cin, buscarInfoCantonXprovincia);
			if (arbolProvinciaCanton.validarProvincia(buscarInfoCantonXprovincia))
				arbolProvinciaCanton.infoXprovincia(buscarInfoCantonXprovincia);
			else
				cout << "Digito no valido, seleccione del 1 al 7" << std::endl;

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
			if (micelaneos.contieneLetras(rangoPoblacion))
			{
				cout << "Solo se permite el ingreso de numeros";
				break;
			}
			else {
				arbolCantonPoblacion.mostrarRango(stoi(rangoPoblacion));
				arbolCantonPoblacion = ArbolCantonPoblacion();//Se elimina el arbol viejo y se crea uno nuevo sin datos
			}

			break;
		case 11:
			//opcion llenar grafo
			cout << "Llenando grafos...." << std::endl;
			gestor->llenarGrafos();
			cout << "Grafos llenos" << std::endl;
			break;
		case 12:
			cout << "Ingrese el nombre de la provincia en la que se situan los cantones para los que desea averiguar la ruta mas corta" << std::endl;
			std::getline(std::cin, provinciaGrafo);
			cout << "Ingrese el nombre del canton desde el cual desea iniciar la ruta" << std::endl;
			std::getline(std::cin, G_cantonInicio);
			cout << "Ingrese el nombre del canton al que desea llegar" << std::endl;
			std::getline(std::cin, G_cantonDestino);

			gestor->rutaMasCorta(provinciaGrafo, G_cantonInicio, G_cantonDestino);

			break;
		case 13:
			cout << "Ingrese el nombre de la provincia para la cual desea visualizar la red de comunicacion mediante fibra optica" << std::endl;
			std::getline(std::cin, provinciaGrafo);
			gestor->fibraOptica(provinciaGrafo);
			break;
		case 14:
			break;
		case 15:
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