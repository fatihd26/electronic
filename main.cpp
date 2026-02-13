

#include <iostream>
#include "src/Circuit.h"
#include "src/Resistor.h"

int main(){

    Circuit c = {};
    c.setTemperature(25);

    Element * element1 = new Resistor();
    element1->setParameters({1000});

    Element * element2 = new Resistor();
    element2->setParameters({2000});

    Element * element3 = new Resistor();
    element3->setParameters({3000});

    Element * element4 = new Resistor();
    element4->setParameters({4000});
    
    c.elements.push_back(element1);
    c.elements.push_back(element2);
    c.elements.push_back(element3);
    c.elements.push_back(element4);

    c.connectNodes(*element1,0,*element2,0);
    c.connectNodes(*element1,1,*element2,1);
    c.connectNodes(*element3,0,*element2,0);
    c.connectNodes(*element3,1,*element4,0);
    c.connectNodes(*element4,1,*element2,1);

    c.buildCircuit();

    std::cout << c.circuit_matrix << std::endl;


    return 0;
}