

#include <stdio.h>
#include <iostream>

#include "src/Circuit.h"
#include "src/Resistor.h"

int main(){

    Circuit c;
    Element * resistor1 = new Resistor();
    Element * resistor2 = new Resistor();

    resistor1->setParameters({1000});
    resistor2->setParameters({2000});

    c.elements.push_back(resistor1);
    c.elements.push_back(resistor2);

    c.setTemperature(30);
    resistor1->showParameters();

    c.setTemperature(40);
    resistor1->showParameters();
    
    c.setTemperature(30);


    resistor1->showParameters();
    c.setTemperature(25);
    c.setTemperature(25);
    resistor1->showParameters();

    

    
    
    

    


    return 0;
}