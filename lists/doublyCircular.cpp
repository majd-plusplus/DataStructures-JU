#include<iostream>
using namespace std;

struct node{
    node* next;
    int data;
    node* pre;
    node(int d,node*p=0,node*n=0){
        next=n;
        data=d;
        pre=p;
    }
};

class list{
    node*tail;
public:
    list(){
        tail=0;
    }
    int count(){
        
       
        if(tail==0)
            return 0;
        if(tail==tail->next)
            return 1;

        int c=0;
        auto*t=tail->next;
        do{
        c++;
        t=t->next;
        }while(t!=tail->next);
        return c;
    }
    void printR(){
        auto *t=tail;
         
        do{
            cout<<t->data<<" ";
            t=t->pre;
        }while(t!=tail);
        cout<<endl;
    }
	void print(){
		auto *t=tail->next;
         
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=tail->next);
        cout<<endl;
	}
	void addEnd(int e){
        if(tail==0)
            tail->next->pre=tail->next=tail=new node(e);
        else{
            tail=tail->next=tail->next->pre=new node(e,tail,tail->next);
        }
	}

	void addBegin(int e){
		if(tail==0)
            tail->next->pre=tail->next=tail=new node(e);
        else{
           tail->next= tail->next->pre=new node(e,tail,tail->next);
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
        t->next=t->next->pre=new node(e,t,t->next);
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
        else{
            auto*t=tail;
            tail->next->pre=tail->pre;
            tail->pre->next=tail->next;
            tail=tail->pre;
            delete t;
           
            return true;

        }

	}

	bool deleteBegin(){
		if(tail==0)
            return false;
		if(tail->next==tail){
            delete tail;
            tail=0;
            return true;
        }
        auto*t=tail->next;
        tail->next->next->pre=tail;
        tail->next=tail->next->next;
        delete t;
        return true;
	}

	bool deletePos(int pos){
		if(tail==0) 
			return false;
		if(pos<1||pos>count())
			return false;
		if (pos==1)
            return deleteBegin();
        if(pos==count())
            return deleteEnd();
		 auto*t=tail->next;
            for(int i=1;i<pos;i++,t=t->next);
            
            t->next->pre=t->pre;
            t->pre->next=t->next;
            delete t;
            
            return true;
	}

	list(const list&o){
		
		if(this!=&o){
			
            auto*t=tail;
            auto *ot=o.tail;
            t=tail=new node(ot->data);
            while(ot->next!=o.tail){
                ot=ot->next;
                t->next=new node(ot->data,t);
                t=t->next;
            }
            t->next=tail;
            tail->pre=t;
            tail->next->pre=tail;
            
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
                t->next=new node(ot->data,t);
                t=t->next;
            }
            t->next=tail;
            tail->pre=t;
            tail->next->pre=tail;
		}
        return *this;
		

	}

    void swap(){

        auto*t=tail->next;
        do{
            int s=t->data;
            t->data=t->next->data;
            t->next->data=s;
            t=t->next->next;
        }while(t!=tail->next);
    }
};
int main(){

list l;
    l.addBegin(1);
    l.addBegin(2);
    l.addBegin(3);
    l.addBegin(4);
  
    l.print();
    
    l.swap();
    l.print();

   
    
}