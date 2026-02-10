#ifndef RESISTOR_H
#define RESISTOR_H
#include "Element.h"

class Resistor:public Element{
    private:
        std::array<size_t,2> node_ids;
        

    public:
        Resistor();
        void stamp() override;
        size_t getNodeID(int node_index) override;
        int getComponentType() override;
};

#endif
