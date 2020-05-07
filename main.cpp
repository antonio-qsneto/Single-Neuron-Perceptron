#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

using namespace std;

int output(int a, int b);
int stepFunction(float soma);
float treinar();

std::vector<std::vector<int>> entradas = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
std::vector<int> saidas = {0, 1, 1, 0};
std::vector<float> pesos = {0.0, 0.0};
float taxa_aprendizagem = 0.1;

int main() {

    treinar();

    cout << output(0, 0) << endl;
    cout << output(0, 1) << endl;
    cout << output(1, 0) << endl;
    cout << output(1, 1) << endl;
    return 0;
}
/*---------------- functions ----------------*/
float treinar()
{
    float saidacalculada = 0.0;
    std::vector<int> vec1;
    int erroTotal = 1;

    while (erroTotal != 0)
    {
        erroTotal = 0;
        for (int i = 0; i < saidas.size(); ++i)
        {
            std::vector<int> vec_temp;
            int first = 0;
            int sec = 0;
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < 2; j++)
                {
                    vec_temp.push_back(entradas[k][j]);
                    for (int m = 0; m < vec_temp.size(); m++) {
                        first = vec_temp[0];
                        sec = vec_temp[1];
                    }
                }
                vec_temp.clear();
                saidacalculada = output(first, sec);
                int erro = abs(saidas[k] - saidacalculada);
                erroTotal += erro;
                for (int n = 0; n < pesos.size(); ++n)
                {
                    pesos[n] = pesos[n] + (taxa_aprendizagem * vec_temp[n] * erro);
                    printf("peso atualizado: %.2f\n", pesos[n]);
                }
            }
            cout << "Total de erros: " << erroTotal << endl;
        }

    }
}

int output(int a, int b){
    std::vector<int> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    double result = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        result += std::inner_product(begin(vec1), end(vec1), pesos.begin(), 0.0);
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