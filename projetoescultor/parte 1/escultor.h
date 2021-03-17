#ifndef ESCULTOR_H
#define ESCULTOR_H

#include <iostream>
#include <fstream>

using namespace std;

struct Voxel{
    float r, g, b;  // cores
    float a;        // transparência
    bool isOn;      // inclusão

};

class Escultor{

protected:
    Voxel ***v; // Matriz 3d

    int nx,ny,nz; // Dimensões da matriz 3d
    float r,g,b,a; // Current drawing color
public:
    Escultor(int _nx, int _ny, int _nz);
    ~Escultor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(char* filename);
};

#endif // ESCULTOR_H
