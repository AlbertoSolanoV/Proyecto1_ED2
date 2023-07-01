#include "NodoProvinciaCanton.h"

NodoProvinciaCanton::NodoProvinciaCanton(int _provincia, string _canton, Color _color)
{
	this->canton = _canton;
	this->color = _color;
	this->provinciaCode = _provincia;
}

string NodoProvinciaCanton::getLlave()
{
	return this->llave;
}

int NodoProvinciaCanton::getColor()
{
	return this-> color;
}

NodoProvinciaCanton* NodoProvinciaCanton::getDerecha()
{
	return this->derecha;
}

NodoProvinciaCanton* NodoProvinciaCanton::getIzquierda()
{
	return this->izquierda;
}

NodoProvinciaCanton* NodoProvinciaCanton::getPadre()
{
	return this->padre;
}

int NodoProvinciaCanton::getProvinciaCode()
{
	return this->provinciaCode;
}

string NodoProvinciaCanton::getCanton()
{
	return this->canton;
}

NodoCanton* NodoProvinciaCanton::getPrtCanton()
{
	return this->PtrCanton;
}

void NodoProvinciaCanton::setLlave(string _llave)
{
	this->llave = _llave;
}

void NodoProvinciaCanton::setColor(Color _color)
{
	this->color = _color;
}

void NodoProvinciaCanton::setDerecha(NodoProvinciaCanton* _derecha)
{
	this->derecha = _derecha;
}

void NodoProvinciaCanton::setIzquierda(NodoProvinciaCanton* _izquierda)
{
	this->izquierda = _izquierda;
}

void NodoProvinciaCanton::setPadre(NodoProvinciaCanton* _padre)
{
	this->padre = _padre;
}

void NodoProvinciaCanton::setProvinciaCode(int _provinciaCode)
{
	this->provinciaCode = _provinciaCode;
}

void NodoProvinciaCanton::setCanton(string _canton)
{
	this->canton = _canton;
}

void NodoProvinciaCanton::setPtrCanton(NodoCanton* ptrCanton)
{
	this->PtrCanton = ptrCanton;
}

