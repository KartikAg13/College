// lecture 87

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

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

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;
    for(auto index: adjList[node]) {
        if(visited[index] == false)
            dfs(index, visited, adjList, component);
    }
}

vector<vector<int>> depth(int V, int E, vector<vector<int>> edges) {
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> result;
    unordered_map<int, bool> visited;
    for(int index = 0; index < edges.size(); index++) {
        int u = edges[index][0];
        int v = edges[index][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int index = 0; index < V; index++) {
        if(visited[index] == false) {
            vector<int> component;
            dfs(index, visited, adjList, component);
            result.push_back(component);
        }
    }
}