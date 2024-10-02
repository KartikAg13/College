// lecture 64

#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Node;
vector<int> zigZagTraversal(Node *);
vector<int> boundaryTraversal(Node *);
vector<int> verticalOrder(Node *);
vector<int> topView(Node *);
void leftView(Node *, vector<int> &, int);

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

vector<int> zigZagTraversal(Node *root) {
    vector<int> result;
    if(root == nullptr)
        return result;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while(q.empty() == false) {
        int size = q.size();
        vector<int> answer(size);
        for(int index = 0; index < size; index++) {
            Node *frontNode = q.front();
            q.pop();
            int value = leftToRight ? index : size - index - 1;
            answer[value] = frontNode->data;
            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }
        leftToRight = !leftToRight;
        for(auto value: answer)
            result.push_back(value);
    }
    return result;
}

void traverseLeft(Node *root, vector<int> &answer) {
    if(root == nullptr || root->left == nullptr && root->right == nullptr)
        return;
    answer.push_back(root->data);
    if(root->left != nullptr)
        traverseLeft(root->left, answer);
    else
        traverseLeft(root->right, answer);
}

void traverseLeaf(Node *root, vector<int> &answer) {
    if(root == nullptr)
        return;
    else if(root->left == nullptr && root->right == nullptr) {
        answer.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, answer);
    traverseLeaf(root->right, answer);
}

void traverseRight(Node *root, vector<int> &answer) {
    if(root == nullptr || root->left == nullptr && root->right == nullptr)
        return;
    if(root->right != nullptr)
        traverseRight(root->right, answer);
    else
        traverseRight(root->right, answer);
    answer.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> answer;
    if(root == nullptr)
        return answer;
    answer.push_back(root->data);
    traverseLeft(root->left, answer);
    traverseLeaf(root, answer);
    traverseRight(root->right, answer);
    return answer;
}

vector<int> verticalOrder(Node *root) {
    map<int, map<int, vector<int>>> nodes;  // int -> Horizontal Distance, int -> Level
    queue<pair<Node *, pair<int, int>>> q;  // int -> Horizontal Distance, int -> Level
    vector<int> answer;
    if(root == nullptr)
        return answer;
    q.push(make_pair(root, make_pair(0, 0)));
    while(q.empty() == false) {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int horizontal_distance = temp.second.first;
        int level = temp.second.second;
        nodes[horizontal_distance][level].push_back(frontNode->data);
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(horizontal_distance - 1, level + 1)));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(horizontal_distance + 1, level + 1)));
    }
    for(auto i: nodes) {
        for(auto j: i.second) {
            for(auto k: j.second)
                answer.push_back(k);
        }
    }
    return answer;
}

vector<int> topView(Node *root) {
    vector<int> answer;
    if(root == nullptr)
        return answer;
    map<int, int> topNode;  // int -> Horizontal Distance, int -> Data
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while(q.empty() == false) {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int horizontal_distance = temp.second;
        if(topNode.find(horizontal_distance) == topNode.end())
            topNode[horizontal_distance] = frontNode->data;
        if(frontNode->left != nullptr)
            q.push(make_pair(frontNode->left, horizontal_distance - 1));
        if(frontNode->right != nullptr)
            q.push(make_pair(frontNode->right, horizontal_distance + 1));
    }
    for(auto index: topNode)
        answer.push_back(index.second);
    return answer;
}

vector<int> bottomView(Node *root) {
    vector<int> answer;
    if(root == nullptr)
        return answer;
    map<int, int> topNode;  // int -> Horizontal Distance, int -> Data
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while(q.empty() == false) {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int horizontal_distance = temp.second;
        topNode[horizontal_distance] = frontNode->data;
        if(frontNode->left != nullptr)
            q.push(make_pair(frontNode->left, horizontal_distance - 1));
        if(frontNode->right != nullptr)
            q.push(make_pair(frontNode->right, horizontal_distance + 1));
    }
    for(auto index: topNode)
        answer.push_back(index.second);
    return answer;
}

void leftView(Node *root, vector<int> &answer, int level) {
    if(root == nullptr)
        return;
    if(level == answer.size())
        answer.push_back(root->data);
    leftView(root->left, answer, level + 1);
    leftView(root->right, answer, level + 1);
}

void rightView(Node *root, vector<int> &answer, int level) {
    if(root == nullptr)
        return;
    if(level == answer.size())
        answer.push_back(root->data);
    leftView(root->right, answer, level + 1);
    leftView(root->left, answer, level + 1);
}

int main() {
    return 0;
}
