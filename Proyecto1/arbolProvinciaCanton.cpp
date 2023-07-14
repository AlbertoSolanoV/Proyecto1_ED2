#include "arbolProvinciaCanton.h"
#include <iostream>
#include <vector>
#include "archivoLeer.h"


arbolProvinciaCanton::arbolProvinciaCanton()
{
}

void arbolProvinciaCanton::listar()
{
    if (this->raiz) {
        listartAyudante(this->raiz, "", true);
    }
}

void arbolProvinciaCanton::listartAyudante(NodoProvinciaCanton* raiz, string indent, bool last) {
    if (raiz != this->nil) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        }
        else {
            cout << "L----";
            indent += "|  ";
        }

        int sColor = raiz->getColor() ? Rojo : Negro;
        cout << raiz->getLlave();
        cout << raiz->getLlave() << "(" << sColor << ")" << endl;
        listartAyudante(raiz->getIzquierda(), indent, false);
        listartAyudante(raiz->getDerecha(), indent, true);
    }
}
// listar info por provincia:
void arbolProvinciaCanton::infoXprovincia(string provincia)
{
    if (this->raiz) {
        ayudanteMostrarInfoPorProvincia(this->raiz, true, provincia);
    }
}
//ayudante para el metodo anterior:
void arbolProvinciaCanton::ayudanteMostrarInfoPorProvincia(NodoProvinciaCanton* root, bool last, string key) {
    if (root != this->nil) {

        string llave= root->getLlave();
        archivoLeer a =  archivoLeer();
        vector<string> provincia = a.split(llave, '-');
        

        
        if (provincia[0] == key) {
            cout << "Canton:" << std::endl;
            cout << "---------------------------------------------------------------" << std::endl;;
            cout << "Nombre de Canton: "+ root->getPrtCanton()->getCanton()->getNombre() << std::endl;
            cout << "Cabecera de canton: " + root->getPrtCanton()->getCanton()->getCabecera() << std::endl;
            cout << "Alcalde: " + root->getPrtCanton()->getCanton()->getNombreAlcalde() << std::endl;
            int poblacion = root->getPrtCanton()->getCanton()->getCantidadPersona();
            string stri = to_string(poblacion);
            cout << "Poblacion: " + stri << std::endl;
            cout << "---------------------------------------------------------------" << std::endl;;
        }
        ayudanteMostrarInfoPorProvincia(root->getIzquierda(), false, key);
        ayudanteMostrarInfoPorProvincia(root->getDerecha(), true, key);
    }

}

void arbolProvinciaCanton::rightRotate(NodoProvinciaCanton* x) {
    NodoProvinciaCanton* y = x->getIzquierda();
    
    x->setIzquierda(y->getDerecha());
    if (y->getDerecha() != this->nil) {
        y->getDerecha()->setPadre(x);
    }
    y->setPadre(x->getPadre());

    if (x->getPadre() == nullptr) {
        this->raiz = y;
    }
    else if (x == x->getPadre()->getDerecha()) {
        x->getPadre()->setDerecha(y);
    }
    else {
        x->getPadre()->setIzquierda(y);
    }
    y->setDerecha(x);
    x->setPadre(y);
}

void arbolProvinciaCanton::leftRotate(NodoProvinciaCanton* x) {
    NodoProvinciaCanton* y = x->getDerecha();
    x->setDerecha(y->getIzquierda());

    if (y->getIzquierda() != this->nil) {
        y->getIzquierda()->setPadre(x);
    }
    y->setPadre(x->getPadre());
    if (x->getPadre() == nullptr) {
        this->raiz = y;
    }
    else if (x == x->getPadre()->getIzquierda()) {
        x->getPadre()->setIzquierda(y);
    }
    else {
        x->getPadre()->setDerecha(y);
    }
    y->setIzquierda(x);
    x->setPadre(y);

}


void arbolProvinciaCanton::insertFix(NodoProvinciaCanton* k) {
    NodoProvinciaCanton* u;
    while (k->getPadre()->getColor() == Rojo) {
        if (k->getPadre() == k->getPadre()->getPadre()->getDerecha()) {
            u = k->getPadre()->getPadre()->getIzquierda();
            if (u->getColor() == Rojo) {
                u->setColor(Negro);
                k->getPadre()->setColor(Negro);
                k->getPadre()->getPadre()->setColor(Rojo);
                k = k->getPadre()->getPadre();
            }
            else {
                if (k == k->getPadre()->getIzquierda()) {
                    k = k->getPadre();

                    rightRotate(k);
                }
                k->getPadre()->setColor(Negro);
                k->getPadre()->getPadre()->setColor(Rojo);
                leftRotate(k->getPadre()->getPadre());
            }
        }
        else {
            u = k->getPadre()->getPadre()->getDerecha();

            if (u->getColor() == Rojo) {
                u->setColor(Negro);
                k->getPadre()->setColor(Negro);
                k->getPadre()->getPadre()->setColor(Rojo);
                k = k->getPadre()->getPadre();
            }
            else {
                if (k == k->getPadre()->getDerecha()) {
                    k = k->getPadre();
                    leftRotate(k);
                }
                k->getPadre()->setColor(Negro);
                k->getPadre()->getPadre()->setColor(Rojo);
                rightRotate(k->getPadre()->getPadre());
            }
        }
        if (k == this->raiz) {
            break;
        }
    }
    this->raiz->setColor(Negro);

}

void arbolProvinciaCanton::insertar(std::string provincia, std::string canton, NodoCanton* pNodoCanton) {
    NodoProvinciaCanton* node = new NodoProvinciaCanton();

    node->setPadre( nullptr);
    node->setLlave(provincia + "-" + canton);
    node->setIzquierda(this->nil);
    node->setDerecha(this->nil);
    node->setColor(Negro);

    
    node->setProvinciaCode(stoi(provincia));
    node->setCanton(canton);
    node->setPtrCanton(pNodoCanton);

    NodoProvinciaCanton* y = nullptr;
    NodoProvinciaCanton* x = this->raiz;

    while (x != nil) {
        y = x;
        if (node->getLlave().compare( x->getLlave()) < 0 ) {
            x = x->getIzquierda();
        }
        else {
            x = x->getDerecha();
        }
    }

    node->setPadre(y);
    if (y == nullptr) {
        this->raiz = node;
    }
    else if (node->getLlave().compare(y->getLlave()) < 0) {

        y->setIzquierda(node);
    }
    else {
        y->setDerecha(node);
    }

    if (node->getPadre() == nullptr) {
        node->setColor(Negro);
        return;
    }

    if (node->getPadre()->getPadre() == nullptr) {
        return;
    }

    insertFix(node);
}

NodoProvinciaCanton* arbolProvinciaCanton::buscar(string llave) {
    return buscarAyudante(this->raiz, llave);
}

NodoProvinciaCanton* arbolProvinciaCanton::buscarAyudante(NodoProvinciaCanton* node, string llave) {
        if (node == this->nil ||  llave.compare(node->getLlave()) == 0 ) {
            return node;
        }

        if (llave.compare(node->getLlave()) != 0) {
            return buscarAyudante(node->getIzquierda(), llave);
        }
        return buscarAyudante(node->getDerecha(), llave);
}