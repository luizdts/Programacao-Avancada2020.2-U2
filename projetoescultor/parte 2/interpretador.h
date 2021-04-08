#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "figurageometrica.h"
#include "escultor.h"
#include <vector>
#include <string>
/**
 * @brief A classe Interpretador é responsável por fazer a leitura do arquivo "figura.txt" e gerar o arquivo .OFF.
 */
class Interpretador
{
    /**
     * @brief dx, dy, dz: Dimensões em x, y e z.
     * @brief r, g, b, a: Cores e transparência.
     */
    int dx, dy, dz;
    float r, g, b, a;

public:
    Interpretador();

    std::vector<FiguraGeometrica*> parse(std::string filename);
    /**
     * @brief getX: Captura a dimensão x da escultura.
     */
    int getX();
    /**
     * @brief getY: Captura a dimensão y da escultura.
     */
    int getY();
    /**
     * @brief getZ: Captura a dimensão z da escultura.
     */
    int getZ();


};

#endif // INTERPRETADOR_H
