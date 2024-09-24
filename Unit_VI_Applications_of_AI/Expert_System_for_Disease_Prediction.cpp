#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // Include this for std::find

using namespace std;

class DiseasePredictor {
public:
    void predictDisease(const vector<string>& symptoms) {
        if (hasFever(symptoms) && hasCough(symptoms)) {
            cout << "Possible Disease: COVID-19" << endl;
        } else if (hasFever(symptoms) && hasRash(symptoms)) {
            cout << "Possible Disease: Measles" << endl;
        } else if (hasCough(symptoms) && hasSoreThroat(symptoms)) {
            cout << "Possible Disease: Common Cold" << endl;
        } else {
            cout << "No specific disease identified. Consult a doctor for further diagnosis." << endl;
        }
    }

private:
    bool hasFever(const vector<string>& symptoms) {
        return find(symptoms.begin(), symptoms.end(), "fever") != symptoms.end();
    }

    bool hasCough(const vector<string>& symptoms) {
        return find(symptoms.begin(), symptoms.end(), "cough") != symptoms.end();
    }

    bool hasRash(const vector<string>& symptoms) {
        return find(symptoms.begin(), symptoms.end(), "rash") != symptoms.end();
    }

    bool hasSoreThroat(const vector<string>& symptoms) {
        return find(symptoms.begin(), symptoms.end(), "sore throat") != symptoms.end();
    }
};

int main() {
    DiseasePredictor predictor;
    vector<string> symptoms;

    string symptom;
    cout << "Enter symptoms (type 'done' when finished): " << endl;

    while (true) {
        cin >> symptom;
        if (symptom == "done") break;
        symptoms.push_back(symptom);
    }

    predictor.predictDisease(symptoms);

    return 0;
}
