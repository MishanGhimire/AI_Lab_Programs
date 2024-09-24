#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class NeuralNetwork {
private:
    vector<double> weights;
    double bias;
    double learningRate;

public:
    NeuralNetwork(double lr) : learningRate(lr) {
        // Initialize weights and bias
        weights.push_back(static_cast<double>(rand()) / RAND_MAX);
        weights.push_back(static_cast<double>(rand()) / RAND_MAX);
        bias = static_cast<double>(rand()) / RAND_MAX;
    }

    double sigmoid(double x) {
        return 1 / (1 + exp(-x));
    }

    double sigmoidDerivative(double x) {
        return x * (1 - x);
    }

    double predict(vector<double>& inputs) {
        double weightedSum = inputs[0] * weights[0] + inputs[1] * weights[1] + bias;
        return sigmoid(weightedSum);
    }

    void train(vector<vector<double>>& trainingData, vector<double>& labels, int epochs) {
        for (int epoch = 0; epoch < epochs; epoch++) {
            for (size_t i = 0; i < trainingData.size(); i++) {
                // Forward pass
                double output = predict(trainingData[i]);
                double error = labels[i] - output;

                // Backward pass
                for (size_t j = 0; j < weights.size(); j++) {
                    weights[j] += learningRate * error * sigmoidDerivative(output) * trainingData[i][j];
                }
                bias += learningRate * error * sigmoidDerivative(output);
            }
        }
    }
};

int main() {
    NeuralNetwork nn(0.1);

    // XOR training data
    vector<vector<double>> trainingData = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    vector<double> labels = {0, 1, 1, 0}; // Expected outputs for XOR

    nn.train(trainingData, labels, 10000); // Train for 10,000 epochs

    // Test the neural network
    cout << "Testing XOR Neural Network:" << endl;
    for (auto& input : trainingData) {
        double output = nn.predict(input);
        cout << input[0] << " XOR " << input[1] << " = " << round(output) << endl;
    }

    return 0;
}
