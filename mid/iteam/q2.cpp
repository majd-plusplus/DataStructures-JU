#include<iostream>
using namespace std;
struct dNode
{
int data;
dNode* next, * prev;
dNode(int el, dNode* n = 0, dNode* p = 0)
{
data = el; next = n; prev = p;
}
};

class DoublyLL {
private:
dNode* head, * tail;
public:
DoublyLL();
void print();
void addToDLLTail(int el);
void removeCommon(DoublyLL&o){
   
    auto*ot=o.head;
    for(;ot!=0;ot=ot->next){
        auto*t=head;
        while(t!=0){
            if(t->data==ot->data){
                if(head==tail){
                    delete t;
                    t=tail=head=0;
                    break;
                }
                else if(t==head){
                    head=head->next;
                    delete t;
                    head->prev=0;
                    t=head;
                }
                else if(t==tail){
                    tail=tail->prev;
                    delete t;
                    tail->next=0;
                    t=0;
                    break;
                }
                else{
                    auto*tmp=t;
                    t->next->prev=t->prev;
                    t->prev->next=t->next;
                    t=t->next;
                    delete tmp;
                }

            }
            else
                t=t->next;
        }
    }
}
};

//Write a prototype for function Remove_Common that will compare 2 lists and remove
//all elements
//from first list that are also found in second list
//EXAMPLE if list1 contains 1 2 3 4 and list2 contains 2 4 6 8
//list1.Remove_Common(list2); will remove 2 and 4 from list1

// void removeCommon(DoublyLL &o){

// 	auto*ot=o.head;
// 	for(;ot!=0;ot=ot->next){
//         for(auto *t=head;t!=0;){
//             if(ot->data==t->data){
//                 if(head==tail){
//                     delete head;
//                     head=tail=0;
//                     t=0;
//                 }
//                 if(t==head){
//                     auto*tmp=head;
//                     head=head->next;
//                     head->prev=0;
//                     delete tmp;
//                     t=head;
//                 }
//                 else if(tail==t){
//                     auto*tmp=tail;
//                     tail=tail->prev;
//                     tail->next=0;
//                     delete tmp;
//                     t=0;
//                 }
//                 else{

//                     auto*tmp=t;
//                     t->next->prev=t->prev;
//                     t->prev->next=t->next;
//                     delete tmp;
//                     t=t->next;
//                 }
//             }
//             else 
//                 t=t->next;
//         }
//     }
//     }
// };
DoublyLL::DoublyLL()
{
head = tail = 0;
}
void DoublyLL::print()
{
dNode* tmp = head;
for (; tmp != 0; tmp = tmp->next)
cout << tmp->data << " ";
cout << endl;
}




void DoublyLL::addToDLLTail(int el) {
if (tail != 0) {
tail = new dNode(el, 0, tail);
tail->prev->next = tail;
}
else head = tail = new dNode(el);
}


int main()
{
//Declare simply circular linked list object o1
//Add elements 2,5,3,9,7,1 into o1
DoublyLL o1;
o1.addToDLLTail(2);
o1.addToDLLTail(5);
o1.addToDLLTail(3);
o1.addToDLLTail(9);
o1.addToDLLTail(7);
o1.addToDLLTail(1);
o1.print();

DoublyLL o2;
o2.addToDLLTail(2);
o2.addToDLLTail(4);
o2.addToDLLTail(5);
o2.addToDLLTail(3);
o2.addToDLLTail(1);
o2.addToDLLTail(4);
o2.addToDLLTail(5);
o2.addToDLLTail(3);
o2.addToDLLTail(1);
o2.print();

o1.removeCommon(o2);
o1.print();
//Apply function Move_max to o1
//Print o1
//Declare 2 doubly linked list objects o2 and o3
//Add elements 2,4,5,3,1 into o2 and 6,7,2,5,9,1,8
//Print o2 and o3
//Apply function Remove_Common remove from o2 all common elements between o2
//and o3
//Print o2
}