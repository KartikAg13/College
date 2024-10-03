#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* binarytree(node* root){
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter the data for left of node "<<data;
    root->left=binarytree(root->left);
    cout<<"enter the data for right of node "<<data;
    root->right=binarytree(root->right);
    return root;
}
void visitednodes(node* root, map<node*,bool>&visited) {
    queue<node*> q;
    q.push(root);
    visited[root] =false;  // Root has no parent

    while(!q.empty()) {
        node* front = q.front();
        visited[front]=false;
        q.pop();

        if(front->left) {
            q.push(front->left);
        }

        if(front->right) {
            q.push(front->right);
        }
    }
}
void inorder(node*root,map<node*,bool>&visited){
    stack<node*>s;
    s.push(root);
    while(!s.empty()){
        if(root->left!=NULL &&visited[root]==false){
            visited[root]=true;
            root=root->left;
            s.push(root);
        }
        else{
            if(root->left==NULL && root->right==NULL){
                cout<<root->data<<" ";
            }
            root=s.top();
            cout<<root->data<<" ";
            s.pop();
            s.push(root->right);
        }
    }
}

void preOrderTraversal(node *root) {
    if(root == nullptr)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    node* root=NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root=binarytree(root);
    cout << endl;
    // preOrderTraversal(root);
    map<node*,bool>visited;
    visitednodes(root,visited);
    inorder(root,visited);
    cout << endl;
    return 0;
}
