#include "ArbolCanton.h"
using namespace std;
int ArbolCanton::obtenerAltura(NodoCanton* pNodoCanton)
{
    if (pNodoCanton == nullptr) {
        return 0;
    }

    return pNodoCanton->getAltura();
}

int ArbolCanton::obtenerFactorBalance(NodoCanton* pNodoCanton)
{
    if (pNodoCanton == nullptr) {
        return 0;
    }
    return obtenerAltura(pNodoCanton->getIzquierda()) - obtenerAltura(pNodoCanton->getDerecha());
}

NodoCanton* ArbolCanton::rotarDerecha(NodoCanton* y)
{
    NodoCanton* x = y->getIzquierda();
    NodoCanton* T2 = x->getDerecha();

    x->setDerecha(y);
    y->setIzquierda(T2);

    y->setAltura(std::max(obtenerAltura(y->getIzquierda()), obtenerAltura(y->getDerecha())) + 1);
    x->setAltura(std::max(obtenerAltura(x->getIzquierda()), obtenerAltura(x->getDerecha())) + 1);

    return x;
}

NodoCanton* ArbolCanton::rotarIzquierda(NodoCanton* x)
{
    NodoCanton* y = x->getDerecha();
    NodoCanton* T2 = y->getIzquierda();

    y->setIzquierda(x);
    x->setDerecha(T2);

    x->setAltura(std::max(obtenerAltura(x->getIzquierda()), obtenerAltura(x->getDerecha())) + 1);
    y->setAltura(std::max(obtenerAltura(y->getIzquierda()), obtenerAltura(y->getDerecha())) + 1);

    return y;
}

NodoCanton* ArbolCanton::insertar(NodoCanton* pNodoCanton, Canton pCanton)
{
    if (pNodoCanton == nullptr) {
        return new NodoCanton(pCanton);
    }

    if (pCanton.getCabecera() < pNodoCanton->getCanton().getCabecera()) {
        pNodoCanton->setIzquierda(insertar(pNodoCanton->getIzquierda(), pCanton));
    }
    else if (pCanton.getCabecera() > pNodoCanton->getCanton().getCabecera()) {
        pNodoCanton->setDerecha(insertar(pNodoCanton->getDerecha(), pCanton));
    }
    else {
        // No se permiten claves duplicadas en árboles AVL
        return pNodoCanton;
    }

    pNodoCanton->setAltura(1 + std::max(obtenerAltura(pNodoCanton->getIzquierda()), obtenerAltura(pNodoCanton->getDerecha())));

    int factorBalance = obtenerFactorBalance(pNodoCanton);

    // Caso Izquierda - Izquierda
    if (factorBalance > 1 && pCanton.getCabecera() < pNodoCanton->getIzquierda()->getCanton().getCabecera()) {
        return rotarDerecha(pNodoCanton);
    }

    // Caso Derecha - Derecha
    if (factorBalance < -1 && pCanton.getCabecera() > pNodoCanton->getDerecha()->getCanton().getCabecera()) {
        return rotarIzquierda(pNodoCanton);
    }

    // Caso Izquierda - Derecha
    if (factorBalance > 1 && pCanton.getCabecera() > pNodoCanton->getIzquierda()->getCanton().getCabecera()) {
        pNodoCanton->setIzquierda(rotarIzquierda(pNodoCanton->getIzquierda()));
        return rotarDerecha(pNodoCanton);
    }

    // Caso Derecha - Izquierda
    if (factorBalance < -1 && pCanton.getCabecera() < pNodoCanton->getDerecha()->getCanton().getCabecera()) {
        pNodoCanton->setDerecha(rotarDerecha(pNodoCanton->getDerecha()));
        return rotarIzquierda(pNodoCanton);
    }

    return pNodoCanton;
}

void ArbolCanton::mostrar(NodoCanton* pNodoCanton)
{
    if (pNodoCanton == nullptr) {
        return;
    }

    mostrar(pNodoCanton->getIzquierda());
    cout << pNodoCanton->getCanton().getNombre() << " ";
    mostrar(pNodoCanton->getDerecha());
}

ArbolCanton::ArbolCanton()
{
        raiz = nullptr;
}

void ArbolCanton::insertar(Canton pCanton)
{
    raiz = insertar(raiz, pCanton);
}

void ArbolCanton::mostrar()
{
    mostrar(raiz);
}
