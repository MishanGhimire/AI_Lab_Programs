#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, const vector<vector<int>> &graph, vector<bool> &visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            cout << "Visited " << node << endl;
            visited[node] = true;

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
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

    vector<bool> visited(5, false); // 5 nodes, initially not visited

    dfs(0, graph, visited);  // Start DFS from node 0

    return 0;
}
