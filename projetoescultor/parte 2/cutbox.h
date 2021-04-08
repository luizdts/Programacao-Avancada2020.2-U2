#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief A classe CutBox é responsável por desativar o Voxel em um determinado intervalo em x, y ou z.
 */
class cutBox : public FiguraGeometrica {
    /**
     * @brief x0, y0, z0, x1, y1, z1: São responsáveis por receber os valores de entrada da função.
     */
    int x0, y0, z0, x1, y1, z1;
public:
    /**
     * @brief cutBox: Desativa o Voxel em um determinado intervalo, seja ele em x, y, ou z, destruindo os blocos no intervalo determinado.
     * @param x0: parâmetro referente ao início da construção do retângulo em relação ao eixo x.
     * @param x1: parâmetro referente ao final da construção do retângulo em relação ao eixo x.
     * @param y0: parâmetro referente ao início da construção do retângulo em relação ao eixo y.
     * @param y1: parâmetro referente ao final da construção do retângulo em relação ao eixo y.
     * @param z0: parâmetro referente ao início da construção do retângulo em relação ao eixo z.
     * @param z1: parâmetro referente ao final da construção do retângulo em relação ao eixo z.
     */
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~cutBox(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);

};

#endif // CUTBOX_H
