//lecture 62

#include <iostream>
#include <queue>
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

void inOrderTraversal(Node *root) {
    if(root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root) {
    if(root == nullptr)
        return;
    cout << root->data << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if(root == nullptr)
        return;
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(Node * &root) {
    queue <Node *> q;
    int value = 0;
    cout << "Please enter the value for the root of the tree: ";
    cin >> value;
    root = new Node(value);
    q.push(root);
    while(1);
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);

    cout << endl << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    
    // 7 3 11 1 17 5
    cout << endl << "In Order Traversal:" << endl;
    inOrderTraversal(root);
    
    // 1 7 3 11 17 5
    cout << endl << endl << "Pre Order Traversal: " << endl;
    preOrderTraversal(root);
    
    // 7 3 11 17 5 1
    cout << endl << endl << "Post Order Traversal: " << endl;
    postOrderTraversal(root);

    cout << endl;
    return 0;
}