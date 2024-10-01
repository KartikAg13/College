//lecture 62

#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while(q.empty() == false) {
        Node *temp = q.front();
        q.pop();
        if(temp == nullptr) {
            cout << endl;
            if(q.empty() == false)
                q.push(nullptr);
        }
        else {
            cout << temp->data << " ";
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(Node *root) {
    vector<Node *> v;
    int index = 0;
    Node *temp = root;
    if(temp != nullptr) {
        v.push_back(temp);
        v.push_back(nullptr);
    }
    else
        return;
    while(index < v.size()) {
        temp = v[index];
        if(temp != nullptr) {
            if(temp->right != nullptr)
                v.push_back(temp->right);
            if(temp->left != nullptr)
                v.push_back(temp->left);
        }
        else if(temp == nullptr && v[v.size() - 1] != nullptr)
            v.push_back(nullptr);
        index++;
    }
    int length = v.size() - 2;
    for(int index = length; index >= 0; index--) {
        if(v[index] == nullptr)
            cout << endl;
        else
            cout << v[index]->data << " ";
    }
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 2 4 8 -1 -1 -1 5 -1 9 -1 -1 3 6 -1 -1 7 -1 10 -1 -1
    Node *root = buildTree(root);

    // 1
    // 2 3
    // 4 5 6 7
    // 8 9 10
    cout << endl << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    // 8 9 10
    // 4 5 6 7
    // 2 3
    // 1
    cout << endl << "Reverse Level Order Traversal:" << endl;
    reverseLevelOrderTraversal(root);

    cout << endl;
    return 0;
}
