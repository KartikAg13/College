// lecture 70

#include <iostream>

class Node;
bool validateBST(Node *, int, int);
int kthsmallest(Node *, int &, int);
pair<int, int> predecessorOrSuccessor(Node *, int);
Node *lca(Node *, Node *, Node *);

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

Node *buildTree(Node *root, int data) {
    if(root == nullptr) {
        root = new Node(data);
        return root;
    }
    else if(data < root->data)
        root->left = buildTree(root->left, data);
    else
        root->right = buildTree(root->right, data);
    return root;
}

bool validateBST(Node *root, int minimum, int maximum) {
    if(root == nullptr)
        return true;
    else if(root->data >= minimum && root->data <= maximum) {
        bool left = validateBST(root, minimum, root->data);
        bool right = validateBST(root, root->data, maximum);
        return left && right;
    }
    else
        return false;
}

int kthSmallest(Node *root, int &index, int k) {
    if(root == nullptr)
        return -1;
    int left = kthSmallest(root->left, index, k);
    if(left != -1)
        return left;
    index++;
    if(index == k)
        return root->data;
    return kthSmallest(root->right, index, k);
}

pair<int, int> predecessorOrSuccessor(Node *root, int key) {
    Node *temp = root;
    int predecessor = -1;
    int successor = -1;
    while(temp->data != key) {
        if(temp->data > key) {
            successor = temp->data;
            temp = temp->left;
        }
        else {
            predecessor = temp->data;
            temp = temp->right;
        }
    }
    Node *leftTree = temp->left;
    while(leftTree != nullptr) {
        predecessor = leftTree->data;
        leftTree = leftTree->right;
    }
    Node *rightTree = temp->right;
    while(rightTree != nullptr) {
        successor = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int, int> answer = make_pair(predecessor, successor);
    return answer;
}

Node *lca(Node *root, Node *p, Node *q) {
    while(root != nullptr) {
        if(root->data < p->data && root->data < q->data)
            root = root->right;
        else if(root->data > p->data && root->data > q->data)
            root = root->left;
        else
            return root;
    }
}

int main() {
    return 0;
}
