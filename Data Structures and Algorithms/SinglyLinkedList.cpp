#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next; //Reference to next node
};

class LinkedList {
    public:
    Node *head; //First element of the list
    Node *tail; //Last element of the list
    
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertNodeAtFront(int value) {
        Node *newNode = new Node;   //Creates a new object of the class Node
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertNodeAtEnd(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tail = head;
            return ;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
            return ;
        }
    }

    void insertAtPosition(int pos, int value) {
        Node *current = new Node;   //To track the current node
        Node *previous = new Node;  //To track the previous node
        current = head;
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(pos < 1)
            cout << "Position cannot be less than one" << endl;
        else if(pos == 1) {
            newNode->next = head;
            head = newNode;
        }
        else {
            for(int i = 1; i < pos; i++) {
                previous = current;
                current = current->next;
                if(current == NULL) {
                    cout << "Invalid Position" << endl;
                    return ;
                }
            }
            previous->next = newNode;
            newNode->next = current;
        }
    }

    void search(int value) {
        Node *current = head;   //Reference variable to start traversal
        while(current != NULL) {
            if(current->data == value) {
                cout << "Element " << value << " is found" << endl;
                return ;
            }
            current = current->next;
        }
        cout << "Element " << value << " was not found" << endl;
    }

    void deleteNode(int value) {
        bool flag = false;
        Node *current = new Node;
        Node *previous = new Node;
        current = head;
        previous = head;
        while(current != NULL) {
            if(current->data == value && current == head) {
                head = current->next;
                free(current);
                flag = true;
                break;
            }
            else if(current->data == value) {
                previous->next = current->next;
                if(current == tail)
                    tail = previous;
                free(current);
                flag = true;
                break;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        if(flag)
            cout << "Element deleted" << endl;
        else
            cout << "Element not found" << endl;
    }

    void displayList() {
        Node *current = head;
        while(current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertNodeAtFront(10);
    list.insertNodeAtEnd(40);
    list.insertNodeAtEnd(50);
    list.insertAtPosition(2, 20);
    list.insertAtPosition(3, 30);
    list.search(30);
    list.deleteNode(30);
    list.displayList();
    return 0;
}