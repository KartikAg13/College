/*
Smallest prime number missing in an array: Given an array containing n distinct
numbers. The task is to find the smallest prime which is not present in the array.
*/

#include <iostream>
#include <math.h>

using namespace std;

class Node {
    public:
    int value;
    Node *left;
    Node *right;

    int isPrime(int x) {
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0)
                return 0;
        }
        return 1;
    }
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

    int maximum(Node *root) {
        Node *current = root;
        int max = current->value;
        while(current != NULL) {
            if(max < current->value)
                max = current->value;
            current = current->right;
        }
        return max;
    }

    Node *inOrder(Node *root) {
        if(root != NULL) {
            root->left = inOrder(root->left);
            if(root->value > 0 && root->isPrime(root->value))
                *(array + root->value) = root->value;
            else if(root->value > 0 && !root->isPrime(root->value))
                *(array + root->value) = -1;
            root->right = inOrder(root->right);
        }
        return root;
    }
};

int main() {
    int number, choice = 1;
    Tree tree(50);
    Node node;
    while(choice) {
        cout << "Please enter any number: ";
        cin >> number;
        tree.root = tree.insertNode(tree.root, number);
        cout << "0. No other element" << endl << "1. Add another element" << endl;
        cin >> choice;
    }
    int max = tree.maximum(tree.root);
    tree.root = tree.inOrder(tree.root);
    for(int i = 2; i <= max; i++) {
        if(*(tree.array + i) == 0 && node.isPrime(i)) {
            cout << "min: " << i << endl;
            return 0;
        }
    }
    cout << "No prime numbers missing" << endl;
    return 0;
}