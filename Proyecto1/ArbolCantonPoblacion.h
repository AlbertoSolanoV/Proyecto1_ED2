#pragma once
#include "NodoCanton.h"
#include "Canton.h"
#include <iostream>
using namespace std;


class ArbolCantonPoblacion
{

private:
    NodoCanton* raiz;

    int obtenerAltura(NodoCanton* pNodoCanton);
    int obtenerFactorBalance(NodoCanton* nodo);
    NodoCanton* rotarDerecha(NodoCanton* y);
    NodoCanton* rotarIzquierda(NodoCanton* x);
    NodoCanton* insertar(NodoCanton* pNodoCanton, Canton pCanton);
    void mostrarMayor(NodoCanton* pNodoCanton);
    void mostrarMenor(NodoCanton* pNodoCanton);

public:
    ArbolCantonPoblacion();
    void insertar(Canton pCanton);
    void mostrarMayor();
    void mostrarMenor();
};

