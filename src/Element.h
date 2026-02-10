#ifndef ELEMENT_H
#define ELEMENT_H

#include <array>

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

        static size_t base_node_id;
        virtual void stamp();
        virtual size_t getNodeID(int node_index);
        virtual int getComponentType();
};


#endif