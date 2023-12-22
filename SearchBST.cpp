#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *, int);
    int search(int);
};

Node *BST::insert(Node *root, int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL) {
        root = newNode;
    }
    else if(value >= root->data)
        root->right = insert(root->right, value);
        
    else
        root->left = insert(root->left, value);
    return root;
}

int BST::search(int searchKey) {
    Node *temp = root;
    while(temp != NULL) {
        if(temp->data == searchKey)
            return searchKey;
        else if(searchKey < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return -1;
}

int main() {
    BST tree;
    string ch = "yes";
    int num = 0;
    int searchKey = 0;
    int depth = 0;
    cout << "Enter the key number: ";
    cin >> num;
    tree.root = tree.insert(tree.root, num);
    do {
        cout << "Do you want to create another junction(yes / no): ";
        cin >> ch;
        if(ch.compare("yes") == 0) {
            cout << "Enter the key number: ";
            cin >> num;
            tree.root = tree.insert(tree.root, num);
        }
        else
            break;
    } while(true);
    cout << "Enter the key to be searched: ";
    cin >> searchKey;
    int flag = tree.search(searchKey);
    if(flag == searchKey)
        cout << "Search Key " << searchKey << " was found" << endl;
    else
        cout << "Search Key " << searchKey << " was not found" << endl;
    return 0;
}