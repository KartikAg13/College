#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

    Node *insertHead(Node *head, int value) {
        Node *temp = new Node(value);
        Node *move = head;
        while(move->next != head)
            move = move->next;
        move->next = temp;
        temp->next = head;
        head = temp;
        return head;
    }

    Node *insertAtK(Node *head, int value, int position) {
        Node *move = head;
        for(int index = 1; index < position; index++)
            move = move->next;
        if(move == head)
            return insertHead(head, value);
        Node *temp = new Node(value);
        temp->next = move->next;
        move->next = temp;
        return head;
    }

    void print(Node *head) {
        Node *move = head;
        while(move->next != head) {
            cout << move->data << " ";
            move = move->next;
        }
        cout << move->data << endl;
    }

    int length(Node *head) {
        Node *move = head;
        int count = 1;
        while(move->next != head) {
            count++;
            move = move->next;
        }
        return count;
    }

    bool checkNegative(Node *head) {
        Node *move = head;
        bool negative = false;
        while(move != head) {
            if(move->data < 0)
                return true;
            move = move->next;
        }
        return false;
    }

    int valueGreater15(Node *head) {
        Node *move = head;
        int count = 0;
        if(move->data > 15)
            count++;
        while(move->next != head) {
            count++;
            move = move->next;
        }
        return count;
    }

    Node *deleteHead(Node *head) {
        Node *move = head;
        Node *temp = head->next;
        while(move->next != head) 
            move = move->next;
        move->next = temp;
        head = temp;
        return head;
    }

    Node *deleteNode(Node *head, int value) {
        Node *move = head;
        if(value == move->data)
            return deleteHead(head);
        while(move->next != head) {
            if(value == move->next->data) {
                Node *temp = move->next;
                move->next = move->next->next;
                temp->next = NULL;
                delete temp;
            }
            move = move->next;
        }
        return head;
    }

    void update(Node *head, int original, int value) {
        Node *move = head;
        while(move->next != head) {
            if(move->data == original)
                move->data = value;
            move = move->next;
        }
        if(move->data == original)
            move->data = value;
    }

    bool isPrime(int value) {
        for(int index = 2; index < value; index++) {
            if(value % index == 0)
                return true;
        }
        return false;
    }

    Node *deletePrime(Node *head) {
        Node *move = head;
        while(move->next != head) {
            if(isPrime(move->data))
                head = deleteNode(head, move->data);
            move = move->next;
        }
        return head;
    }

    bool isFibonacci(int value) {
        int a = 0;
        int b = 1; 
        int c = a + b;
        while(c < value) {
            if(c == value || a == value || b == value)
                return true;
            a = b;
            b = c;
            c = a + b;
        }
        return true;
    }

    Node *deleteFibonnaci(Node *head) {
        Node *move = head;
        while(move->next != head) {
            if(isFibonacci(move->data))
                head = deleteNode(head, move->data);
            move = move->next;
        }
        return head;
    }

    int main() {
        Node *head = new Node(1);
        insertAtK(head, 2, 2);
        insertAtK(head, 3, 1);
        insertAtK(head, 5, 2);
        insertAtK(head, 7, 1);
        print(head);
        cout << "Length: " << length(head);
        cout << "Negative: " << checkNegative(head) << endl;
        cout << "Greater than 15: " << valueGreater15(head) << endl;
        return 0;
    }