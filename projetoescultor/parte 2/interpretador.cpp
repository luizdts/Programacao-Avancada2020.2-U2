#include "interpretador.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <putbox.h>
#include <putvoxel.h>
#include <putsphere.h>
#include <putellipsoid.h>
#include <cutvoxel.h>
#include <cutbox.h>
#include <cutsphere.h>
#include <cutellipsoid.h>

Interpretador::Interpretador()
{

}
std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename){
    std::ifstream fin;
    std::string s, token;
    std::stringstream ss;
    std::vector<FiguraGeometrica*> figura;

    fin.open(filename.c_str());
    if(!fin.is_open()){
        std::cout << "Erro de abertura!" << std::endl;
        exit(true);
    }
    while(fin.good()){
        std::getline(fin, s);
        ss.clear();
        ss.str(s);
        if(token.compare("tamanho")==0){
            ss >> dx >> dy >> dz;

        } else if (token.compare("putVoxel")==0){
            int x,y,z;
            ss >> x >> y >> z >> r >> g >> b >> a;
            figura.push_back(new putVoxel(x,y,z,r,g,b,a));
        } else if(token.compare("putBox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figura.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        } else if(token.compare("putSphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figura.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        } else if(token.compare("putEllipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figura.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));

        } else if(token.compare("cutVoxel")==0){
            int x, y, z;
            ss >> x >> y >> z;
            figura.push_back(new cutVoxel(x, y, z));
        } else if(token.compare("cutBox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figura.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        } else if(token.compare("cutSphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss >> xcenter >> ycenter >> zcenter >> radius;
            figura.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
        } else if(token.compare("cutEllipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figura.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
        }
    }
    return figura;
}

int Interpretador::getX(){
    return dx;

}

int Interpretador::getY(){
    return dy;
}

int Interpretador::getZ(){
    return dz;
}
