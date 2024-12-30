#include <iostream>
using namespace std;

// Enum to represent error codes
enum error { success, underflow, out };

// Structure for a node
struct node {
    int data;
    node *next;
    // Constructor to initialize a node
    node(int d, node *n = nullptr) {
        data = d;
        next = n;
    }
};

// Class representing the singly linked list
class list {
    node *head;

public:
void move(list&o){
	auto*t=head;
	auto*ot=o.head;
	ot=o.head=new node(head->data);
	
	for(;t->next!=0;){
		t=t->next;
		ot->next=new node(t->data);
		ot=ot->next;
		
	}

    while(head!=0)
        delete_pos(0);
	
	
}
    // Constructor to initialize an empty list
    list() {
        head = nullptr;
    }

    // Function to add an element at the end of the list
    void add_end(int el) {
        node *newNode = new node(el);
        if (head == nullptr) { // If the list is empty
            head = newNode;
        } else {
            node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete a node at a specified position
    error delete_pos(int pos) {
        if (head == nullptr) {
            return underflow; // List is empty
        }

        if (pos < 0) {
            return out; // Invalid position
        }

        node *current = head;
        if (pos == 0) { // Deleting the head node
            head = head->next;
            delete current;
            return success;
        }

        // Traverse to the node before the position
        node *prev = nullptr;
        int index = 0;
        while (current != nullptr && index < pos) {
            prev = current;
            current = current->next;
            index++;
        }

        if (current == nullptr) { // Position out of bounds
            return out;
        }

        // Delete the node
        prev->next = current->next;
        delete current;
        return success;
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

// Main function to demonstrate the functionality
int main() {
    list myList;

    // Adding elements to the end
    myList.add_end(10);
    myList.add_end(20);
    myList.add_end(30);

    // Displaying the list
    
    myList.display();

    list l2;
    myList.move(l2);
    l2.display();
    myList.display();
}