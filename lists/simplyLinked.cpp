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
    node*head,*tail;
public:
    list(){
        head=tail=0;
    }
    int count(){
        auto*t=head;
        int c=0;
        for(;t!=0;t=t->next){
            c++;
        }
        return c;
    }
    
	void print(){
		auto *t=head;
        for(;t!=0;t=t->next){
            cout<<t->data<<" ";
        }
        cout<<endl;
	}
	void addEnd(int e){
        if(head==0)
            tail=head=new node(e);
        else{
            tail=tail->next=new node(e);
        }
	}

	void addBegin(int e){
		if(head==0)
            tail=head=new node(e);
        else{
            head=new node(e,head);
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
		auto*t=head;
        for(int i=1;i<pos-1;i++){
            t=t->next;
        }
        t->next=new node(e,t->next);
		return true;
	}

	bool deleteEnd(){
        if(head==0)
            return false;
		if(head==tail){
            delete head;
            tail=head=0;
            return true;
        }
        else{
            auto*t=head;
            for(;t->next!=tail;t=t->next);
            delete tail;
            tail=t;
            tail->next=0;
            return true;

        }

	}

	bool deleteBegin(){
		if(head==0)
            return false;
		if(head==tail){
            delete head;
            tail=head=0;
            return true;
        }
        auto*t=head;
        head=head->next;
        delete t;
        return true;

	}

	bool deletePos(int pos){
		if(head==0) 
			return false;
		if(pos<1||pos>count())
			return false;
		
		 auto*t=head;
            for(int i=1;i<pos-1;i++,t=t->next);
            auto *tmp=t->next;
            t->next=t->next->next;
            delete tmp;
            return true;
	}

	list(const list&o){
		
		if(this!=&o){
			
            auto*t=head;
            auto *ot=o.head;
            t=head=new node(ot->data);
            while(ot->next!=0){
                ot=ot->next;
                t->next=new node(ot->data);
                t=t->next;
            }
            tail=t;
		}
		

	}
	
	list&operator=(const list&o){
			if(this!=&o){
			while(head!=0)
				deleteBegin();
            auto*t=head;
            auto *ot=o.head;
            t=head=new node(ot->data);
            while(ot->next!=0){
                ot=ot->next;
                t->next=new node(ot->data);
                t=t->next;
            }
            tail=t;
		}
        return *this;
		

	}

    void removeDuplicates(){

        auto*t=head;
        for(;t->next!=0;){
            if(t->data==t->next->data){
                if(t==head){
                    head=head->next;
                    delete t;
                    t=head;
                }
                if(t->next->next==0){
                    delete tail;
                    tail=t;
                    tail->next=0;
                    t=0;
                }
                else{
                auto*tmp=t->next;
                t=t->next->next;
                delete tmp;
                }
            }
            else{
                t=t->next;
            }
        }
    }
};

int main(){


    list l;
    l.addBegin(1);
    l.addBegin(2);
    l.addBegin(2);   
     l.addBegin(3);
    l.addBegin(4);
   
   

    l.removeDuplicates();
    l.print();
    
}