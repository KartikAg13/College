#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

bool dfs(vector<vector<int>> &residual, int node, int sink, unordered_map<int, int> &parent, unordered_map<int, bool> &visited) {
	visited[node] = true;
	if(node == sink)
		return true;
	for(int index = 0; index < residual.size(); index++) {
		if(visited[index] == false && residual[node][index] > 0) {
			parent[index] = node;
			if(dfs(residual, index, sink, parent, visited))
				return true;
		}
	}
	return false;
}

int fordFulkerson(vector<vector<int>> &graph, int source, int sink) {
	vector<vector<int>> residual = graph;
	unordered_map<int, int> parent;
	int maxFlow = 0;
	while(true) {
		unordered_map<int, bool> visited;
		if(dfs(residual, source, sink, parent, visited) == false)
			break;
		int pathFlow = INT_MAX;
		for(int v = sink; v != source; v = parent[v]) {
			int u = parent[v];
			pathFlow = min(pathFlow, residual[u][v]);
		}
		for(int v = sink; v != source; v = parent[v]) {
			int u = parent[v];
			residual[u][v] -= pathFlow;
			residual[v][u] += pathFlow;
		} 
		maxFlow += pathFlow;
	}
	return maxFlow;
}

int main() {
	vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
	cout << "The maximum possible flow is: " << fordFulkerson(graph, 0, 5) << endl;
	return 0;
}