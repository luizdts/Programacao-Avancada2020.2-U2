#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "escultor.h"

class cutVoxel : public FiguraGeometrica{

    int x, y, z;

public:
    cutVoxel(int x, int y, int z);
    ~cutVoxel(){};
    void draw(Escultor &e);
};

#endif // CUTVOXEL_H
