#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    public:
    unordered_map<int, list<pair<int, int>>> adjList;   // node -> neighbour, weight

    void addEdge(int u, int v, int w, bool direction = false) {
        adjList[u].push_back(make_pair(v, w));
        if(direction == false)
            adjList[v].push_back(make_pair(u, w));
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout << i.first << "-> ";
            for(auto j: i.second) {
                cout << "{" << j.first << ", " << j.second << "}, ";
            }
            cout << endl;
        }
    }

    vector<int> breadthFirstSearch() {
        unordered_map<int, bool> visited;
        vector<int> result;
        int node = 0;   // source node
        queue<int> q;

        q.push(node);
        visited[node] = true;

        while(q.empty() == false) {
            int frontNode = q.front();
            q.pop();
            result.push_back(frontNode);
            for(auto index: adjList[frontNode]) {
                node = index.first;
                if(visited[node] == false) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }

        return result;
    }

    void depthFirstSearch(int node, unordered_map<int, bool> &visited, vector<int> &result) {
        result.push_back(node);
        visited[node] = true;
        for(auto index: adjList[node]) {
            if(visited[index.first] == false)
                depthFirstSearch(index.first, visited, result);
        }
    }

    bool isCycle() {
        int node = 0;   // source node
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(node);
        parent[node] = -1;
        visited[node] = true;
        while(q.empty() == false) {
            int frontNode = q.front();
            q.pop();
            for(auto index: adjList[frontNode]) {
                node = index.first;
                if(visited[node] == true && parent[frontNode] != node)
                    return true;
                else if(visited[node] == false) {
                    q.push(node);
                    visited[node] = true;
                    parent[node] = frontNode;
                }
            }
        }
        return false;
    }
};

void print(vector<int> &result) {
    for(int index = 0; index < result.size(); index++)
        cout << result[index] << ", ";
    cout << endl;
}

int main() {
    Graph graph;
    vector<int> bfs, dfs;
    unordered_map<int, bool> visited;

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(1, 4, 1);
    graph.addEdge(2, 5, 1);
    graph.addEdge(2, 6, 1);

    graph.printAdjList();

    bfs = graph.breadthFirstSearch();
    cout << "BFS: ";
    print(bfs); // 0, 1, 2, 3, 4, 5, 6,

    graph.depthFirstSearch(0, visited, dfs);
    cout << "DFS: ";
    print(dfs); // 0, 1, 3, 4, 2, 5, 6,

    if(graph.isCycle())
        cout << "Graph is cyclic" << endl;
    else
        cout << "Graph is not cyclic" << endl;

    return 0;
}