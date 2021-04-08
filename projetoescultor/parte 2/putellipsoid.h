#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief The putEllipsoid class
 */
class putEllipsoid : public FiguraGeometrica{
    /**
     * @brief xcenter, ycenter, zcenter, rx, ry, rz: São responsáveis por receber os valores de entrada da função.
     */
    int xcenter, ycenter, zcenter, rx, ry, rz;

public:
    /**
     * @brief putEllipsoid: método responsável por gerar a figura de uma elipse no plano do desenho.
     * @param xcenter: parâmetro referente à coordenada do x do centro.
     * @param ycenter: parâmetro referente à coordenada do y do centro.
     * @param zcenter: parâmetro referente à coordenada do z do centro.
     * @param rx: parâmetro referente à coordenada do eixo x.
     * @param ry: parâmetro referente à coordenada do eixo y.
     * @param rz: parâmetro referente à coordenada do eixo z.
     * @param r: Cor vermelha.
     * @param g: Cor verde.
     * @param b: Cor azul.
     * @param a: Transparência.
     */
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~putEllipsoid(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);

};

#endif // PUTELLIPSOID_H
