#include "Resistor.h"

Resistor::Resistor()
{   
    node_ids.fill(0);
    node_ids[0] = base_node_id;
    base_node_id++;
    node_ids[1] = base_node_id;
    base_node_id++;
}

void Resistor::stamp()
{
}

size_t Resistor::getNodeID(int node_index)
{
    if (node_index > 1){
        return;
    }
    return node_ids[node_index];
}

int Resistor::getComponentType()
{
    return RESISTOR;
}
