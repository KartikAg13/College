#include <iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next) {
        val = x;
        this->next = next;
    }
};
ListNode *insertBack(ListNode *head, int value) {
    ListNode *temp = new ListNode(value);
    if(head == NULL) {
        head = temp;
        return head;
    }
    ListNode *move = head;
    while(move->next != NULL)
        move = move->next;
    move->next = temp;
    return head;
}
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *result = NULL;
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    while(head1 != NULL && head2 != NULL) {
        if(head1->val < head2->val) {
            result = insertBack(result, head1->val);
            head1 = head1->next;
        }
        else if(head1->val > head2->val) {
            result = insertBack(result, head2->val);
            head2 = head2->next;
        }
        else if(head1->val == head2->val) {
            result = insertBack(result, head1->val);
            result = insertBack(result, head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return result;
}
void print(ListNode *head) {
    ListNode *move = head;
    while(move != NULL) {
        cout << move->val << " ";
        move = move->next;
    }
    cout << endl;
}
int main() {
    ListNode *list1 = new ListNode(1);
    list1 = insertBack(list1, 2);
    list1 = insertBack(list1, 4);
    ListNode *list2 = new ListNode(1);
    list2 = insertBack(list2, 3);
    list2 = insertBack(list2, 4);
    ListNode *result = mergeTwoLists(list1, list2);
    print(list1);
    print(list2);
    print(result);
    return 0;
}