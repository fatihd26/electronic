#ifndef RESISTOR_H
#define RESISTOR_H
#include "Element.h"

class Resistor:public Element{
    private:
        double base_resistance;
        double resistance;
        std::array<size_t,2> node_ids;
        
        
    public:


        Resistor();
        ~Resistor() override;
        void stamp(Eigen::MatrixXd& G,Eigen::MatrixXd& I, size_t ground_node_id) override;
        size_t getNodeID(int node_index) override;
        int getComponentType() override;
        void setParameters(std::vector<double>params) override;
        void showParameters() override;
        void setNodeID(int node_id_index, size_t node_id_);
};

#endif
