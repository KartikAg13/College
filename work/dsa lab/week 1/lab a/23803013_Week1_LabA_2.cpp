#include <iostream>
#include <string>
using namespace std;
class Node {
    public:
    string data;
    Node *next;

    Node(string data) {
        this->data = data;
        next = NULL;
    }
};

    void insertTail(Node *head, string value) {
        Node *move = head;
        Node *temp = new Node(value);
        while(move->next != NULL)
            move = move->next;
        move->next = temp;
    }

    void print(Node *head) {
        Node *move = head;
        while(move != NULL) {
            cout << move->data << " ";
            move = move->next;
        }
        cout << endl;
    }

    void printSpecific(Node *head, char search) {
        Node *move = head;
        while(move != NULL) {
            if(move->data[0] == search)
                cout << move->data << " ";
            move = move->next;
        }
        cout << endl;
    }

    void search(Node *head, string value) {
        Node *move = head;
        while(move != NULL) {
            if(move->data == value)
                cout << move->data << " ";
            move = move->next;
        }
        cout << endl;
    }

    Node *maxLength(Node *head) {
        Node *temp = head;
        Node *address = NULL;
        int length = 0, max_length = 0;
        while(temp != NULL) {
            length = temp->data.length();
            if(length > max_length) {
                max_length = length;
                address = temp;
            }
            temp = temp->next;
        }
        return address;
    }

    void searchSubstring(Node *head) {
        Node *temp = head;
        int found = 0;
        while(temp != NULL) {
            found = temp->data.find("xyz");
            if(found != string::npos)
                cout << "xyz found in " << temp->data << " at " << found << endl;
            else
                cout << "xyz not found in " << temp->data << endl;
            temp = temp->next;
        }
    }

    Node *interchange(Node *head, int pos1, int pos2) {
        Node *move = head;
        Node *prev1 = head;
        Node *prev2 = head;
        for(int index = 1; index < pos1; index++)
            prev1 = prev1->next;
        for(int index = 1; index < pos2; index++)
            prev2 = prev2->next;
        Node *add1 = prev1->next;
        Node *add2 = prev2->next;
        prev1->next = add2;
        prev2->next = add1;
        Node *temp2 = add2->next;
        Node *temp1 = add1->next;
        add1->next = temp2;
        add2->next = temp1;
        return head;
    }

    Node *deleteNode(Node *head, int position) {
        Node *temp = head;
        if(position > 1) {
            for(int index = 1; index < position; index++)
                temp = temp->next;
            temp->next = temp->next->next;
        }
        else
            head = head->next;
        return head;
    }

    int main() {
        Node *head = new Node("kartik");
        insertTail(head, "arnav");
        insertTail(head, "vihan");
        insertTail(head, "aditya");
        insertTail(head, "arush");
        print(head);
        printSpecific(head, 'a');
        search(head, "aditya");
        searchSubstring(head);
        head = interchange(head, 1, 4);
        head = deleteNode(head, 2);
        return 0;
    }