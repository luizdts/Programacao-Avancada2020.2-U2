#include "escultor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;
Escultor::Escultor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny; // construtor da classe Escultor
    nz = _nz;


    v = new Voxel**[nz]; // criação do Voxel na forma ponteiro para ponteiro

    v[0] = new Voxel*[nz*nx]; // alocação de linhas para o Voxel

    for(int k=1;k<nz; k++){
        v[k] = v[k-1] + nx; // adição de linhas aos planos
    }

    v[0][0] = new Voxel[nz*nx*ny]; // alocação dos Voxel na matriz 3D


    int n = 0;
    // adição de colunas entre as linhas e planos da matriz 3D
    for(int k=0;k<nz;k++){
        for(int i=0;i<nx;i++){
            v[k][i] = v[0][0] + n*ny;
            n++;
        }
    }

}

Escultor::~Escultor(){
    delete [] v[0][0]; // liberação a partir do comando delete para o Voxel
    delete [] v[0]; // liberação das linhas
    delete [] v; // liberação da figura desenhada

}

void Escultor::setColor(float verm, float verde, float azul, float alpha){
    // utilizado para definir a cor do desenho
    r = verm; // cor vermelha
    g = verde; // cor verde
    b = azul; // cor azul
    a = alpha; // transparência da peça
};

// ativa o Voxel na posição (x,y,z), atribuindo assim isOn = true

void Escultor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true; // ativação do isOn, fazendo o voxel aparecer
    v[x][y][z].r = r; // implementação das cores do sistema RGB e da transparência.
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;



};

void Escultor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false; // desativa o Voxel
};


void Escultor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // insere um Voxel com as coordenadas correspondentes aos eixos, gerando uma
    // caixa.
    for(int k=z0;k<=z1;k++){
        for(int j=y0;j<=y1;j++){
            for(int i=x0;i<=x1;i++){
                putVoxel(i,j,k); // habilita o Voxel, desenhando assim o retângulo nas coordenadas especificadas.

            }
        }
    }
}

void Escultor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // desabilita os Voxels em um determinado espaço atribuido pelas coordenadas do plano x, y, z.
    for (int k=z0;k<=z1;k++){
        for(int i=x0;i<=x1;i++){ // análise de planos, linhas e colunas da matriz.
            for(int j=y0;j<=y1;j++){
                cutVoxel(i,j,k); // desabilita o Voxel de acordo com as coordenadas passadas.
            }
        }

    }
}


void Escultor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    // método responsável por gerar a representação de uma esfera no plano x, y, z.
    // esse método insere a esfera de acordo com as coordenadas da esfera (x,y,z) e o raio da esfera (radius).
    float d;

    for(int k=0;k<=nz;k++){
        for(int j=0; j<=ny; j++){ // análise de planos, linhas e colunas da matriz.
            for(int i=0; i<=nx; i++){
                d = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
                if(d <= pow(radius, 2)){
                    putVoxel(i,j,k); // insere a esfera de acordo com as coordenadas formadas na saída.
                }
            }
        }
    }
}

void Escultor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    // método responsável por desabilitar a representação da esfera no plano x, y, z de acordo com as coordenadas definidas.
    // esse método apaga a esfera de acordo com as coordenadas da esfera (x,y,z) e o raio da esfera (radius).
    float d;

    for(int k=0;k<=nz;k++){
        for(int j=0;j<=ny;j++){  // análise de planos, linhas e colunas da matriz.
            for(int i=0;i<=nx;i++){
                d = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
                if(d <= pow(radius, 2)){
                    cutVoxel(i,j,k); // desabilita o Voxel em uma determinada área do plano x, y, z.
                }
            }
        }
    }
}

void Escultor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float d;

    if(rx ==0){
        for(int k=0;k<=nz;k++){  // análise de planos, linhas e colunas da matriz.
            for(int j=0;j<=ny;j++){
                d = pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter, 2)/pow(rz,2);

                if(d <= 1){
                    putVoxel(xcenter,j,k); // Habilita o Voxel em uma determinada área do plano x, y, z.

                }

            }

        }
    }
    else if(ry==0){
        for(int k=0; k<=nz; k++){  // análise de planos, linhas e colunas da matriz.
            for(int i=0;i<=nx;i++){
                d = pow(i - xcenter,2)/pow(rx,2) + pow(k - zcenter, 2)/pow(rz,2);
                if(d <= 1){
                    putVoxel(i,ycenter,k); // Habilita o Voxel em uma determinada área do plano x, y, z.

                }
            }
        }
    }
    else if(rz==0){
        for(int i=0;i<=nx;i++){  // análise de planos, linhas e colunas da matriz.
            for(int j=0;j<=ny;j++){
                d = pow(i - xcenter, 2)/pow(rx,2) + pow(j-ycenter, 2)/pow(ry,2);

                if(d <= 1){
                    putVoxel(i,j,zcenter); // Habilita o Voxel em uma determinada área do plano x, y, z.

                }
            }
        }
    }
    else{
        for(int k=0;k<=nz;k++){
            for(int j=0;j<=ny;j++){  // análise de planos, linhas e colunas da matriz.
                for(int i=0;i<=nx;i++){

                    d = pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry, 2) + pow(k-zcenter,2)/pow(rz,2);
                    if(d <=1){
                        putVoxel(i,j,k); // Habilita o Voxel em uma determinada área do plano x, y, z.
                    }
                }
            }
        }
    }
}

void Escultor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float d;

    if(rx ==0){
        for(int k=0;k<=nz;k++){  // análise de planos, linhas e colunas da matriz.
            for(int j=0;j<=ny;j++){
                d = pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter, 2)/pow(rz,2);

                if(d <= 1){
                    cutVoxel(xcenter,j,k); // desabilita o Voxel em uma determinada área do plano x, y, z.

                }

            }

        }
    }
    else if(ry==0){
        for(int k=0; k<=nz; k++){
            for(int i=0;i<=nx;i++){
                d = pow(i - xcenter,2)/pow(rx,2) + pow(k - zcenter, 2)/pow(rz,2);
                if(d <= 1){
                    cutVoxel(i,ycenter,k); // desabilita o Voxel em uma determinada área do plano x, y, z.

                }
            }
        }
    }
    else if(rz==0){
        for(int i=0;i<=nx;i++){
            for(int j=0;j<=ny;j++){
                d = pow(i - xcenter, 2)/pow(rx,2) + pow(j-ycenter, 2)/pow(ry,2);

                if(d <= 1){
                    cutVoxel(i,j,zcenter); // desabilita o Voxel em uma determinada área do plano x, y, z.

                }
            }
        }
    }
    else{
        for(int k=0;k<=nz;k++){
            for(int j=0;j<=ny;j++){
                for(int i=0;i<=nx;i++){

                    d = pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry, 2) + pow(k-zcenter,2)/pow(rz,2);
                    if(d <=1){
                        cutVoxel(i,j,k); // desabilita o Voxel em uma determinada área do plano x, y, z.
                    }
                }
            }
        }
    }
}


void Escultor::writeOFF(char* filename){
    ofstream fout;

    fixed(fout);

    int vertices = 0;
    int faces = 0;
    int aux = 0;

    fout.open(filename); // abertura do arquivo .OFF para escrita

    if(fout.is_open()){
        cout << "Gravando arquivo OFF..." << endl;
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
        cout<<"Arquivo OFF salvo, verifique o caminho de saida" << endl;  // finalização da gravação do arquivo .OFF
   }
}
