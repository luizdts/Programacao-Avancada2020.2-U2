#ifndef ESCULTOR_H
#define ESCULTOR_H

/**
 * @brief The Voxel struct
 * A estrutura Voxel é responsável por gerar a matriz 3D de acordo com seus parâmetros
 * @param r: refere-se à cor vermelha existente no sistema RGB, sua variação de tom é feita entre 0 e 255.
 * @param g: refere-se à cor verde existente no sistema RGB, sua variação de tom é feita entre 0 e 255.
 * @param b: refere-se à cor azul existente no sistema RGB, sua variação de tom é feita entre 0 e 255.
 * @param a: refere-se à transparência (opacidade) de uma figura, a variação de transparência é feita entre 0 e 1.
 * @param isOn: habilita ou desabilita o Voxel, é um parâmetro booleano, sendo utilizado apenas como True ou False.

 */

struct Voxel{

    float r, g, b;  // cores
    float a;        // transparência
    bool isOn;      // inclusão

};
/**
 * @brief The Escultor class
 *  Classe responsável por gerar o Escultor da figura 3D, dentro dessa
 *  classe encontram-se métodos que possibilitam o desenho da figura requerida pelo usuário
 *  sendo assim, ela se relaciona com a estrutura Voxel.
 */

class Escultor{

protected:
    /** Construtor da classe Escultor, declara-se com parâmetros privados
     */

    Voxel ***v; // Matriz 3d

    int nx,ny,nz; // Dimensões da matriz 3d
    float r,g,b,a; // Current drawing color

public:
    /** Métodos públicos da classe Escultor, é onde se localiza os códigos desenvolvidos
     *  para a criação da figura 3D. Os métodos são compostos pela construção de figuras geométricas
     *  conhecidas (retângulos, esferas e elipses) e podem ser manipuladas pelo programador para construir
     *  sua figura.
     */
    Escultor(int _nx, int _ny, int _nz);


    ~Escultor(); // Destrututor da classe Escultor
    /**
     * @brief setColor: Função responsável por dar cor no padrão RGB às peças criadas
     * @param r: parâmetro referente à cor vermelha do sistema RGB.
     * @param g: parâmetro referente à cor verde do sistema RGB.
     * @param b: parâmetro referente à cor azul do sistema RGB. O valor de variação do tom das cores é de 0 a 255.
     * @param alpha: parâmetro que se refere à transparência (opacidade) do objeto. O valor de variação da transparência é de 0 a 1.
     */
    void setColor(float r, float g, float b, float alpha);
    /**
     * @brief putVoxel: Habilita o Voxel para operar na coloração dos blocos desenhados.
     * @param x: coordenada em relação ao eixo x.
     * @param y: coordenada em relação ao eixo y.
     * @param z: coordenada em relação ao eixo z.
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief cutVoxel: Desabilita o Voxel que estava operando na coloração dos blocos.
     * @param x: coordenada em relação ao eixo x.
     * @param y: coordenada em relação ao eixo y.
     * @param z: coordenada em relação ao eixo z.
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief putBox: Ativa o Voxel em um determinado intervalo, seja ele em x, y ou z, os blocos criados recebem a cor estabelecida.
     * @param x0: parâmetro referente ao início da construção do retângulo em relação ao eixo x.
     * @param x1: parâmetro referente ao final da construção do retângulo em relação ao eixo x.
     * @param y0: parâmetro referente ao início da construção do retângulo em relação ao eixo y.
     * @param y1: parâmetro referente ao final da construção do retângulo em relação ao eixo y.
     * @param z0: parâmetro referente ao início da construção do retângulo em relação ao eixo z.
     * @param z1: parâmetro referente ao final da construção do retângulo em relação ao eixo z.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief cutBox: Desativa o Voxel em um determinado intervalo, seja ele em x, y, ou z, destruindo os blocos no intervalo determinado.
     * @param x0: parâmetro referente ao início da construção do retângulo em relação ao eixo x.
     * @param x1: parâmetro referente ao final da construção do retângulo em relação ao eixo x.
     * @param y0: parâmetro referente ao início da construção do retângulo em relação ao eixo y.
     * @param y1: parâmetro referente ao final da construção do retângulo em relação ao eixo y.
     * @param z0: parâmetro referente ao início da construção do retângulo em relação ao eixo z.
     * @param z1: parâmetro referente ao final da construção do retângulo em relação ao eixo z.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief putSphere: método responsável por gerar a figura de uma esfera no plano de desenho.
     * @param xcenter: parâmetro que se refere ao x do centro da esfera.
     * @param ycenter: parâmetro que se refere ao x do centro da esfera.
     * @param zcenter: parâmetro que se refere ao x do centro da esfera.
     * @param radius: parâmetro que se refere ao tamanho do raio da esfera.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief cutSphere método responsável por cortar uma determinada área de uma figura de uma esfera no plano do desenho.
     * @param xcenter: parâmetro referente à coordenada do x do centro.
     * @param ycenter: parâmetro referente à coordenada do y do centro.
     * @param zcenter: parâmetro referente à coordenada do z do centro.
     * @param radius: parâmetro referente ao tamanho do raio da esfera.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief putEllipsoid: método responsável por gerar a figura de uma elipse no plano do desenho.
     * @param xcenter: parâmetro referente à coordenada do x do centro.
     * @param ycenter: parâmetro referente à coordenada do y do centro.
     * @param zcenter: parâmetro referente à coordenada do z do centro.
     * @param rx: parâmetro referente à coordenada do eixo x.
     * @param ry: parâmetro referente à coordenada do eixo y.
     * @param rz: parâmetro referente à coordenada do eixo z.
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief cutEllipsoid: método responsável por cortar a área de uma figura de um elipse no plano do desenho.
     * @param xcenter: parâmetro referente à coordenada do x do centro.
     * @param ycenter: parâmetro referente à coordenada do y do centro.
     * @param zcenter: parâmetro referente à coordenada do z do centro.
     * @param rx: parâmetro referente à coordenada do eixo x.
     * @param ry: parâmetro referente à coordenada do eixo y.
     * @param rz: parâmetro referente à coordenada do eixo z.
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief writeOFF: método responsável pela gravação do arquivo OFF no final de sua execução.
     * @param filename: armazena o nome do arquivo .OFF.
     */
    void writeOFF(char* filename);

};

#endif // ESCULTOR_H
