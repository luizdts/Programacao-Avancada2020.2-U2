#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief The putBox class
 */
class putBox : public FiguraGeometrica{
    /**
     * @brief x0, y0, z0, x1, y1, z1: São responsáveis por receber os valores de entrada da função.
     */
    int x0, x1, y0, y1, z0, z1;
public:
    /**
     * @brief putBox: Ativa o Voxel em um determinado intervalo, seja ele em x, y ou z, os blocos criados recebem a cor estabelecida.
     * @param x0: parâmetro referente ao início da construção do retângulo em relação ao eixo x.
     * @param x1: parâmetro referente ao final da construção do retângulo em relação ao eixo x.
     * @param y0: parâmetro referente ao início da construção do retângulo em relação ao eixo y.
     * @param y1: parâmetro referente ao final da construção do retângulo em relação ao eixo y.
     * @param z0: parâmetro referente ao início da construção do retângulo em relação ao eixo z.
     * @param z1: parâmetro referente ao final da construção do retângulo em relação ao eixo z.
     * @param r: Cor vermelha.
     * @param g: Cor verde.
     * @param b: Cor azul.
     * @param a: Transparência.
     */
    putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~putBox(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);

};

#endif // PUTBOX_H
