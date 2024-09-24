#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string name;
    string species;
    string color;

    Animal(string n, string s, string c) : name(n), species(s), color(c) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Color: " << color << endl;
    }
};

int main() {
    Animal cat("Whiskers", "Cat", "White");
    cat.displayInfo();

    Animal dog("Buddy", "Dog", "Brown");
    dog.displayInfo();

    return 0;
}
