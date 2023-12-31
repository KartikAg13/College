#include <iostream>

using namespace std;

class Node {
    public:
    int vertex;
    int weight;
    Node *next;
};

void create(Node *head[]) {
    char ch = 'y';
    int v1 = 0;
    int v2 = 0;
    int choice = 0;
    int no = 0;
    int weight = 0;
    Node *newNode;
    Node *temp;
    cout << "0 - Directed Graph" << endl;
    cout << "1 - Undirected Graph" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter the number of edges: ";
    cin >> no;
    for(int i = 0; i < no; i++) {
        cout << "Enter the starting node, ending node and weight: " << endl;
        cin >> v1 >> v2 >> weight;
        newNode = new Node();
        newNode->vertex = v2;
        newNode->weight = weight;
        temp = head[v1];
        if(temp == NULL)
            head[v1] = newNode;
        else {
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        if (choice == 1) {
            newNode = new Node();
            newNode->vertex = v1;
            newNode->weight = weight;
            temp = head[v2];
            if (temp == NULL)
                head[v2] = newNode;
            else {
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }
}

void display(Node *head[], int n) {
    int v = 0;
    Node *adj;
    cout << "Adjacency List is: " << endl;
    for(v = 0; v < n; v++) {
        cout << "Head[" << v << "]: ";
        adj = head[v];
        while(adj != NULL) {
            cout << adj->vertex << " => weight: " << adj->weight << " ";
            adj = adj->next;
        }
        cout << endl;
    }
}

int main() {
    char c = 'y';
    int ch = 0;
    int start = 0;
    int n = 0;
    int visited[10];
    int v = 0;
    Node *head[50];
    cout << "No. of vertices in the graph: " << endl;
    cin >> n;
    for(v = 0; v < n; v++)
        head[v] = NULL;
    create(head);
    display(head, n);
    return 0;
}