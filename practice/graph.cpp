#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int start, int end, int weight, bool direction = true) {
        adjList[start].push_back(make_pair(end, weight));
        if(direction == false)
            adjList[end].push_back(make_pair(start, weight));
    }

    void print() {
        for(auto element: adjList) {
            cout << element.first << " -> ";
            for(auto neighbour: element.second) {
                cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
            }
            cout << endl;
        }
    }

    void breadthFirstSearch(vector<int> &result) {
        unordered_map<int, bool> visited;
        queue<int> q;
        int node = 0;
        q.push(node);
        visited[node] = true;
        while(q.empty() == false) {
            int frontNode = q.front();
            q.pop();
            result.push_back(frontNode);
            for(auto neighbour: adjList[frontNode]) {
                if(visited[neighbour.first] == false) {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
    }

    bool isCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
        visited[node] = true;
        dfsVisited[node] = true;
        for(auto neighbour: adjList[node]) {
            if(visited[neighbour.first] == false) {
                if(isCycle(neighbour.first, visited, dfsVisited))
                    return true;
            }
            else if(dfsVisited[neighbour.first] == true)
                return true;
        }
        dfsVisited[node] = false;
        return false;
    }

    void dijkstra() {
        int node = 0;

        unordered_map<int, int> distance;
        for (auto neighbour : adjList)
            distance[neighbour.first] = INT_MAX; // Initialize all distances to infinity
        
        distance[node] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node}); // Distance, Node

        while (pq.empty() == false) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (dist + edgeWeight < distance[nextNode]) {
                    distance[nextNode] = dist + edgeWeight;
                    pq.push({distance[nextNode], nextNode});
                }
            }
        }

        for (auto d : distance) {
            cout << "Distance from " << node << " to " << d.first << " is " << d.second << endl;
        }
    }

    void primMST() {
    unordered_map<int, int> parent;
    unordered_map<int, int> key;
    unordered_map<int, bool> mstSet;

    for (auto node : adjList) {
        key[node.first] = INT_MAX;
        mstSet[node.first] = false;
    }
    key.begin()->second = 0;
    parent.begin()->second = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, adjList.begin()->first}); // Weight, Node

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (auto neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    for (auto it = parent.begin(); it != parent.end(); ++it) {
        if (it->second != -1)
            cout << "Edge: " << it->second << " - " << it->first << endl;
    }
}


};
