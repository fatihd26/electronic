#include "VSource.h"

Vsource::Vsource()
{
    node_ids.fill(0);
    node_ids[0] = base_node_id;
    base_node_id++;
    node_ids[1] = base_node_id;
    base_node_id++;
}

Vsource::~Vsource()
{
}

void Vsource::stamp(Eigen::MatrixXd& G,Eigen::MatrixXd& I, size_t ground_node_id)
{
    size_t k = G.rows();
    G.conservativeResize(k+1,k+1);
    I.conservativeResize(k+1,1);
    G.row(k).setZero();
    G.col(k).setZero();
    I(k,0) = 0;
    bool i_is_ground = (node_ids[0] == ground_node_id);
    bool j_is_ground = (node_ids[1] == ground_node_id);

    size_t row_index = G.rows()-1;

    // ikisi de ground → hiçbir şey yapma
    if (i_is_ground && j_is_ground)
        return;

    if (!i_is_ground && !j_is_ground){
        size_t i = matrix_index[node_ids[0]];
        size_t j = matrix_index[node_ids[1]];
        G(i,row_index) +=1;
        G(j,row_index) -=1;
        G(row_index,i) +=1;
        G(row_index,j) -=1;
        return;
    }
 
    if (j_is_ground) {
        size_t i = matrix_index[node_ids[0]];
        G(row_index,i) += 1;
        G(i,row_index) += 1;
        I(row_index,0) +=max_voltage;
        return;
    }

    // sadece i ground
    if (i_is_ground) {
        size_t i = matrix_index[node_ids[1]];
        G(row_index,i) -= 1;
        G(i,row_index) -= 1;
        I(row_index,0) += max_voltage;
        return;
    }

    

}

size_t Vsource::getNodeID(int node_index)
{
    if (node_index > 1){
        return -1;
    }
    return node_ids[node_index];
}

int Vsource::getComponentType()
{
    return 0;
}

void Vsource::setParameters(std::vector<double> params)
{
    max_voltage = params[0];
}

void Vsource::showParameters()
{
    printf("Temperature:%lf\nVoltage:%lf\nNode positive id:%zu\nNode negative id:%zu\n\n",
        temperature,max_voltage,getNodeID(0),getNodeID(1));
}

void Vsource::setNodeID(int node_id_index, size_t node_id_)
{
    node_ids[node_id_index] = node_id_;
}
