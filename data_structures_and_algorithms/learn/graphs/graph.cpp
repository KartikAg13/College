// lecture 85

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if(direction == false)
            adj[v].push_back(u);
    }

    void printAdjList() {
        for(auto i: adj) {
            cout << i.first << " -> ";
            for(auto j: i.second)
                cout << j << ", ";
            cout << endl;
        }
    }
};

int main() {
    int n = 0, m = 0;
    cout << "Please enter the number of nodes: ";
    cin >> n;
    cout << "Please enter the number of edges: ";
    cin >> m;
    Graph g;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);
    }
    g.printAdjList();
    return 0;
}