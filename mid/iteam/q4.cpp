#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    // Constructor for initializing a node
    node(int d, node *n = nullptr) {
        data = d;
        next = n;
    }
};

class list {
    node *head;

public:

void copy(list&o){
	auto*t=head;
	auto*ot=o.head=new node(head->data);
	for(;t->next!=nullptr;){
		t=t->next;
        cout<<t->data<<endl;
		if(!o.search(t->data)){
			ot->next=new node(t->data);
			ot=ot->next;
		}
		
	}
}
    // Constructor to initialize an empty list
    list() {
        head = nullptr;
    }

    // Function to insert an element at the beginning of the list
    void insertAtHead(int el) {
        head = new node(el, head);
    }

    // Function to search for an element in the list
    bool search(int el) {
        node *current = head;
        while (current != nullptr) {
            if (current->data == el) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to display all elements in the list
    void display() {
        node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~list() {
        node *current = head;
        while (current != nullptr) {
            node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    list l1;
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtHead(14);
    l1.insertAtHead(112);
    l1.insertAtHead(2);
    l1.insertAtHead(14);
    l1.display();
    list l2;
    l1.copy(l2);
    l2.display();
    
   

    return 0;
}
