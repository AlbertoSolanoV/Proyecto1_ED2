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
/*
int string::compare (const string& str) const
Returns:
0 : if both strings are equal.
A value < 0 : if *this is shorter than str or,
first character that doesn't match is smaller than str.
A value > 0 : if *this is longer than str or,
first character that doesn't match is greater
*/
NodoCanton* ArbolCanton::insertar(NodoCanton* pNodoCanton, Canton pCanton)
{
	if (pNodoCanton == nullptr) {
		return new NodoCanton(pCanton);
	}

	int valor = pCanton.getNombre().compare(pNodoCanton->getCanton().getNombre());

	if (valor < 0) {
		pNodoCanton->setIzquierda(insertar(pNodoCanton->getIzquierda(), pCanton));
	}
	else if (valor > 0) {
		pNodoCanton->setDerecha(insertar(pNodoCanton->getDerecha(), pCanton));
	}
	else {
		// No se permiten claves duplicadas en árboles AVL
		return pNodoCanton;
	}

	pNodoCanton->setAltura(1 + std::max(obtenerAltura(pNodoCanton->getIzquierda()), obtenerAltura(pNodoCanton->getDerecha())));

	int factorBalance = obtenerFactorBalance(pNodoCanton);

	// Caso Izquierda - Izquierda
	if (factorBalance > 1 && pCanton.getNombre().compare(pNodoCanton->getIzquierda()->getCanton().getNombre()) < 0) {
		return rotarDerecha(pNodoCanton);
	}

	// Caso Derecha - Derecha
	if (factorBalance < -1 && pCanton.getNombre().compare(pNodoCanton->getDerecha()->getCanton().getNombre()) > 0 ) {
		return rotarIzquierda(pNodoCanton);
	}

	// Caso Izquierda - Derecha
	if (factorBalance > 1 && pCanton.getNombre().compare(pNodoCanton->getIzquierda()->getCanton().getNombre()) >0 ) {
		pNodoCanton->setIzquierda(rotarIzquierda(pNodoCanton->getIzquierda()));
		return rotarDerecha(pNodoCanton);
	}

	// Caso Derecha - Izquierda
	if (factorBalance < -1 && pCanton.getNombre().compare(pNodoCanton->getDerecha()->getCanton().getNombre()) <0 ) {
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
	/*cout << "--------------------------------------------------------------" << endl;
	cout << pNodoCanton->getCanton().getNombre() << " - " <<endl; 
	if (pNodoCanton->getIzquierda() != nullptr) {
		cout << "Izquierdo: ";
		cout << pNodoCanton->getIzquierda()->getCanton().getCabecera() << endl;
	}
	if (pNodoCanton->getDerecha() != nullptr) {
		cout << "Derecha: ";
		cout << pNodoCanton->getDerecha()->getCanton().getCabecera() << endl;
	}
	cout << "--------------------------------------------------------------" << endl;*/
	cout << pNodoCanton->getCanton().getNombre() << " - " << endl;
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

NodoCanton* ArbolCanton::buscarPorNombre(string pNombreCanton)
{
	NodoCanton* canton = buscar(pNombreCanton, raiz);
	if (canton != NULL) {
		displayData(canton);
		return canton;
	}else{
		cout << "No se ha encontrado el canton" << endl;
		return NULL;
	}
}

void ArbolCanton::imprimirNodos()
{
	imprimirNodos(raiz, 0);
}

void ArbolCanton::imprimirNodos(NodoCanton* nodo, int nivel)
{
	if (nodo == nullptr)
		return;

	imprimirNodos(nodo->getDerecha(), nivel + 1);

	for (int i = 0; i < nivel; i++)
		std::cout << "    ";

	std::cout << nodo->getCanton().getCabecera() << std::endl;
	imprimirNodos(nodo->getIzquierda(), nivel + 1);
}

NodoCanton* ArbolCanton::buscar(string pNombreCanton, NodoCanton* pNodoCanton)
{

	if (pNodoCanton == nullptr) {
		return pNodoCanton;
	}
	// cout << "Canton: " << pNodoCanton->getCanton().getNombre() << endl; debug line, delete later
	if (pNodoCanton->getCanton().getNombre() == pNombreCanton) {
		return pNodoCanton;
	}
		
	if (pNombreCanton < pNodoCanton->getCanton().getNombre())
		return buscar(pNombreCanton, pNodoCanton->getIzquierda());
	else
		return buscar(pNombreCanton, pNodoCanton->getDerecha());
}

void ArbolCanton::displayData(NodoCanton* _canton) {
	cout << "Informacion del canton:" << endl;
	cout << "Cabecera: " << _canton->getCanton().getCabecera() << endl;
	cout.flush();
	cout << "Cantidad de habitantes: " << _canton->getCanton().getCantidadPersona() << endl;
	cout.flush();
	cout << "Nombre del alcalde: " << _canton->getCanton().getNombreAlcalde() << endl;
}
