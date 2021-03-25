#include "cutvoxel.h"

cutVoxel::cutVoxel(int x, int y, int z){
    this->x=x;
    this->y=y;
    this->z=z;
}

void cutVoxel::draw(Escultor &e){
    e.cutVoxel(x,y,z);
}
