// lecture 89

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
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

bool isCyclic(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList) {
    visited[node] = true;
    dfsVisited[node] = true;
    for(auto index: adjList[node]) {
        if(visited[index] == false) {
            bool cycle = isCyclic(index, visited, dfsVisited, adjList);
            if(cycle)
                return true;
        }
        else if(dfsVisited[index])
            return true;
    }
    dfsVisited[node] = false;
    return false;
}

int cycleDetection(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited, dfsVisited;
    for(int index = 0; index < edges.size(); index++) {
        int u = edges[index].first;
        int v = edges[index].second;
        adjList[u].push_back(v);
    }
    for(int index = 0; index <= n; index++) {
        if(visited[index] == false) {
            if(isCyclic(index, visited, dfsVisited, adjList))
                return true;
        }
    }
    return false;
}