#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float r,g,b; 
  float a;    
  bool isOn; 
};
class Sculptor {
protected:
     
  Voxel ***v;      //matriz alocada dinamicamente 
     
    int nx,  ny, nz; // coordenadas no espaço
     
    float r, g, b, a; //cores e transparencia

public:
    
  Sculptor(int _nx, int _ny, int _nz); //construtor da classe scultor
  ~Sculptor();  //destrutor da classe scultor
    
  void setColor(float r, float g, float b, float alpha); // método para trabalhar a cor 
     
  void putVoxel(int x, int y, int z); // ativa os voxels
      
  void cutVoxel(int x, int y, int z); // desativa os voxels
      
  void writeOFF(char* filename); // grava a escultura no off
  
};

#endif // SCULPTOR_H

