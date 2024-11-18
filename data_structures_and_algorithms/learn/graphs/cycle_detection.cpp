// lecture 88

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

bool isCyclicBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(q.empty() == false) {
        int frontNode = q.front();
        q.pop();
        for(auto index: adjList[frontNode]) {
            if(visited[index] == true && parent[frontNode] != index)
                return true;
            else if(visited[index] == false) {
                q.push(index);
                visited[index] = true;
                parent[index] = frontNode;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) { //parent initial -1
    visited[node] = true;
    for(auto index: adjList[node]) {
        if(visited[index] == false) {
            bool cycle = isCyclicDFS(index, node, visited, adjList);
            if(cycle)
                return true;
        }
        else if(parent != index)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    for(int index = 0; index < m; index++) {
        int u = edges[index][0];
        int v = edges[index][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int index = 0; index < n; index++) {
        if(visited[index] == false) {
            if(isCyclicBFS(index, visited, adjList))    //isCyclicDFS(index, -1, visited, adjList)
                return "Yes";
        }
    }
    return "No";
}