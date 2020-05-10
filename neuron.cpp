/*
 * Copyright 2020 Antonio Neto
 * */

#include <iostream>
#include "utils.h"

using std::cout;
using std::endl;

int main() {

    /*Train de network*/
    neuron().train();

    /*here we can test passing the inputs*/
    neuron().sigma_output(0, 0);
    neuron().sigma_output(0, 1);
    neuron().sigma_output(1, 0);
    neuron().sigma_output(1, 1);
    
    return 0;
}