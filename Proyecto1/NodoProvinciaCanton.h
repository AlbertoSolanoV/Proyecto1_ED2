#pragma once
#include <string>
#include "NodoCanton.h"
using namespace std;
#pragma once
enum Color
{
	Rojo = 1,
	Negro = 0
};

class NodoProvinciaCanton 
{
private:
	string llave;
	Color color;
	NodoProvinciaCanton* derecha;
	NodoProvinciaCanton* izquierda;
	NodoProvinciaCanton* padre;
	int provinciaCode;
	string canton;
	NodoCanton* PtrCanton;
public:
	NodoProvinciaCanton(int, string, Color);
	NodoProvinciaCanton();
	~NodoProvinciaCanton();
	//getters
	string getLlave();
	int getColor();
	NodoProvinciaCanton* getDerecha();
	NodoProvinciaCanton* getIzquierda();
	NodoProvinciaCanton* getPadre();
	int getProvinciaCode();
	string getCanton();
	NodoCanton* getPrtCanton();

	//setters
	void setLlave(string); 
	void setColor(Color); 
	void setDerecha(NodoProvinciaCanton*);
	void setIzquierda(NodoProvinciaCanton*);
	void setPadre(NodoProvinciaCanton*);
	void setProvinciaCode(int);
	void setCanton(string);
	void setPtrCanton(NodoCanton*);

};