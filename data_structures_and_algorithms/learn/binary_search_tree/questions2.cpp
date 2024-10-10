// lecture 71

#include <iostream>
#include <vector>
using namespace std;

class Node;
bool twoSum(Node *, int);
Node *flatten(Node *);
Node *inOrderToBST(int, int, vector<int> &);
Node *preOrderToBST(vector<int>, int, int, int &);

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

void inOrderTraversal(Node *root, vector<int> &inorder) {
    if(root == nullptr)
        return ;
    inOrderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inOrderTraversal(root->right, inorder);
}

bool twoSum(Node *root, int target) {
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    int start = 0;
    int end = inorder.size() - 1;
    while(start < end) {
        int sum = inorder[start] + inorder[end];
        if(sum == target)
            return true;
        else if(sum > target)
            end--;
        else
            start++;
    }
    return false;
}

Node *flatten(Node *root) {
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    int size = inorder.size();
    Node *newRoot = new Node(inorder[0]);
    Node *temp = newRoot;
    for(int index = 1; index < size; index++) {
        Node *node = new Node(inorder[index]);
        temp->left = nullptr;
        temp->right = node;
        temp = node;
    }
    temp->left = nullptr;
    temp->right = nullptr;
    return newRoot;
}

Node *inOrderToBST(int start, int end, vector<int> &inorder) {
    if(start > end)
        return nullptr;
    int middle = (start + end) / 2;
    Node *root = new Node(inorder[middle]);
    root->left = inOrderToBST(start, middle - 1, inorder);
    root->right = inOrderToBST(middle + 1, end, inorder);
    return root;
}

Node *preOrderToBST(vector<int> preorder, int minimum, int maximum, int &index) {
    if(index >= preorder.size() || preorder[index] < minimum || preorder[index] > maximum)
        return nullptr;
    Node *root = new Node(preorder[index++]);
    root->left = preOrderToBST(preorder, minimum, root->data, index);
    root->right = preOrderToBST(preorder, root->data, maximum, index);
    return root;
}

int main() {
    return 0;
}
