#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

using namespace std;

int sigma_output(int a, int b);
int stepFunction(float soma);
float neuron();

std::vector<std::vector<int>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
std::vector<int> output = {0, 0, 0, 1};
std::vector<float> weight = {0.0, 0.0};
float learning_rate = 0.1;

int main() {

    neuron();

    cout << sigma_output(0, 0) << endl;
    cout << sigma_output(0, 1) << endl;
    cout << sigma_output(1, 0) << endl;
    cout << sigma_output(1, 1) << endl;
    return 0;
}
/*---------------- functions ----------------*/
float neuron()
{
    float calculated_output = 0.0;
    int total_erros = 1;

    while (total_erros != 0)
    {
        total_erros = 0;
        for (int i = 0; i < output.size(); ++i)
        {
            std::vector<int> vector_inputs_x1_x2;
            int input_x1 = 0;
            int input_x2 = 0;
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < 2; j++)
                {
                    vector_inputs_x1_x2.push_back(inputs[k][j]);
                    for (int m = 0; m < vector_inputs_x1_x2.size(); m++) {
                        input_x1 = vector_inputs_x1_x2[0];
                        input_x2 = vector_inputs_x1_x2[1];
                    }
                }
                vector_inputs_x1_x2.clear();
                calculated_output = sigma_output(input_x1, input_x2);
                int erro = abs(output[k] - calculated_output);
                total_erros += erro;
                for (int n = 0; n < weight.size(); ++n)
                {
                    weight[n] = weight[n] + (learning_rate * vector_inputs_x1_x2[n] * erro);
                    printf("Weight updated: %.2f\n", weight[n]);
                }
            }
            cout << "Total errors: " << total_erros << endl;
        }

    }
}

int sigma_output(int a, int b){
    std::vector<int> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    double result = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        result += std::inner_product(begin(vec1), end(vec1), weight.begin(), 0.0);
    }
    return stepFunction(result);
}

int stepFunction(float soma) {
    /*Step Function return 1 or 0
     * solve linear problems*/
    if (soma >= 1)
    {
        return 1;
    }
    return 0;
}
