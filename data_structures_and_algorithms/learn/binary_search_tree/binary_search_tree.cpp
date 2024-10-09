// lecture 69

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

bool searchBST(Node *root, int value) {
    Node *temp = root;
    while(temp != nullptr) {
        if(temp->data == value)
            return true;
        else if(value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

Node *minimum(Node *root) {
    Node *temp = root;
    while(temp->left != nullptr)
        temp = temp->left;
    return temp;
}

Node *maximum(Node *root) {
    Node *temp = root;
    while(temp->right != nullptr)
        temp = temp->right;
    return temp;
}

Node *deleteBST(Node *root, int value) {
    if(root == nullptr)
        return root;
    else if(root->data == value) {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if(root->left != nullptr && root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == nullptr && root->right != nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else {
            int minimumValue = minimum(root->right)->data;
            root->data = minimumValue;
            root->right = deleteBST(root->right, minimumValue);
            return root;
        }
    }
    else if(value < root->data) {
        root->left = deleteBST(root->left, value);
        return root;
    }
    else {
        root->right = deleteBST(root->right, value);
        return root;
    }
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

int main() {
    int data = 0;
    cout << "Please enter the root of the binary search tree: ";
    // 5 3 9 1 4 2 8 6 7
    cin >> data;
    Node *root = nullptr;
    while(data >= 0) {
        root = buildTree(root, data);
        cout << "Please enter a number: ";
        cin >> data;
    }

    // 5
    // 3 9
    // 1 4 8
    // 2 6
    // 7
    cout << endl << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    return 0;
}
