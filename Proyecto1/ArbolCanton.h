#pragma once
#include "NodoCanton.h"
#include "Canton.h"
#include "ArbolCantonPoblacion.h"
#include <iostream>
using namespace std;

class ArbolCanton
{
private:
    NodoCanton* raiz;

    int obtenerAltura(NodoCanton* pNodoCanton);
    int obtenerFactorBalance(NodoCanton* nodo);
    NodoCanton* rotarDerecha(NodoCanton* y);
    NodoCanton* rotarIzquierda(NodoCanton* x);
    NodoCanton* insertar(NodoCanton* pNodoCanton, Canton* pCanton);
    void mostrar(NodoCanton* pNodoCanton);
    NodoCanton* buscar(string, NodoCanton*);
    void imprimirNodos(NodoCanton* nodo, int nivel);
    void modifyCanton(string, NodoCanton*);
    void displayData(NodoCanton*);
    void llenarArbolPoblacion(ArbolCantonPoblacion& pArbolCantonPoblacion, NodoCanton* pNodoCanton);

public:
    ArbolCanton();
    void insertar(Canton* pCanton);
    void mostrar();
    void imprimirNodos();
    void modifyCanton(string);
    NodoCanton* buscarPorNombre(string, bool);
    void llenarArbolPoblacion(ArbolCantonPoblacion& pArbolCantonPoblacion);
};

