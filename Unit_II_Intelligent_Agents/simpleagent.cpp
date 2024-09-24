#include <iostream>
using namespace std;

// Class to define the environment
class Environment {
public:
    char location;
    char status;

    Environment(char loc, char stat) {
        location = loc;
        status = stat;
    }
};

// Class to define the Reflex Agent
class ReflexAgent {
public:
    void clean(Environment &env) {
        cout << "Cleaning location " << env.location << endl;
        env.status = 'C';  // 'C' for Clean
    }

    void move(Environment &env) {
        if (env.location == 'A') {
            env.location = 'B';
        } else {
            env.location = 'A';
        }
        cout << "Moved to location " << env.location << endl;
    }

    void act(Environment &env) {
        if (env.status == 'D') {  // 'D' for Dirty
            clean(env);
        } else {
            move(env);
        }
    }
};

int main() {
    // Initialize the environment
    Environment envA('A', 'D');  // Location A, Dirty
    Environment envB('B', 'D');  // Location B, Dirty

    // Create the agent
    ReflexAgent agent;

    // Simulate the agent's actions
    for (int i = 0; i < 4; i++) {
        if (envA.location == 'A') {
            agent.act(envA);
        } else {
            agent.act(envB);
        }

        cout << "Environment status - A: " << envA.status << ", B: " << envB.status << endl;
    }

    return 0;
}
