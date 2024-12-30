#include <iostream>
using namespace std;
struct cNode
{
int data;
cNode* next;
cNode(int d, cNode* n = 0)
{
data = d; next = n;
}
};
class SimplyCircularLL
{
cNode* tail;
public:
SimplyCircularLL();
void print();
void add_end(int el);
bool moveMax();
//Write a prototype for function Move_max that will move maximum element to front
//of a list
};
//Define Move_max function
SimplyCircularLL::SimplyCircularLL()
{
tail = 0;
}
void SimplyCircularLL::print()
{
if (tail != 0)
{
cNode* t = tail->next;
do
{
cout << t->data << " ";
t = t->next;
} while (t != tail->next);
}
cout << endl;
}

void SimplyCircularLL::add_end(int el)
{
if (tail == 0)
tail->next = tail = new cNode(el);
else
tail = tail->next = new cNode(el, tail->next);

}
bool SimplyCircularLL::moveMax(){
	auto*max=tail->next;
	auto*t=tail->next;
	do{
		if(t->data>max->data){
			max=t;
		}
		t=t->next;
	}while(t!=tail->next);
	int dmax=max->data;
	if(tail==tail->next)
		return true;
	if(max==tail->next)
		return true;
	if(max==tail){
		auto *tmp=tail->next;
		for(;t->next!=tail;t=t->next);
		t->next=tail->next;
        
        tail=t;
		tail->next=new cNode(dmax,tail->next);
        delete max;
		return true;
	}
	else{
		auto *tmp=tail->next;
		for(;t->next!=max;t=t->next);
		tmp->next=tmp->next->next;
		delete max;
		tail->next=new cNode(dmax,tail->next);
		return true;
	}
	
}

bool SimplyCircularLL::moveMax(){
	auto *max=tail->next;
	int pMax=1;
	int i=1;
	auto*t=tail->next;
	
	do{
		if(t->data>max->data){
			max=t;
			pMax=i;
			
		}
		i++;
        t=t->next;
	}while(t!=tail->next);
	
	if(max==tail->next)
		return true;
	if(max==tail){
		auto*tmp=tail->next;
		for(;tmp->next!=tail;tmp=tmp->next);
        tail->next=new cNode(max->data,tail->next);
		tmp->next=tail->next;
        
        delete tail;
        tail=tmp;
        return true;
	}
	else{
		auto*tmp=tail->next;
		for(;tmp->next!=max;tmp=tmp->next);
		tmp->next=tmp->next->next;
		tail->next=new cNode(max->data,tail->next);
		delete max;
        return true;
	}
   
	
}

int main(){

    SimplyCircularLL o1;
//Add elements 2,5,3,9,7,1 into o1
o1.add_end(2);
o1.add_end(5);
o1.add_end(3);
o1.add_end(9);
o1.add_end(7);
o1.add_end(10);
//Print o1
o1.print();
//Apply function Move_max to o1
o1.moveMax();
//Print o1
o1.print();
}