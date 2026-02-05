#include "Circuit.h"


void Circuit::createResistor(ResistorParameters resistor_parameters, Position position){
    size_t entity = entity_manager.createEntity();
    size_t node1 = node_manager.createNode();
    size_t node2 = node_manager.createNode();

    component_store.nodes[entity] = {node1,node2};
    component_store.position_components[entity] = position;
    component_store.resistor_parameters_components[entity] = resistor_parameters;
    


}


void Circuit::infoMap(){
    for (size_t i = 0; i < entity_manager.getID(); i++)
    {
        printf("%lf\n",component_store.resistor_parameters_components[i].resistance_);
    }
    
}