#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "escultor.h"
/**
 * @brief A classe CutSphere é responsável por desativar o Voxel em um determinado intervalo de x, y ou z.
 */
class cutSphere : public FiguraGeometrica{
    /**
     * @brief xcenter, ycenter, zcenter, radius: São responsáveis por receber os valores de entrada da função.
     */
    int xcenter, ycenter, zcenter, radius;
public:
    /**
     * @brief cutSphere método responsável por cortar uma determinada área de uma figura de uma esfera no plano do desenho.
     * @param xcenter: parâmetro referente à coordenada do x do centro.
     * @param ycenter: parâmetro referente à coordenada do y do centro.
     * @param zcenter: parâmetro referente à coordenada do z do centro.
     * @param radius: parâmetro referente ao tamanho do raio da esfera.
     */
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~cutSphere(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    void draw(Escultor &e);
};

#endif // CUTSPHERE_H
