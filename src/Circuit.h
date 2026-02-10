
#ifndef circuit_h
#define circuit_h
#include "Element.h"
#include <vector>

class Circuit{
    private:
        double temperature_;
    public:
        std::vector<Element*>  elements;

        Circuit();

        void setTemperature(double temperature);
        double getTemperature();


};



#endif