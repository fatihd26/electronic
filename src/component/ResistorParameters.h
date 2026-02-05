#ifndef RESISTOR_PARAMETERS_H
#define RESISTOR_PARAMETERS_H


struct ResistorParameters{
    double temp_coeff_;
    double resistance_;
    double tolerance_;
    double temperature_;

    ResistorParameters(): temp_coeff_(0.0039), resistance_(1000), tolerance_(0.05),temperature_(25){}
    ResistorParameters(double temp_coeff, double resistance,double tolerance,double temperature): temp_coeff_(temp_coeff), resistance_(resistance),tolerance_(tolerance),temperature_(temperature){}
};



#endif