#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "escultor.hpp"

class FiguraGeometrica{
protected:
    float r,g,b,a;

public:


   virtual ~FiguraGeometrica(){}; ///destrutor da classe
    //classe abstrata 
  virtual void draw(Sculptor  &e)=0; // metedo para desenhar formas geometricas na escultura
   
};


#endif // FIGURAGEOMETRICA_H
