#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief A classe CutEllipsoid é responsável por desativar o Voxel em um determinado intervalo de x, y ou z.
 */
class cutEllipsoid : public FiguraGeometrica{
    /**
    * @brief xcenter, ycenter, zcenter, rx, ry, rz: São responsáveis por receber os valores de entrada da função.
    */
    int xcenter, ycenter, zcenter, rx, ry, rz;

public:
    /**
     * @brief cutEllipsoid: método responsável por cortar a área de uma figura de um elipse no plano do desenho.
     * @param xcenter: parâmetro referente à coordenada do x do centro.
     * @param ycenter: parâmetro referente à coordenada do y do centro.
     * @param zcenter: parâmetro referente à coordenada do z do centro.
     * @param rx: parâmetro referente à coordenada do eixo x.
     * @param ry: parâmetro referente à coordenada do eixo y.
     * @param rz: parâmetro referente à coordenada do eixo z.
     */
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~cutEllipsoid(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);

};

#endif // CUTELLIPSOID_H
