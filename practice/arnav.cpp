#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> ipair; // {weight, vertex}

class Graph {
    int V;                     // Number of vertices
    vector<vector<int>> matrix; // Adjacency matrix

public:
    Graph(int V); // Constructor

    void addEdge(int u, int v, int w);  // Add an edge
    void printGraph();                 // Print the adjacency matrix
    void primMST();                    // Prim's algorithm for MST
    void dijkstra(int src);            // Dijkstra's algorithm for shortest paths
};

// Constructor to initialize an empty adjacency matrix
Graph::Graph(int V) {
    this->V = V;
    matrix.resize(V, vector<int>(V, INF)); // Initialize all weights to INF
    for (int i = 0; i < V; i++) {
        matrix[i][i] = 0; // Distance from a vertex to itself is 0
    }
}

// Add an edge between u and v with weight w
void Graph::addEdge(int u, int v, int w) {
    matrix[u][v] = w; // Undirected graph
    matrix[v][u] = w; // Comment this line for directed graphs
}

// Print the adjacency matrix
void Graph::printGraph() {
    cout << "Adjacency Matrix of the Graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                cout << "INF\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Prim's Algorithm for Minimum Spanning Tree (Using Priority Queue)
void Graph::primMST() {
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq; // Min-heap priority queue
    vector<int> key(V, INF);    // Minimum weights for each vertex
    vector<int> parent(V, -1);  // Store MST edges
    vector<bool> inMST(V, false); // Track vertices included in MST

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest weight
        pq.pop();

        inMST[u] = true; // Include this vertex in MST

        // Process all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (matrix[u][v] != INF && !inMST[v] && matrix[u][v] < key[v]) {
                key[v] = matrix[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "\nEdges in the Minimum Spanning Tree (Prim's Algorithm):\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\tWeight: " << matrix[i][parent[i]] << endl;
        totalWeight += matrix[i][parent[i]];
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

// Dijkstra's Algorithm for shortest paths from src (Using Priority Queue)
void Graph::dijkstra(int src) {
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq; // Min-heap priority queue
    vector<int> dist(V, INF);    // Initialize distances to INF
    vector<bool> visited(V, false); // Track visited vertices

    dist[src] = 0;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();

        if (visited[u]) continue; // Skip if already visited
        visited[u] = true;

        // Update distances for all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (matrix[u][v] != INF && !visited[v] && dist[v] > dist[u] + matrix[u][v]) {
                dist[v] = dist[u] + matrix[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest Distances from Vertex " << src << " (Dijkstra's Algorithm):\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Print the adjacency matrix
    g.printGraph();

    // Run Prim's Algorithm
    g.primMST();

    // Run Dijkstra's Algorithm from vertex 0
    g.dijkstra(0);

    return 0;
}