#include "Canton.h"

void Canton::setCabecera(string pCabecera)
{
	this->cabecera = pCabecera;
}

void Canton::setNombre(string pNombreC)
{
	this->nombre = pNombreC;
}

void Canton::setCantidadPersona(int pCantidad)
{
	this->cantidadPersona = pCantidad;
}

void Canton::setNombreAlcalde(string pNombreAlcalde)
{
	this->nombreAlcalde = pNombreAlcalde;
}

string Canton::getCabecera()
{
	return this->cabecera;
}

string Canton::getNombre()
{
	return this->nombre;
}

int Canton::getCantidadPersona()
{
	return this->cantidadPersona;
}

string Canton::getNombreAlcalde()
{
	return this->nombreAlcalde;
}

void Canton::modificar(string pNombreAlcalde, int pCantidad)
{
	this->nombreAlcalde = pNombreAlcalde;
	this->cantidadPersona = pCantidad;
}
