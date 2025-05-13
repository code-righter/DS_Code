#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex number!" << endl;
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    void BFS(int start) {
        if (start < 0 || start >= V) {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;
 
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        if (start < 0 || start >= V) {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int vertices, choice;
    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\n==== Graph Menu ====\n";
        cout << "1. Add Edge\n";
        cout << "2. BFS Traversal\n";
        cout << "3. DFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v;
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.addEdge(u, v);
                break;
            }
            case 2: {
                int start;
                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                g.BFS(start);
                break;
            }
            case 3: {
                int start;
                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                g.DFS(start);
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}