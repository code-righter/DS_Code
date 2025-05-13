#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

class Graph {
    int V; // Number of vertices
    vector<vector<pii>> adj; // adjacency list: node -> [(weight, neighbor)]

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({weight, v});
        // For undirected graph, also add reverse edge:
        // adj[v].push_back({weight, u});
    }

    void dijkstra(int src, int dest) {
        vector<int> dist(V, numeric_limits<int>::max());
        vector<int> parent(V, -1);  // To store path
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (const pair<int, int>& neighbor : adj[u]) {
                int weight = neighbor.first;
                int v = neighbor.second;

                if (dist[v] > currDist + weight) {
                    dist[v] = currDist + weight;
                    parent[v] = u;  // Track path
                    pq.push({dist[v], v});
                }
            }
        }

        // Print distances
        cout << "\nShortest distances from vertex " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To vertex " << i << " -> ";
            if (dist[i] == numeric_limits<int>::max())
                cout << "INF\n";
            else
                cout << dist[i] << "\n";
        }

        // Print shortest path from src to dest
        cout << "\nShortest path from " << src << " to " << dest << ": ";
        if (dist[dest] == numeric_limits<int>::max()) {
            cout << "No path exists.\n";
            return;
        }

        vector<int> path;
        for (int v = dest; v != -1; v = parent[v])
            path.push_back(v);
            reverse(path.begin(), path.end());

        for (int v : path)
            cout << v << (v == dest ? "\n" : " -> ");
    }

};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges in the format: u v weight (0-based index)\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int start, end;
    cout << "Enter the starting vertex : ";
    cin >> start;
    cout<<"Enter the destination vertex :  ";
    cin>>end;


    g.dijkstra(start, end);

    return 0;
}
