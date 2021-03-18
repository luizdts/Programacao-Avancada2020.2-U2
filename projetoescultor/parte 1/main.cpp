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
    v3->putBox(0,30,0,1,0,30);


    v3->writeOFF("arquivoteste.off");

  return 0; 

}
