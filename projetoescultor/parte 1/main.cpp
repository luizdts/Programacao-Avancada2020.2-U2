#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "escultor.h"

using namespace std;

int main()
{
    Escultor *v3;
    int a = 120, b= 120, c = 120;

    v3 = new Escultor(a,b,c);

    v3->setColor(0,255,0,0.5);
    v3->putBox(25,25,25,30,30,30);
    v3->putBox(25,25,25,31,30,31);
    v3->putBox(25,25,25,32,30,32);
    v3->putBox(25,25,25,33,30,33);
    v3->putBox(25,25,25,34,30,34);
    v3->putBox(25,25,25,35,30,35);
    v3->putBox(25,25,25,36,30,36);


    v3->writeOFF("arquivoteste.off");

  return 0; 

}
