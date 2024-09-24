#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, const vector<vector<int>> &graph, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << "Visited " << node << endl;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Example graph with 5 nodes
    vector<vector<int>> graph = {
        {1, 2},      // Node 0 is connected to nodes 1 and 2
        {0, 3},      // Node 1 is connected to nodes 0 and 3
        {0, 4},      // Node 2 is connected to nodes 0 and 4
        {1},         // Node 3 is connected to node 1
        {2}          // Node 4 is connected to node 2
    };

    vector<bool> visited(5, false);  // 5 nodes, initially not visited

    bfs(0, graph, visited);  // Start BFS from node 0

    return 0;
}
