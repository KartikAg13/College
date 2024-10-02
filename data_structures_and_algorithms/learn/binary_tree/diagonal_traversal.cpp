// lecture 64

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildTree(Node *root) {
    int value = 0;
    cin >> value;
    if(value == -1)
        return nullptr;
    root = new Node(value);
    cout << "Please enter the data for left of " << root->data << ": ";
    root->left = buildTree(root->left);
    cout << "Pleas enter the data for right of " << root->data << ": ";
    root->right = buildTree(root->right);
    return root;
}

void traverseRight(Node *root, vector<pair<Node *, pair<int, int>>> &nodes, int horizontal_distance, int level, int index) {
    if(root == nullptr)
        return;
    nodes.push_back(make_pair(root, make_pair(horizontal_distance, level)));
    traverseRight(root->right, nodes, horizontal_distance + 1, level + 1, index + 1);
}

void diagonalTraversal(Node *root) {
    vector<pair<Node *, pair<int, int>>> nodes;  // int -> Horizontal Distance, int -> Level
    Node *next = root;
    Node *temp = root;
    int index = 0;
    int update = 0;
    nodes.push_back(make_pair(root, make_pair(0, 0)));
    while(true) {   //TBD
        next = nodes[update].first;
        if(next->right != nullptr) {
            if(nodes[index].first->left != nullptr && index != 0) {
                Node *first = nodes[index].first;
                pair<int, int> second = nodes[index].second;
                nodes.push_back(make_pair(first->left, make_pair(second.first - 1, second.second + 1)));
            }
            else {
                int horizontal_distance = nodes[update].second.first + 1;
                int level = nodes[update].second.second + 1;
                nodes.push_back(make_pair(next->right, make_pair(horizontal_distance, level)));
            }
        }
        else if(nodes[index].first->left != nullptr) {
            int horizontal_distance = nodes[index].second.first - 1;
            int level = nodes[index].second.second + 1;
            nodes.push_back(make_pair(next->left, make_pair(horizontal_distance, level)));    //TBD
            index++;
            update = index - 1;
        }
        cout << next->data << " ";
        update++;
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 2 4 8 -1 -1 -1 5 -1 9 -1 -1 3 6 -1 -1 7 -1 10 -1 -1
    Node *root = buildTree(root);

    // 1 3 7 10 2 5 6 9 4 8
    cout << endl << "Diagonal Traversal: " << endl;
    diagonalTraversal(root);

    cout << endl;
    return 0;
}
