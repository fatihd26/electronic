#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "../../src/system/ResistorSystem.h"
#include "../../src/entity/Entity.h"
#include "../../src/entity/Node.h"
#include "../../src/component/ComponentStore.h"

class Circuit{

    private:
        ResistorSystem resistor_system;
        NodeManager node_manager;
        EntityManager entity_manager;
        ComponentStore component_store;

    public:
        void createResistor(ResistorParameters resistor_paramters, Position position);
        void infoMap();

        
        
};

#endif