#pragma once
#include "NodoCanton.h"
#include "Canton.h"
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
    NodoCanton* insertar(NodoCanton* pNodoCanton, Canton pCanton);
    void mostrar(NodoCanton* pNodoCanton);

public:
    ArbolCanton();
    void insertar(Canton pCanton);
    void mostrar();
};
