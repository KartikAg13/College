// lecture 62

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

void inOrderTraversal(Node *root) {
    stack<Node *> s;
    Node *temp = root;
    if(temp != nullptr)
        s.push(temp);
    while(s.empty() == false) {
        temp = s.top();
        if(temp->left != nullptr)
            s.push(temp->left);
        else {
            if(temp->left == nullptr && temp->right == nullptr) {
                cout << temp->data << " ";
                s.pop();
                temp = s.top();
            }
            cout << temp->data << " ";
            s.pop();
            if(temp->right != nullptr)
                s.push(temp->right);
        }
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);

    // 7 3 11 1 17 5
    cout << endl << endl << "In Order Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
