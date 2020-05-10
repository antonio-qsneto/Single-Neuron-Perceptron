cmake_minimum_required(VERSION 3.16)
project(Single_Neuron_Perceptron)

set(CMAKE_CXX_STANDARD 14)

add_executable(Single_Neuron_Perceptron
        neuron.cpp utils.cpp utils.h)
