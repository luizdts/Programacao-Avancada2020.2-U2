#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.hpp"

class FiguraGeometrica{
protected:
    float r,g,b,a;

public:


   virtual ~FiguraGeometrica(){}; ///destrutor da classe
    //classe abstrata 
  virtual void draw(Sculptor  &s)=0; // metedo para desenhar formas geometricas na escultura
   
};


#endif // FIGURAGEOMETRICA_H