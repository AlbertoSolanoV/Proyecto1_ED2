#pragma once
#include "NodoProvinciaCanton.h"
#include "Micelaneos.h"
#include <string>
using namespace std;

class arbolProvinciaCanton
{


    private:
    NodoProvinciaCanton* raiz;
    NodoProvinciaCanton* nil;

    void leftRotate(NodoProvinciaCanton* x);
    void rightRotate(NodoProvinciaCanton* x);
    void insertFix(NodoProvinciaCanton* k);
    void insertHelper(NodoProvinciaCanton* z);
    void deleteNodeHelper(NodoProvinciaCanton* node, string canton);
    void inorderHelper(NodoProvinciaCanton* node);
    void transplant(NodoProvinciaCanton* u, NodoProvinciaCanton* v);
    void deleteFixup(NodoProvinciaCanton* x);
    void listartAyudante(NodoProvinciaCanton* root, string indent, bool last);
    void ayudanteMostrarInfoPorProvincia(NodoProvinciaCanton* root, bool last,string key);
    NodoProvinciaCanton* buscarAyudante(NodoProvinciaCanton* node, string key);
    void desplegarInOrden(NodoProvinciaCanton*);
    void desplegarInOrdenRevez(NodoProvinciaCanton*);
    void buscarInfoProvincia(NodoProvinciaCanton*, string pProvincia, int* pCantones, int* pPoblacion);
    void displayData(NodoCanton*);

    public:
    arbolProvinciaCanton();
    void insertar(string provincia, string canton, NodoCanton*);
    void infoXprovincia(string provincia);
    void buscarInformacionProvincia(string provincia);
    void listar();
    //busca por llave
    NodoProvinciaCanton* buscar(string llave);
    void desplegarCantonesInOrder();
    void desplegarCantonesInOrderRevez();
    bool validarProvincia(string pProvincia);

};

