#include <iostream>

class DoublyLinkedList {
private:
    // Definition of a doubly linked list node
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
bool deleteEven(){
	if(isEmpty())
		return false;
	auto*t=head;
	for(;t!=0;){
		if(t->data%2==0){
			if(head==tail)
				{
				delete tail;
				head=tail=0;
				t=0;
                break;
				}
			else if(t==head)
			{
				head=head->next;
				delete t;
				head->prev=0;
				t=head;
			}
			else if(t==tail)
			{
				tail=tail->prev;
				tail->next=0;
                delete t;
				t=0;
                break;
			}
            else{

                auto *tmp=t;
                t->next->prev=t->prev;
                t->prev->next=t->next;
                t=t->next;
                delete tmp;
            }
		}
		else 
			t=t->next;
	}
	return true;
	
}
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Search for a value in the list
    bool search(int v) {
        Node* current = head;
        while (current) {
            if (current->data == v) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Utility function to add a node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Utility function to display the list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Test the list
    dll.append(10);
    dll.append(21);
    dll.append(30);
    dll.append(24);
    dll.append(23);
    dll.append(31);
    dll.append(2);
    dll.display();
    dll.deleteEven();
    dll.display();

}
