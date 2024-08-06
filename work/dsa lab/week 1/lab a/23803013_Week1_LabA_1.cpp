#include <iostream>
#include <vector>
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

Node *insertHead(Node *head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}

double calculateAverage(Node *head) {
    double sum = 0;
    int count = 0;
    Node *move = head;
    while (move != NULL) {
        sum = sum + move->data;
        move = move->next;
        count++;
    }
    return (sum / count);
}

void printStart(Node *head, int m) {
    Node *move = head;
    for(int index = 1; index <= m; index++) {
        cout << move->data << " ";
        move = move->next;
    }
    cout << endl;
}

Node *deleteHead(Node *head) {
    Node *temp = head;
    head = temp->next;
    delete temp;
    return head;
}

bool middleIsEven(Node *head) {
    Node *fast = head;
    Node *slow = head;
    while(fast->next != NULL && fast != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(slow->data % 2 == 0)
        return true;
    else
        return false;
}

void printEnd(Node *head, int l) {
    Node *first = head;
    Node *second = head;
    for(int index = 1; index <= l; index++)
        first = first->next;
    while(first != NULL) {
        first = first->next;
        second = second->next;
    }
    while(second != first) {
        cout << second->data << " ";
        second = second->next;
    }
    cout << endl;
}

Node *deleteElement(Node *head, int element) {
    Node *current = head->next;
    Node *previous = head;
    if(head->data == element)
        deleteHead(head);
    while(current->next != NULL) {
        if(current->data == element) {
            previous->next = current->next;
            delete current;
            break;
        }
        current = current->next;
        previous = previous->next;
    }
    return head;
}

void print(Node *head) {
    Node *move = head;
    while(move != NULL) {
        cout << move->data << " ";
        move = move->next;
    }
    cout << endl;
}

bool searchList(Node *head, vector<int> sublist) {
    int size = sublist.size();
    int position = 1;
    Node *temp = head;
    while(temp != NULL) {
        position++;
        if(sublist[0] == temp->data)
            break;
        temp = temp->next;
    }
    Node *search = temp->next;
    for(int index = 1; index < size; index++) {
        if(sublist[index] == search->data)
            continue;
        else {
            position = -1;
            break;
        }
    }
    return position;
}


int main() {
    Node *head = new Node(-67);
    head = insertHead(head, 100);
    head = insertHead(head, 56);
    head = insertHead(head, 3);
    head = insertHead(head, 2);
    head = insertHead(head, 45);
    head = insertHead(head, -9);
    head = insertHead(head, 3);
    head = insertHead(head, 1);
    print(head);
    cout << "Average: " << calculateAverage(head) << endl;
    printStart(head, 4);
    cout << "Middle is Even: " << middleIsEven(head) << endl;
    printEnd(head, 3);
    head = deleteElement(head, 45);
    vector<int> sublist = {3, -9, 45};
    cout << "Sublist exists: " << searchList(head, sublist) << endl;
    return 0;
}