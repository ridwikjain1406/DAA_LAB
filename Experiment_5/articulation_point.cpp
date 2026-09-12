#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    vector<int> discovery;
    vector<int> low;
    vector<bool> visited;
    vector<bool> articulation;

    int timer;

    void DFS(int u, int parent) {
        visited[u] = true;

        discovery[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            if (!visited[v]) {
                children++;

                DFS(v, u);

                low[u] = min(low[u], low[v]);

                if (parent == -1 && children > 1)
                    articulation[u] = true;

                if (parent != -1 && low[v] >= discovery[u])
                    articulation[u] = true;
            }
            else {
                
                low[u] = min(low[u], discovery[v]);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);

        discovery.resize(V, -1);
        low.resize(V, -1);
        visited.resize(V, false);
        articulation.resize(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                DFS(i, -1);
        }

        cout << "Articulation Points: ";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (articulation[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges:\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}