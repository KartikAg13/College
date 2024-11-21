#include <iostream>
#include <vector>

using namespace std;

class Graph {
    public:
    vector<vector<int>> adjMat;

    Graph(int size) {
        adjMat.resize(size);
    }

    void addEdge(int u, int v, int w, bool direction = false) {
        adjMat[u][v] = w;
        if(direction == false)
            adjMat[v][u] = w;
    }

    void printAdjMat() {
        int row_size = adjMat[0].size();
        for(int i = 0; i < row_size; i++) {
            for(int j = 0; j < row_size; j++)
                cout << adjMat[i][j] << " ";
            cout << endl;
        }
    }
};