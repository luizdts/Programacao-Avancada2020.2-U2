#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "figurageometrica.h"
#include "escultor.h"
#include <vector>
#include <string>

class Interpretador
{
    int x, y, z;
    float r, g, b, a;

public:
    Interpretador();
    std::vector<FiguraGeometrica*> parse(std::string filename);

    int getX();

    int getY();

    int getZ();


};

#endif // INTERPRETADOR_H
