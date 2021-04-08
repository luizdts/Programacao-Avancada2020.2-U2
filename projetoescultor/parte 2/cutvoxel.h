#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief A classe CutVoxel é responsável por desativar o Voxel em um determinado intervalo de x, y ou z.
 */
class cutVoxel : public FiguraGeometrica{
    /**
     * @brief x, y, z: São responsáveis por receber os valores de entrada da função.
     */
    int x, y, z;

public:
    /**
     * @brief cutVoxel: Desabilita o Voxel que estava operando na coloração dos blocos.
     * @param x: coordenada em relação ao eixo x.
     * @param y: coordenada em relação ao eixo y.
     * @param z: coordenada em relação ao eixo z.
     */
    cutVoxel(int x, int y, int z);
    ~cutVoxel(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);
};

#endif // CUTVOXEL_H
