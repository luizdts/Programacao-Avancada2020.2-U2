#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "escultor.h"

class cutEllipsoid : public FiguraGeometrica{

    int xcenter, ycenter, zcenter, rx, ry, rz;

public:

    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~cutEllipsoid(){};
    void draw(Escultor &e);

};

#endif // CUTELLIPSOID_H
