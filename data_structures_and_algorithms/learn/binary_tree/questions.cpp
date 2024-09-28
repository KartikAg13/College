// lecture 63

#include <iostream>
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

int height(Node *root) {
    if(root == nullptr)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    int answer = max(left, right) + 1;
    return answer;
}

// diameter in O(n2)
int diameter(Node *root) {
    if(root == nullptr)
        return 0;
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    int answer = max(op1, max(op2, op3));
    return answer;
}

// diameter in O(n)
pair<int, int> diameterFast(Node *root) {
    if(root == nullptr) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int, int> answer;
    answer.first = max(op1, max(op2, op3));
    answer.second = max(left.second, right.second) + 1;
    return answer;
}

// isBalanced in O(n2)
bool isBalanced(Node *root) {
    if(root == nullptr)
        return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool difference = abs(height(root->left) - height(root->right)) <= 1;
    if (left == true && right == true && difference == true)
        return true;
    else
        return false;
}

// isBalanced in O(n)
pair<bool, int> isBalancedFast(Node *root) {
    if(root == nullptr) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool differnce = abs(left.second - right.second) <= 1;
    pair<bool, int> answer;
    if(leftAns == true && rightAns == true && differnce == true)
        answer.first = true;
    else
        answer.first = false;
    answer.second = max(left.second, right.second) + 1;
    return answer;
}

bool isIdentical(Node *r1, Node *r2) {
    if(r1 == nullptr && r2 == nullptr)
        return true;
    else if(r1 == nullptr && r2 != nullptr || r1 != nullptr && r2 == nullptr)
        return false;
    bool left = isIdentical(r1->left, r2->right);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    if(left == true && right == true && value == true)
        return true;
    else
        return false;
}

pair<bool, int> isSumTree(Node *root) {
    if(root == nullptr || root->left == nullptr && root->right == nullptr) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isSumTree(root->left);
    pair<bool, int> right = isSumTree(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool sum = root->data == left.second + right.second;
    pair<bool, int> answer;
    if(leftAns == true && rightAns == true || sum == true) {
        answer.first = true;
        answer.second = 2 * root->data;
    }
    else
        answer.second = false;
    return answer;
}

int main() {
    return 0;
}
