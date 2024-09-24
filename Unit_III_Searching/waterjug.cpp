#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

struct State {
    int jug1, jug2;
    State(int x, int y) : jug1(x), jug2(y) {}
    bool operator<(const State &other) const {
        return tie(jug1, jug2) < tie(other.jug1, other.jug2);
    }
};

void waterJugBFS(int capacity1, int capacity2, int goal) {
    queue<State> q;
    set<State> visited;

    q.push({0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int jug1 = current.jug1;
        int jug2 = current.jug2;

        cout << "Jug 1: " << jug1 << ", Jug 2: " << jug2 << endl;

        if (jug1 == goal || jug2 == goal) {
            cout << "Found solution!" << endl;
            return;
        }

        vector<State> nextStates = {
            {capacity1, jug2},  // Fill jug1
            {jug1, capacity2},  // Fill jug2
            {0, jug2},          // Empty jug1
            {jug1, 0},          // Empty jug2
            {min(jug1 + jug2, capacity1), max(0, jug1 + jug2 - capacity1)},  // Pour jug2 -> jug1
            {max(0, jug1 + jug2 - capacity2), min(jug1 + jug2, capacity2)}   // Pour jug1 -> jug2
        };

        for (State &next : nextStates) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    cout << "No solution found." << endl;
}

int main() {
    int jug1_capacity = 4, jug2_capacity = 3, goal = 2;

    waterJugBFS(jug1_capacity, jug2_capacity, goal);

    return 0;
}
