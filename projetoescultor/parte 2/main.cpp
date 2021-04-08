#include <iostream>
#include <vector>
#include <fstream>
#include "escultor.h"
#include "interpretador.h"
#include "figurageometrica.h"


using namespace std;

int main()
{
    Escultor *s;
    Interpretador parser;

    vector<FiguraGeometrica*>figura;
    
    figura = parser.parse("figura.txt");

    s = new Escultor(parser.getX(), parser.getY(), parser.getZ());

     for(size_t i=0;i<figura.size();i++){
       cout << "desenhando\n";
       figura[i]->draw(*s);
   }
    s->writeOFF((char*) "teste.off");
    for(size_t i=0;i<figura.size();i++){
       delete figura[i];
    }
    delete s;
    return 0;

}
