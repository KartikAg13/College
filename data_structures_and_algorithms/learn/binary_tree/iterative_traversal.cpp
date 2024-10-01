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
    if(temp != nullptr) {
        s.push(temp);
        m[temp] = true;
    }
    else
        return;
    while(s.empty() == false) {
        temp = s.top();
        if(temp->left != nullptr && m.find(temp->left) == m.end()) {
            s.push(temp->left);
            m[temp->left] = true;
        }
        else {
            if(temp->left == nullptr && temp->right == nullptr) {
                cout << temp->data << " ";
                s.pop();
                if(s.empty() == true)
                    break;
                else
                    temp = s.top();
            }
            cout << temp->data << " ";
            s.pop();
            if(temp->right != nullptr && m.find(temp->right) == m.end()) {
                s.push(temp->right);
                m[temp->right] = true;
            }
        }
    }
}

// NLR
void preOrderTraversal(Node *root) {
    stack<Node *> s;
    map<Node *, bool> m;
    Node *temp = root;
    if(temp != nullptr) {
        s.push(temp);
        m[temp] = false;
    }
    else
        return;
    while(s.empty() == false) {
        temp = s.top();
        if(m[temp] == false) {
            cout << temp->data << " ";
            m[temp] = true;
        }
        if(temp->left != nullptr && m.find(temp->left) == m.end()) {
            s.push(temp->left);
            m[temp->left] = false;
        }
        else {
            if(temp->left == nullptr && temp->right == nullptr) {
                s.pop();
                if(s.empty() == true)
                    break;
                else
                    temp = s.top();
            }
            s.pop();
            if(temp->right != nullptr && m.find(temp->right) == m.end()) {
                s.push(temp->right);
                m[temp] = false;
            }
        }
    }
}

// LRN
void postOrderTraversal(Node *root) {
    stack<Node *> s;
    map<Node *, bool> m;
    Node *temp = root;
    if(temp != nullptr) {
        s.push(temp);
        m[temp] = true;
    }
    else
        return;
    while(s.empty() == false) {
        temp = s.top();
        if(temp->left != nullptr && m.find(temp->left) == m.end()) {
            s.push(temp->left);
            m[temp->left] = true;
        }
        else {
            if(temp->right != nullptr && m.find(temp->right) == m.end()) {
                s.push(temp->right);
                m[temp->right] = true;
                continue;
            }
            else {
                cout << temp->data << " ";
                s.pop();
            }
        }
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 2 4 8 -1 -1 -1 5 -1 9 -1 -1 3 6 -1 -1 7 -1 10 -1 -1
    Node *root = buildTree(root);

    // 8 4 2 5 9 1 6 3 7 10
    cout << endl << endl << "In Order Traversal: " << endl;
    inOrderTraversal(root);

    // 1 2 4 8 5 9 3 6 7 10
    cout << endl << "Pre Order Traversal: " << endl;
    preOrderTraversal(root);

    // 8 4 9 5 2 6 10 7 3 1
    cout << endl << "Post Order Traversal: " << endl;
    postOrderTraversal(root);

    cout << endl;
    return 0;
}
