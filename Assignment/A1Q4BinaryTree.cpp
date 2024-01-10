/*
Given an unsorted array with both positive and negative elements. Find the smallest
positive number missing from the array in O(n) time using constant extra space. It is
allowed to modify the original array.
*/

#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node *left;
    Node *right;
};

class Tree {
    public:
    Node *root;
    int *array;

    Tree(int size) {
        root = NULL;
        array = new int[size]();
    }

    Node *insertNode(Node *root, int number) {
        Node *current = new Node();
        current->value = number;
        current->left = NULL;
        current->right = NULL;
        if(root == NULL) 
            root = current;
        else if(number < root->value) 
            root->left = insertNode(root->left, number);
        else
            root->right = insertNode(root->right, number);
        return root;
    }

    Node *inOrder(Node *root) {
        if(root != NULL) {
            root->left = inOrder(root->left);
            *(array + root->value) =  root->value;
            root->right = inOrder(root->right);
        }
        return root;
    }
};

int main() {
    int number, choice = 1;
    Tree tree(50);
    while(choice) {
        cout << "Please enter any number: ";
        cin >> number;
        if(number > 0)
            tree.root = tree.insertNode(tree.root, number);
        cout << "0. No other element" << endl << "1. Add another element" << endl;
        cin >> choice;
    }
    tree.root = tree.inOrder(tree.root);
    for(int i = 1; i < 50; i++) {
        if(*(tree.array + i) == 0) {
            cout << "min: " << i << endl;
            break;
        }
    }
    return 0;
} 