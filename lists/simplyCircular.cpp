#include<iostream>
using namespace std;

struct node{
    node* next;
    int data;
    node(int d,node*n=0){
        next=n;
        data=d;
    }
};

class list{
    node *tail;
public:
    list(){
        tail=0;
    }
    int count(){
        auto*t=tail->next;
        int c=0;
        if(tail==0)
            return 0;
        do{
            t=t->next;
            c++;
        }while(t->next!=tail->next);
        return c;
    }
	void print(){
		 auto*t=tail->next;
    
       
        do{
           cout<<t->data<<" ";
           t=t->next;
        }while(t->next!=tail->next);
        cout<<endl;
	}
	void addEnd(int e){
        if(tail==0)
            tail->next=tail=new node(e);
        else{
            tail=tail->next=new node(e,tail->next);
        }
	}

	void addBegin(int e){
		if(tail==0)
            tail->next=tail=new node(e);
        else{
            tail->next=new node(e,tail->next);
        }
	}

	bool addPos(int e,int pos){
        if(pos<1||pos>count()+1)
            return false;
		if(pos==1){
             addBegin(e);
             return true;
        }
		if(pos==count()+1){
	        addEnd(e);
            return true;
        }
		auto*t=tail->next;
        for(int i=1;i<pos-1;i++){
            t=t->next;
        }
        t->next=new node(e,t->next);
		return true;
	}

	bool deleteEnd(){
        if(tail==0)
            return false;
		if(tail->next==tail){
            delete tail;
            tail=0;
            return true;
        }
        
            auto*t=tail->next;
            for(;t->next!=tail;t=t->next);
            auto*tmp=tail;
            tail=t->next=tail->next;
            delete tmp;
            return true;
	}

	bool deleteBegin(){
		if(tail->next==0)
            return false;
		if(tail->next==tail){
            delete tail;
            tail=0;
            return true;
        }
        auto*t=tail->next;
        tail->next=tail->next->next;
        delete t;
        return true;

	}

	bool deletePos(int pos){
		if(tail==0) 
			return false;
		if(pos<1||pos>count())
			return false;
		
		 auto*t=tail->next;
            for(int i=1;i<pos-1;i++,t=t->next);
            auto *tmp=t->next;
            t->next=t->next->next;
            delete tmp;
            return true;
	}

	list(const list&o){
		
		if(this!=&o){
			
            auto*t=tail;
            auto *ot=o.tail;
            t=tail=new node(ot->data);
            while(ot->next!=tail){
                ot=ot->next;
                t->next=new node(ot->data);
                t=t->next;
            }
            t->next=tail;
		}
		

	}
	
	list&operator=(const list&o){
			if(this!=&o){
			while(tail!=0)
                deleteBegin();
            auto*t=tail;
            auto *ot=o.tail;
            t=tail=new node(ot->data);
            while(ot->next!=o.tail){
                ot=ot->next;
                t->next=new node(ot->data);
                t=t->next;
            }
            t->next=tail;
		}
        return *this;
		

	}
};

int main(){


    list l;
    l.addBegin(1);
    l.addBegin(2);
    l.addBegin(3);
    l.addBegin(4);
    l.addEnd(2);
    l.print();
    
     l.addPos(100,1);

    l.print();
    l.deleteBegin();
    l.print();
    l.deleteEnd();
    l.print();
    l.deletePos(2);
    l.print();

    list l2;
    l2=l;
    l2.print();
}