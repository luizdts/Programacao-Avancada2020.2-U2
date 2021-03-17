#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <escultor.h>

/* Classe FiguraGeometrica, ela é abstrata pois ainda não foi definida completamente pelo sistema
 * A sua principal função é que as figuras sejam feitos de forma rápida e compreensível pelas outras classes.
*/
class FiguraGeometrica
{
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(escultor &t)=0;

};

#endif // FIGURAGEOMETRICA_H
