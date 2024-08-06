#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node *back;

    Node(int data) {
        this->data = data;
        next = back = NULL;
    }
};

    Node *insertHead(Node *head, int value) {
        Node *temp = new Node(value);
        temp->next = head;
        head->back = temp;
        head = temp;
    }

    void check(Node *head, int m) {
        Node *move = head;
        while(move != NULL) {
            if(move->data % m == 0)
                cout << move->data << " is divisible" << endl;
            else
                cout << move->data << " is not divisible" << endl;
            move = move->next;
        }
    }

    Node *deleteHead(Node *head) {
        Node *move = head;
        move->next->back = NULL;
        head = move->next;
        move->next = NULL;
        delete move;
        return head;
    }

    Node *deleteX(Node *head, int x) {
        Node *move = head;
        if(move->data > x)
            return deleteHead(head);
        move = move->next;
        while(move != NULL) {
            if(move->data > x) {
                move->back->next = move->next;
                move->next->back = move->back;
                move->next = move->back = NULL;
                delete move;                
            }
            move = move->next;
        }
    }

    int number(Node *head, int duplicate) {
        Node *first = head;
        int count = 0;
        while(first != NULL) {
            if(first->data == duplicate)
                break;
            first = first->next;
        }
        Node *second = first->next;
        while(second != NULL) {
            if(second->data == duplicate)
                break;
            count++;
            second = second->next;
        }
        return count;
    }