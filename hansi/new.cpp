#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* insertnode(node*&head,int value){
    node* temp=new node(value);
    if(head==NULL){
        head=temp;
        head->next=head;
    }
    node*curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    return head;
}
void oddeven(node*head){
    node* temp=head;
    node* e=new node(-1);
    node* even=e;
    node* o=new node(-1);
    node* odd=o;
    while(temp->next!=head){
        if(temp->data%2==0){
            e->next=new node(temp->data);
            e=e->next;
        }
        else{
            o->next=new node(temp->data);
            o=o->next;
        }
        temp=temp->next;
    }
    if(temp->data%2==0){
        e->next=new node(temp->data);
    }
    else{
        o->next=new node(temp->data);
    }
    even=even->next;
    odd=odd->next;
    e->next=even;
    o->next=odd;
   
    node* temp1=even;
    node*temp2=odd;
    while(temp1->next!=even){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
    while(temp2->next!=odd){
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
}

int main() {
   node* node1=new node(1);
   node* head=node1;
   node1->next=insertnode(head,2);
   node1->next=insertnode(head,3);
   node1->next=insertnode(head,4);
   node1->next=insertnode(head,5);
   node1->next=insertnode(head,6);
   node1->next=insertnode(head,9);
   node1->next=insertnode(head,11);
   oddeven(head);
}

