#include "Resistor.h"

Resistor::~Resistor(){
    
}

Resistor::Resistor()
{   
    resistance = 1000;
    node_ids.fill(0);
    node_ids[0] = base_node_id;

    base_node_id++;
    node_ids[1] = base_node_id;
    base_node_id++;

}

void Resistor::stamp(Eigen::MatrixXd& G,Eigen::MatrixXd& I, size_t ground_node_id)
{
    resistance = base_resistance * (1+ 0.0039*(temperature - base_temperature));

    double g = 1.0 / resistance;

    bool i_is_ground = (node_ids[0] == ground_node_id);
    bool j_is_ground = (node_ids[1] == ground_node_id);

    // ikisi de ground → hiçbir şey yapma
    if (i_is_ground && j_is_ground)
        return;

    // sadece j ground
    if (j_is_ground) {
        size_t i = matrix_index[node_ids[0]];
        G(i,i) += g;
        return;
    }

    // sadece i ground
    if (i_is_ground) {
        size_t j = matrix_index[node_ids[1]];
        G(j,j) += g;
        return;
    }

    // normal resistor
    size_t i = matrix_index[node_ids[0]];
    size_t j = matrix_index[node_ids[1]];

    G(i,i) += g;
    G(j,j) += g;
    G(i,j) -= g;
    G(j,i) -= g;
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
    printf("Temperature:%lf\nResistance:%lf\nNode positive id:%zu\nNode negative id:%zu\n\n",
        temperature,resistance,getNodeID(0),getNodeID(1));
}

void Resistor::setNodeID(int node_id_index, size_t node_id_)
{
    node_ids[node_id_index] = node_id_;
}
