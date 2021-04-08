#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief The putVoxel class é responsável ativar o Voxel, ela realiza o preenchimento do espaço
 * com base nos parâmetros de entrada fornecidos pelo usuário.
 */
class putVoxel : public FiguraGeometrica{
    /**
     * @brief x, y, z: São responsáveis por receber os valores de entrada da função.
     */

    int x, y, z;

public:
    /**
* @brief putVoxel: Habilita o Voxel para operar na coloração dos blocos desenhados.
     * @param x: coordenada em relação ao eixo x.
     * @param y: coordenada em relação ao eixo y.
     * @param z: coordenada em relação ao eixo z.
     * @param r: Cor vermelha.
     * @param g: Cor verde.
     * @param b: Cor azul.
     * @param a: Transparência.
     */
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~putVoxel(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);

};

#endif // PUTVOXEL_H
