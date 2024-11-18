// lecture 86

#include <iostream>
#include <unordered_map>
#include <set>
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

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges) {
    for(int index = 0; index < edges.size(); index++) {
        int u = edges[index].first;
        int v = edges[index].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> adjList, unordered_map<int, bool> visited, vector<int> &result, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(q.empty() == false) {
        int frontNode = q.front();
        q.pop();
        result.push_back(frontNode);
        for(auto index: adjList[frontNode]) {
            if(visited[index] == false) {
                q.push(index);
                visited[index] = true;
            }
        }
    }
}

vector<int> breadth(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> result;
    unordered_map<int, bool> visited;
    prepareAdjList(adjList, edges);
    for(int index = 0; index < vertex; index++) {
        if(visited[index] == false)
            bfs(adjList, visited, result, index);
    }
}

int main() {
    return 0;
}