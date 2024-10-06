// lecture 65

#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Node;
void sumOfLongestBloodline(Node *, int, int &, int, int);
Node *lca(Node *, int, int);
void sumK(Node *, int, int &, vector<int>);
Node *kthAncestor(Node *, int &, int);
pair<int, int> getMaxSum(Node *);

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

Node *lca(Node *root, int n1, int n2) {
    if(root == nullptr)
        return nullptr;
    if(root->data == n1 || root->data == n2)
        return root;
    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);
    if(leftAns != nullptr && rightAns != nullptr)
        return root;
    else if(leftAns != nullptr && rightAns == nullptr)
        return leftAns;
    else if(leftAns == nullptr && rightAns != nullptr)
        return rightAns;
    else
        return nullptr;
}

void sumK(Node *root, int k, int &count, vector<int> path) {
    if(root == nullptr)
        return ;
    path.push_back(root->data);
    sumK(root->left, k, count, path);
    sumK(root->right, k, count, path);
    int size = path.size();
    int sum = 0;
    for(int index = size - 1; index >= 0; index--) {
        sum = sum + path[index];
        if(sum == k)
            count++;
    }
    path.pop_back();
}

Node *kthAncestor(Node *root, int &k, int node) {
    if(root == nullptr)
        return nullptr;
    if(root->data == node)
        return root;
    Node *leftAns = kthAncestor(root->left, k, node);
    Node *rightAns = kthAncestor(root->right, k, node);
    if(leftAns != nullptr && rightAns == nullptr) {
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == nullptr && rightAns != nullptr) {
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return nullptr;
}

pair<int, int> getMaxSum(Node *root) {
    if(root == nullptr) {
        pair<int, int> p = make_pair(0, 0); //.first -> sum including the node, .second-> sum excluding the node
        return p;
    }
    pair<int, int> left = getMaxSum(root->left);
    pair<int, int> right = getMaxSum(root->right);
    pair<int, int> result;
    result.first = root->data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);
    return result;
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);

    int sum = 0;
    int maxSum = INT_MIN;
    int len = 0;
    int maxLen = 0;
    sumOfLongestBloodline(root, sum, maxSum, len, maxLen);
    cout << endl << "Sum of Longest Bloodline: " << maxSum << endl;

    Node *value = lca(root, 3, 11);
    cout << "Least Common Ancestor: " << value->data << endl;

    int count = 0;
    vector<int> path;
    sumK(root, 11, count, path);
    cout << "Number of paths with sum = 11: " << count << endl;

    int k = 2;
    value = kthAncestor(root, k, 17);
    if(value == nullptr || value->data == 17)
        cout << "Kth Ancestor not found" << endl;
    else
        cout << "Kth Ancestor is: " << value->data << endl;

    pair<int, int> result;
    result = getMaxSum(root);
    cout << "Maximum sum of Non-adjacent nodes: " << max(result.first, result.second) << endl;

    cout << endl;
    return 0;
}
