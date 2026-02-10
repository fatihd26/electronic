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
        void stamp() override;
        size_t getNodeID(int node_index) override;
        int getComponentType() override;
        void setParameters(std::vector<double>params) override;
        void showParameters() override;
};

#endif
