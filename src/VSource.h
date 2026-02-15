#ifndef VSOURCE_H
#define VSOURCE_H

#include "Element.h"

class Vsource : public Element{
    private:
        double max_voltage;
        std::array<size_t,2> node_ids;
    public:
        Vsource();

        ~Vsource() override;
        void stamp(Eigen::MatrixXd& G,Eigen::MatrixXd& I, size_t ground_node_id) override;
        size_t getNodeID(int node_index) override;
        int getComponentType() override;
        void setParameters(std::vector<double>params) override;
        void showParameters() override;
        void setNodeID(int node_id_index, size_t node_id_);

    
    
};

#endif