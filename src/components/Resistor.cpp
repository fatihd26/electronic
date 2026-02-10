#include "Resistor.h"

void Resistor::stamp(){
    
}

void Resistor::setNodePositiveID(size_t id){
    node_positive_id = id;
}

void Resistor::setNodeNegativeID(size_t id){
    node_negative_id = id;
}

size_t Resistor::getNodePositiveID(){
    return node_positive_id;
}

size_t Resistor::getNodeNegativeID(){
    return node_negative_id;
}
