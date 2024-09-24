#include <iostream>
#include <string>

using namespace std;

class LoanEligibilitySystem {
public:
    string checkEligibility(int age, double income) {
        if (age > 18 && income >= 50000) {
            return "Eligible for Loan";
        } else if (age <= 18) {
            return "Not Eligible: Underage";
        } else if (income < 50000) {
            return "Not Eligible: Insufficient Income";
        }
        return "Not Eligible";
    }
};

int main() {
    LoanEligibilitySystem loanSystem;
    int age;
    double income;

    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Income: ";
    cin >> income;

    string result = loanSystem.checkEligibility(age, income);
    cout << "Loan Eligibility: " << result << endl;

    return 0;
}
