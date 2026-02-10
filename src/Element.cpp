
#include "Element.h"

size_t Element::base_node_id = 0;
double Element::temperature = 25;
double Element::base_temperature = 25;
size_t Element::getNodeID(int node_index){
    return 0;
}

int Element::getComponentType()
{
    return 0;
}

void Element::setParameters(std::vector<double> params)
{
}

void Element::showParameters()
{
}

void Element::stamp(){
    
}
