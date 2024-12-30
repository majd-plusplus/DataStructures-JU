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
    void printR(){
        auto *t=tail;
        for(;t!=0;t=t->pre){
            cout<<t->data<<" ";
        }
        cout<<endl;

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
            tail=tail->next=new node(e,tail);
        }
	}

	void addBegin(int e){
		if(head==0)
            tail=head=new node(e);
        else{
            head=head->pre=new node(e,0,head);
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
        t->next=t->next->pre=new node(e,t,t->next);
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
            auto*t=tail;
            tail=tail->pre;
            delete t;
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
        head->pre=0;
        return true;
	}

	bool deletePos(int pos){
		if(head==0) 
			return false;
		if(pos<1||pos>count())
			return false;
		
		 auto*t=head;
            for(int i=1;i<pos;i++,t=t->next);
            
            t->next->pre=t->pre;
            t->pre->next=t->next;
            delete t;
            
            return true;
	}

	list(const list&o){
		
		if(this!=&o){
			
            auto*t=head;
            auto *ot=o.head;
            t=head=new node(ot->data);
            while(ot->next!=0){
                ot=ot->next;
                t->next=new node(ot->data,t);
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
                t->next=new node(ot->data,t);
                t=t->next;
            }
            tail=t;
		}
        return *this;
		

	}

    void deleteEven(){
        auto*t=head;
        for(;t!=0;){

            if(t->data%2==0){
                if(head==tail){
                    delete head;
                    t=head=tail=0;
                    break;
                }
                else if(t==head){
                    head=head->next;
                    delete t;
                    t=head;
                }
                else if(t==tail){

                    tail=tail->pre;
                    delete t;
                    tail->next=0;
                    t=0;
                    break;
                }
                else{

                    auto*tmp=t;
                    t->pre->next=t->next;
                    t=t->next;
                    delete tmp;
                }
            }
            else t=t->next;
        }
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
    l.deleteEven();
    l.print();
}