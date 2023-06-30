#include "NodoCanton.h"

NodoCanton::NodoCanton(Canton pCanton)
{
	this->canton = pCanton;
	this->izquierdo = nullptr;
	this->derecho = nullptr;
	this->altura = 1;
}

void NodoCanton::setCanton(Canton pCanton)
{
	this->canton = pCanton;
}

void NodoCanton::setIzquierda(NodoCanton* pIzquierda)
{
	this->izquierdo = pIzquierda;
}

void NodoCanton::setDerecha(NodoCanton* pDerecha)
{
	this->derecho = pDerecha;
}

void NodoCanton::setAltura(int pAltura)
{
	this->altura = pAltura;
}

Canton NodoCanton::getCanton()
{
	return this->canton;
}

NodoCanton* NodoCanton::getIzquierda()
{
	return this->izquierdo;
}

NodoCanton* NodoCanton::getDerecha()
{
	return this->derecho;
}

int NodoCanton::getAltura()
{
	return this->altura;
}

void NodoCanton::Modificar(string pNombreAlcalde, int pPoblacion)
{
	this->canton.modificar(pNombreAlcalde, pPoblacion);
}



