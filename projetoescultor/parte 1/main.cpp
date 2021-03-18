
#include "escultor.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(void){
   
    Escultor *v3;
    int a = 120, b= 120, c = 120;

    v3 = new Escultor(a,b,c);
    
    v3->setColor(0,255,0,1);
    v3->putBox(0,50,0,1,0,30); // piso
      
    v3->setColor(255,255,255,1);

    v3->putBox(15,15,0,15,15,15); // cabo da bandeira
    
    v3->setColor(255,0,0,1);
    v3->putBox(15,20,15,21,15,15); // bandeira

    v3->cutBox(18,20,15,15,15,16);
    v3->cutBox(19,20,16,16,15,16); // cortes inferiores
    v3->cutBox(20,20,17,17,15,16);
    v3->cutBox(20,20,19,20,15,16);

    v3->cutBox(19,20,20,21,15,16);
    v3->cutBox(20,20,20,21,15,16); // cortes superiores
    v3->cutBox(19,20,20,21,15,16);
    v3->cutBox(18,20,21,21,15,16);

    v3->setColor(255,255,255,1);
    v3->putSphere(29,1,9,1); 
   
    v3->setColor(0,0,0,0);
    v3->cutBox(16,16,1,1,15,15); // buraco

    v3->putBox(46,48,0,9,25,25);
    v3->putBox(46,48,0,9,29,29); // bolsa de golfe
    v3->putBox(45,45,0,9,25,29);
    v3->putBox(49,49,0,9,25,29);

    v3->cutBox(49,49,2,9,25,25);
    v3->cutBox(49,49,2,9,29,29);
    v3->cutBox(45,45,2,9,25,25); // molde da bolsa de golfe
    v3->cutBox(45,45,2,9,29,29);

    v3->putBox(46,46,0,12,26,26); // tacos da bolsa
    v3->putBox(48,48,0,12,27,27);

    v3->putSphere(45,12,26,1); //bolinha de teste
    v3->putSphere(49,12,27,1); //bolinha de teste
    v3->putBox(44,44,11,11,26,26);  // preenchimentos do taco
    v3->putBox(49,50,11,11,27,27);

    v3->cutBox(49,49,12,12,26,26);
    v3->cutBox(49,49,12,12,28,28);
    v3->cutBox(49,49,13,13,27,27);  // molde dos tacos

    v3->cutBox(45,45,12,12,25,25);
    v3->cutBox(45,45,12,12,27,27);
    v3->cutBox(45,45,13,13,26,26);  // molde dos tacos


    v3->writeOFF((char*)"arquivoteste.off");


}
