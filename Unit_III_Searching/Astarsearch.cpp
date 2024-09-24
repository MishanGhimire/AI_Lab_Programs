#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int x, y;
    int g;  // Cost from start
    int h;  // Heuristic (Manhattan distance to goal)
    bool operator>(const Node &other) const {
        return (g + h) > (other.g + other.h);
    }
};

int heuristic(Node current, Node goal) {
    return abs(current.x - goal.x) + abs(current.y - goal.y);
}

void aStarSearch(Node start, Node goal, const vector<vector<int>> &grid) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(start);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        cout << "Visiting node at (" << current.x << ", " << current.y << ")" << endl;

        if (current.x == goal.x && current.y == goal.y) {
            cout << "Goal reached!" << endl;
            return;
        }

        vector<Node> neighbors = {
            {current.x - 1, current.y, current.g + 1, 0}, {current.x + 1, current.y, current.g + 1, 0},
            {current.x, current.y - 1, current.g + 1, 0}, {current.x, current.y + 1, current.g + 1, 0}
        };

        for (Node &neighbor : neighbors) {
            if (neighbor.x >= 0 && neighbor.y >= 0 && neighbor.x < grid.size() && neighbor.y < grid[0].size() && grid[neighbor.x][neighbor.y] == 0) {
                neighbor.h = heuristic(neighbor, goal);
                pq.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Node start = {0, 0, 0, 0};  // Starting point (x, y)
    Node goal = {4, 4, 0, 0};   // Goal point (x, y)

    start.h = heuristic(start, goal);

    aStarSearch(start, goal, grid);

    return 0;
}
