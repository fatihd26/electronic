
#include "ResistorSystem.h"

void ResistorSystem::computeEffectiveResistance(ResistorParameters& resp1, double temperature){
    resp1.resistance_ = resp1.resistance_ * (1+resp1.temp_coeff_*(temperature-resp1.temperature_));

}