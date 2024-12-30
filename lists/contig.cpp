#include<iostream>
using namespace std;
const int capacity=10;
class list{
	int l[capacity];
	int len;
	
public:
	list(){
		len=0;
	}
	void print(){
		for(int i=0;i<len;i++)
			cout<<l[i]<<" ";
		cout<<endl;
	}
	bool addEnd(int e){
		if(len!=capacity){
			l[len++]=e;
			return true;
		}
		return false;
	}

	bool addBegin(int e){
		if(len!=capacity){
			for(int i=len;i>0;i--){
				l[i]=l[i-1];
			}
			l[0]=e;
			len++;
			return true;
		}
		return false;
	}

	bool addPos(int e,int pos){
		if(pos==0)
			return addBegin(e);
		if(pos==len)
			return	addEnd(e);
		
		if(len!=capacity){
			for(int i=len;i>pos;i--){
				l[i]=l[i-1];
			}
			l[pos]=e;
			len++;
			return true;
		}
		return false;
	}

	bool deleteEnd(){
		if(len!=0){
			len--;
			return true;
		}
		return false;
	}

	bool deleteBegin(){
		if(len!=0){
			for(int i=0;i<len;i++){
				l[i]=l[i+1];
			}
			len--;
			return true;
		}
		return false;
	}

	bool deletePos(int pos){
		if(len==0) 
			return false;
		if(pos<0||pos>=len)
			return false;
		
		for(int i=pos;i<len;i++){
				l[i]=l[i+1];
			}
			len--;
		return true;
	}

	list(const list&o){
		if(this!=&o){
			len=o.len;
			for(int i=0;i<len;i++){
				l[i]=o.l[i];
			}
		}

	}
	
	list&operator=(const list&o){
		if(this!=&o){
			while(len!=0)
				deleteBegin();
			len=o.len;
			for(int i=0;i<len;i++){
				l[i]=o.l[i];
			}
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
	l.addEnd(12);
	l.addPos(100,3);
	l.print(); 
	l.deletePos(5);
	l.print();
	list l2;
	l2=l;
	l2.print();
}
