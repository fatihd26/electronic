
#ifndef circuit_h
#define circuit_h
#include "Element.h"
#include <vector>
#include <Eigen/Dense>
#include <set>


class Circuit{
    private:
        size_t node_id1;
        size_t node_id2;
        std::vector<size_t> node_ids;
        double temperature_;
    public:
        Eigen::MatrixXd circuit_matrix;
        std::vector<Element*>  elements;

        Circuit();

        void setTemperature(double temperature);
        double getTemperature();
        void buildCircuit();
        void connectNodes(Element& element1, int element1_node_id_index, Element& element2, int element2_node_id_index);
        void setGround(Element& element, int node_id_index);


};



#endif