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

void inOrderTraversal(Node *root) {
    Node *current = root;
    Node *predecessor = nullptr;
    while(current != nullptr) {
        if(current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            predecessor = current->left;
            while(predecessor->right != nullptr && predecessor->right != current)
                predecessor = predecessor->right;
            if(predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            }
            else {
                predecessor->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);

    cout << endl << "Inorder Traversal: " << endl;
    inOrderTraversal(root);

    cout << endl;
    return 0;
}
