#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "escultor.h"
/**
 * @brief Classe FiguraGeometrica: Classe abstrata, ainda não foi definida completamente pelo sistema.
 * A sua principal função é que as figuras sejam feitos de forma rápida e compreensível pelas outras classes.
 */
class FiguraGeometrica
{
protected:
    /**
     * @brief r, g, b, a: Valores iniciais para definir a cor do objeto, seja ele vermelho, verde, azul e se
     * possui transparência.
     */
    float r, g, b, a;
public:

    virtual ~FiguraGeometrica(){};
    /**
     * @brief draw: função responsável por instruir o objeto a se desenhar em um objeto do tipo Escultor.
     * @param e: parâmetro responsável por referenciar o valor recebido pela função draw.
     */
    virtual void draw(Escultor &e)=0;
    FiguraGeometrica();

};

#endif // FIGURAGEOMETRICA_H
