#include "Circuit.h"
#include "Element.h"
#include <iostream>

Circuit::Circuit()
{   
    node_ids = {};
    temperature_ = 25;
    Element::base_temperature = temperature_;
}

void Circuit::setTemperature(double temperature)
{   

    temperature_ = temperature;
    Element::temperature = temperature_;
}

double Circuit::getTemperature()
{   
    return temperature_;
}


void Circuit::buildCircuit(){ 
    std::set<size_t> unique_nodes(node_ids.begin(), node_ids.end());

    size_t idx=0;


    size_t row_col = unique_nodes.size();
    
    circuit_matrix.resize(row_col,row_col);
    circuit_matrix.setZero(row_col,row_col);

    for (size_t i : unique_nodes){
        Element::matrix_index[i] = idx++;
    }

    for (Element* element : elements){
        
        element->showParameters();
        element->stamp(circuit_matrix);
    }
}

void Circuit::setGround(Element &element, int node_id_index)
{
    
}

void Circuit::connectNodes(Element &element1, int element1_node_id_index, Element &element2, int element2_node_id_index)
{

    node_id1 = element1.getNodeID(element1_node_id_index);
    node_id2 = element2.getNodeID(element2_node_id_index);

    

    if (node_id1 < node_id2){
        
        
        element2.setNodeID(element2_node_id_index,node_id1);
        node_ids.push_back(node_id1);

        
        

        
    }
    else{
        
        element1.setNodeID(element1_node_id_index,node_id2);
        node_ids.push_back(node_id2);
    
    }
    
    
}


