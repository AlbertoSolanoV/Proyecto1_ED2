#include <iostream>
#include "ArbolCanton.h"
#include "Canton.h"

int main()
{
    ArbolCanton arbol;
    int opcion;
    Canton canton1;
    Canton canton2;
    Canton canton3;

    canton1.setCabecera("SJ");
    canton1.setNombre("San Jose");
    canton1.setCantidadPersona(18000);
    canton1.setNombreAlcalde("Jonhy");

    canton2.setCabecera("CSC");
    canton2.setNombre("Cartago");
    canton2.setCantidadPersona(18000);
    canton2.setNombreAlcalde("Jonhy");

    canton3.setCabecera("H");
    canton3.setNombre("Heredia");
    canton3.setCantidadPersona(18000);
    canton3.setNombreAlcalde("Jonhy");

    do {
        std::cout << "==== Menú del Árbol AVL ====" << std::endl;
        std::cout << "1. Insertar valor" << std::endl;
        std::cout << "2. Realizar recorrido inorden" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
           /* std::cout << "Ingrese el valor a insertar: ";
            std::cin >> valor;*/
            arbol.insertar(canton1);
            arbol.insertar(canton2);
            arbol.insertar(canton3);
            std::cout << "Valor insertado correctamente." << std::endl;
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
