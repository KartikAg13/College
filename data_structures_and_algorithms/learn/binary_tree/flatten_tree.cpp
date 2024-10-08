// lecture 68

#include <iostream>
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

void flatten(Node *root) {
    Node *current = root;
    Node *predecessor = nullptr;
    while(current != nullptr) {
        if(current->left != nullptr) {
            predecessor = current->left;
            while(predecessor->right != nullptr)
                predecessor = predecessor->right;
            predecessor->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }
        current = current->right;
    }
}

int main() {
    return 0;
}
