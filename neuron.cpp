/*
 * Copyright 2020 Antonio Neto
 * */

#include <iostream>
#include "utils.h"

using std::cout;
using std::endl;

int main() {

    utils rede;
    rede.neuron();

    rede.sigma_output(0, 0);
    rede.sigma_output(0, 1);
    rede.sigma_output(1, 0);
    rede.sigma_output(1, 1);
    
    return 0;
}