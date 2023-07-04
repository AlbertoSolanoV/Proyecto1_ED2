#pragma once
#include "NodoProvinciaCanton.h"
#include <string>
using namespace std;

class arbolProvinciaCanton
{


private:
    NodoProvinciaCanton* raiz;
    NodoProvinciaCanton* nil;

    void leftRotate(NodoProvinciaCanton* x);
    void rightRotate(NodoProvinciaCanton* x);
    void insertFixup(NodoProvinciaCanton* z);
    void insertHelper(NodoProvinciaCanton* z);
    void deleteNodeHelper(NodoProvinciaCanton* node, string canton);
    void inorderHelper(NodoProvinciaCanton* node);
    void transplant(NodoProvinciaCanton* u, NodoProvinciaCanton* v);
    void deleteFixup(NodoProvinciaCanton* x);

public:

    arbolProvinciaCanton();
    void insertar(string provincia, string canton);
    void remove(string canton);
    void listar();
};

