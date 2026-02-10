#ifndef RESISTOR_H
#define RESISTOR_H

#include "Element.h"

class Resistor : public Element{
    private:
        size_t node_positive_id;
        size_t node_negative_id;
    public:
        void stamp() override;

        void setNodePositiveID(size_t id);
        void setNodeNegativeID(size_t id);
      
        size_t getNodePositiveID();
        size_t getNodeNegativeID();
};

#endif