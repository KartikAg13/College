// lecture 72

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

void convertIntoSortedDoublyLinkedList(Node *root, Node * &head) {
    if(root == nullptr)
        return nullptr;
    convertIntoSortedDoublyLinkedList(root->right, head);
    root->right = head;
    if(head != nullptr)
        head->left = root;
    head = root;
    convertIntoSortedDoublyLinkedList(root->left, head);
}

Node *mergeLinkedList(Node *head1, Node *head2) {
    Node *head = nullptr;
    Node *tail = nullptr;
    while(head1 != nullptr && head2 != nullptr) {
        if(head1->data < head2->data) {
            if(head == nullptr) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else {
            if(head == nullptr) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != nullptr) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != nullptr) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->right;
    }
    return count;
}

Node *sortedLLToBST(Node *&head, int n) {
    if(n <= 0 || head == nullptr)
        return nullptr;
    Node *left = sortedLLToBST(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->next;
    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

Node *mergeBST(Node *root1, Node *root2) {
    Node *head1 = nullptr;
    convertIntoSortedDoublyLinkedList(root1, head1);
    head1->left = nullptr;
    Node *head2 = nullptr;
    convertIntoSortedDoublyLinkedList(root2, head2);
    head2->left = nullptr;
    
    Node *head = mergeLinkedList(head1, head2);

    return sortedLLToBST(head, countNodes(head));
}