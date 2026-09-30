// RIDWIK JAIN
// 25/DA/053
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalWeight = 0;

    cout << "\nKruskal's MST:\n";

    for (Edge e : edges) {
        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);

        if (u != v) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalWeight += e.weight;
            unionSet(parent, rank, u, v);
        }
    }

    cout << "Total MST Weight = " << totalWeight << endl;
}


void prim(vector<vector<pair<int, int>>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!inMST[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    cout << "\nPrim's MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;

        totalWeight += key[i];
    }

    cout << "Total MST Weight = " << totalWeight << endl;
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges;
    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    prim(graph, V);
    kruskal(V, edges);

    return 0;
}