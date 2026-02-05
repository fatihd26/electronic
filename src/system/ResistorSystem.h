#ifndef RESISTOR_SYSTEM_H
#define RESISTOR_SYSTEM_H   
#include "../../src/component/ResistorParameters.h"

class ResistorSystem{
    public:
        void computeEffectiveResistance(ResistorParameters& resp1, double temperature);
        
        

        
        
};


#endif