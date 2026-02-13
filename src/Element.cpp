
#include "Element.h"

size_t Element::base_node_id = 0;
double Element::temperature = 25;
double Element::base_temperature = 25;

std::unordered_map< size_t,size_t> Element::matrix_index;



Element::~Element(){

}

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

void Element::setNodeID(int node_id_index, size_t node_id_)
{
    
}



void Element::stamp(Eigen::MatrixXd& G){
    
}
