// lecture 65

#include <iostream>
using namespace std;

class Node;
void sumOfLongestBloodline(Node *, int, int &, int, int);

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

void sumOfLongestBloodline(Node *root, int sum, int &maxSum, int len, int maxLen) {
    if(root == nullptr) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
            maxSum = max(sum, maxSum);
        return;
    }
    sum = sum + root->data;
    sumOfLongestBloodline(root->left, sum, maxSum, len + 1, maxLen);
    sumOfLongestBloodline(root->right, sum, maxSum, len + 1, maxLen);
}

int main() {
    return 0;
}
