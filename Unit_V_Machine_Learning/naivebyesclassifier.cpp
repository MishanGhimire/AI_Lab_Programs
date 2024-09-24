#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

class NaiveBayes {
private:
    map<string, int> count;
    map<string, double> priorProbabilities;
    map<string, map<string, int>> featureCount;
    int totalSamples = 0;

public:
    void train(const vector<pair<string, vector<string>>>& data) {
        for (const auto& sample : data) {
            const string& label = sample.first;
            priorProbabilities[label]++;
            totalSamples++;

            for (const auto& feature : sample.second) {
                featureCount[label][feature]++;
            }
        }

        for (auto& pair : priorProbabilities) {
            pair.second /= totalSamples; // Calculate prior probabilities
        }
    }

    string predict(const vector<string>& features) {
        double maxProb = -1;
        string bestLabel;

        for (const auto& label : priorProbabilities) {
            double prob = label.second; // Start with prior probability

            for (const auto& feature : features) {
                prob *= (featureCount[label.first][feature] + 1.0) / (count[label.first] + featureCount[label.first].size());
            }

            if (prob > maxProb) {
                maxProb = prob;
                bestLabel = label.first;
            }
        }

        return bestLabel;
    }

    void display() {
        cout << "Prior Probabilities:" << endl;
        for (const auto& pair : priorProbabilities) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    NaiveBayes nb;

    // Training data: {label, {features}}
    vector<pair<string, vector<string>>> trainingData = {
        {"Spam", {"free", "win", "money"}},
        {"Spam", {"free", "win"}},
        {"Not Spam", {"hello", "friend"}},
        {"Not Spam", {"meeting", "tomorrow"}}
    };

    nb.train(trainingData);
    nb.display();

    // Test data
    vector<string> testFeatures = {"free", "money"};
    string result = nb.predict(testFeatures);
    cout << "Predicted: " << result << endl;

    return 0;
}
