#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <Eigen/Dense>
#include <iostream>

typedef enum {
    RESISTOR = 0,
    CAPACITOR = 1,
    INDUCTOR = 2,
    TRANSISTOR = 10,
    DIODE = 11,
    DCVSOURCE = 20,
    ACVSOURCE = 30,
    CUSTOMVSOURCE = 40
}ComponentTypes;

class Element{
    public:

        virtual ~Element();

        static double base_temperature;
        static double temperature;
        static size_t base_node_id;

        static std::unordered_map<size_t,size_t> matrix_index;
        

        virtual void stamp(Eigen::MatrixXd& G);

        virtual size_t getNodeID(int node_index);
        virtual int  getComponentType();
        virtual void setParameters(std::vector<double>params);
        virtual void showParameters();
        virtual void setNodeID(int node_id_index, size_t node_id_);
};


#endif