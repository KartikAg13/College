//lecture 62

#include <iostream>
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

void reverseLevelOrderTraversal(Node *root) {
    vector<Node *> v;
    int index = 0;
    v.push_back(root);
    v.push_back(nullptr);
    while(true) {
        if(v[index] != nullptr) {
            if(v[index]->right != nullptr)
                v.push_back(v[index]->right);
            if(v[index]->left != nullptr)
                v.push_back(v[index]->left);
            if(v[index]->right == nullptr && v[index]->left == nullptr)
                break; 
        }
        else
            v.push_back(nullptr);
        index++;
    }
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i] == nullptr)
            cout << endl;
        else
            cout << v[i]->data << " ";
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);
    cout << endl << "Reverse Level Order Traversal:" << endl;
    reverseLevelOrderTraversal(root);
    return 0;
}