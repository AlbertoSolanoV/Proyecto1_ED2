#pragma once
#include "Canton.h"

class NodoCanton
{
private:
    Canton canton;
    NodoCanton* izquierdo;
    NodoCanton* derecho;
    int altura;


public: 
    //GETS Y SETS
    void setCanton(Canton);
    void setIzquierda(NodoCanton*);
    void setDerecha(NodoCanton*);
    void setAltura(int);

    Canton getCanton();
    NodoCanton* getIzquierda();
    NodoCanton* getDerecha();
    int getAltura();

    void Modificar(string, int);
    NodoCanton(Canton pCanton);

};

