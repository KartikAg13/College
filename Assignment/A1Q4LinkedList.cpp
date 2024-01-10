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
    Node *next;
};

class LinkedList {
    public:
    Node *head;
    Node *tail;
    int *array;

    LinkedList(int size) {
        head = NULL;
        tail = NULL;
        array = new int[size]();
    }

    void insertNodeAtEnd(int number) {
        Node *current = new Node();
        current->value = number;
        current->next = NULL;
        if(head == NULL) {
            head = current;
            tail = head;
        }
        else {
            tail->next = current;
            tail = tail->next;
        }
    }

    void traversal() {
        Node *current = head;
        int data = 0;
        while(current != NULL) {
            data = current->value;
            *(array + data) = data;
            current = current->next;
        }
        delete current;
    }
};

int main() {
    int number, choice = 1;
    LinkedList list(50);
    while(choice) {
        cout << "Please enter any number: ";
        cin >> number;
        if(number > 0)
            list.insertNodeAtEnd(number);
        cout << "0. No other element" << endl << "1. Add another element" << endl;
        cin >> choice;
    }
    list.traversal();
    for(int i = 1; i < 50; i++) {
        if(*(list.array + i) == 0) {
            cout << "min: " << i << endl;
            break;
        } 
    }
    return 0;
}