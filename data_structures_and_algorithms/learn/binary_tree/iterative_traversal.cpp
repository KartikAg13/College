// lecture 62

#include <iostream>
#include <stack>
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

// LNR
void inOrderTraversal(Node *root) {
    stack<Node *> s;
    map<Node *, bool> m;
    Node *temp = root;
    if(temp != nullptr)
        s.push(temp);
    m[temp] = true;
    while(s.empty() == false) {
        temp = s.top();
        if(temp->left != nullptr && m[temp->left] == false) {
            s.push(temp->left);
            m[temp->left] = true;
        }
        else {
            if(temp->left == nullptr && temp->right == nullptr) {
                cout << temp->data << " ";
                s.pop();
                temp = s.top();
            }
            cout << temp->data << " ";
            s.pop();
            if(temp->right != nullptr) {
                s.push(temp->right);
                m[temp->right] = true;
            }
        }
    }
}

// NLR
void preOrderTraversal(Node *root) {
    stack<Node *> s;
    map<Node *, int> m;
    Node *temp = root;
    if(temp != nullptr)
        s.push(temp);
    m[temp] = 1;
    while(s.empty() == false) {
        temp = s.top();
        if(m[temp] != 2) {
            cout << temp->data << " ";
            m[temp] = 2;
        }
        if(temp->left != nullptr && m.find(temp->left) == m.end()) {
            s.push(temp->left);
            m[temp] = 1;
        }
        else {
            s.pop();
            temp = s.top();
            s.pop();
            if(temp->right != nullptr) {
                s.push(temp->right);
                m[temp] = 1;
            }
        }
    }
}

// LRN
void postOrderTraversal(Node *root) {
    stack<Node *> s;
    map<Node *, bool> m;
    Node *temp = root;
    if(temp != nullptr)
        s.push(temp);
    m[temp] = true;
    while(s.empty() == false) {
        temp = s.top();
        if(temp->left != nullptr && m[temp->left] == false) {
            s.push(temp->left);
            m[temp->left] = true;
        }
        else {
            cout << temp->data << " ";
            s.pop();
            temp = s.top();
            if(temp->right != nullptr && m[temp->right] == false) {
                s.push(temp->right);
                m[temp->right] = true;
            }
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

    cout << endl << "Pre Order Traversal: " << endl;
    preOrderTraversal(root);

    cout << endl << "Post Order Traversal: " << endl;
    postOrderTraversal(root);

    cout << endl;
    return 0;
}
