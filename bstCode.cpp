#include<iostream>
using namespace std;
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
    
    int height(node*r){
        if(r==0)
            return -1;
        int hl=height(r->left);
        int hr=height(r->right);
        if(hl>hr)
            return hl+1;
        else 
            return hr+1;
    }
//     Q1 - Define a BST member recursive function that will find the sum
// of even values of the internal nodes (internal nodes means all
// nodes without leaves).
    int sumEven(node*r){
        if(r==0)
            return 0;

        if(r->data%2==0&&(r->left!=0||r->right!=0))
            return r->data+ sumEven(r->right)+sumEven(r->left);
        else
            return 0+sumEven(r->right)+sumEven(r->left);

    }
//     Q2 - Define a BST member recursive function that will decrement
//  value of each element in BST by 1 .
    void decrement(node*&r){
        if(r!=0){
            decrement(r->left);
            decrement(r->right);
            r->data--;
        }
    }

// Q3 - Define a BST member recursive function that will find the sum
// of internal nodes (internal nodes means all nodes without

int internalSum(node*r){
    if(r==0)
        return 0;
    if(r->right!=0||r->left!=0){
        return r->data+internalSum(r->left)+internalSum(r->right);
    }
    else{
        return 0+internalSum(r->left)+internalSum(r->right);
    }
}

// Q5 - Define a BST member recursive function that will increment
// all elements by specific number .
// Ex. If bst have nodes (1,2,3,4) when call the function incByNum(5)
// the nodes will be (6,7,8,9)

void incrementBy(int n,node*&r){
        if(r!=0){
            incrementBy(n,r->left);
            incrementBy(n,r->right);
            r->data+=n;;
        }
    }

// Define a BST member recursive function that will count the
// number of leaves (leaves mean the node that has not any child)

int noOfLeaves(node*r){
    if(r==0)
        return 0;
    if(r->left==0&&r->right==0)
        return 1;
    return noOfLeaves(r->left)+noOfLeaves(r->right); 
}

// Q9 – Write a simple member function to find the maximum number in
// the bst .
int max(node*r){

    if(r->right==0)
        return r->data;
    return max(r->right);
}

// Q11 - Complete the definition of the following BST member
// recursive function that will find the sum of all nodes value from
// the root to a certain value .

int sumToN(int n){9
 
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

    int sumEven(){
       return  sumEven(root);
    }
    
    void decrement(){
        decrement(root);
    }

    int internalSum(){
        return internalSum(root);
    }

    void incrementBy(int n){
        incrementBy(n,root);
    }

    int noOfLeaves(){
        return noOfLeaves(root);
    }
    
    int max(){
        return max(root);
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
    tree.add(9);
    tree.add(7);
    cout<<tree.max()<<endl;
}