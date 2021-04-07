#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "escultor.h"

class FiguraGeometrica{
protected:
    float r,g,b,a;

public:


    virtual ~FiguraGeometrica(){}; ///destrutor da classe
    //classe abstrata 
    virtual void draw(Escultor  &e)=0; // metedo para desenhar formas geometricas na escultura
    FiguraGeometrica();

   
};


#endif // FIGURAGEOMETRICA_H
