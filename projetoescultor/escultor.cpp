#include "escultor.h"
#include <iostream>
#include <fstream>
#include <cmath>

escultor::escultor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz; // valores de entrada pro construtor
    v = new Voxel**[nx];
    for(int i=0;i<nx;i++){          // construção da matriz
        v[i] = new Voxel*[ny];
        for(int j=0;j<ny;j++){
            v[i][j] = new Voxel[nz];
        }
    }

};

void escultor::setColor(float verm, float verde, float azul, float alpha){
    // utilizado para definir a cor do desenho
    r = verm; g = verde; b = azul; a = alpha;
};

// ativa o Voxel na posição (x,y,z), atribuindo assim isOn = true
void escultor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true; // ativação do isOn, fazendo o voxel aparecer
};

void escultor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false; // desativa o Voxel
};


escultor::~escultor(){
    delete v[0][0];
    delete v[0];
    delete v;
}

void escultor::writeOFF(char *filename){
    ofstream fout;

    fixed(fout);

    int vertices = 0;
    int faces = 0;

    fout.open(filename);

    if(fout.is_open()){
        std::cout << "Gravando arquivo OFF";
    } else {
        std::cout << "Erro de abertura de arquivo OFF";
        exit(true);
    }
    fout << "OFF" << endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    vertices = 8;
                    faces = 6;

                }
            }
        }

    }

   fout << vertices << faces << " "<< 0 << endl;

   for(int i=0;i<nx;i++){
       for(int j=0;j<ny;j++){
           for(int k=0;k<nz;k++){
               if(v[i][j][k].isOn){
                   fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                   fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                   fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                   fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                   fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                   fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                   fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                   fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
               }
           }
       }
   }

   for(int i=0;i<nx;i++){
       for(int j=0;j<ny;j++){
           for(int k=0;k<nz;k++){
               fout << 4 << " " << 0 + 8*i << " " << 3 + 8*i << " " << 2 + 8*i << " " << 1 + 8*i << " " << v[i][j][k].r
                    << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
               fout << 4 << " " << 4 + 8*i << " " << 5 + 8*i << " " << 6 + 8*i << " " << 7 + 8*i << " " << v[i][j][k].r
                    << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
               fout << 4 << " " << 0 + 8*i << " " << 1 + 8*i << " " << 5 + 8*i << " " << 4 + 8*i << " " << v[i][j][k].r
                    << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
               fout << 4 << " " << 0 + 8*i << " " << 4 + 8*i << " " << 7 + 8*i << " " << 3 + 8*i << " " << v[i][j][k].r
                    << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
               fout << 4 << " " << 3 + 8*i << " " << 7 + 8*i << " " << 6 + 8*i << " " << 2 + 8*i << " " << v[i][j][k].r
                    << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
               fout << 4 << " " << 1 + 8*i << " " << 2 + 8*i << " " << 6 + 8*i << " " << 5 + 8*i << " " << v[i][j][k].r
                    << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
           }
       }
   }


   if(fout.is_open()){
       std::cout<<"Arquivo salvo";
   }
}
