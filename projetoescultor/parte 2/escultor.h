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
    float r,g,b,a; // Cores do sistema RGB e a transparência

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
     * @brief writeOFF: método responsável pela gravação do arquivo OFF no final de sua execução.
     * @param filename: armazena o nome do arquivo .OFF.
     */
    void writeOFF(char* filename);
};

#endif // ESCULTOR_H
