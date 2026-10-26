
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<long long> dist(V, LLONG_MAX);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        bool updated = false;

        for (const Edge& e : edges) {
            if (dist[e.u] != LLONG_MAX &&
                dist[e.u] + e.weight < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.weight;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    bool negativeCycle = false;

    for (const Edge& e : edges) {
        if (dist[e.u] != LLONG_MAX &&
            dist[e.u] + e.weight < dist[e.v]) {

            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Graph contains a reachable negative-weight cycle.\n";
    } else {
        cout << "Shortest distances from source " << source << ":\n";

        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";

            if (dist[i] == LLONG_MAX)
                cout << "Unreachable";
            else
                cout << dist[i];

            cout << endl;
        }
    }

    return 0;
}
