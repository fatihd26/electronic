#include "Circuit.h"
#include "Element.h"
#include <iostream>

Circuit::Circuit()
{   
    temperature_ = 25;
    Element::base_temperature = temperature_;
}

void Circuit::setTemperature(double temperature)
{   

    temperature_ = temperature;
    Element::temperature = temperature_;
    

    for (Element * element : elements){
        element->stamp();
    }
}

double Circuit::getTemperature()
{   
    return temperature_;
}
