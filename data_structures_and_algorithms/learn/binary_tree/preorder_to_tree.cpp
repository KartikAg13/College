// lecture 66

#include <iostream>
#include <map>
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

void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    for(int index = 0; index < n; index++)
        nodeToIndex[in[index]] = index;
}

Node *preOrderToTree(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex) {
    if(index >= n || inOrderStart > inOrderEnd)
        return nullptr;
    int element = pre[index++];
    Node *root = new Node(element);
    int position = nodeToIndex[index];
    root->left = preOrderToTree(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
    root->right = preOrderToTree(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
    return root;
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);

    int in = {};
    int pre = {};
    int n = 0;  // n -> size of the array
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    // createMapping(in, nodeToIndex, n);
    return 0;
}
