#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief The putSphere class
 */
class putSphere : public FiguraGeometrica{
    /**
     * @brief xcenter, ycenter, zcenter, radius: São responsáveis por receber os valores de entrada da função.
     */
    int xcenter, ycenter, zcenter, radius;
public:
    /**
     * @brief putSphere: método responsável por gerar a figura de uma esfera no plano de desenho.
     * @param xcenter: parâmetro que se refere ao x do centro da esfera.
     * @param ycenter: parâmetro que se refere ao x do centro da esfera.
     * @param zcenter: parâmetro que se refere ao x do centro da esfera.
     * @param radius: parâmetro que se refere ao tamanho do raio da esfera.
     * @param r: Cor vermelha.
     * @param g: Cor verde.
     * @param b: Cor azul.
     * @param a: Transparência.
     */
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~putSphere(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);
};

#endif // PUTSPHERE_H
