#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "figurageometrica.h"
#include "escultor.h"
#include <vector>
#include <string>

class Interpretador
{
    int dx, dy, dz; // dimensão
    float r, g, b, a;

public:
    Interpretador();
    std::vector<FiguraGeometrica*> parse(std::string filename);

    int getX();

    int getY();

    int getZ();


};

#endif // INTERPRETADOR_H
