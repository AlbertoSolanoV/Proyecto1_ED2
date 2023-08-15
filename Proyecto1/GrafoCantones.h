#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


struct Arista {
    std::string cantonDestino;
    int peso;
};

class GrafoCantones
{
private:
    unordered_map<string,vector<Arista>> listaAdyacencia;
    int nodos = 0;
public:


    GrafoCantones();

    // Agregar un cant�n (nodo) al grafo
    void agregarCanton(const std::string& canton);

    // Agregar una arista (con peso) entre dos cantones existentes en el grafo
    void agregarArista(const std::string& canton1, const std::string& canton2, int peso);

    // Mostrar el grafo
    void mostrarGrafo();

    // Encontrar la ruta m�s corta desde un cant�n de inicio a otro cant�n de destino dentro de la misma provincia
    std::vector<std::string> rutaMasCorta(const std::string& cantonInicio, const std::string& cantonDestino);

    unordered_map<string, vector<Arista>> recubridorMinimo_kruskal();

};
