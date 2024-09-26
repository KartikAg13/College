//lecture 62

#include <iostream>
#include <stack>
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
    stack<Node *> s;
    s.push(root);
    s.push(nullptr);
    while(true) {
        Node *temp = s.top();
        if(temp == nullptr && s.empty() == false)
            s.push(nullptr);
        else {
            if(temp->left != nullptr)
                s.push(temp->left);
            if(temp->right != nullptr)
                s.push(temp->right);
        }
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);
    cout << endl << "Revrese Level Order Traversal:" << endl;
    return 0;
}