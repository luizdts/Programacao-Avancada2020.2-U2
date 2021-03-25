#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "escultor.h"

class cutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~cutSphere(){};
    void draw(Escultor &e);
};

#endif // CUTSPHERE_H
