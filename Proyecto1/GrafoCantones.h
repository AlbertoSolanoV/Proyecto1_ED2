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
struct AristaDetallada {
    std::string cantonOrigen;
    std::string cantonDestino;
    int peso;
};

class GrafoCantones
{
private:
    std::unordered_map<std::string, std::vector<Arista>> listaAdyacencia;
    std::string encontrarPadre(const std::string& canton, std::unordered_map<std::string, std::string>& padres);
    void unirPadres(const std::string& canton1, const std::string& canton2, std::unordered_map<std::string, std::string>& padres);

public:


    GrafoCantones();

    // Agregar un cantón (nodo) al grafo
    void agregarCanton(const std::string& canton);

    // Agregar una arista (con peso) entre dos cantones existentes en el grafo
    void agregarArista(const std::string& canton1, const std::string& canton2, int peso);

    // Mostrar el grafo
    void mostrarGrafo();

    // Encontrar la ruta más corta desde un cantón de inicio a otro cantón de destino dentro de la misma provincia
    std::vector<std::string> rutaMasCorta(const std::string& cantonInicio, const std::string& cantonDestino);

    //Para la fibra optica
    std::vector<AristaDetallada>kruskal();
};
