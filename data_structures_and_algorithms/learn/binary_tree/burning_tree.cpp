// lecture 67

#include <iostream>
#include <iterator>
#include <map>
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

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent) {
    Node *result = nullptr;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = nullptr;
    while(q.empty() == false) {
        Node *front = q.front();
        q.pop();
        if(front->data == target)
            result = front;
        if(front->left != nullptr) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right != nullptr) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent) {
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while(q.empty() == false) {
        bool flag = false;
        int size = q.size();
        for(int index = 0; index < size; index++) {
            Node *front = q.front();
            q.pop();
            if(front->left && visited[front->left] == false) {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if(front->right && visited[front->right] == false) {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if(nodeToParent[front] && visited[nodeToParent[front]]) {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag == true)
            ans++;
    }
    return ans;
}

int main() {
    cout << "Please enter the value for root of the tree: ";
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = buildTree(root);

    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, 3, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    cout << endl << "Time taken to burn the tree: " << ans << endl;
    return 0;
}
