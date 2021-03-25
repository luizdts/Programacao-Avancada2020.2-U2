#ifndef ESCULTOR_H
#define ESCULTOR_H

struct Voxel {
  float r,g,b; 
  float a;    
  bool isOn; 
};
class Escultor {
protected:
     
  Voxel ***v;      //matriz alocada dinamicamente 
     
    int nx,  ny, nz; // coordenadas no espaço
     
    float r, g, b, a; //cores e transparencia

public:
    
  Escultor(int _nx, int _ny, int _nz); //construtor da classe scultor
  ~Escultor();  //destrutor da classe scultor
    
  void setColor(float r, float g, float b, float alpha); // método para trabalhar a cor 
     
  void putVoxel(int x, int y, int z); // ativa os voxels
      
  void cutVoxel(int x, int y, int z); // desativa os voxels
      
  void writeOFF(char* filename); // grava a escultura no off
  
};

#endif // ESCULTOR_H

