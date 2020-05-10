/*
 * Copyright 2020 Antonio Neto
 * */

#include <iostream>
#include "utils.h"

using std::cout;
using std::endl;

int main() {

    /*Train de network*/
    utils().neuron();

    /*here we can test passing the inputs*/
    utils().sigma_output(0, 0);
    utils().sigma_output(0, 1);
    utils().sigma_output(1, 0);
    utils().sigma_output(1, 1);
    
    return 0;
}