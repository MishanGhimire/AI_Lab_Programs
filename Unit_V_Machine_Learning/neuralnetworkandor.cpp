#include <iostream>
#include <vector>

using namespace std;

class SimpleNN {
private:
    double weight1, weight2, bias;

public:
    SimpleNN(double w1, double w2, double b) : weight1(w1), weight2(w2), bias(b) {}

    int activate(int input1, int input2) {
        double sum = input1 * weight1 + input2 * weight2 + bias;
        return (sum > 0) ? 1 : 0; // Step activation function
    }
};

int main() {
    // AND Gate
    SimpleNN andGate(1.0, 1.0, -1.5);
    cout << "AND Gate Results:" << endl;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            cout << i << " AND " << j << " = " << andGate.activate(i, j) << endl;
        }
    }

    // OR Gate
    SimpleNN orGate(1.0, 1.0, -0.5);
    cout << "\nOR Gate Results:" << endl;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            cout << i << " OR " << j << " = " << orGate.activate(i, j) << endl;
        }
    }

    return 0;
}
