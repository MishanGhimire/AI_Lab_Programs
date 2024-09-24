#include <iostream>
#include <string>

using namespace std;

// Predicate logic for sibling relationship
bool isSibling(string person1, string person2) {
    if ((person1 == "Alice" && person2 == "Bob") || (person1 == "Bob" && person2 == "Alice")) {
        return true;
    }
    return false;
}

int main() {
    string person1, person2;

    cout << "Enter first person's name: ";
    cin >> person1;
    cout << "Enter second person's name: ";
    cin >> person2;

    if (isSibling(person1, person2)) {
        cout << person1 << " and " << person2 << " are siblings." << endl;
    } else {
        cout << person1 << " and " << person2 << " are not siblings." << endl;
    }

    return 0;
}
