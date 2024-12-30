#include<iostream>

struct node{
    node*right;
    node*left;
    int data;
    node(int d,node*r=0,node*l=0):
    right(r),
    left(l),
    data(d)
    {
    }

};

class bst{

    node*root;

    bool add(int e,node*&r){
        if(r==0){
            r=new node(e);
            return true;
        }   
        if(e<r->data){
            return add(e,r->left);
        }
        if(e>r->data){
           return add(e,r->right);
        }
        return false;
    }

    void print_inorder(node*r){
        if(r!=0){
            print_inorder(r->left);
            std::cout<<r->data<<std::endl;
            print_inorder(r->right);
        }
    }

    void deleteTree(node*&r){
        if(r!=0){
            deleteTree(r->right);
            deleteTree(r->left);
            delete r;
            r=0;   
        }
    }

    bool search(int e,node*r){
        if(r!=0){
            if(e==r->data)
                return true;
            if(e<r->data){
                return search(e,r->left);
            }
            if(e>r->data){
                return search(e,r->right);
            }  
        }
        return false;
    }
    
    void deleteLeaves(node*&r){
        if(r==0)
            return;

        if(r->left==0&&r->right==0){
            delete r;
            r=0;
            return;
        }

        deleteLeaves(r->left);
        deleteLeaves(r->right);
        
    }

    void copyTree(node* &r, node* r2){
        if(r2!=0){
            add(r2->data);
            copyTree(r->left,r2->left);
            copyTree(r->right,r2->right);
        }
    }
    

public:

    bst():root(0)
    {
    }

    bool empty(){
        return root==0;
    }

    bool add(int e){
        return add(e,root);
    }

    void print_inorder(){
        print_inorder(root);
    }

    void deleteTree(){
        deleteTree(root);
    }

    bool search(int e){
        return search(e,root);
    }

    void deleteLeaves(){
        deleteLeaves(root);
    }

    void copyTree(bst&o){
        deleteTree();
        copyTree(root,o.root);

    }
};


int main(){

    bst tree,t2;
    tree.add(5);
    tree.add(2);
    tree.add(6);
    tree.add(4);
    tree.add(1);
    tree.add(8);
    
    t2.add(52);
    t2.add(212);
    t2.add(642);
    t2.add(214);
    t2.add(212);
    t2.add(842);
    
    tree.copyTree(t2);
    tree.print_inorder();
    
}