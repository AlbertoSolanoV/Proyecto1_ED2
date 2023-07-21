#include "ArbolCantonPoblacion.h"

int ArbolCantonPoblacion::obtenerAltura(NodoCanton* pNodoCanton)
{
	if (pNodoCanton == nullptr) {
		return 0;
	}

	return pNodoCanton->getAltura();
}

int ArbolCantonPoblacion::obtenerFactorBalance(NodoCanton* pNodoCanton)
{
	if (pNodoCanton == nullptr) {
		return 0;
	}
	return obtenerAltura(pNodoCanton->getIzquierda()) - obtenerAltura(pNodoCanton->getDerecha());
}

NodoCanton* ArbolCantonPoblacion::rotarDerecha(NodoCanton* y)
{
	NodoCanton* x = y->getIzquierda();
	NodoCanton* T2 = x->getDerecha();

	x->setDerecha(y);
	y->setIzquierda(T2);

	y->setAltura(std::max(obtenerAltura(y->getIzquierda()), obtenerAltura(y->getDerecha())) + 1);
	x->setAltura(std::max(obtenerAltura(x->getIzquierda()), obtenerAltura(x->getDerecha())) + 1);

	return x;
}

NodoCanton* ArbolCantonPoblacion::rotarIzquierda(NodoCanton* x)
{
	NodoCanton* y = x->getDerecha();
	NodoCanton* T2 = y->getIzquierda();

	y->setIzquierda(x);
	x->setDerecha(T2);

	x->setAltura(std::max(obtenerAltura(x->getIzquierda()), obtenerAltura(x->getDerecha())) + 1);
	y->setAltura(std::max(obtenerAltura(y->getIzquierda()), obtenerAltura(y->getDerecha())) + 1);

	return y;
}

NodoCanton* ArbolCantonPoblacion::insertar(NodoCanton* pNodoCanton, Canton* pCanton)
{
	if (pNodoCanton == nullptr) {
		return new NodoCanton(pCanton);
	}

	bool igual = true;
	while (igual) {
		if (pCanton->getCantidadPersona() < pNodoCanton->getCanton()->getCantidadPersona()) {
			pNodoCanton->setIzquierda(insertar(pNodoCanton->getIzquierda(), pCanton));
			igual = false;
		}
		else if (pCanton->getCantidadPersona() > pNodoCanton->getCanton()->getCantidadPersona()) {
			pNodoCanton->setDerecha(insertar(pNodoCanton->getDerecha(), pCanton));
			igual = false;
		}
		else {
			// Si son iguales de poblacion, se le suma 1
			pCanton->setCantidadPersona(pCanton->getCantidadPersona() + 1);
		}
	}


	pNodoCanton->setAltura(1 + std::max(obtenerAltura(pNodoCanton->getIzquierda()), obtenerAltura(pNodoCanton->getDerecha())));

	int factorBalance = obtenerFactorBalance(pNodoCanton);

	// Caso Izquierda - Izquierda 
	if (factorBalance > 1 && pCanton->getCantidadPersona() < pNodoCanton->getIzquierda()->getCanton()->getCantidadPersona()) {
		return rotarDerecha(pNodoCanton);
	}

	// Caso Derecha - Derecha
	if (factorBalance < -1 && pCanton->getCantidadPersona() > pNodoCanton->getDerecha()->getCanton()->getCantidadPersona()) {
		return rotarIzquierda(pNodoCanton);
	}

	// Caso Izquierda - Derecha
	if (factorBalance > 1 && pCanton->getCantidadPersona() > pNodoCanton->getIzquierda()->getCanton()->getCantidadPersona()) {
		pNodoCanton->setIzquierda(rotarIzquierda(pNodoCanton->getIzquierda()));
		return rotarDerecha(pNodoCanton);
	}

	// Caso Derecha - Izquierda
	if (factorBalance < -1 && pCanton->getCantidadPersona() < pNodoCanton->getDerecha()->getCanton()->getCantidadPersona()) {
		pNodoCanton->setDerecha(rotarDerecha(pNodoCanton->getDerecha()));
		return rotarIzquierda(pNodoCanton);
	}

	return pNodoCanton;
}

void ArbolCantonPoblacion::mostrarMayor(NodoCanton* pNodoCanton)
{
	if (pNodoCanton == nullptr) {
		return;
	}

	mostrarMayor(pNodoCanton->getIzquierda());
	displayData(pNodoCanton);
	mostrarMayor(pNodoCanton->getDerecha());

}

void ArbolCantonPoblacion::mostrarMenor(NodoCanton* pNodoCanton)
{
	if (pNodoCanton == nullptr) {
		return;
	}

	mostrarMenor(pNodoCanton->getDerecha());
	displayData(pNodoCanton);
	mostrarMenor(pNodoCanton->getIzquierda());

}



ArbolCantonPoblacion::ArbolCantonPoblacion()
{
	raiz = nullptr;
}

void ArbolCantonPoblacion::insertar(Canton* pCanton)
{
	raiz = insertar(raiz, pCanton);
}

void ArbolCantonPoblacion::mostrarMayor()
{
	mostrarMayor(raiz);
}

void ArbolCantonPoblacion::mostrarMenor()
{
	mostrarMenor(raiz);
}
void ArbolCantonPoblacion::mostrarRango(int pRango)
{
	mostrarRango(pRango, raiz);
}
void ArbolCantonPoblacion::mostrarRango(int pRango, NodoCanton* pNodoCanton)
{
	if (pNodoCanton == nullptr) {
		return;
	}

	mostrarRango(pRango, pNodoCanton->getDerecha());
	if (pNodoCanton->getCanton()->getCantidadPersona() >= pRango)
		displayData(pNodoCanton);

	mostrarRango(pRango, pNodoCanton->getIzquierda());

}


void ArbolCantonPoblacion::displayData(NodoCanton* pCanton)
{
	cout << "=================================" << endl;
	cout << "Informacion del canton:" << pCanton->getCanton()->getNombre() << endl;
	cout << "Cabecera: " << pCanton->getCanton()->getCabecera() << endl;
	cout.flush();
	cout << "Cantidad de habitantes: " << pCanton->getCanton()->getCantidadPersona() << endl;
	cout.flush();
	cout << "Nombre del alcalde: " << pCanton->getCanton()->getNombreAlcalde() << endl;
	cout << "=================================" << endl;
	cout << endl;
}
