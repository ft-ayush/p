#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(const vector<vector<int>>& graph, int m) {
    int V = graph.size();
    vector<int> color(V, 0);

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "\nNo solution exists for " << m << " colors.\n";
        return false;
    }

    cout << "\nSolution Exists: Vertex -> Color assignment:\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    return true;
}

int main() {
    int V, m;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of colors: ";
    cin >> m;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (" << V << " x " << V << "):\n";

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "\nGraph Coloring Problem for " << m << " colors:\n";
    graphColoring(graph, m);

    return 0;
}
