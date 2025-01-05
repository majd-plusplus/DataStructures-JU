#include<iostream>
#include"../lists/doublyLinked.h"

using namespace std;

// Create a recursive function to find the greatest common
// divisor (GCD) of two numbers in C++.
//using euclidean algo
void gcd(int l, int u) {

    if (l == 0)
        cout<<u<<endl;

    if(l!=0)
        gcd(u%l,l);
    
}

int gcd(int l, int u,int diff) {
    
    int g;
    if(l==0){
        return u;
    }
    g=gcd(u%l,l,diff);
        return g;
    
}

// Develop a recursive C++ function to compute the sum of
// elements in an array.

int sum(int a[],int s){
    
    if(s==0){
        return a[0];
    }
    return a[s]+sum(a,s-1);
}

// Develop a recursive C++ function to find the power of a
// number (x^n).

int pow(int x, int y){
    if(y==0)
        return 1;
    return x*pow(x,y-1);

}
// Create a simple recursive function to print numbers from 1
// to N in C++.

void printF(int n){
    if(n!=1){
    printF(n-1);
    cout<<n<<endl;
    }
    else{
        cout<<1<<endl;
    }
}
void printB(int n){
    if(n!=1){
    cout<<n<<endl;
    printB(n-1);
    }
    else 
        cout<<n<<endl;
}

// Write a recursive function to calculate the product of two
// positive integers without using the multiplication operator
// in C++.

int prod(int a,int b){
    if(b==0)
        return 0;
    return a+prod(a,b-1);
}

// Implement a recursive algorithm to calculate the sum of
// digits of a given positive number in C++.

int sumOfDigits(int n){
    if(n%10==0&&n/10==0)
        return 0;
    return n%10+sumOfDigits(n/10);

}

// Create a recursive function to calculate the sum of the
// first N even numbers in C++.

int sumOfEven(int n){
    if(n==0)
        return 0;
    if(n%2==0)
        return n+sumOfEven(n-1);
    else{
        return sumOfEven(n-1);
    }
}
// Write a recursive function in C++ to find the minimum value
// in an array .

int min(int a[],int s){
    if(s==0)
        return a[0];
    int m=min(a,s-1);
    if(m<a[s])
        return m;
    else 
        return a[s];   
}

// Write a recursive function in C++ to print an array
// backward.

void printR(int a[],int s){
    
    if(s>=0){
        printR(a,s-1);
            cout<<a[s]<<" ";
    }
   
}

// Write a recursive C++ function to calculate the nth
// Fibonacci number.

int fib(int n){
    if(n==0)
        return 0;
    if(n==2||n==1)
        return 1;

    return fib(n-1)+fib(n-2);

}

//Consider the following circular doubly linked list, write the
// implementation of the find_max functions (The private one and the
// public one) these functions aim to return the maximum value of the
// list recursively .

//the answer is in the header file of the doubly linked list
int main(){
    list l;
    l.addBegin(1);
    l.addBegin(2);
    l.addBegin(24);
    l.addBegin(24);
    l.addBegin(21);
    cout<<l.max()<<endl;
}