#include "escultor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

//construtor
Sculptor::Sculptor(int _nx, int _ny, int _nz){
   nx = _nx;
   ny = _ny;
   nz = _nz;


   v = new Voxel**[nx];
   for(int i=0;i<nx;i++){
       v[i] = new Voxel*[ny];
       for(int j=0;j<ny;j++){
           v[i][j] = new Voxel[nz];
       }
   }


}
//destrutor
Escultor::~Escultor()
{
   delete[] v[0][0];
   delete[] v[0];
   delete[] v;
}
//metodo para setar cor
void Escultor::setColor(float r, float g, float b, float alpha)
{
         this -> r=r;

         this -> g=g;

         this -> b=b;

         a=alpha;
}
//ativando voxel
void Escultor::putVoxel(int x, int y, int z)
{
     v[x][y][z].isOn = true;
     v[x][y][z].r = r;
     v[x][y][z].g = g;
     v[x][y][z].b = b;
     v[x][y][z].a = a;

}
// desativando voxel
void Escultor::cutVoxel(int x, int y, int z){
     v[x][y][z].isOn = false;
}

void Escultor::writeOFF(char* filename){
    ofstream fout;

    fixed(fout);

    int vertices = 0;
    int faces = 0;
    int aux = 0;

    fout.open(filename);

    if(fout.is_open()){
        cout << "Gravando arquivo OFF" << endl;
    }
    else {
        cout << "Erro no arquivo OFF";
        exit(1);
    }
    fout << "OFF" << endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    vertices = vertices+8;
                    faces = faces+6;

                }
            }
        }

    }

   fout << vertices <<" "<< faces << " "<< 0 << endl;

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
               if(v[i][j][k].isOn){
                fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" " <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                aux=aux+8;
           }
       }
   }
}

   if(fout.is_open()){
        cout<<"Arquivo OFF salvo, verifique o caminho de saida" << endl;
   }
}
