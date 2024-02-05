#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*lchild;
        Node*rchild;
    Node(int size){
        this->data=size;
        this->lchild=NULL;
        this->rchild=NULL;
    }
};
class BST{
    private:
        Node*root;
    public:
    BST(){
        this->root=NULL;
    }
    Node*getroot(){
        return root;
    }

    Node* insert(Node* &root,int val){
        Node*temp=new Node(val);
        if(root==NULL){
            root=temp;
            return root;
        }
        else{
            if(val<root->data){
                root->lchild=insert(root->lchild,val);
            }
            else{
                root->rchild=insert(root->rchild,val);
            }
            return root;
        }
    }
    void inorder(Node* &root){
        if(root==NULL){
            return;
        }
        else{
            inorder(root->lchild);
            cout<<root->data<<" ";
            inorder(root->rchild);
        }
    }
    void preorder(Node* &root){
        if(root==NULL){
            return;
        }
        else{
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
        }
    }
    void postorder(Node* &root){
        if(root==NULL){
            return;
        }
        else{
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<root->data<<" ";
        }
    }
    int totalnode(Node* &root){
        if(root==NULL){
            return 0;
        }
        else{
            return (totalnode(root->lchild)+totalnode(root->rchild)+1);
        }
    }
    int totalinternalnode(Node* &root){
        if(root==NULL){
            return 0;
        }
        else if(root->lchild==NULL && root->rchild==NULL){
            return 0;
        }
        else{
            return (totalinternalnode(root->lchild)+totalinternalnode(root->rchild)+1);
        }
    }
    int totalexternalnode(Node* &root){
        if(root==NULL){
            return 0;
        }
        else if(root->lchild==NULL && root->rchild==NULL){
            return 1;
        }
        else{
            return (totalnode(root)-totalinternalnode(root));
        }
    }
    int height(Node*root){
        if(root==NULL){
            return 0;
        }
        else{
            return 1+max(height(root->lchild),height(root->rchild));
        }
    }
    Node* min(Node* &root){
        if (root==NULL){
            return NULL;
        }
        while(root->lchild){
            root=root->lchild;
        }
        return root;
    }
    Node* maximum(Node* &root){
        if(root==NULL){
            return NULL;
        }
        while(root->rchild){
            root=root->rchild;
        }
        return root;
    }
};

int main(){
    int choice,val;
    Node*root;
    BST b1;
    do{
        cout<<"\nBST OPERATION\n1. insert\n2. inorder traverse\n3. preorder traverse\n4. postorder traverse\n5. height\n0. exit\n";
        cout<<"enter your operations ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter node ";
                cin>>val;
                b1.insert(root,val);
                cout<<endl;
                break;
            case 2:
                b1.inorder(root);
                break;
            case 5:
                cout<<"height of binary tree "<<b1.height(root);
                break;
            case 0:
                cout<<"exiting from the program ";
                break;
            default:
                cout<<"invalid ";
                break;
        }

    }while(choice);
}