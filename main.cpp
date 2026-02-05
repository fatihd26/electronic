

#include <stdio.h>
#include "src/circuit/Circuit.h"

int main(){


    Circuit * c = new Circuit();

    c->createResistor(ResistorParameters(),Position());

    c->infoMap();

    delete c;
    
    

    

    return 0;
}