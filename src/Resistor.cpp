#include "Resistor.h"

Resistor::Resistor()
{   
    resistance = 1000;
    node_ids.fill(0);
    node_ids[0] = base_node_id;
    base_node_id++;
    node_ids[1] = base_node_id;
    base_node_id++;

}

void Resistor::stamp()
{
    resistance = base_resistance * (1+ 0.0039* (temperature - base_temperature));
}

size_t Resistor::getNodeID(int node_index)
{
    if (node_index > 1){
        return -1;
    }
    return node_ids[node_index];
}

int Resistor::getComponentType()
{
    return RESISTOR;
}

void Resistor::setParameters(std::vector<double> params)
{
    resistance = params[0];
    base_resistance = resistance;
    
}

void Resistor::showParameters()
{
    printf("Temperature:%lf\nResistance:%lf\nNode positive id:%zu\nNode negative id:%zu\n ",
        temperature,resistance,getNodeID(0),getNodeID(1));
}
