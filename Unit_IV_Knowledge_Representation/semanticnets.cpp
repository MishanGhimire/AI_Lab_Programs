#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Graph structure to represent semantic network
class Node {
public:
    string name;
    vector<Node*> relations;
    vector<string> relationTypes;

    Node(string n) : name(n) {}

    void addRelation(Node* other, string relationType) {
        relations.push_back(other);
        relationTypes.push_back(relationType);
    }

    void displayRelations() {
        for (size_t i = 0; i < relations.size(); i++) {
            cout << name << " " << relationTypes[i] << " " << relations[i]->name << endl;
        }
    }
};

int main() {
    Node alice("Alice");
    Node bob("Bob");
    Node charlie("Charlie");

    alice.addRelation(&bob, "is a friend of");
    bob.addRelation(&charlie, "is a parent of");
    alice.addRelation(&charlie, "is a friend of");

    cout << "Relations involving Alice:" << endl;
    alice.displayRelations();

    cout << "Relations involving Bob:" << endl;
    bob.displayRelations();

    return 0;
}
