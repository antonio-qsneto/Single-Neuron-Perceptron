//
// Created by qwerty on 09/05/2020.
//

#ifndef SINGLE_NEURON_PERCEPTRON_UTILS_H
#define SINGLE_NEURON_PERCEPTRON_UTILS_H
#include <iostream>

class utils {
public:
    void neuron();
    int stepFunction(float soma);
    int sigma_output(int a, int b);
};

#endif //SINGLE_NEURON_PERCEPTRON_UTILS_H
