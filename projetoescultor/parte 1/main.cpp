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
    
    v3->setColor(0,255,0,1);
    v3->putBox(0,30,0,1,0,30);
    v3->putBox(15,15,0,15,15,15);
    v3->putBox(15,20,15,21,15,15);

    v3->cutBox(18,20,15,15,15,16);
    v3->cutBox(19,20,16,16,15,16); // cortes inferiores
    v3->cutBox(20,20,17,17,15,16);
    v3->cutBox(20,20,19,20,15,16);

    v3->cutBox(19,20,20,21,15,16);
    v3->cutBox(19,19,20,21,15,16);
    v3->cutBox(20,20,20,21,15,16); // cortes superiores
    v3->cutBox(19,20,20,21,15,16);
    v3->cutBox(18,20,21,21,15,16);

    v3->writeOFF("arquivoteste.off");

  return 0; 

}