
#ifndef COMPONENT_STORE_H
#define COMPONENT_STORE_H

#include <unordered_map>
#include "ResistorParameters.h"
#include "Position.h"

struct ComponentStore{
    std::unordered_map<size_t, ResistorParameters> resistor_parameters_components;
    std::unordered_map<size_t, Position> position_components;
    std::unordered_map<size_t, std::vector<size_t>> nodes;
};



#endif