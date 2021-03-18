#ifndef ESCULTOR_H
#define ESCULTOR_H

struct Voxel{
    /**
    * A estrutura Voxel é responsável por gerar a matriz 3D de acordo com seus parâmetros
    * @param r: refere-se à cor vermelha existente no sistema RGB, sua variação de tom é feita entre 0 e 255.
    * @param g: refere-se à cor verde existente no sistema RGB, sua variação de tom é feita entre 0 e 255.
    * @param b: refere-se à cor azul existente no sistema RGB, sua variação de tom é feita entre 0 e 255.
    * @param a: refere-se à transparência (opacidade) de uma figura, a variação de transparência é feita entre 0 e 1.
    * @param isOn: habilita ou desabilita o Voxel, é um parâmetro booleano, sendo utilizado apenas como True ou False.
    */
    float r, g, b;  // cores
    float a;        // transparência
    bool isOn;      // inclusão

};


class Escultor{
protected:
    Voxel ***v; // Matriz 3d

    int nx,ny,nz; // Dimensões da matriz 3d
    float r,g,b,a; // Correspondente às cores do sistema RGB e transparência da figura.

public:
    Escultor(int _nx, int _ny, int _nz);
    ~Escultor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(char* filename);
};

#endif // ESCULTOR_H
